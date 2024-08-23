#include "calc.h"

stack *push(stack *top, double number, char operands, int priority,
            char *func) {
  stack *ptr = malloc(sizeof(stack));
  ptr->number = number;
  ptr->operands = operands;
  ptr->priority = priority;
  ptr->next = top;
  strcpy(ptr->func, func);
  return ptr;
}

stack *pop(stack *top) {
  if (top == NULL) return top;
  stack *ptr_next = top->next;
  free(top);
  return ptr_next;
}
// void show(const stack *top) {
//   const stack *current = top;
//   while (current != NULL) {

//     printf("число %f\n", current->number);
//     printf("знак %c\n", current->operands);
//     printf("приор %d\n", current->priority);
//     printf("функц %s\n -------\n", current->func);

//     current = current->next;
//   }
// }