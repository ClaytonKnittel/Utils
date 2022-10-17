
#include <utils/math/group/group.h>

#include "test_utils.h"

using namespace util::math::group;

typedef Cyclic<1> C1;
typedef Cyclic<2> C2;
typedef Cyclic<3> C3;
typedef Cyclic<4> C4;
typedef Cyclic<5> C5;
typedef Cyclic<6> C6;

typedef Dihedral<1> D1;
typedef Dihedral<2> D2;
typedef Dihedral<3> D3;
typedef Dihedral<4> D4;
typedef Dihedral<5> D5;
typedef Dihedral<6> D6;

START_TEST(test_c1_identity_ord) {
  C1 c;
  ck_assert_uint_eq(c.ordinal(), 0);
}
END_TEST

START_TEST(test_c2_ords) {
  C2 r0(0);
  C2 r1(1);
  ck_assert_uint_eq(r0.ordinal(), 0);
  ck_assert_uint_eq(r1.ordinal(), 1);
}
END_TEST

#define TEST_CN_INV(N)                         \
  START_TEST(test_c##N##_inv) {                \
    /* test the identity's inverse */          \
    C##N ident = C##N::identity();             \
    C##N ident_inv = ident.inverse();          \
    ck_assert(ident == ident_inv);             \
    /* test all other inverses */              \
    for (uint32_t i = 1; i < N; i++) {         \
      C##N r(i);                               \
      C##N r_inv = r.inverse();                \
      ck_assert(r* r_inv == C##N::identity()); \
      ck_assert(r_inv* r == C##N::identity()); \
    }                                          \
  }                                            \
  END_TEST

TEST_CN_INV(1)
TEST_CN_INV(2)
TEST_CN_INV(3)
TEST_CN_INV(4)
TEST_CN_INV(5)
TEST_CN_INV(6)

START_TEST(test_d1_identity_ord) {
  D1 d;
  ck_assert_uint_eq(d.ordinal(), 0);
}
END_TEST

START_TEST(test_d1_ords) {
  D1 s0(D1::Action::REFL, 0);
  ck_assert_uint_eq(s0.ordinal(), 1);
}
END_TEST

START_TEST(test_d2_ords) {
  D2 r0(D2::Action::ROT, 0);
  D2 r1(D2::Action::ROT, 1);
  D2 s0(D2::Action::REFL, 0);
  D2 s1(D2::Action::REFL, 1);
  ck_assert_uint_eq(r0.ordinal(), 0);
  ck_assert_uint_eq(r1.ordinal(), 1);
  ck_assert_uint_eq(s0.ordinal(), 2);
  ck_assert_uint_eq(s1.ordinal(), 3);
}
END_TEST

#define TEST_DN_INV(N)                         \
  START_TEST(test_d##N##_inv) {                \
    /* test the identity's inverse */          \
    D##N ident = D##N::identity();             \
    D##N ident_inv = ident.inverse();          \
    ck_assert(ident == ident_inv);             \
    /* test all rotational inverses */         \
    for (uint32_t i = 1; i < N; i++) {         \
      D##N r(D##N::Action::ROT, i);            \
      D##N r_inv = r.inverse();                \
      ck_assert(r* r_inv == D##N::identity()); \
      ck_assert(r_inv* r == D##N::identity()); \
    }                                          \
    /* test all reflective inverses */         \
    for (uint32_t i = 0; i < N; i++) {         \
      D##N s(D##N::Action::REFL, i);           \
      D##N s_inv = s.inverse();                \
      ck_assert(s* s_inv == D##N::identity()); \
      ck_assert(s_inv* s == D##N::identity()); \
    }                                          \
  }                                            \
  END_TEST

TEST_DN_INV(1)
TEST_DN_INV(2)
TEST_DN_INV(3)
TEST_DN_INV(4)
TEST_DN_INV(5)
TEST_DN_INV(6)

START_TEST(test_direct_identity_ord) {
  DirectProduct<C3, D5, D2> d;
  ck_assert_int_eq(d.ordinal(), 0);
}
END_TEST

START_TEST(test_direct_ords) {
  uint64_t ords = 0;
  typedef DirectProduct<D2, C3, D1> DP;

  ck_assert_int_eq(DP::order(), D2::order() * C3::order() * D1::order());

  for (uint64_t i = 0; i < D2::order(); i++) {
    D2 d2(i);
    for (uint64_t j = 0; j < C3::order(); j++) {
      C3 c3(j);
      for (uint64_t k = 0; k < D1::order(); k++) {
        D1 d1(k);

        DP dp(d2, c3, d1);
        uint64_t total_order = dp.ordinal();
        ck_assert_uint_lt(total_order, DP::order());

        uint64_t bitmask = UINT64_C(1) << total_order;

        ck_assert_uint_eq((bitmask & ords), 0);

        ords |= bitmask;
      }
    }
  }

  ck_assert_uint_eq(ords, (UINT64_C(1) << DP::order()) - 1);
}
END_TEST

START_TEST(test_direct_prods) {
  typedef DirectProduct<D2, C3, D1> DP;

  ck_assert_int_eq(DP::order(), D2::order() * C3::order() * D1::order());

  for (uint64_t i1 = 0; i1 < D2::order(); i1++) {
    for (uint64_t i2 = 0; i2 < D2::order(); i2++) {
      D2 d2a(i1);
      D2 d2b(i2);
      for (uint64_t j1 = 0; j1 < C3::order(); j1++) {
        for (uint64_t j2 = 0; j2 < C3::order(); j2++) {
          C3 c3a(j1);
          C3 c3b(j2);
          for (uint64_t k1 = 0; k1 < D1::order(); k1++) {
            for (uint64_t k2 = 0; k2 < D1::order(); k2++) {
              D1 d1a(k1);
              D1 d1b(k2);

              DP dpa(d2a, c3a, d1a);
              DP dpb(d2b, c3b, d1b);

              DP dp_prod = dpa * dpb;

              D2 d2_prod = d2a * d2b;
              C3 c3_prod = c3a * c3b;
              D1 d1_prod = d1a * d1b;
              DP dp_prod_ex(d2_prod, c3_prod, d1_prod);

              ck_assert(dp_prod == dp_prod_ex);
            }
          }
        }
      }
    }
  }
}
END_TEST

Suite* test_group_cc() {
  TCase* tc_cyclic;
  TCase* tc_dihedral;
  TCase* tc_direct_product;

  Suite* s = suite_create("Group");

  tc_cyclic = tcase_create("Cyclic");
  tcase_add_test(tc_cyclic, test_c1_identity_ord);
  tcase_add_test(tc_cyclic, test_c2_ords);

  tcase_add_test(tc_cyclic, test_c1_inv);
  tcase_add_test(tc_cyclic, test_c2_inv);
  tcase_add_test(tc_cyclic, test_c3_inv);
  tcase_add_test(tc_cyclic, test_c4_inv);
  tcase_add_test(tc_cyclic, test_c5_inv);
  tcase_add_test(tc_cyclic, test_c6_inv);
  suite_add_tcase(s, tc_cyclic);

  tc_dihedral = tcase_create("Dihedral");
  tcase_add_test(tc_dihedral, test_d1_identity_ord);
  tcase_add_test(tc_dihedral, test_d1_ords);
  tcase_add_test(tc_dihedral, test_d2_ords);

  tcase_add_test(tc_dihedral, test_d1_inv);
  tcase_add_test(tc_dihedral, test_d2_inv);
  tcase_add_test(tc_dihedral, test_d3_inv);
  tcase_add_test(tc_dihedral, test_d4_inv);
  tcase_add_test(tc_dihedral, test_d5_inv);
  tcase_add_test(tc_dihedral, test_d6_inv);
  suite_add_tcase(s, tc_dihedral);

  tc_direct_product = tcase_create("Direct Product");
  tcase_add_test(tc_dihedral, test_direct_identity_ord);
  tcase_add_test(tc_dihedral, test_direct_ords);
  tcase_add_test(tc_dihedral, test_direct_prods);
  suite_add_tcase(s, tc_direct_product);

  return s;
}
