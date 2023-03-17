#include "tests.h"

START_TEST(t1) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "1+2+3");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", 6.0);
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t2) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "sin(1)^tan(1)+43/2*0+cos(45)");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "1.289607");
  free(buf);
}
END_TEST

START_TEST(t3) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "tan(x)-5");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", tan(0) - 5);
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t4) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "5+5+66*312.24^sin(45)");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "8762.115184");
  free(buf);
}
END_TEST

START_TEST(t5) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "sin(Pi)");
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", sin(M_PI));
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t6) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "ln(e)");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", log(M_E));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t7) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "sqrt(2536745.2354)");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", sqrt(2536745.2354));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t8) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "-5+cos(Pi)-sin(Pi/2)");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", -5 + cos(M_PI) - sin(M_PI / 2));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t9) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "1/(1+3-5)*1000");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", 1.0 / (1 + 3 - 5) * 1000);
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t10) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "x");
  buf = s21_calc(buf, 5);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", 5.0);
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t12) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "1 +  2");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", 3.0);
  ck_assert_str_eq(buf, tmp);
  free(buf);
}
END_TEST

START_TEST(t13) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "ln(123)^log(321)-222");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", pow(log(123), log10(321)) - 222);
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t14) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "asin(1)");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", asin(1));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t15) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "atan(1)");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", atan(1));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t16) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "acos(1)");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", acos(1));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(t17) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "10mod2");
  buf = s21_calc(buf, 0);
  char *tmp = (char *)calloc(256, sizeof(char));
  sprintf(tmp, "%f", fmod(10, 2));
  ck_assert_str_eq(buf, tmp);
  free(buf);
  free(tmp);
}
END_TEST

START_TEST(error_1) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "++++");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

START_TEST(error_2) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "*1");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

START_TEST(error_3) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "1/0");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Деление на 0\n");
  free(buf);
}
END_TEST

START_TEST(error_4) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "asdjdasjk");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

START_TEST(error_5) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "sin()");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

START_TEST(error_6) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "1..1");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

START_TEST(error_7) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "Popa");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

START_TEST(error_8) {
  char *buf = (char *)calloc(256, sizeof(char));
  sprintf(buf, "1moda2");
  buf = s21_calc(buf, 0);
  ck_assert_str_eq(buf, "Not correct\n");
  free(buf);
}
END_TEST

Suite *tester(void) {
  Suite *s = suite_create("ALL");
  TCase *calculator;

  calculator = tcase_create("...");
  tcase_add_test(calculator, t1);
  tcase_add_test(calculator, t2);
  tcase_add_test(calculator, t3);
  tcase_add_test(calculator, t4);
  tcase_add_test(calculator, t5);
  tcase_add_test(calculator, t6);
  tcase_add_test(calculator, t7);
  tcase_add_test(calculator, t8);
  tcase_add_test(calculator, t9);
  tcase_add_test(calculator, t10);
  tcase_add_test(calculator, t12);
  tcase_add_test(calculator, t13);
  tcase_add_test(calculator, t14);
  tcase_add_test(calculator, t15);
  tcase_add_test(calculator, t16);
  tcase_add_test(calculator, t17);
  tcase_add_test(calculator, error_1);
  tcase_add_test(calculator, error_2);
  tcase_add_test(calculator, error_3);
  tcase_add_test(calculator, error_4);
  tcase_add_test(calculator, error_5);
  tcase_add_test(calculator, error_6);
  tcase_add_test(calculator, error_7);
  tcase_add_test(calculator, error_8);
  suite_add_tcase(s, calculator);

  return s;
}
