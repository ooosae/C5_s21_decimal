#include "s21_decimal_test.h"

START_TEST(is_less_or_equal_0) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_1) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  s21_set_bit(&val1, 127, 1);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 11);
  s21_set_scale(&val2, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  s21_set_scale(&val1, 10);
  s21_set_scale(&val2, 11);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_7) {
  s21_decimal val1 = {{0}};
  s21_decimal val2 = {{0}};
  val2.bits[2] = 257;
  s21_set_bit(&val1, 127, 1);
  s21_set_bit(&val2, 127, 1);
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_10) {
  float a = -25.158531f;
  float b = -39.425785f;

  s21_decimal _a = {{0}};
  s21_decimal _b = {{0}};
  s21_from_float_to_decimal(a, &_a);
  s21_from_float_to_decimal(b, &_b);
  ck_assert_int_eq(s21_is_less_or_equal(_a, _b), a <= b);
}
END_TEST

START_TEST(is_less_or_equal_12) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_13) {
  s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_14) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_15) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_set_sign(&value_2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_16) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
  s21_set_sign(&value_1);
  s21_set_sign(&value_2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(is_less_or_equal_17) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_set_scale(&value_2, 2);
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(is_less_or_equal_18) {
  s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
  int return_value = s21_is_less_or_equal(value_1, value_2);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(less_or_equal_1) {
  float num1 = 1.375342323523f;
  float num2 = 1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_2) {
  float num1 = 1.39f;
  float num2 = 1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_3) {
  float num1 = 1.39f;
  float num2 = -1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_4) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_5) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_6) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_7) {
  float num1 = -3453434.232446543232446543f;
  float num2 = -3.232323233232323233f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_8) {
  float num1 = -34534553434.232446543232446543f;
  float num2 = 34534553434.232446543232446543f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_9) {
  float num1 = 1.78f;
  float num2 = 1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_10) {
  float num1 = -3453453452.0f;
  float num2 = -34.0f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_11) {
  float num1 = 104235454634.34534534f;
  float num2 = 1042354546.34534534f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_12) {
  float num1 = 1042354546.34534534f;
  float num2 = 104235454634.345345f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_13) {
  float num1 = 1042.5667777f;
  float num2 = 1042.345345f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_14) {
  float num1 = 1.375342323523f;
  float num2 = 1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_15) {
  float num1 = 1.39f;
  float num2 = 1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_16) {
  float num1 = 1.39f;
  float num2 = -1.39f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_17) {
  int num1 = 0;
  int num2 = 0;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_18) {
  int num1 = 3;
  int num2 = 9;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_19) {
  int num1 = -3;
  int num2 = -3;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(less_or_equal_20) {
  int num1 = 10;
  int num2 = 3;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_int_to_decimal(num1, &dec1);
  s21_from_int_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_21) {
  float num1 = 104232346.34534534f;
  float num2 = 3.3453453234f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(less_or_equal_22) {
  float num1 = -3.34534534f;
  float num2 = 3.34534534f;
  s21_decimal dec1 = {0}, dec2 = {0};
  s21_from_float_to_decimal(num1, &dec1);
  s21_from_float_to_decimal(num2, &dec2);
  int res = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_1) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal b = {{1, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_2) {
  s21_decimal a = {{1, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_2i) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_3) {
  s21_decimal a = {{UINT_MAX - 1, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_4) {
  s21_decimal a = {{UINT_MAX, 0, 0, 0}};
  s21_decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_41) {
  s21_decimal a = {{UINT_MAX, 1, 0, 0}};
  s21_decimal b = {{UINT_MAX, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_5) {
  s21_decimal a = {{UINT_MAX, UINT_MAX - 1, 0, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_6) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_7) {
  s21_decimal a = {{UINT_MAX, UINT_MAX, UINT_MAX - 1, 0}};
  s21_decimal b = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_8) {
  s21_decimal a = {{0, UINT_MAX, UINT_MAX, 0}};
  s21_decimal b = {{0, UINT_MAX, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_9) {
  s21_decimal a = {{0, 0, UINT_MAX, 0}};
  s21_decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_test_is_less_or_equal_10) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, UINT_MAX, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);
}
END_TEST

START_TEST(s21_is_less_or_equalTest01) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};
  src2.bits[0] = 0x3;
  src2.bits[1] = 0x0;
  src2.bits[2] = 0x0;
  src2.bits[3] = 0x0;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest1) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest2) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest3) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest4) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest5) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest6) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest7) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest8) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest9) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest10) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest11) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest12) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest13) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest14) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest15) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest16) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest18) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest19) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest20) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest21) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest22) {
  s21_decimal src1 = {0}, src2 = {0};

  src1.bits[0] = 0x910AF4CA;
  src1.bits[1] = 0xC045D5F2;
  src1.bits[2] = 0x27E41B00;
  src1.bits[3] = 0x80150000;

  src2.bits[0] = 0x11CDD185;
  src2.bits[1] = 0xF5BC6FC0;
  src2.bits[2] = 0x2D50F3F;
  src2.bits[3] = 0x100000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest23) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest24) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest25) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest26) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest27) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest28) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest29) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest30) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest31) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest32) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest33) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest34) {
  s21_decimal src1 = {0}, src2 = {0};

  src1.bits[0] = 0x58431906;
  src1.bits[1] = 0x72D605;
  src1.bits[2] = 0x0;
  src1.bits[3] = 0x0;

  src2.bits[0] = 0xBE118597;
  src2.bits[1] = 0xD93D12C6;
  src2.bits[2] = 0x59648;

  src2.bits[3] = 0x0;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 1;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest35) {
  s21_decimal src1 = {{0}};
  s21_decimal src2 = {{0}};

  src1.bits[0] = 0xB13B45F4;
  src1.bits[1] = 0x3883AC81;
  src1.bits[2] = 0x19595C18;

  src1.bits[3] = 0x800B0000;

  src2.bits[0] = 0xE6259369;
  src2.bits[1] = 0x38DAE2B4;
  src2.bits[2] = 0xBB5FD11E;
  src2.bits[3] = 0x800B0000;
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_is_less_or_equalTest36) {
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
  int result = s21_is_less_or_equal(src1, src2);
  int origin = 0;
  ck_assert_int_eq(result, origin);
}
END_TEST

