#include "s21_decimal_test.h"

START_TEST(is_greater_0) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_8) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 0);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_11) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_12) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_greater_13) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_14) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_greater_15) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  s21_set_sign(&value_2);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_greater_16) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_scale(&value_2, 10);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_greater_17) {
  s21_decimal value_1 = {{234, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_set_scale(&value_1, 2);
  int return_value = s21_is_greater(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(greater_1) {
  float num1 = 1.375342323523f;
  float num2 = 1.39f;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_2) {
  float num1 = 1.39f;
  float num2 = 1.39f;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_3) {
  float num1 = 1.39f;
  float num2 = -1.39f;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(greater_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_7) {
  int num1 = -3;
  int num2 = 3;
  s21_decimal dec1, dec2;
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_8) {
  float num1 = -3.232446546f;
  float num2 = -3.2f;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_9) {
  float num1 = -345.232446546f;
  float num2 = -3.2f;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(greater_10) {
  float num1 = -3.232323233232323233f;
  float num2 = -34545124.232446543232446543f;
  s21_decimal dec1, dec2;
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_test_is_greater_1) {
  s21_decimal a = {{2, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_2) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_2i) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX - 1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_3) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_test_is_greater_4) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_test_is_greater_41) {
  s21_decimal a = {{UINT_MAX, 1, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_5) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX - 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_51) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, 0, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_test_is_greater_6) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_7) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_8) {
  s21_decimal a = {{0, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{0, UINT_MAX, UINT_MAX - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_9) {
  s21_decimal a = {{0, 0, UINT_MAX, 0}};
  s21_decimal b = {{0, 0, UINT_MAX - 1, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_greater_10) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

START_TEST(s21_is_greaterTest1) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x2;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x3;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest2) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x3;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x2;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest3) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x3;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x3;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest4) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x2;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x0;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest5) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x3;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest6) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x2;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x0;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest7) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x1979;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x12189;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest8) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x4;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x5D19D1B;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest9) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x3E9DF1E;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x5;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest10) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x590CC;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80000000;
  src2.bits[0] = 0x1;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest11) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x1;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0xFDB31C31;
  src2.bits[1] = 0x16;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest12) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x4CD281C5;
  src1.bits[1] = 0x2;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x80000000;
  src2.bits[0] = 0x3;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x80000000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest13) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x89E7FFFF;
  src1.bits[1] = 0x8AC72304;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x1;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest14) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x1;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest15) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xFFFFFFF6;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0x9;
  src1.bits[3] = 0x10000;
  src2.bits[0] = 0x398BA562;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest16) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x82E25AED;
  src1.bits[1] = 0xF9E825AD;
  src1.bits[2] = 0xB03EF094;
  src1.bits[3] = 0x800E0000;
  src2.bits[0] = 0x340972E;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest18) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x4EE43976;
  src1.bits[1] = 0x4B35A1D9;
  src1.bits[2] = 0x19B974BF;
  src1.bits[3] = 0xF0000;
  src2.bits[0] = 0x0;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest19) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x910AF4CA;
  src1.bits[1] = 0xC045D5F2;
  src1.bits[2] = 0x27E41B00;
  src1.bits[3] = 0x150000;
  src2.bits[0] = 0x11CDD185;
  src2.bits[1] = 0xF5BC6FC0;
  src2.bits[2] = 0x2D50F3F;
  src2.bits[3] = 0x100000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest20) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x910AF4CA;
  src1.bits[1] = 0xC045D5F2;
  src1.bits[2] = 0x27E41B00;
  src1.bits[3] = 0x80150000;
  src2.bits[0] = 0x11CDD185;
  src2.bits[1] = 0xF5BC6FC0;
  src2.bits[2] = 0x2D50F3F;
  src2.bits[3] = 0x100000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest21) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x910AF4CA;
  src1.bits[1] = 0xC045D5F2;
  src1.bits[2] = 0x27E41B00;
  src1.bits[3] = 0x150000;
  src2.bits[0] = 0x11CDD185;
  src2.bits[1] = 0xF5BC6FC0;
  src2.bits[2] = 0x2D50F3F;
  src2.bits[3] = 0x80100000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest22) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x910AF4CA;
  src1.bits[1] = 0xC045D5F2;
  src1.bits[2] = 0x27E41B00;
  src1.bits[3] = 0x80150000;
  src2.bits[0] = 0x11CDD185;
  src2.bits[1] = 0xF5BC6FC0;
  src2.bits[2] = 0x2D50F3F;
  src2.bits[3] = 0x80100000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest23) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x0;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest24) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x0;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest25) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x0;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest26) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0xFFFFFFFF;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x1;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x80000000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest27) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x5F08045B;
  src1.bits[1] = 0x6DF37F67;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x3E9AC4E;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest28) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x27AA2EE1;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x1052E659;
  src2.bits[1] = 0x1F41F2;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest29) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xFE90D95F;
  src1.bits[1] = 0x846421E8;
  src1.bits[2] = 0x1;
  src1.bits[3] = 0x130000;
  src2.bits[0] = 0xD4AE3D8A;
  src2.bits[1] = 0x741427A3;
  src2.bits[2] = 0x84144;
  src2.bits[3] = 0x180000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest30) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x54403D8C;
  src1.bits[1] = 0x8B520559;
  src1.bits[2] = 0x1FA981AD;
  src1.bits[3] = 0x800C0000;
  src2.bits[0] = 0x65F24DAC;
  src2.bits[1] = 0x7A9AB;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x80060000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest31) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xB0F708D;
  src1.bits[1] = 0x96B05951;
  src1.bits[2] = 0x11A17B81;
  src1.bits[3] = 0x1C0000;
  src2.bits[0] = 0x17254C02;
  src2.bits[1] = 0xF5159B;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x110000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest32) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xAC281855;
  src1.bits[1] = 0x34291EBC;
  src1.bits[2] = 0x4;
  src1.bits[3] = 0x80140000;
  src2.bits[0] = 0x13EDF788;
  src2.bits[1] = 0xC3C80BD9;
  src2.bits[2] = 0x4;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest33) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xFFFFFFFF;
  src1.bits[1] = 0xFFFFFFFF;
  src1.bits[2] = 0xFFFFFFFF;
  src1.bits[3] = 0x80000000;
  src2.bits[0] = 0x1;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest34) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x58431906;
  src1.bits[1] = 0x72D605;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0xBE118597;
  src2.bits[1] = 0xD93D12C6;
  src2.bits[2] = 0x59648;
  src2.bits[3] = 0x110000;
  int result = s21_is_greater(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_greaterTest36) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0x0;
  src1.bits[1] = 0x0;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;
  src2.bits[0] = 0x4FB46065;
  src2.bits[1] = 0x4236B661;
  src2.bits[2] = 0x7ABD8C9A;
  src2.bits[3] = 0x800C0000;
  int result = s21_is_greater(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_greater_11) {
  s21_decimal dec5 = {{12345, 0, 0, 0x40000}};
  s21_decimal dec6 = {{12, 0, 0, 0x80010000}};
  ck_assert_int_eq(s21_is_greater(dec5, dec6), 1);
  ck_assert_int_eq(s21_is_greater(dec6, dec5), 0);

  s21_decimal dec7 = {{12345, 0, 0, 0x80040000}};
  s21_decimal dec8 = {{12, 0, 0, 0x10000}};
  ck_assert_int_eq(s21_is_greater(dec7, dec8), 0);
  ck_assert_int_eq(s21_is_greater(dec8, dec7), 1);

  s21_decimal dec1 = {{12345, 0, 0, 0x40000}};
  s21_decimal dec2 = {{12, 0, 0, 0x10000}};
  ck_assert_int_eq(s21_is_greater(dec1, dec2), 1);
  ck_assert_int_eq(s21_is_greater(dec2, dec1), 0);

  s21_decimal dec3 = {{12345, 0, 0, 0x80040000}};
  s21_decimal dec4 = {{12, 0, 0, 0x80010000}};
  ck_assert_int_eq(s21_is_greater(dec3, dec4), 0);
  ck_assert_int_eq(s21_is_greater(dec4, dec3), 1);
}
END_TEST

