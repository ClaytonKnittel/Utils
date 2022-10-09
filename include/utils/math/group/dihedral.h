#ifndef _DIHEDRAL_H
#define _DIHEDRAL_H

#include <array>
#include <cstdint>
#include <string>

namespace util {

namespace group {

template <uint32_t N>
class Dihedral {
  template <uint32_t N_>
  friend Dihedral<N_> operator*(const Dihedral<N_>& e1, const Dihedral<N_>& e2);
  template <uint32_t N_>
  friend bool operator==(const Dihedral<N_>& e1, const Dihedral<N_>& e2);
  template <uint32_t N_>
  friend bool operator!=(const Dihedral<N_>& e1, const Dihedral<N_>& e2);

 public:
  // An encoding_t is equal to <n> + (rfl ? N : 0), where <n> is the number of
  // rotations applied (0 to N-1), and rfl is true if a reflection was
  // applied.
  typedef uint8_t encoding_t;

  enum class Action : uint64_t {
    // Rotate by 2*Pi/N counterclockwise
    ROT = 0,
    // Reflect across the x axis
    REFL,
  };

  static constexpr uint64_t order() {
    return static_cast<uint64_t>(2 * N);
  }

  static constexpr Action action(encoding_t e) {
    return static_cast<Action>(e / N);
  }

  static constexpr uint32_t degree(encoding_t e) {
    return static_cast<uint32_t>(e % N);
  }

  static constexpr Dihedral<N> identity() {
    return Dihedral<N>();
  }

  constexpr Dihedral() : Dihedral(Action::ROT, 0) {}

  constexpr Dihedral(Action a, uint32_t degree)
      : Dihedral(static_cast<uint8_t>(static_cast<uint32_t>(a) * N + degree)) {}

  explicit constexpr Dihedral(encoding_t e) : e_(e) {}

  /*
   * Returns a unique uint32_t for this element, with the guarantee that it will
   * be the same when called on any equivalent elements, and that the ordinals
   * of all elements are >= 0 and contiguous.
   */
  constexpr uint32_t ordinal() const {
    return e_;
  }

  Action action() const {
    return action(e_);
  }

  uint32_t degree() const {
    return degree(e_);
  }

  Dihedral<N> inverse() const {
    if (e_ < N) {
      return Dihedral<N>((N - e_) % N);
    } else {
      return Dihedral<N>(e_);
    }
  }

  std::string toString() const {
    return std::string(action() == Action::ROT ? "r" : "s") +
           std::to_string(degree());
  }

 private:
  static constexpr uint64_t composeTableSize() {
    return order() * order();
  }

  static constexpr std::array<encoding_t, composeTableSize()> genTable();

 private:
  encoding_t e_;

  static constexpr std::array<encoding_t, composeTableSize()> compose_table =
      genTable();
};

template <uint32_t N>
Dihedral<N> operator*(const Dihedral<N>& e1, const Dihedral<N>& e2) {
  return Dihedral<N>(
      Dihedral<N>::compose_table[e1.e_ * Dihedral<N>::order() + e2.e_]);
}

template <uint32_t N>
bool operator==(const Dihedral<N>& e1, const Dihedral<N>& e2) {
  return e1.e_ == e2.e_;
}

template <uint32_t N>
bool operator!=(const Dihedral<N>& e1, const Dihedral<N>& e2) {
  return e1.e_ != e2.e_;
}

template <uint32_t N>
constexpr std::array<typename Dihedral<N>::encoding_t,
                     Dihedral<N>::composeTableSize()>
Dihedral<N>::genTable() {
  std::array<encoding_t, composeTableSize()> table{ 0 };

  for (encoding_t i = 0; i < static_cast<encoding_t>(order()); i++) {
    for (encoding_t j = 0; j < static_cast<encoding_t>(order()); j++) {
      // calculates the effect of the operation e(i) * e(j)
      encoding_t& el = table[i * order() + j];

      switch (action(i)) {
        case Dihedral<N>::Action::ROT: {
          switch (action(j)) {
            case Dihedral<N>::Action::ROT: {
              el = Dihedral<N>(Dihedral<N>::Action::ROT,
                               (degree(i) + degree(j)) % N)
                       .e_;
              break;
            }
            case Dihedral<N>::Action::REFL: {
              el = Dihedral<N>(Dihedral<N>::Action::REFL,
                               (degree(i) + degree(j)) % N)
                       .e_;
              break;
            }
          }
          break;
        }
        case Dihedral<N>::Action::REFL: {
          switch (action(j)) {
            case Dihedral<N>::Action::ROT: {
              el = Dihedral<N>(Dihedral<N>::Action::REFL,
                               (N + degree(i) - degree(j)) % N)
                       .e_;
              break;
            }
            case Dihedral<N>::Action::REFL: {
              el = Dihedral<N>(Dihedral<N>::Action::ROT,
                               (N + degree(i) - degree(j)) % N)
                       .e_;
              break;
            }
          }
          break;
        }
      }
    }
  }

  return table;
}

}  // namespace group

}  // namespace util

#endif /* _DIHEDRAL_H */
