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

bool push(Stack *stack, int item);

int main() {
  Stack *stack = createStack(5);

  if (stack == NULL) {
    printf("Error creating stack\n");
    return 1;
  }

  if (isEmpty(stack)) printf("Stack is empty\n");

  push(stack, 1);
  printf("Stack size: %d\n", stack->size);

  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);

  printf("Stack size: %d\n", stack->size);
  if (isFull(stack)) {
    printf("Stack is full\n");
  }

  destroyStack(stack);

  return 0;
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

bool push(Stack *stack, int item) {
  if (isFull(stack)) return false;

  stack->collection[stack->size] = item;
  stack->size++;

  return true;
}
