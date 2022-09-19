#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *collection;
  int capacity;
  int size;
} Stack;

Stack *createStack(int capacity);
void destroyStack(Stack *stack);

bool isFull(Stack *stack);
bool isEmpty(Stack *stack);

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

void destroyStack(Stack *stack) {
  free(stack->collection);
  free(stack);
}

bool isFull(Stack *stack) {
  return stack->capacity == stack->size;
}

bool isEmpty(Stack *stack) {
  return stack->size == 0;
}
