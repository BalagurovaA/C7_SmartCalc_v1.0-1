#include "calc.h"

int check_x(char symbol) { return (symbol == 'x') ? true : false; }
int check_number(char symbol) {
  return (symbol >= '0' && symbol <= '9') ? true : false;
}
int check_dot(char symbol) { return (symbol == '.') ? true : false; }
int check_operands(char symbol) {
  return (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-' ||
          symbol == '^')
             ? true
             : false;
}
int check_un_operands(char symbol) {
  return (symbol == '-' || symbol == '+') ? true : false;
}
int ch_bracket_1(char symbol) { return (symbol == '(') ? true : false; }
int ch_bracket_2(char symbol) { return (symbol == ')') ? true : false; }

//-------------SQRT && ARC-FUNC-------------//
int is_sqrt_arc_f(char *str, int i, int *updated_i) {
  int code = true;
  char ptr_str[5];
  if (strchr(FIRST_SYMB, str[i]) != NULL) {
    char *ptr = &str[i];
    strncpy(ptr_str, ptr, 5);
    if (strstr(ptr_str, "sqrt(") != NULL) {
      *updated_i = i + 3;
      code = true;
    } else if (strstr(ptr_str, "asin(") != NULL) {
      *updated_i = i + 3;
      code = true;
    } else if (strstr(ptr_str, "acos(") != NULL) {
      *updated_i = i + 3;
      code = true;
    } else if (strstr(ptr_str, "atan(") != NULL) {
      *updated_i = i + 3;
      code = true;
    } else {
      code = false;
    }
  } else
    code = false;
  return code;
}

//-------------sin cos tan log------------//
int is_sin_cos_tan_log(char *str, int i, int *updated_i) {
  int code = true;
  char ptr_str[4];
  if (strchr(FIRST_SYMB, str[i]) != NULL) {
    char *ptr = &str[i];
    strncpy(ptr_str, ptr, 4);
    if (strstr(ptr_str, "cos(") != NULL) {
      code = true;
      *updated_i = i + 2;
    } else if (strstr(ptr_str, "sin(") != NULL) {
      *updated_i = i + 2;
      code = true;
    } else if (strstr(ptr_str, "tan(") != NULL) {
      *updated_i = i + 2;
      code = true;
    } else if (strstr(ptr_str, "log(") != NULL) {
      *updated_i = i + 2;
      code = true;
    } else
      code = false;
  } else
    code = false;
  return code;
}
//-------------LN------------//
int is_ln(char *str, int i, int *updated_i) {
  int code = true;
  char ptr_str[3];
  if (strchr(FIRST_SYMB, str[i]) != NULL) {
    char *ptr = &str[i];
    strncpy(ptr_str, ptr, 3);
    if (strstr(ptr_str, "ln(") != NULL) {
      *updated_i = i + 1;
      code = true;
    } else
      code = false;
  } else
    code = false;
  return code;
}
//-------------MOD------------//
int is_mod(char *str, int i, int *updated_i) {
  int code = true;
  char ptr_str[3];
  if (strchr(FIRST_SYMB, str[i]) != NULL) {
    char *ptr = &str[i];
    strncpy(ptr_str, ptr, 3);
    if (strstr(ptr_str, "mod") != NULL) {
      *updated_i = i + 2;
      code = true;
    } else
      code = false;
  } else
    code = false;
  return code;
}

//////////////////////////////// валидация ////////////////////////////////
// валидация числа
int valid_number(char *str, int *i) {
  int code = true;
  if (*i != 0) {
    if (ch_bracket_2(str[*i - 1]) == false && check_x(str[*i - 1]) == false &&
        ch_bracket_1(str[*i + 1]) == false &&
        is_sin_cos_tan_log(str, *i + 1, i) == false &&
        is_sqrt_arc_f(str, *i + 1, i) == false &&
        is_ln(str, *i + 1, i) == false && check_x(str[*i + 1]) == false &&
        str[*i + 1] != ' ' && str[*i + 1] != '\n')
      code = true;
    else
      code = false;
  } else if (ch_bracket_1(str[*i + 1]) == false &&
             is_sin_cos_tan_log(str, *i + 1, i) == false &&
             is_sqrt_arc_f(str, *i + 1, i) == false &&
             is_ln(str, *i + 1, i) == false && check_x(str[*i + 1]) == false &&
             str[*i + 1] != ' ' && str[*i + 1] != '\n')
    code = true;
  else
    code = false;
  return code;
}

