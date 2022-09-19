#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *collection;
  int capacity;
  int size;
} Stack;

Stack *createStack(int capacity);

int main() {

}

Stack *createStack(int capacity) {
  if (capacity <= 0) return NULL;

  Stack *stack = malloc(sizeof(Stack));
  if (stack == NULL) return NULL;

  stack->collection = malloc(sizeof(int) * capacity);
  if (stack->collection == NULL) {
    free(stack);
    return NULL;
  }

  stack->capacity = capacity;
  stack->size = 0;

  return stack;
}
