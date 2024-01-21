#include "s21_decimal_test.h"

START_TEST(s21_round_1) {
  s21_decimal dec1 = {0};
  dec1.bits[0] = 0x93F01C52;
  dec1.bits[1] = 0x120;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0xA0000;
  s21_decimal result = {0};
  result.bits[0] = 0x7C;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_2) {
  s21_decimal dec1 = {0};
  dec1.bits[0] = 0xA4;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x80010000;
  s21_decimal result = {0};
  result.bits[0] = 0x10;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal dec1 = {0};
  dec1.bits[0] = 0xFFFFFFFF;
  dec1.bits[1] = 0x3FFFFF;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x30000;
  s21_decimal result = {0};

  result.bits[0] = 0x4DD2F1A9;
  result.bits[1] = 0x1062;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_4) {
  s21_decimal dec1 = {0};
  dec1.bits[0] = 0xF7274;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x80030000;
  s21_decimal result = {0};
  result.bits[0] = 0x3F4;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal dec1 = {0};
  dec1.bits[0] = 0x800003F4;
  dec1.bits[1] = 0x40000;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x80070000;
  s21_decimal result = {0};
  result.bits[0] = 0x6B5FD7D;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
  s21_decimal dec1 = {0};
  dec1.bits[0] = 0x800003F4;
  dec1.bits[1] = 0x0;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x0;
  s21_decimal result = {0};
  result.bits[0] = 0x800003F4;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal dec1 = {0};

  dec1.bits[0] = 0x630FFFFF;
  dec1.bits[1] = 0x6BC75E2D;
  dec1.bits[2] = 0x5;
  dec1.bits[3] = 0x800A0000;
  s21_decimal result = {0};
  result.bits[0] = 0x540BE400;
  result.bits[1] = 0x2;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal dec1 = {0};

  dec1.bits[0] = 0x553AEBB1;
  dec1.bits[1] = 0xDB4DA5F;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0x80120000;
  s21_decimal result = {0};
  result.bits[0] = 0x1;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal dec1 = {0};

  dec1.bits[0] = 0x93F01C52;
  dec1.bits[1] = 0x120;
  dec1.bits[2] = 0x0;
  dec1.bits[3] = 0xA0000;
  s21_decimal result = {0};
  result.bits[0] = 0x7C;
  result.bits[1] = 0x0;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal dec1 = {0};

  dec1.bits[0] = 0x97739FFF;
  dec1.bits[1] = 0x3C08318D;
  dec1.bits[2] = 0x1;
  dec1.bits[3] = 0x70000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  s21_decimal result = {0};
  result.bits[0] = 0x36B68C40;
  result.bits[1] = 0x212;
  result.bits[2] = 0x0;
  result.bits[3] = 0x0;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_13) {
  s21_decimal dec1 = {0};

  dec1.bits[0] = 0x97739FFF;
  dec1.bits[1] = 0x3C08318D;
  dec1.bits[2] = 0x1;
  dec1.bits[3] = 0x80070000;
  s21_decimal res1 = {0};
  s21_round(dec1, &res1);
  s21_decimal result = {0};
  result.bits[0] = 0x36B68C40;
  result.bits[1] = 0x212;
  result.bits[2] = 0x0;
  result.bits[3] = 0x80000000;

  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_roundTest1) {
  s21_decimal src1, origin;

  src1.bits[0] = 2;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 2;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest2) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x23;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x10000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x4;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest3) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x23;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80010000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x4;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest4) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x0;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest5) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x4CD281C5;
  src1.bits[1] = 0x2;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x4CD281C5;
  origin.bits[1] = 0x2;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest6) {
  s21_decimal src1, origin;

  src1.bits[0] = 0xDEB4AA61;
  src1.bits[1] = 0xF4F85EE9;
  src1.bits[2] = 0x2;
  src1.bits[3] = 0x80050000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x8674BB91;
  origin.bits[1] = 0x1F016;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest7) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x79B1F98;
  src1.bits[1] = 0x664891A3;
  src1.bits[2] = 0x48B1D;
  src1.bits[3] = 0x80180000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x5;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest8) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x4EE43976;
  src1.bits[1] = 0x4B35A1D9;
  src1.bits[2] = 0x19B974BF;
  src1.bits[3] = 0xF0000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0xA41E402E;
  origin.bits[1] = 0x73D;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest9) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x788AF4CA;
  src1.bits[1] = 0x620AE487;
  src1.bits[2] = 0x27E41AD5;
  src1.bits[3] = 0x80150000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0xBC614D;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest10) {
  s21_decimal src1, origin;

  src1.bits[0] = 0xADC8D95F;
  src1.bits[1] = 0x48A2B481;
  src1.bits[2] = 0x1;
  src1.bits[3] = 0x130000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x2;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest11) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x1;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x1;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest12) {
  s21_decimal src1, origin;

  src1.bits[0] = 0xB;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x10000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x1;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest13) {
  s21_decimal src1, origin;

  src1.bits[0] = 0xB;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80010000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x1;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest14) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x988;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x20000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x18;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x0;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_roundTest15) {
  s21_decimal src1, origin;

  src1.bits[0] = 0x84C;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80030000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_round(src1, &result);
  origin.bits[0] = 0x2;
  origin.bits[1] = 0x0;
  origin.bits[2] = 0x0;
  origin.bits[3] = 0x80000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

Suite* suite_round2(void) {
  Suite* s;
  TCase* tc;
  s = suite_create("s21_round");
  tc = tcase_create("case_round");
  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_2);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_4);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_6);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_9);

  tcase_add_test(tc, s21_round_12);
  tcase_add_test(tc, s21_round_13);

  tcase_add_test(tc, s21_roundTest1);
  tcase_add_test(tc, s21_roundTest2);
  tcase_add_test(tc, s21_roundTest3);
  tcase_add_test(tc, s21_roundTest4);
  tcase_add_test(tc, s21_roundTest5);
  tcase_add_test(tc, s21_roundTest6);
  tcase_add_test(tc, s21_roundTest7);
  tcase_add_test(tc, s21_roundTest8);
  tcase_add_test(tc, s21_roundTest9);
  tcase_add_test(tc, s21_roundTest10);
  tcase_add_test(tc, s21_roundTest11);
  tcase_add_test(tc, s21_roundTest12);
  tcase_add_test(tc, s21_roundTest13);
  tcase_add_test(tc, s21_roundTest14);
  tcase_add_test(tc, s21_roundTest15);

  suite_add_tcase(s, tc);
  return s;
}
