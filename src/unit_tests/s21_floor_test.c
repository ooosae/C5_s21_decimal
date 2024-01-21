#include "s21_decimal_test.h"

START_TEST(floor_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(floor_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(floor_2) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(floor_3) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_scale(&val, 5);
  s21_floor(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(floor_5) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_set_scale(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(floor_6) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_set_scale(&value_1, 5);
  s21_set_sign(&value_1);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_set_sign(&check);
  s21_decimal result = {0};
  int return_value = s21_floor(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(floor_7) {
  s21_decimal src1;
  src1.bits[0] = 0xFFFFFFF;
  src1.bits[1] = 0x3E250261;
  src1.bits[2] = 0x204FCE5E;
  src1.bits[3] = 0x800A0000;
  s21_decimal res_od = {0};
  s21_floor(src1, &res_od);
  s21_decimal result = {0};
  result.bits[0] = 0xA7640000;
  result.bits[1] = 0xDE0B6B3;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("case_floor");

  tcase_add_test(tc, floor_0);
  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);

  suite_add_tcase(s, tc);
  return s;
}
