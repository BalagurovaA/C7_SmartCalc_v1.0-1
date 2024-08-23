#include "calc.h"

int priority_sign(char operands) {
  int code = 0;
  switch (operands) {
    case 'x':
      code = 0;
      break;
    case '-':
    case '+':
      code = 1;
      break;
    case '*':
    case 'm':
    case '/':
      code = 2;
      break;
    case '^':
      code = 3;
      break;
    case 's':
    case 'c':
    case 't':
    case 'a':
    case 'l':
      code = 4;
      break;
    case ')':
      code = 5;
      break;
    case '(':
      code = 6;
      break;
  }
  return code;
}

/****************** перенос строки в стек *****************/
stack *number_stack(stack *result, char *str, int *i) {
  int count_after_dot = 0;
  double new_number = 0;
  int flag_dot = 0;

  while (check_number(str[*i]) || check_dot(str[*i])) {
    if (check_dot(str[*i])) {
      *i += 1;
      flag_dot = 1;
    }
    new_number = new_number * 10 + (str[*i] - '0');
    *i += 1;
    if (flag_dot) {
      count_after_dot += 1;
    }
  }
  if (flag_dot) {
    new_number /= pow(10, count_after_dot);
  }
  result = push(result, new_number, '0', 0, "\0");
  return result;
}

/****************** распределение знаков из строки  в стек *****************/
stack *operands_stack(stack *result, char *str, int *i) {
  if (check_un_operands(str[*i]) && (*i == 0 || str[*i - 1] == '(')) {
    result = push(result, 0, '\0', 0, "\0");
  }
  result = push(result, 0, str[*i], priority_sign(str[*i]), "\0");
  return result;
}

/****** распределение тригонометрии и др функий в из строки  в стек ********/
stack *functions_stack(stack *result, char *str, int *i) {
  if (str[*i] == 'a') {
    if (str[*i + 1] == 's')
      result = push(result, 0, 0, priority_sign(str[*i]), "asin");
    else if (str[*i + 1] == 'c')
      result = push(result, 0, 0, priority_sign(str[*i]), "acos");
    else if (str[*i + 1] == 't')
      result = push(result, 0, 0, priority_sign(str[*i]), "atan");
    *i += 2;
  } else if (str[*i] == 's') {
    if (str[*i + 1] == 'i') {
      result = push(result, 0, 0, priority_sign(str[*i]), "sin");
      *i += 1;
    } else if (str[*i + 1] == 'q') {
      result = push(result, 0, 0, priority_sign(str[*i]), "sqrt");
      *i += 3;
    }
  } else if (str[*i] == 'l') {
    if (str[*i + 1] == 'o') {
      result = push(result, 0, 0, priority_sign(str[*i]), "log");
      *i += 1;
    } else if (str[*i + 1] == 'n')
      result = push(result, 0, 0, priority_sign(str[*i]), "ln");
  } else if (str[*i] == 'm') {
    result = push(result, 0, 0, priority_sign(str[*i]), "mod");
    *i += 2;
  } else if (str[*i] == 't') {
    result = push(result, 0, 0, priority_sign(str[*i]), "tan");
    *i += 2;
  } else if (str[*i] == 'c') {
    result = push(result, 0, 0, priority_sign(str[*i]), "cos");
    *i += 2;
  }
  return result;
}

/****************** переворачивание строки в стеке *****************/
stack *reverse(stack *result) {
  stack *reVerse = NULL;
  while (result != NULL) {
    reVerse = push(reVerse, result->number, result->operands, result->priority,
                   result->func);
    result = pop(result);
  }
  return reVerse;
}