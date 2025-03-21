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

constexpr Trivial operator*(const Trivial& e1, const Trivial& e2) {
  (void) e1;
  (void) e2;
  return Trivial();
}

constexpr bool operator==(const Trivial& e1, const Trivial& e2) {
  (void) e1;
  (void) e2;
  return true;
}

constexpr bool operator!=(const Trivial& e1, const Trivial& e2) {
  (void) e1;
  (void) e2;
  return false;
}

}  // namespace group
}  // namespace math
}  // namespace util

#endif /* _TRIVIAL_H */
