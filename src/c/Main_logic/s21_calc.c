#include "s21_calc.h"

char *s21_calc(char *str, double x) {
  char *res = calloc(256, sizeof(char));
  s21_stack_char TMP, RESULT;
  s21_init_stack_char(&TMP);
  s21_init_stack_char(&RESULT);
  s21_parse(&TMP, &RESULT, str);
  if (RESULT.is_correct && TMP.is_correct) {
    double result;
    s21_stack_char TMP1;
    s21_reverse_stack_char(&RESULT);
    s21_copy_stack(RESULT, &TMP1);
    if (RESULT.is_x > 0) {
      result = s21_calculation(&TMP1, &x);
    } else {
      result = s21_calculation(&TMP1, NULL);
    }
    if (TMP1.is_correct == 1) {
      sprintf(res, "%lf", result);
    } else if (TMP1.is_correct == 0) {
      res = strcpy(res, "Not correct\n");
    } else {
      res = strcpy(res, "Деление на 0\n");
    }
    s21_remove_stack_char(&TMP1);
  } else {
    res = strcpy(res, "Not correct\n");
  }
  s21_remove_stack_char(&TMP);
  s21_remove_stack_char(&RESULT);
  return res;
}