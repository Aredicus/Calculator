#include "s21_calculation.h"

void s21_time_to_clean_up(s21_stack_char *stackChar) {
  while (!s21_is_empty_stack_char(*stackChar)) {
    char *tmp = s21_pop_stack_char(stackChar);
    free(tmp);
  }
  s21_ERROR(stackChar);
}

double s21_calculation(s21_stack_char *stackChar, double *x) {
  double res = 0;
  s21_stack_double TMP;
  s21_init_stack_double(&TMP);
  while (!s21_is_empty_stack_char(*stackChar)) {
    char *tmp = s21_pop_stack_char(stackChar);
    if (strcmp(tmp, "x") == 0 && x != NULL) {
      s21_push_stack_double(&TMP, *x);
    } else if (isdigit(tmp[0]) || *tmp == 'e' || *tmp == 'P') {
      if (isdigit(*tmp)) {
        s21_push_stack_double(&TMP, atof(tmp));
      } else if (*tmp == 'P') {
        s21_push_stack_double(&TMP, M_PI);
      } else {
        s21_push_stack_double(&TMP, M_E);
      }
    } else if (isalpha(tmp[0]) && tmp[0] != 'm') {
      if (s21_is_empty_stack_double(TMP)) {
        free(tmp);
        s21_time_to_clean_up(stackChar);
        break;
      } else {
        s21_push_stack_double(
            &TMP, s21_get_function(tmp, *s21_pop_stack_double(&TMP)));
      }
    } else {
      if (s21_is_empty_stack_double(TMP)) {
        free(tmp);
        s21_time_to_clean_up(stackChar);
        break;
      } else if (*tmp != '~') {
        double f = *s21_pop_stack_double(&TMP);
        if (s21_is_empty_stack_double(TMP)) {
          free(tmp);
          s21_time_to_clean_up(stackChar);
          break;
        }
        double res = s21_get_operator(tmp, f, s21_pop_stack_double(&TMP));
        if (isinf(res)) {
          stackChar->is_correct = -1;
        }
        s21_push_stack_double(&TMP, res);
      } else {
        double res = s21_get_operator(tmp, *s21_pop_stack_double(&TMP), NULL);
        s21_push_stack_double(&TMP, res);
      }
    }
    free(tmp);
  }
  if (!s21_is_empty_stack_double(TMP) && stackChar->is_correct != -1) {
    res = *s21_pop_stack_double(&TMP);
    if (s21_is_empty_stack_double(TMP) == 0) {
      stackChar->is_correct = 0;
    } else {
      stackChar->is_correct = 1;
    }
  }
  s21_remove_stack_double(&TMP);
  return res;
}

double s21_get_operator(char *opr, double first, double *second) {
  double res = 0;
  char tmp = *opr;
  switch (tmp) {
  case '~':
    res = -first;
    break;
  case '+':
    res = first + (*second);
    break;
  case '-':
    res = (*second) - first;
    break;
  case '*':
    res = first * (*second);
    break;
  case '/':
    res = (*second) / first;
    break;
  case '^':
    res = pow(*second, first);
    break;
  case 'm':
    res = fmod(*second, first);
    break;
  }
  return res;
}

double s21_get_function(char *fun, double arg) {
  double res = 0;
  char tmp = *fun;
  switch (tmp) {
  case 's':
    if (strcmp(fun, "sin") == 0) {
      res = sin(arg);
    } else
      res = sqrt(arg);
    break;
  case 'c':
    res = cos(arg);
    break;
  case 't':
    res = tan(arg);
    break;
  case 'a':
    if (strcmp(fun, "acos") == 0) {
      res = acos(arg);
    } else if (strcmp(fun, "asin") == 0) {
      res = asin(arg);
    } else {
      res = atan(arg);
    }
    break;
  case 'l':
    if (strcmp(fun, "ln") == 0) {
      res = log(arg);
    } else {
      res = log10(arg);
    }
    break;
  }
  return res;
}