#ifndef _DIRECT_PRODUCT_H
#define _DIRECT_PRODUCT_H

#include <cstdint>

namespace util {

namespace math {

namespace group {

template <class... T>
class DirectProduct {
  template <class... T_>
  friend constexpr bool operator==(const DirectProduct<T_...>& e1,
                                   const DirectProduct<T_...>& e2);
  template <class... T_>
  friend constexpr bool operator==(const DirectProduct<T_...>& e1,
                                   const DirectProduct<T_...>& e2);
  template <class... T_>
  friend constexpr DirectProduct<T_...> operator*(
      const DirectProduct<T_...>& e1, const DirectProduct<T_...>& e2);

 public:
  static constexpr uint64_t order() {
    return (... * T::order());
  }

  typedef typename std::conditional<
      order() < 256, uint8_t,
      typename std::conditional<order() < 65535, uint16_t,
                                uint32_t>::type>::type encoding_t;

  static constexpr DirectProduct identity() {
    return DirectProduct();
  }

  constexpr DirectProduct() : e_(0) {}

  explicit constexpr DirectProduct(encoding_t e) : e_(e) {}

  constexpr DirectProduct(T... subg) : e_(0) {
    encoding_t basis = 1;
    encoding_t total = 0;
    for (auto [subg_ordinal, subg_order] : { unpack(subg)... }) {
      total += basis * subg_ordinal;
      basis *= subg_order;
    }

    e_ = total;
  }

  constexpr uint32_t ordinal() const {
    return e_;
  }

  constexpr DirectProduct inverse() const {
    return DirectProduct(calcInverse<T...>(e_));
  }

  std::string toString() const {
    return std::string("<") + toStringComposer<T...>(e_) + std::string(">");
  }

 private:
  template <class SubgroupT>
  static constexpr std::pair<encoding_t, encoding_t> unpack(SubgroupT subg) {
    return { subg.ordinal(), subg.order() };
  }

  static constexpr uint64_t composeTableSize() {
    return order() * order();
  }

  template <class SubgroupT>
  static constexpr encoding_t calcInverse(encoding_t e) {
    return SubgroupT(e).inverse().ordinal();
  }

  template <class SubgroupT, class SubgroupNextT, class... SubgroupTs>
  static constexpr encoding_t calcInverse(encoding_t e) {
    encoding_t ord = SubgroupT(e % SubgroupT::order()).inverse().ordinal();
    e /= SubgroupT::order();

    return SubgroupT::order() * calcInverse<SubgroupNextT, SubgroupTs...>(e) +
           ord;
  }

  template <class SubgroupT>
  static constexpr encoding_t slowCompose(encoding_t e1, encoding_t e2) {
    return (SubgroupT(e1) * SubgroupT(e2)).ordinal();
  }

  template <class SubgroupT, class SubgroupTNext, class... SubgroupTs>
  static constexpr encoding_t slowCompose(encoding_t e1, encoding_t e2) {
    SubgroupT o1 = SubgroupT(e1 % SubgroupT::order());
    SubgroupT o2 = SubgroupT(e2 % SubgroupT::order());

    e1 /= SubgroupT::order();
    e2 /= SubgroupT::order();

    encoding_t ord = (o1 * o2).ordinal();
    return SubgroupT::order() *
               slowCompose<SubgroupTNext, SubgroupTs...>(e1, e2) +
           ord;
  }

  template <class SubgroupT>
  static std::string toStringComposer(encoding_t e) {
    return SubgroupT(e).toString();
  }

  template <class SubgroupT, class SubgroupNextT, class... SubgroupTs>
  static std::string toStringComposer(encoding_t e) {
    std::string str1 = SubgroupT(e % SubgroupT::order()).toString();
    e /= SubgroupT::order();

    return str1 + std::string(", ") +
           toStringComposer<SubgroupNextT, SubgroupTs...>(e);
  }

  static constexpr std::array<encoding_t, composeTableSize()> genTable() {
    std::array<encoding_t, DirectProduct<T...>::composeTableSize()> table{ 0 };

    for (encoding_t i = 0;
         i < static_cast<encoding_t>(DirectProduct<T...>::order()); i++) {
      for (encoding_t j = 0;
           j < static_cast<encoding_t>(DirectProduct<T...>::order()); j++) {
        // calculates the effect of the operation e(i) * e(j)
        table[i * DirectProduct<T...>::order() + j] = slowCompose<T...>(i, j);
      }
    }

    return table;
  }

 private:
  encoding_t e_;

  static constexpr std::array<encoding_t, composeTableSize()> compose_table =
      genTable();
};

template <class... T>
constexpr bool operator==(const DirectProduct<T...>& e1,
                          const DirectProduct<T...>& e2) {
  return e1.e_ == e2.e_;
}

template <class... T>
constexpr bool operator!=(const DirectProduct<T...>& e1,
                          const DirectProduct<T...>& e2) {
  return e1.e_ != e2.e_;
}

template <class... T>
constexpr DirectProduct<T...> operator*(const DirectProduct<T...>& e1,
                                        const DirectProduct<T...>& e2) {
  return DirectProduct<T...>(
      DirectProduct<T...>::compose_table[e1.e_ * DirectProduct<T...>::order() +
                                         e2.e_]);
}

}  // namespace group

}  // namespace math

}  // namespace util

#endif /* _DIRECT_PRODUCT_H */
