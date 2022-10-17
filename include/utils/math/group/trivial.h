#ifndef _TRIVIAL_H
#define _TRIVIAL_H

namespace util {

namespace math {

namespace group {

class Trivial {
 public:
  static constexpr uint64_t order() {
    return 1;
  }

  static constexpr Trivial identity() {
    return Trivial();
  }

  constexpr Trivial() {}
  explicit constexpr Trivial(uint32_t ordinal) {
    (void) ordinal;
  }

  constexpr uint32_t ordinal() const {
    return 0;
  }

  constexpr Trivial inverse() const {
    return Trivial();
  }

  std::string toString() const {
    return "tr";
  }
};

}  // namespace group
}  // namespace math
}  // namespace util

#endif /* _TRIVIAL_H */