// валидация x
int valid_x(char *str, int *i) {
  int code = true;
  if (*i != 0) {
    if (ch_bracket_2(str[*i - 1]) == false && check_x(str[*i - 1]) == false &&
        check_number(str[*i - 1]) == false &&
        ch_bracket_1(str[*i + 1]) == false &&
        is_sin_cos_tan_log(str, *i + 1, i) == false &&
        is_sqrt_arc_f(str, *i + 1, i) == false &&
        is_ln(str, *i + 1, i) == false && check_x(str[*i + 1]) == false &&
        str[*i + 1] != ' ' && str[*i + 1] != '\n' &&
        check_number(str[*i + 1]) == false)
      code = true;
    else
      code = false;
  } else if (ch_bracket_1(str[*i + 1]) == false &&
             is_sin_cos_tan_log(str, *i + 1, i) == false &&
             is_sqrt_arc_f(str, *i + 1, i) == false &&
             is_ln(str, *i + 1, i) == false && check_x(str[*i + 1]) == false &&
             str[*i + 1] != ' ' && str[*i + 1] != '\n' &&
             check_number(str[*i + 1]) == false && str[*i + 1] != '\0')
    code = true;
  else
    code = false;
  return code;
}

// валидация скобка (
int valid_bracket_1(char *str, int *i) {
  int code = true;
  if (*i != 0) {
    if (((((check_number(str[*i - 1]) == false ||
            check_x(str[*i - 1]) == false) &&
           ch_bracket_2(str[*i - 1]) == false &&
           ch_bracket_2(str[*i + 1]) == false &&
           check_operands(str[*i + 1]) == false &&
           is_mod(str, *i + 1, i) == false && str[*i + 1] != '\0' &&
           str[*i + 1] != ' ' && str[*i + 1] != '\n')) ||
         (check_un_operands(str[*i - 1]) == true ||
          check_un_operands(str[*i + 1]) == true))) {
      code = true;
    } else
      code = false;
  } else if ((ch_bracket_2(str[*i + 1]) == false &&
              check_operands(str[*i + 1]) == false &&
              is_mod(str, *i + 1, i) == false && str[*i + 1] != '\0' &&
              str[*i + 1] != ' ' && str[*i + 1] != '\n') ||
             check_un_operands(str[*i + 1]) == true)
    code = true;
  else
    code = false;

  return code;
}

// валидация скобка )
int valid_bracket_2(char *str, int *i) {
  int code = true;
  if (*i != 0) {
    if (check_number(str[*i + 1]) == false &&
        ch_bracket_1(str[*i + 1]) == false &&
        is_sqrt_arc_f(str, *i + 1, i) == false &&
        is_sin_cos_tan_log(str, *i + 1, i) == false &&
        is_ln(str, *i + 1, i) == false && ch_bracket_1(str[*i - 1]) == false &&
        check_operands(str[*i - 1]) == false &&
        ch_bracket_1(str[*i - 1]) == false && str[*i + 1] != ' ')
      code = true;
    else
      code = false;
  } else if (check_number(str[*i + 1]) == false &&
             ch_bracket_1(str[*i + 1]) == false &&
             is_sqrt_arc_f(str, *i + 1, i) == false &&
             is_sin_cos_tan_log(str, *i + 1, i) == false &&
             is_ln(str, *i + 1, i) == false && str[*i + 1] != ' ') {
    code = true;
  } else {
    code = false;
  }
  return code;
}

// //валидация знаки
int valid_operators(char *str, int *i) {
  int code = true;
  if ((check_operands(str[0]) || check_un_operands(str[0])) && str[1] == '=')
    code = false;
  if (valid_unary_operators(str, i) == true)
    code = true;

  else if (*i != 0) {
    if (ch_bracket_2(str[*i + 1]) == false &&
        check_operands(str[*i + 1]) == false &&
        ch_bracket_1(str[*i - 1]) == false &&
        check_operands(str[*i - 1]) == false &&
        (str[0] != '*' && str[0] != '/' && str[0] != '^') &&
        str[*i + 1] != '\0' && str[*i + 1] != ' ' && str[*i + 1] != '\n')
      code = true;
    else
      code = false;
  } else if (ch_bracket_2(str[*i + 1]) == false &&
             check_operands(str[*i + 1]) == false && str[*i + 1] != '\0' &&
             (str[0] != '*' && str[0] != '/' && str[0] != '^') &&
             str[*i + 1] != ' ' && str[*i + 1] != '\n')
    code = true;
  else
    code = false;
  return code;
}

