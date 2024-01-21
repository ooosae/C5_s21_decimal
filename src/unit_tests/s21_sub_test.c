#include "s21_decimal_test.h"

START_TEST(sub_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  s21_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_19) {
  s21_decimal val1 = {{4, 0, 0, 0}};
  s21_decimal val2 = {{4, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_20) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_21) {
  s21_decimal dec1 = {{0}};
  s21_decimal dec2 = {{0}};
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  s21_decimal res1 = {{0}};
  int res = 99899;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_22) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_sign(&value_1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_set_sign(&value_2);
  s21_decimal result = {0};
  s21_decimal check = {{156, 0, 0, 0}};
  s21_set_scale(&check, 2);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_23) {
  s21_decimal value_1 = {{13, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_set_sign(&value_1);
  s21_decimal value_2 = {{286, 0, 0, 0}};
  s21_set_scale(&value_2, 2);
  s21_decimal result = {0};
  s21_decimal check = {{416, 0, 0, 0}};
  s21_set_scale(&check, 2);
  s21_set_sign(&check);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_24) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_25) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_sign(&value_2);
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_add(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(sub_26) {
  s21_decimal value_1 = {{64071, 0, 0, 0}};
  s21_set_scale(&value_1, 4);
  s21_decimal value_2 = {{5919, 0, 0, 0}};
  s21_set_scale(&value_2, 1);
  s21_decimal result = {0};
  s21_decimal check = {{5854929, 0, 0, 0}};
  s21_set_scale(&check, 4);
  s21_set_sign(&check);
  int return_value = s21_sub(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(sub_27) {
  s21_decimal src1 = {0}, src2 = {0};
  float a = -9403;
  float b = 202.098f;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = a - b;
  s21_decimal res_od = {0};
  s21_sub(src1, src2, &res_od);
  s21_from_decimal_to_float(res_od, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_subTest1) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000002;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000003;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000001;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest2) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000003;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000002;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000001;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest3) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000003;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000003;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest4) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000002;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000000;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000002;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest5) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000003;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000003;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest6) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000002;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000000;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000002;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest7) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00001979;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00012189;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00010810;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest8) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000004;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x5D19D1B;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x5D19D17;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest9) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 100;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 95;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 5;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest10) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x000590CC;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x80000000;

  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x000590CD;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest11) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000001;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0xFDB31C31;
  src2.bits[1] = 0x00000016;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0xFDB31C30;
  origin.bits[1] = 0x00000016;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest12) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x4CD281C5;
  src1.bits[1] = 0x00000002;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x80000000;

  src2.bits[0] = 0x00000003;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x80000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x4CD281C2;
  origin.bits[1] = 0x00000002;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest13) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x89E7FFFF;
  src1.bits[1] = 0x8AC72304;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x89E7FFFE;
  origin.bits[1] = 0x8AC72304;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest14) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0xFFFFFFFE;
  origin.bits[1] = 0xFFFFFFFF;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest15) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0xFFFFFFF6;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0x00000009;
  src1.bits[3] = 0x00010000;

  src2.bits[0] = 0x398BA562;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0xC08B8A22;
  origin.bits[1] = 0xFFFFFFFD;
  origin.bits[2] = 0x00000009;
  origin.bits[3] = 0x00010000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest16) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x82E25AED;
  src1.bits[1] = 0xF9E825AD;
  src1.bits[2] = 0xB03EF094;
  src1.bits[3] = 0x800E0000;

  src2.bits[0] = 0x340972E;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x9499DAED;
  origin.bits[1] = 0xC5936962;
  origin.bits[2] = 0xB03EF1BC;
  origin.bits[3] = 0x800E0000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest17) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x82E25AED;
  src1.bits[1] = 0xF9E825AD;
  src1.bits[2] = 0xB03EF094;
  src1.bits[3] = 0x800E0000;

  src2.bits[0] = 0x481B1F98;
  src2.bits[1] = 0xFBFD896D;
  src2.bits[2] = 0x00046D77;
  src2.bits[3] = 0x80180000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x4F9AFFFF;
  origin.bits[1] = 0xF9E63EDB;
  origin.bits[2] = 0xB03EF094;
  origin.bits[3] = 0x800E0000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest18) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x4EE43976;
  src1.bits[1] = 0x4B35A1D9;
  src1.bits[2] = 0x19B974BF;
  src1.bits[3] = 0x000F0000;

  src2.bits[0] = 0x00000000;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x4EE43976;
  origin.bits[1] = 0x4B35A1D9;
  origin.bits[2] = 0x19B974BF;
  origin.bits[3] = 0xF0000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest23) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000000;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000000;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest24) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000000;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000000;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest25) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000000;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x00000000;
  origin.bits[1] = 0x00000000;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest26) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x28F5C28F;
  src1.bits[1] = 0xF5C28F5C;
  src1.bits[2] = 0x28F5C28;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x80000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x28F5C290;
  origin.bits[1] = 0xF5C28F5C;
  origin.bits[2] = 0x028F5C28;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest27) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x5F08045B;
  src1.bits[1] = 0x6DF37F67;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x03E9AC4E;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x5B1E580D;
  origin.bits[1] = 0x6DF37F67;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x00000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest28) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x27AA2EE1;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;

  src2.bits[0] = 0x1052E659;
  src2.bits[1] = 0x001F41F2;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0xE8A8B778;
  origin.bits[1] = 0x001F41F1;
  origin.bits[2] = 0x00000000;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest29) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0xFE90D95F;
  src1.bits[1] = 0x846421E8;
  src1.bits[2] = 0x00000001;
  src1.bits[3] = 0x00130000;

  src2.bits[0] = 0xD4AE3D8A;
  src2.bits[1] = 0x741427A3;
  src2.bits[2] = 0x00084144;
  src2.bits[3] = 0x00180000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x0EFFA82A;
  origin.bits[1] = 0x29D60234;
  origin.bits[2] = 0x0005F0A1;
  origin.bits[3] = 0x80180000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest30) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x54403D8C;
  src1.bits[1] = 0x8B520559;
  src1.bits[2] = 0x1FA981AD;
  src1.bits[3] = 0x800C0000;

  src2.bits[0] = 0x65F24DAC;
  src2.bits[1] = 0x0007A9AB;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x80060000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0xD2927A8C;
  origin.bits[1] = 0x9E9E7104;
  origin.bits[2] = 0x1FA98138;
  origin.bits[3] = 0x800C0000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_subTest31) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x0B0F708D;
  src1.bits[1] = 0x96B05951;
  src1.bits[2] = 0x11A17B81;
  src1.bits[3] = 0x001C0000;

  src2.bits[0] = 0x17254C02;
  src2.bits[1] = 0x00F5159B;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00110000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x5ABE5F73;
  origin.bits[1] = 0x2D3D3068;
  origin.bits[2] = 0x04A8D557;
  origin.bits[3] = 0x801C0000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST
