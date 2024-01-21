# Компилятор

CC := gcc

# Опции компилятора

CFLAGS := -std=c11 -Wall -pedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
UNITFLAGS := -lcheck
COV_FLAG :=
OS:=$(shell uname -s)
ifeq ($(OS), Darwin)
	UNITFLAGS += $(shell pkg-config --cflags --libs check)
else
	UNITFLAGS += -lsubunit -lrt -lm -lpthread
endif

# Объектные файлы

OBJS := ./out/s21_another_functions.o ./out/s21_arithmetic.o ./out/s21_comparison.o ./out/s21_converters.o ./out/s21_get_set.o ./out/s21_normalize.o
UNITOBJS := ./out/s21_add_test.o ./out/s21_div_test.o ./out/s21_float_to_decimal_test.o ./out/s21_floor_test.o ./out/s21_from_decimal_to_float_test.o ./out/s21_from_decimal_to_int_test.o ./out/s21_from_int_to_decimal_test.o ./out/s21_is_equal.o ./out/s21_is_greater_or_equal_test.o ./out/s21_is_greater_test.o ./out/s21_is_less_or_equal_test.o ./out/s21_is_less_test.o ./out/s21_is_not_equal_test.o ./out/s21_mod_test.o ./out/s21_mul_test.o ./out/s21_negate_test.o ./out/s21_round_test.o ./out/s21_round_test2.o ./out/s21_sub_test.o ./out/s21_truncate_test.o ./out/s21_decimal_test.o

.PHONY : all clean gcov_report del_lib

test : unit_tests.exe
	./unit_tests.exe || echo

all : COV_FLAG += --coverage
all : clean gcov_report

unit_tests.exe : $(OBJS) $(UNITOBJS) s21_decimal.a
	$(CC) -o unit_tests.exe $(UNITOBJS) $(UNITFLAGS) -L. -ls21_decimal -fprofile-arcs -ftest-coverage

gcov_report : COV_FLAG += --coverage
gcov_report : del_lib test
	lcov -t "coverage" -o coverage.info -c -d . 
	genhtml -o report coverage.info
	rm -rf ./*.g*

del_lib :
	rm -rf ./*.a
	rm -rf ./s21_decimal.o
	rm -rf ./out/s21_decimal.o
	
s21_decimal.a : $(OBJS)
	ar rc $@ $^
	ranlib $@
	cp $@ lib$@

./out/%.o : ./unit_tests/%.c
	mkdir -p ./out
	$(CC) $(CFLAGS) $(UNITFLAGS) -c $<
	mv ./*.o ./out/

./out/%.o : ./%.c ./s21_decimal.h
	mkdir -p ./out
	$(CC) $(CFLAGS) $(COV_FLAG) -c $<
	mv ./*.o ./out/

clean :
	rm -f ./*.exe
	rm -rf ./out
	rm -rf ./*.a
	rm -rf ./*.g*
	rm -rf ./report
	rm -rf ./*.info
	
