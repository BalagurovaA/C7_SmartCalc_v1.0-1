#include "calc.h"

stack *calc_func(stack *source, stack *buff, double *num) {
  int flag = 0;
  if (source->priority == 4) {
    if (strcmp(source->func, "sin") == 0) {
      buff = push(buff, sin(*num), source->operands, source->priority, "\0");
    } else if (strcmp(source->func, "cos") == 0) {
      buff = push(buff, cos(*num), source->operands, source->priority, "\0");
    } else if (strcmp(source->func, "tan") == 0) {
      buff = push(buff, tan(*num), source->operands, source->priority, "\0");
    } else if ((strcmp(source->func, "asin") == 0) && *num > -1 && *num < 1) {
      buff = push(buff, asin(*num), source->operands, source->priority, "\0");
    } else if ((strcmp(source->func, "acos") == 0) && *num > -1 && *num < 1) {
      buff = push(buff, acos(*num), source->operands, source->priority, "\0");
    } else if (strcmp(source->func, "atan") == 0) {
      buff = push(buff, atan(*num), source->operands, source->priority, "\0");
    } else if (strcmp(source->func, "sqrt") == 0) {
      buff = push(buff, sqrt(*num), source->operands, source->priority, "\0");
    } else if ((strcmp(source->func, "log") == 0) && *num > 0) {
      buff = push(buff, log10(*num), source->operands, source->priority, "\0");
    } else if ((strcmp(source->func, "ln") == 0) && *num > 0) {
      buff = push(buff, log(*num), source->operands, source->priority, "\0");
    } else
      flag = 1;
  }
  if (flag == 1) {
    buff = push(buff, 0, 0, 0, "\0");
  }
  return buff;
}

stack *calc_operators(stack *source, stack *buff) {
  if (buff == NULL) {
    return buff;
  }
  double num1 = 0;
  double num2 = 0;
  while (source != NULL && buff != NULL) {
    num1 = buff->number;
    buff = pop(buff);
    if (buff != NULL && source->priority != 4) {
      num2 = buff->number;
      buff = pop(buff);
    }
    if (source->operands == '+') {
      buff = push(buff, num2 + num1, '0', 0, "\0");
      source = pop(source);
    } else if (source->operands == '-') {
      buff = push(buff, num2 - num1, '0', 0, "\0");
      source = pop(source);
    } else if (source->operands == '*') {
      buff = push(buff, num2 * num1, '0', 0, "\0");
      source = pop(source);
    } else if (source->operands == '/' && num1 != 0) {
      buff = push(buff, num2 / num1, '0', 0, "\0");
      source = pop(source);
    } else if (source->operands == '/' && num1 == 0) {
      buff = push(buff, INFINITY, '0', 0, "\0");
      source = pop(source);
    } else if (source->operands == '^') {
      buff = push(buff, pow(num2, num1), '0', 0, "\0");
      source = pop(source);
    } else if (strcmp(source->func, "mod") == 0) {
      buff = push(buff, fmod(num2, num1), '0', 0, "\0");
      source = pop(source);
    } else if (source->priority == 4) {
      buff = calc_func(source, buff, &num1);
      source = pop(source);
    }
    num1 = 0;
    num2 = 0;
    while (source != NULL && source->priority == 0) {
      buff = push(buff, source->number, '0', 0, "\0");
      source = pop(source);
    }
  }
  return buff;
}

stack *calculation(stack *source) {
  stack *buff = NULL;
  if (source->next == NULL) {
    buff = push(buff, source->number, 0, 0, "\0");
    source = pop(source);
  } else if (source != NULL) {
    while (source->priority < 1) {
      buff = push(buff, source->number, 0, 0, "\0");
      source = pop(source);
    }
    if (source->priority > 0 && source->priority < 5) {
      buff = calc_operators(source, buff);
    }
  }
  return buff;
}

stack *completed_expression(char *str, stack *top, double number_X) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (check_number(str[i])) {
      top = number_stack(top, str, &i);
    }
    if (check_operands(str[i])) {
      top = operands_stack(top, str, &i);
    }
    if (str[i] == '(' || str[i] == ')') {
      top = push(top, 0, str[i], priority_sign(str[i]), "\0");
    }
    if (str[i] == 'x') {
      top = push(top, number_X, 0, 0, "\0");
    }
    if (str[i] == 's' || str[i] == 'c' || str[i] == 't' || str[i] == 'a' ||
        str[i] == 'm' || str[i] == 'l') {
      top = functions_stack(top, str, &i);
    }
  }
  top = polish_notation(top);
  top = reverse(top);
  top = calculation(top);
  return top;
}