Suite *suite_is_greater(void) {
  Suite *s = suite_create("suite_is_greater");
  TCase *tc = tcase_create("is_greater_tc");

  tcase_add_test(tc, is_greater_0);
  tcase_add_test(tc, is_greater_1);
  tcase_add_test(tc, is_greater_2);
  tcase_add_test(tc, is_greater_3);
  tcase_add_test(tc, is_greater_4);
  tcase_add_test(tc, is_greater_5);
  tcase_add_test(tc, is_greater_6);
  tcase_add_test(tc, is_greater_7);
  tcase_add_test(tc, is_greater_8);
  tcase_add_test(tc, is_greater_11);
  tcase_add_test(tc, is_greater_12);
  tcase_add_test(tc, is_greater_13);
  tcase_add_test(tc, is_greater_14);
  tcase_add_test(tc, is_greater_15);
  tcase_add_test(tc, is_greater_16);
  tcase_add_test(tc, is_greater_17);

  tcase_add_test(tc, greater_1);
  tcase_add_test(tc, greater_2);
  tcase_add_test(tc, greater_3);
  tcase_add_test(tc, greater_4);
  tcase_add_test(tc, greater_5);
  tcase_add_test(tc, greater_6);
  tcase_add_test(tc, greater_7);
  tcase_add_test(tc, greater_8);
  tcase_add_test(tc, greater_9);
  tcase_add_test(tc, greater_10);
  tcase_add_test(tc, s21_greater_11);

  tcase_add_test(tc, s21_is_greaterTest1);
  tcase_add_test(tc, s21_is_greaterTest2);
  tcase_add_test(tc, s21_is_greaterTest3);
  tcase_add_test(tc, s21_is_greaterTest4);
  tcase_add_test(tc, s21_is_greaterTest5);
  tcase_add_test(tc, s21_is_greaterTest6);
  tcase_add_test(tc, s21_is_greaterTest7);
  tcase_add_test(tc, s21_is_greaterTest8);
  tcase_add_test(tc, s21_is_greaterTest8);
  tcase_add_test(tc, s21_is_greaterTest9);
  tcase_add_test(tc, s21_is_greaterTest10);
  tcase_add_test(tc, s21_is_greaterTest11);
  tcase_add_test(tc, s21_is_greaterTest12);
  tcase_add_test(tc, s21_is_greaterTest13);
  tcase_add_test(tc, s21_is_greaterTest14);
  tcase_add_test(tc, s21_is_greaterTest15);
  tcase_add_test(tc, s21_is_greaterTest16);
  tcase_add_test(tc, s21_is_greaterTest18);
  tcase_add_test(tc, s21_is_greaterTest19);
  tcase_add_test(tc, s21_is_greaterTest20);
  tcase_add_test(tc, s21_is_greaterTest21);
  tcase_add_test(tc, s21_is_greaterTest22);
  tcase_add_test(tc, s21_is_greaterTest23);
  tcase_add_test(tc, s21_is_greaterTest24);
  tcase_add_test(tc, s21_is_greaterTest25);
  tcase_add_test(tc, s21_is_greaterTest26);
  tcase_add_test(tc, s21_is_greaterTest27);
  tcase_add_test(tc, s21_is_greaterTest28);
  tcase_add_test(tc, s21_is_greaterTest29);
  tcase_add_test(tc, s21_is_greaterTest30);
  tcase_add_test(tc, s21_is_greaterTest31);
  tcase_add_test(tc, s21_is_greaterTest32);
  tcase_add_test(tc, s21_is_greaterTest33);
  tcase_add_test(tc, s21_is_greaterTest34);
  tcase_add_test(tc, s21_is_greaterTest36);

  tcase_add_test(tc, s21_test_is_greater_1);
  tcase_add_test(tc, s21_test_is_greater_2);
  tcase_add_test(tc, s21_test_is_greater_3);
  tcase_add_test(tc, s21_test_is_greater_4);
  tcase_add_test(tc, s21_test_is_greater_5);
  tcase_add_test(tc, s21_test_is_greater_6);
  tcase_add_test(tc, s21_test_is_greater_7);
  tcase_add_test(tc, s21_test_is_greater_8);
  tcase_add_test(tc, s21_test_is_greater_9);
  tcase_add_test(tc, s21_test_is_greater_10);
  tcase_add_test(tc, s21_test_is_greater_51);
  tcase_add_test(tc, s21_test_is_greater_41);
  tcase_add_test(tc, s21_test_is_greater_2i);

  suite_add_tcase(s, tc);
  return s;
}
