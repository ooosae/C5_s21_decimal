#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  s21_zero_decimal(dst);
  int error = 0;
  if (src < 0) {
    s21_set_sign(dst);
    src = (-1) * src;
  }
  if (src > INT_MAX)
    error = 1;
  else
    dst->bits[0] = src;
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_zero_decimal(dst);
  int return_value = 0;
  if (isinf(src) || isnan(src)) {
    return_value = 1;
  } else {
    if (fabs(src) > eps) {
      int sign = *(int *)&src >> 31;
      int exp = ((*(int *)&src & ~0x80000000) >> 23) - BUFF_SIZE;
      double temp = (double)fabs(src);
      int off = 0;
      for (; off < 28 && (int)temp / (int)pow(2, 21) == 0; temp *= 10, off++) {
      }
      temp = round(temp);
      if (off <= 28 && (exp > -94 && exp < START_INFO)) {
        floatbits mant = {0};
        temp = (float)temp;
        for (; fabs(fmod(temp, 10)) < eps && off > 0; off--, temp /= 10) {
        }
        mant.fl = (float)temp;
        exp = ((*(int *)&mant.fl & ~0x80000000) >> 23) - BUFF_SIZE;
        dst->bits[exp / 32] |= 1 << exp % 32;
        for (int i = exp - 1, j = 22; j >= 0; i--, j--)
          if ((mant.ui & (1 << j)) != 0) dst->bits[i / 32] |= 1 << i % 32;
        dst->bits[3] = (sign << 31) | (off << 16);
      }
    }
  }
  return return_value;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double temp = (double)*dst;
  for (int i = 0; i < START_INFO; i++) {
    temp += s21_get_bit(src, i) * pow(2, i);
  }
  temp = temp * pow(10, -s21_get_scale(src));
  if (s21_get_bit(src, BUFF_SIZE)) temp = temp * (-1);
  *dst = (float)temp;
  return 0;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  int scale = s21_get_scale(src);
  if (src.bits[1] || src.bits[2]) {
    error = 1;
  } else {
    *dst = src.bits[0];
    if (scale > 0 && scale <= 28) {
      *dst /= (int)pow(10, scale);
    }
  }
  if (s21_get_bit(src, BUFF_SIZE)) *dst = *dst * (-1);
  return error;
}

int s21_from_decimal_to_double(s21_decimal src, long double *dst) {
  long double temp = (double)*dst;
  for (int i = 0; i < START_INFO; i++) {
    temp += s21_get_bit(src, i) * pow(2, i);
  }
  temp = temp * pow(10, -s21_get_scale(src));
  if (s21_get_bit(src, BUFF_SIZE)) temp = temp * (-1);
  *dst = temp;
  return 0;
}
