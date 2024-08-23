#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_SYMB "astclm"
#define MAX_NUM 256

/*---------------------struct--------------------*/
typedef struct obj {
  double number;
  char operands;
  int priority;
  char func[5];
  struct obj *next;
} stack;

/*---------------------VALIDATOR---------------------*/
int check_x(char symbol);
int check_number(char symbol);
int check_dot(char symbol);
int check_operands(char symbol);
int check_un_operands(char symbol);
int valid_unary_operators(char *str, int *i);
int ch_bracket_1(char symbol);
int ch_bracket_2(char symbol);
int is_sqrt_arc_f(char *str, int i, int *updated_i);
int is_sin_cos_tan_log(char *str, int i, int *updated_i);
int is_ln(char *str, int i, int *updated_i);
int is_mod(char *str, int i, int *updated_i);
int valid_number(char *str, int *i);
int valid_x(char *str, int *i);
int valid_bracket_1(char *str, int *i);
int valid_bracket_2(char *str, int *i);
int valid_operators(char *str, int *i);
int valid_func(char *str, int *i);
int valid_dot(char *str, int *i);
int valid_mod(char *str, int *i);
int both_brackets(char *str, int *i, int *check_brack);
int validator(char *str);

/*---------------------PARCING---------------------*/
stack *push(stack *top, double number, char operands, int priority, char *str);
stack *pop(stack *top);
// void show(const stack *top);

stack *number_stack(stack *result, char *str, int *i);
int priority_sign(char operands);
stack *operands_stack(stack *result, char *str, int *i);
stack *functions_stack(stack *result, char *str, int *i);
stack *reverse(stack *result);

/*---------------------POLISH NOTATION---------------------*/
stack *polish_notation(stack *source);
stack *calc_func(stack *source, stack *buff, double *num);
stack *calc_operators(stack *source, stack *buff);
stack *calculation(stack *source);

stack *completed_expression(char *str, stack *top, double number_X);

int calculator(char *str, double *result);
int calculator_XY(char *str, double *result, double number_X);