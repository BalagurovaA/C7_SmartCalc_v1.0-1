#include "calc.h"

int calculator(char *str, double *result) {
  stack *top = NULL;
  int code = true;
  double number_X = 0;
  if (validator(str) == true) {
    top = (completed_expression(str, top, number_X));
    *result = top->number;
    top = pop(top);
  } else
    code = false;
  return code;
}

int calculator_XY(char *str, double *result, double number_X) {
  stack *top = NULL;
  int code = true;
  if (validator(str) == true) {
    top = (completed_expression(str, top, number_X));
    *result = top->number;
    top = pop(top);
  } else
    code = false;
  return code;
}