START_TEST(s21_less_or_equal_23) {
  s21_decimal dec5 = {{12345, 0, 0, 0x40000}};
  s21_decimal dec6 = {{12, 0, 0, 0x80010000}};
  ck_assert_int_eq(s21_is_less_or_equal(dec5, dec6), 0);
  ck_assert_int_eq(s21_is_less_or_equal(dec6, dec5), 1);

  s21_decimal dec7 = {{12345, 0, 0, 0x80040000}};
  s21_decimal dec8 = {{12, 0, 0, 0x10000}};
  ck_assert_int_eq(s21_is_less_or_equal(dec7, dec8), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec8, dec7), 0);

  s21_decimal dec1 = {{12345, 0, 0, 0x40000}};
  s21_decimal dec2 = {{12, 0, 0, 0x10000}};
  ck_assert_int_eq(s21_is_less_or_equal(dec1, dec2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(dec2, dec1), 1);

  s21_decimal dec3 = {{12345, 0, 0, 0x80040000}};
  s21_decimal dec4 = {{12, 0, 0, 0x80010000}};
  ck_assert_int_eq(s21_is_less_or_equal(dec3, dec4), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec4, dec3), 0);

  s21_decimal dec9 = {{12345, 0, 0, 0}};
  s21_decimal dec10 = {{12345, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(dec9, dec10), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec10, dec9), 1);

  s21_decimal dec11 = {{0, 0, 0, 0}};
  s21_decimal dec12 = {{0, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(dec11, dec12), 1);
  ck_assert_int_eq(s21_is_less_or_equal(dec12, dec11), 1);
}
END_TEST

