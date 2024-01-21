#include "s21_decimal_test.h"

START_TEST(s21_truncate_1) {
  s21_decimal dec1 = {0};

  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x00000000;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[3] = 0x00000000;
  result.bits[2] = 0x00000000;
  result.bits[1] = 0x00000000;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal dec1 = {0};

  dec1.bits[3] = 0x800C0000;
  dec1.bits[2] = 0x00000000;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x00000000;
  result.bits[1] = 0x00000000;
  result.bits[0] = 0x1197998;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal dec1 = {0};

  dec1.bits[3] = 0x80000000;
  dec1.bits[2] = 0x00000000;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x00000000;
  result.bits[1] = 0xFFFFFFFF;
  result.bits[0] = 0xFFFFFFFF;
  s21_decimal res1 = {0};
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal dec1 = {0};

  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0x00000000;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  s21_decimal result = {0};
  s21_truncate(dec1, &result);
  s21_decimal res1 = {0};

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0x00000000;
  res1.bits[1] = 0x00000004;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_12) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x00000002;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

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

START_TEST(s21_truncate_14) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

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

START_TEST(s21_truncate_15) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x00000000;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

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

START_TEST(s21_truncate_22) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x00000001;
  src1.bits[1] = 0x00000000;
  src1.bits[2] = 0x00000000;
  src1.bits[3] = 0x00000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

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

START_TEST(s21_truncate_23) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_truncate_24) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_truncate_25) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(s21_truncate_26) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_set_scale(&val, 5);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = -0.0;
  ck_assert_float_eq(need, fres);
}

START_TEST(s21_truncate_27) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_scale(&val, 1);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 12;
  ck_assert_float_eq(need, fres);
}

START_TEST(s21_truncate_29) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal check = {{3, 0, 0, 0}};
  s21_set_scale(&value_1, 1);
  s21_truncate(value_1, &value_1);
  ck_assert_int_eq(s21_is_equal(value_1, check), 1);
}
END_TEST

START_TEST(s21_truncate_30) {
  s21_decimal value_1 = {{123456, 0, 0, 0}};
  s21_set_scale(&value_1, 3);
  s21_set_sign(&value_1);
  s21_decimal check = {{123, 0, 0, 0}};
  s21_set_sign(&check);
  s21_truncate(value_1, &value_1);
  ck_assert_int_eq(s21_is_equal(value_1, check), 1);
}
END_TEST

START_TEST(s21_truncate_31) {
  s21_decimal src1 = {0};
  src1.bits[3] = 0x000A0000;
  src1.bits[2] = 0x00000000;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[0] = 0xFFFFFFFF;
  s21_decimal result = {0};
  result.bits[3] = 0x00000000;
  result.bits[2] = 0x00000000;
  result.bits[1] = 0x00000000;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res_od = {0};
  s21_truncate(src1, &res_od);
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *s = suite_create("suite_truncate");
  TCase *tc = tcase_create("suite_truncate_tc");

  tcase_add_test(tc, s21_truncate_23);
  tcase_add_test(tc, s21_truncate_24);
  tcase_add_test(tc, s21_truncate_25);
  tcase_add_test(tc, s21_truncate_26);
  tcase_add_test(tc, s21_truncate_27);
  tcase_add_test(tc, s21_truncate_29);
  tcase_add_test(tc, s21_truncate_30);
  tcase_add_test(tc, s21_truncate_31);
  tcase_add_test(tc, s21_truncate_1);
  tcase_add_test(tc, s21_truncate_2);
  tcase_add_test(tc, s21_truncate_3);
  tcase_add_test(tc, s21_truncate_6);
  tcase_add_test(tc, s21_truncate_12);
  tcase_add_test(tc, s21_truncate_14);
  tcase_add_test(tc, s21_truncate_15);
  tcase_add_test(tc, s21_truncate_22);

  suite_add_tcase(s, tc);
  return s;
}
