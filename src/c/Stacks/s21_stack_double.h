
#ifndef C7_SMARTCALC_V1_0_0_S21_STACK_DOUBLE_H
#define C7_SMARTCALC_V1_0_0_S21_STACK_DOUBLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s21_stack_double {
  double *doubles;
  int size;
} s21_stack_double;

void s21_init_stack_double(s21_stack_double *stack);

void s21_push_stack_double(s21_stack_double *stack, double number);

void s21_remove_stack_double(s21_stack_double *stack);

double *s21_pop_stack_double(s21_stack_double *stack);

int s21_is_empty_stack_double(s21_stack_double stack);

#endif // C7_SMARTCALC_V1_0_0_S21_STACK_DOUBLE_H
