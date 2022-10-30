#ifndef _ARENA_H
#define _ARENA_H

#ifdef __APPLE__
#include <mach/vm_statistics.h>
#endif
#include <sys/mman.h>

#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <new>

namespace util {

namespace memory {

template <class T, uint32_t ptr_size>
class Arena;

template <class T, uint32_t ptr_size = 8>
class ArenaPtr {
  template <class _T, uint32_t _ptr_size>
  friend class Arena;

  typedef typename std::conditional<
      ptr_size == 8, uint64_t,
      std::conditional<
          ptr_size == 4, uint32_t,
          std::conditional<ptr_size == 2, uint16_t,
                           std::conditional<ptr_size == 1, uint8_t, void>>>>::
      type ptr_data_t;

 private:
  constexpr ArenaPtr(T* ptr, const Arena<T, ptr_size>& arena);

  static constexpr uint64_t PtrToInt(T* ptr, T* arena_start) {
    return static_cast<uint64_t>(ptr - arena_start);
  }

 public:
  explicit constexpr ArenaPtr(uint64_t ptr_val) : ptr_val_(ptr_val) {}
  constexpr ArenaPtr(const ArenaPtr& ptr) = default;
  constexpr ArenaPtr() : ArenaPtr(null()) {}

  bool operator==(const ArenaPtr<T, ptr_size>& other) {
    return ptr_val_ == other.ptr_val_;
  }

  bool operator!=(const ArenaPtr<T, ptr_size>& other) {
    return !(*this == other);
  }

  T* get(const Arena<T, ptr_size>& arena) const;

  static constexpr ArenaPtr<T, ptr_size> null() {
    return ArenaPtr<T, ptr_size>(-1u);
  }

 private:
  ptr_data_t ptr_val_;
};

template <class T, uint32_t ptr_size = 8>
class Arena {
 private:
  static constexpr int MMAP_FLAGS =
#ifdef __APPLE__
      MAP_PRIVATE | MAP_ANONYMOUS | VM_FLAGS_SUPERPAGE_SIZE_2MB
#elif defined(MAP_HUGE_2MB)
      MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB | MAP_HUGE_2MB
#else
      MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB
#endif
      ;

  static constexpr void* SystemMemMap(std::size_t size) {
    void* region = mmap(NULL, size, PROT_WRITE, MMAP_FLAGS, -1, 0);
    return region;
  }

  static constexpr void* SystemMemMapExtend(void* arena_end, std::size_t size) {
    void* region =
        mmap(arena_end, size, PROT_WRITE, MMAP_FLAGS | MAP_FIXED, -1, 0);
    return region;
  }

  static constexpr int SystemMemUnmap(void* addr, std::size_t size) {
    return munmap(addr, size);
  }

  uint64_t NumElements(std::size_t arena_size) const {
    return arena_size / sizeof(T);
  }

 public:
  Arena(std::size_t arena_size = 2 * 1024 * 1024) : arena_size_(arena_size) {
    void* arena_start = SystemMemMap(arena_size);

    start_ = reinterpret_cast<T*>(arena_start);
    next_ = start_;
    end_ = reinterpret_cast<T*>(reinterpret_cast<uint64_t>(arena_start) +
                                arena_size);
  }
  ~Arena() {
    // Delete all elements in the arena.
    for (T* ptr = start_; ptr != next_; ptr++) {
      ptr->~T();
    }
    SystemMemUnmap(start_, arena_size_);
  }

  T* start() const {
    return start_;
  }

  template <typename... Args>
  ArenaPtr<T, ptr_size> malloc(Args... args) {
    if (next_ + 1 > end_) {
      void* res = SystemMemMapExtend(end_, arena_size_);
      if (res == nullptr) {
        return ArenaPtr<T, ptr_size>::null();
      }

      end_ =
          reinterpret_cast<T*>(reinterpret_cast<uint64_t>(end_) + arena_size_);
    }
    ArenaPtr<T, ptr_size> res(next_, *this);

    // Construct the element in place.
    new (reinterpret_cast<void*>(next_)) T(std::forward<Args>(args)...);

    next_++;
    return res;
  }

 private:
  T* start_;
  T* next_;
  T* end_;
  std::size_t arena_size_;
};

template <class T, uint32_t ptr_size>
constexpr ArenaPtr<T, ptr_size>::ArenaPtr(T* ptr,
                                          const Arena<T, ptr_size>& arena)
    : ArenaPtr(PtrToInt(ptr, arena.start())) {}

template <class T, uint32_t ptr_size>
T* ArenaPtr<T, ptr_size>::get(const Arena<T, ptr_size>& arena) const {
  return arena.start() + ptr_val_;
}

}  // namespace memory

}  // namespace util

#endif /* _ARENA_H */
