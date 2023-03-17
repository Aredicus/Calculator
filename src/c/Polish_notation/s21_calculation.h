#include "../Stacks/s21_stack_char.h"
#include "../Stacks/s21_stack_double.h"
#include <ctype.h>
#include <math.h>

#ifndef C7_SMARTCALC_V1_0_0_S21_CALCULATION_H
#define C7_SMARTCALC_V1_0_0_S21_CALCULATION_H

#define S21_INF 1.0 / 0.0

double s21_calculation(s21_stack_char *stackChar, double *x);
double s21_get_operator(char *opr, double first, double *second);
double s21_get_function(char *fun, double arg);
void s21_time_to_clean_up(s21_stack_char *stackChar);

#endif // C7_SMARTCALC_V1_0_0_S21_CALCULATION_H
