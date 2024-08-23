#include "calc.h"

/****************** польская нотация *****************/
stack *polish_notation(stack *source) {
  stack *result = NULL;
  stack *signs = NULL;
  source = reverse(source);
  while (source != NULL) {
    if (source->priority > 0 && source->priority < 5) {
      if (signs != NULL && source->priority <= signs->priority &&
          signs->priority != 6) {
        while (signs != NULL && source->priority <= signs->priority &&
               signs->priority != 6) {
          result =
              push(result, 0, signs->operands, signs->priority, signs->func);
          signs = pop(signs);
        }
        signs =
            push(signs, 0, source->operands, source->priority, source->func);
        source = pop(source);
      } else {
        signs =
            push(signs, 0, source->operands, source->priority, source->func);
        source = pop(source);
      }
    }
    if (source != NULL && source->priority == 0) {
      result = push(result, source->number, source->operands, 0, source->func);
      source = pop(source);
    } else if (source->priority == 6) {
      signs = push(signs, 0, source->operands, source->priority, source->func);
      source = pop(source);
    } else if (source->priority == 5) {
      while (signs->priority != 6) {
        if (signs != NULL) {
          result =
              push(result, 0, signs->operands, signs->priority, signs->func);
          signs = pop(signs);
        }
      }
      if (signs != NULL && signs->priority == 6) {
        signs = pop(signs);
      }
      source = pop(source);
    }
    while (signs != NULL && source == NULL) {
      result = push(result, 0, signs->operands, signs->priority, signs->func);
      signs = pop(signs);
    }
  }
  return result;
}