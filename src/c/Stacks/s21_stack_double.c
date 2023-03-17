#include "s21_stack_double.h"

void s21_init_stack_double(s21_stack_double *stack) {
  stack->size = 0;
  stack->doubles = (double *)calloc(256, sizeof(double));
  stack->size = 0;
}

void s21_push_stack_double(s21_stack_double *stack, double number) {
  stack->doubles[(stack->size)++] = number;
}

void s21_remove_stack_double(s21_stack_double *stack) {
  stack->size = 0;
  free(stack->doubles);
}

double *s21_pop_stack_double(s21_stack_double *stack) {
  if (stack->size == 0) {
    return NULL;
  } else {
    return &stack->doubles[--(stack->size)];
  }
}

int s21_is_empty_stack_double(s21_stack_double stack) {
  char res = 0;
  if (stack.size == 0)
    res++;
  return res;
}