Suite *suite_is_less_or_equal(void) {
  Suite *s = suite_create("suite_is_less_or_equal");
  TCase *tc = tcase_create("case_is_less_or_equal");
  tcase_add_test(tc, is_less_or_equal_0);
  tcase_add_test(tc, is_less_or_equal_1);
  tcase_add_test(tc, is_less_or_equal_2);
  tcase_add_test(tc, is_less_or_equal_3);
  tcase_add_test(tc, is_less_or_equal_4);
  tcase_add_test(tc, is_less_or_equal_5);
  tcase_add_test(tc, is_less_or_equal_6);
  tcase_add_test(tc, is_less_or_equal_7);
  tcase_add_test(tc, is_less_or_equal_10);
  tcase_add_test(tc, is_less_or_equal_12);
  tcase_add_test(tc, is_less_or_equal_13);
  tcase_add_test(tc, is_less_or_equal_14);
  tcase_add_test(tc, is_less_or_equal_15);
  tcase_add_test(tc, is_less_or_equal_16);
  tcase_add_test(tc, is_less_or_equal_17);
  tcase_add_test(tc, is_less_or_equal_18);

  tcase_add_test(tc, less_or_equal_1);
  tcase_add_test(tc, less_or_equal_2);
  tcase_add_test(tc, less_or_equal_3);
  tcase_add_test(tc, less_or_equal_4);
  tcase_add_test(tc, less_or_equal_5);
  tcase_add_test(tc, less_or_equal_6);
  tcase_add_test(tc, less_or_equal_7);
  tcase_add_test(tc, less_or_equal_8);
  tcase_add_test(tc, less_or_equal_9);
  tcase_add_test(tc, less_or_equal_10);
  tcase_add_test(tc, less_or_equal_11);
  tcase_add_test(tc, less_or_equal_12);
  tcase_add_test(tc, less_or_equal_13);
  tcase_add_test(tc, less_or_equal_14);
  tcase_add_test(tc, less_or_equal_15);
  tcase_add_test(tc, less_or_equal_16);
  tcase_add_test(tc, less_or_equal_17);
  tcase_add_test(tc, less_or_equal_18);
  tcase_add_test(tc, less_or_equal_19);
  tcase_add_test(tc, less_or_equal_20);
  tcase_add_test(tc, less_or_equal_21);
  tcase_add_test(tc, less_or_equal_22);
  tcase_add_test(tc, s21_less_or_equal_23);

  tcase_add_test(tc, s21_test_is_less_or_equal_1);
  tcase_add_test(tc, s21_test_is_less_or_equal_2);
  tcase_add_test(tc, s21_test_is_less_or_equal_2i);
  tcase_add_test(tc, s21_test_is_less_or_equal_3);
  tcase_add_test(tc, s21_test_is_less_or_equal_4);
  tcase_add_test(tc, s21_test_is_less_or_equal_41);
  tcase_add_test(tc, s21_test_is_less_or_equal_5);
  tcase_add_test(tc, s21_test_is_less_or_equal_6);
  tcase_add_test(tc, s21_test_is_less_or_equal_7);
  tcase_add_test(tc, s21_test_is_less_or_equal_8);
  tcase_add_test(tc, s21_test_is_less_or_equal_8);
  tcase_add_test(tc, s21_test_is_less_or_equal_9);
  tcase_add_test(tc, s21_test_is_less_or_equal_10);
  tcase_add_test(tc, s21_is_less_or_equalTest01);
  tcase_add_test(tc, s21_is_less_or_equalTest1);
  tcase_add_test(tc, s21_is_less_or_equalTest2);
  tcase_add_test(tc, s21_is_less_or_equalTest3);
  tcase_add_test(tc, s21_is_less_or_equalTest4);
  tcase_add_test(tc, s21_is_less_or_equalTest5);
  tcase_add_test(tc, s21_is_less_or_equalTest6);
  tcase_add_test(tc, s21_is_less_or_equalTest7);
  tcase_add_test(tc, s21_is_less_or_equalTest8);
  tcase_add_test(tc, s21_is_less_or_equalTest9);
  tcase_add_test(tc, s21_is_less_or_equalTest10);
  tcase_add_test(tc, s21_is_less_or_equalTest11);
  tcase_add_test(tc, s21_is_less_or_equalTest12);
  tcase_add_test(tc, s21_is_less_or_equalTest13);
  tcase_add_test(tc, s21_is_less_or_equalTest14);
  tcase_add_test(tc, s21_is_less_or_equalTest15);
  tcase_add_test(tc, s21_is_less_or_equalTest16);
  tcase_add_test(tc, s21_is_less_or_equalTest18);
  tcase_add_test(tc, s21_is_less_or_equalTest19);
  tcase_add_test(tc, s21_is_less_or_equalTest20);
  tcase_add_test(tc, s21_is_less_or_equalTest21);
  tcase_add_test(tc, s21_is_less_or_equalTest22);
  tcase_add_test(tc, s21_is_less_or_equalTest23);
  tcase_add_test(tc, s21_is_less_or_equalTest24);
  tcase_add_test(tc, s21_is_less_or_equalTest25);
  tcase_add_test(tc, s21_is_less_or_equalTest26);
  tcase_add_test(tc, s21_is_less_or_equalTest27);
  tcase_add_test(tc, s21_is_less_or_equalTest28);
  tcase_add_test(tc, s21_is_less_or_equalTest29);
  tcase_add_test(tc, s21_is_less_or_equalTest30);
  tcase_add_test(tc, s21_is_less_or_equalTest31);
  tcase_add_test(tc, s21_is_less_or_equalTest32);
  tcase_add_test(tc, s21_is_less_or_equalTest33);
  tcase_add_test(tc, s21_is_less_or_equalTest34);
  tcase_add_test(tc, s21_is_less_or_equalTest35);
  tcase_add_test(tc, s21_is_less_or_equalTest36);

  suite_add_tcase(s, tc);
  return s;
}
