#ifndef _CYCLIC_H
#define _CYCLIC_H

#include <array>
#include <cstdint>
#include <string>

namespace util {

namespace math {

namespace group {

template <uint32_t N>
class Cyclic {
  template <uint32_t N_>
  constexpr friend Cyclic<N_> operator*(const Cyclic<N_>& e1,
                                        const Cyclic<N_>& e2);
  template <uint32_t N_>
  constexpr friend bool operator==(const Cyclic<N_>& e1, const Cyclic<N_>& e2);
  template <uint32_t N_>
  constexpr friend bool operator!=(const Cyclic<N_>& e1, const Cyclic<N_>& e2);

 public:
  typedef uint8_t encoding_t;

  static constexpr uint64_t order() {
    return static_cast<uint64_t>(N);
  }

  static constexpr Cyclic<N> identity() {
    return Cyclic<N>();
  }

  constexpr Cyclic() : Cyclic(0) {}

  explicit constexpr Cyclic(encoding_t degree) : e_(degree) {}

  /*
   * Returns a unique uint32_t for this element, with the guarantee that it will
   * be the same when called on any equivalent elements, and that the ordinals
   * of all elements are >= 0 and contiguous.
   */
  constexpr uint32_t ordinal() const {
    return e_;
  }

  constexpr Cyclic<N> inverse() const {
    return Cyclic<N>((N - e_) % N);
  }

  std::string toString() const {
    return std::string("r") + std::to_string(e_);
  }

 private:
  encoding_t e_;
};

template <uint32_t N>
constexpr Cyclic<N> operator*(const Cyclic<N>& e1, const Cyclic<N>& e2) {
  return Cyclic<N>(
      static_cast<typename Cyclic<N>::encoding_t>((e1.e_ + e2.e_) % N));
}

template <uint32_t N>
constexpr bool operator==(const Cyclic<N>& e1, const Cyclic<N>& e2) {
  return e1.e_ == e2.e_;
}

template <uint32_t N>
constexpr bool operator!=(const Cyclic<N>& e1, const Cyclic<N>& e2) {
  return e1.e_ != e2.e_;
}

}  // namespace group

}  // namespace math

}  // namespace util

#endif /* _CYCLIC_H */