// функция для унарных знаков
int valid_unary_operators(char *str, int *i) {
  int code = true;
  if (*i != 0) {
    if (check_un_operands(str[*i]) &&
        (ch_bracket_1(str[*i - 1]) || *i == 0 ||
         (check_number(str[*i + 1]) || is_sqrt_arc_f(str, *i + 1, i) ||
          is_sin_cos_tan_log(str, *i + 1, i) || is_ln(str, *i + 1, i))) &&
        !check_un_operands(str[*i - 1]))
      code = true;
    else
      code = false;
  } else if ((check_un_operands(str[*i]) &&
              (*i == 0 ||
               (check_number(str[*i + 1]) || is_sqrt_arc_f(str, *i + 1, i) ||
                is_sin_cos_tan_log(str, *i + 1, i) || is_ln(str, *i + 1, i)))))
    code = true;
  else
    code = false;
  return code;
}

// валидация функции
int valid_func(char *str, int *i) {
  int code = true;
  int j = *i;
  j -= 2;
  if (j != 0) {
    if (ch_bracket_2(str[*i - 1]) == false &&
        check_number(str[*i - 1]) == false &&
        check_number(str[*i + 1]) == false && str[*i + 1] != ' ' &&
        str[*i + 1] != '\n')
      code = true;
    else
      code = false;
  } else if (check_number(str[*i + 1]) == false && str[*i + 1] != ' ' &&
             str[*i + 1] != '\n')
    code = true;
  else
    code = false;
  return code;
}

// валидация точки
int valid_dot(char *str, int *i) {
  int code = true;
  int count_dot = 0;
  int j = *i;
  if (*i != 0 && check_number(str[*i - 1]) == true &&
      check_number(str[*i + 1]) == true) {
    code = true;
  } else
    code = false;
  while (code != false && count_dot <= 1 &&
         (check_number(str[j]) == true || check_dot(str[j]) == true)) {
    if (check_dot(str[j]) == true) {
      count_dot += 1;
    }
    if (check_dot(str[j]) == true && check_dot(str[j + 1]) == true)
      code = false;
    if (count_dot > 1) code = false;
    j++;
  }
  count_dot = 0;
  return code;
}

// валидация mod
int valid_mod(char *str, int *i) {
  int code = true;
  if (*i != 0) {
    if ((ch_bracket_2(str[*i - 1]) == true ||
         check_number(str[*i - 1]) == true ||
         ch_bracket_1(str[*i + 1]) == true ||
         check_number(str[*i + 1]) == true ||
         is_sin_cos_tan_log(str, *i + 1, i) == true ||
         is_sqrt_arc_f(str, *i + 1, i) == true ||
         is_ln(str, *i + 1, i) == true) &&
        (check_operands(str[*i - 1]) == false)) {
      code = true;
    } else
      code = false;
  } else if ((ch_bracket_1(str[*i + 1]) == true ||
              check_number(str[*i + 1]) == true ||
              is_sin_cos_tan_log(str, *i + 1, i) == true ||
              is_sqrt_arc_f(str, *i + 1, i) == true ||
              is_ln(str, *i + 1, i) == true)) {
    code = true;
  } else
    code = false;
  return code;
}

// валидация скобок
int both_brackets(char *str, int *i, int *check_brack) {
  int code = true;
  if (ch_bracket_1(str[*i]) == true) {
    *check_brack += 1;
    if (valid_bracket_1(str, i) == true)
      code = true;
    else
      code = false;
  } else if (ch_bracket_2(str[*i]) == true) {
    *check_brack -= 1;
    if (valid_bracket_2(str, i) == true)
      code = true;
    else
      code = false;
  }
  return code;
}

int validator(char *str) {
  int flag = 0, code = true;
  int check_brack = 0;
  for (int i = 0; str[i] != '\0' && code == true && flag != 1; i++) {
    if (check_number(str[i])) {
      if (valid_number(str, &i) == true)
        code = true;
      else
        code = false;
    } else if (check_dot(str[i]) == true) {
      if (valid_dot(str, &i) == true)
        code = true;
      else
        code = false;
    } else if (check_x(str[i]) == true) {
      if (valid_x(str, &i) == true)
        code = true;
      else
        code = false;
    } else if (ch_bracket_1(str[i]) == true || ch_bracket_2(str[i]) == true) {
      if (both_brackets(str, &i, &check_brack) == true)
        code = true;
      else
        code = false;
    } else if (is_mod(str, i, &i) == true) {
      if (valid_mod(str, &i) == true)
        code = true;
      else
        code = false;
    } else if (check_operands(str[i]) == true) {
      if (valid_operators(str, &i) == true)
        code = true;
      else
        code = false;
    } else if (is_sqrt_arc_f(str, i, &i) == true ||
               is_sin_cos_tan_log(str, i, &i) == true ||
               is_ln(str, i, &i) == true) {
      if (valid_func(str, &i) == true)
        code = true;
      else
        code = false;
    } else
      code = false;
  }
  if (check_brack == 0 && code == true && flag == 0) {
    code = true;
  } else
    code = false;
  return code;
}