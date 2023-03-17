#ifndef C7_SMARTCALC_V1_0_0_S21_PARSER_H
#define C7_SMARTCALC_V1_0_0_S21_PARSER_H

#include "../Stacks/s21_stack_char.h"
#include <ctype.h>
#include <string.h>

void s21_parse(s21_stack_char *stackChar, s21_stack_char *stackResult,
               const char *string);
void s21_push_double(s21_stack_char *stackChar, char *string);
void s21_push_fun(s21_stack_char *stackChar, char *string);
void s21_push_operator(s21_stack_char *stackChar, s21_stack_char *stackResult,
                       char *string, int un_min);
int s21_get_priority(char *opr);

#endif // C7_SMARTCALC_V1_0_0_S21_PARSER_H