START_TEST(s21_subTest33) {
  s21_decimal src1, src2, origin;

  src1.bits[0] = 0x99999999;
  src1.bits[1] = 0x99999999;
  src1.bits[2] = 0x19999999;
  src1.bits[3] = 0x80000000;

  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_sub(src1, src2, &result);

  origin.bits[0] = 0x9999999A;
  origin.bits[1] = 0x99999999;
  origin.bits[2] = 0x19999999;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_0) {
  s21_decimal c = {{10, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{5, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_1) {
  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{5, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 0);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_2) {
  s21_decimal c = {{INT_MAX, 0, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{2147483642, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_3) {
  s21_decimal c = {{INT_MAX, INT_MAX, 0, 0}};
  s21_decimal d = {{5, 0, 0, 0}};
  s21_decimal etalon = {{INT_MAX - 5, INT_MAX, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}

START_TEST(s21_test_decimal_sub_simple_7) {
  s21_decimal c = {{1, 0, 0, 0}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{2, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_8) {
  s21_decimal c = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{1, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{0, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_10) {
  s21_decimal c = {{100, 0, 0, 0}};
  s21_decimal d = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal etalon = {{200, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);

  int equal = s21_is_equal(res, etalon);
  ck_assert_int_eq(equal, 1);
}
END_TEST

START_TEST(s21_test_decimal_sub_simple_11) {
  s21_decimal c = {{100, 0, 0, ~(INT_MAX)}};
  s21_decimal d = {{100, 0, 0, ~(INT_MAX)}};

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal* p_res = &res;

  int add = s21_sub(c, d, p_res);
  ck_assert_int_eq(add, 0);
}
END_TEST

START_TEST(sub_test_11) {
  int num1 = 123;
  float num2 = 12.5;
  float origin_float = 110.5;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, origin_float);
}
END_TEST

START_TEST(sub_test_12) {
  int num1 = -123;
  float num2 = 12.5;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_14) {
  int num1 = 9403;
  float num2 = 202.098f;
  float dif_float = 9200.902f;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_15) {
  int num1 = -9403;
  float num2 = 202.098f;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_16) {
  float num1 = 9403.0;
  float num2 = 202.09e8f;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_17) {
  float num1 = 9403.0e2;
  float num2 = 202.09e8f;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_18) {
  float num1 = -9403.0e2;
  int num2 = -202;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_19) {
  float num1 = -94;
  float num2 = -202;
  float dif_float = num1 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal((int)num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, dif_float);
}
END_TEST

START_TEST(sub_test_20) {
  float num1 = -1.0 / 0.0;
  int num2 = 202;
  double dif_float = 0 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, (float)dif_float);
}
END_TEST

START_TEST(sub_test_21) {
  float num1 = 1.0 / 0.0;
  int num2 = 20;
  double dif_float = 0 - num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0.0;
  s21_sub(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, (float)dif_float);
}
END_TEST

START_TEST(s21_sub_int_22) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_23) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  int res = 99899;
  s21_decimal res1 = {{0}};
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_24) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -2147483647;
  int tmp2 = -2147483647;
  int res_s21 = 0;
  int res = 0;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_25) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -214748347;
  int tmp2 = 217483647;
  int res_s21 = 0;
  int res = -214748347 - 217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_int_26) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 214748347;
  int tmp2 = -217483647;
  int res_s21 = 0;
  int res = 214748347 - -217483647;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1 = {{0}};
  s21_sub(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(s21_sub_inf_27) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, 0}};
  s21_decimal dec2 = {{1, 0, 0, (unsigned int)tmp}};
  s21_decimal res1 = {{0}};
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(1, ret_s21);
}
END_TEST

START_TEST(s21_sub_neg_inf_28) {
  float tmp = pow(2, 31);
  s21_decimal dec1 = {{4294967295, 4294967295, 4294967295, (unsigned int)tmp}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res1 = {{0}};
  int ret_s21 = s21_sub(dec1, dec2, &res1);
  ck_assert_int_eq(2, ret_s21);
}
END_TEST

START_TEST(s21_sub_max_30) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0xFFFFFFFF;
  src1.bits[3] = 0x00000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0x00000003;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00030000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0xFFFFFFFE;
  original_res.bits[1] = 0xFFFFFFFF;
  original_res.bits[2] = 0xFFFFFFFF;
  original_res.bits[3] = 0x00000000;
  s21_decimal s21_res = {0};
  s21_sub(src1, src2, &s21_res);
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_sub_max_31) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0xFFFFFFFF;
  src1.bits[3] = 0x00000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0x00000005;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00010000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0xFFFFFFFE;
  original_res.bits[1] = 0xFFFFFFFF;
  original_res.bits[2] = 0xFFFFFFFF;
  original_res.bits[3] = 0x00000000;
  s21_decimal s21_res = {0};
  s21_sub(src1, src2, &s21_res);
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_sub_max_32) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0xFFFFFFFF;
  src1.bits[3] = 0x00000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal original_res = {0};
  original_res.bits[0] = 0xFFFFFFFE;
  original_res.bits[1] = 0xFFFFFFFF;
  original_res.bits[2] = 0xFFFFFFFF;
  original_res.bits[3] = 0x00000000;
  s21_decimal s21_res = {0};
  s21_sub(src1, src2, &s21_res);
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 0);
  ck_assert_int_eq(original_res.bits[0], s21_res.bits[0]);
  ck_assert_int_eq(original_res.bits[1], s21_res.bits[1]);
  ck_assert_int_eq(original_res.bits[2], s21_res.bits[2]);
  ck_assert_int_eq(original_res.bits[3], s21_res.bits[3]);
}
END_TEST

START_TEST(s21_sub_max_35) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0xFFFFFFFF;
  src1.bits[3] = 0x80000000;
  s21_decimal src2 = {0};
  src2.bits[0] = 0x00000001;
  src2.bits[1] = 0x00000000;
  src2.bits[2] = 0x00000000;
  src2.bits[3] = 0x00000000;
  s21_decimal s21_res = {0};
  ck_assert_int_eq(s21_sub(src1, src2, &s21_res), 2);
}
END_TEST

Suite* suite_sub(void) {
  Suite* s = suite_create("suite_sub");
  TCase* tc = tcase_create("log_tc");

  tcase_add_test(tc, sub_0);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);
  tcase_add_test(tc, sub_17);
  tcase_add_test(tc, sub_18);
  tcase_add_test(tc, sub_19);
  tcase_add_test(tc, sub_20);
  tcase_add_test(tc, sub_21);
  tcase_add_test(tc, sub_22);
  tcase_add_test(tc, sub_23);
  tcase_add_test(tc, sub_24);
  tcase_add_test(tc, sub_25);
  tcase_add_test(tc, sub_26);
  tcase_add_test(tc, sub_27);

  tcase_add_test(tc, s21_subTest1);
  tcase_add_test(tc, s21_subTest2);
  tcase_add_test(tc, s21_subTest3);
  tcase_add_test(tc, s21_subTest4);
  tcase_add_test(tc, s21_subTest5);
  tcase_add_test(tc, s21_subTest6);
  tcase_add_test(tc, s21_subTest7);
  tcase_add_test(tc, s21_subTest8);
  tcase_add_test(tc, s21_subTest9);
  tcase_add_test(tc, s21_subTest10);
  tcase_add_test(tc, s21_subTest11);
  tcase_add_test(tc, s21_subTest12);
  tcase_add_test(tc, s21_subTest13);
  tcase_add_test(tc, s21_subTest14);
  tcase_add_test(tc, s21_subTest15);
  tcase_add_test(tc, s21_subTest16);
  tcase_add_test(tc, s21_subTest17);
  tcase_add_test(tc, s21_subTest18);
  tcase_add_test(tc, s21_subTest23);
  tcase_add_test(tc, s21_subTest24);
  tcase_add_test(tc, s21_subTest25);
  tcase_add_test(tc, s21_subTest26);
  tcase_add_test(tc, s21_subTest27);
  tcase_add_test(tc, s21_subTest28);
  tcase_add_test(tc, s21_subTest29);
  tcase_add_test(tc, s21_subTest30);
  tcase_add_test(tc, s21_subTest31);
  tcase_add_test(tc, s21_subTest33);

  tcase_add_test(tc, s21_test_decimal_sub_simple_0);
  tcase_add_test(tc, s21_test_decimal_sub_simple_1);
  tcase_add_test(tc, s21_test_decimal_sub_simple_2);
  tcase_add_test(tc, s21_test_decimal_sub_simple_3);

  tcase_add_test(tc, s21_test_decimal_sub_simple_7);
  tcase_add_test(tc, s21_test_decimal_sub_simple_8);
  tcase_add_test(tc, s21_test_decimal_sub_simple_10);
  tcase_add_test(tc, s21_test_decimal_sub_simple_11);

  tcase_add_test(tc, sub_test_11);
  tcase_add_test(tc, sub_test_12);
  tcase_add_test(tc, sub_test_14);
  tcase_add_test(tc, sub_test_15);
  tcase_add_test(tc, sub_test_16);
  tcase_add_test(tc, sub_test_17);
  tcase_add_test(tc, sub_test_18);
  tcase_add_test(tc, sub_test_19);
  tcase_add_test(tc, sub_test_20);
  tcase_add_test(tc, sub_test_21);
  tcase_add_test(tc, s21_sub_int_22);
  tcase_add_test(tc, s21_sub_int_23);
  tcase_add_test(tc, s21_sub_int_24);
  tcase_add_test(tc, s21_sub_int_25);
  tcase_add_test(tc, s21_sub_int_26);
  tcase_add_test(tc, s21_sub_inf_27);
  tcase_add_test(tc, s21_sub_neg_inf_28);

  tcase_add_test(tc, s21_sub_max_30);
  tcase_add_test(tc, s21_sub_max_31);
  tcase_add_test(tc, s21_sub_max_32);
  tcase_add_test(tc, s21_sub_max_35);

  suite_add_tcase(s, tc);
  return s;
}
