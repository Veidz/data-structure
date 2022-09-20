#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *collection;
  int capacity;
  int currentSize;
} Stack;

Stack *createStack(int capacity);
void destroyStack(Stack *stack);

bool isFull(Stack *stack);
bool isEmpty(Stack *stack);

bool push(Stack *stack);
bool pop(Stack *stack);

void display();

int main() {
  Stack *stack = createStack(5);

  if (stack == NULL) {
    printf("Error creating stack\n");
    return 1;
  }

  int choice = 0;

  while (true) {
    printf("\n1 - Show stack\n");
    printf("2 - Insert a value\n");
    printf("3 - Remove a value\n\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        display(stack);
        break;
      case 2:
        if (!push(stack)) printf("\nStack is full\n");
        break;
      case 3:
        if (!pop(stack)) printf("\nStack is empty\n");
        break;
    }
  }

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
  stack->currentSize = 0;

  return stack;
}

void destroyStack(Stack *stack) {
  free(stack->collection);
  free(stack);
}

bool isFull(Stack *stack) {
  return stack->capacity == stack->currentSize;
}

bool isEmpty(Stack *stack) {
  return stack->currentSize == 0;
}

bool push(Stack *stack) {
  if (isFull(stack)) return false;

  int item;
  printf("\nEnter the item to be pushed in stack: ");
  scanf("%d", &item);

  stack->collection[stack->currentSize] = item;
  stack->currentSize++;

  return true;
}

bool pop(Stack *stack) {
  if (isEmpty(stack)) return false;

  stack->currentSize--;
  stack->collection[stack->currentSize];

  return true;
}

void display(Stack *stack) {
  if (isEmpty(stack)) {
    printf("\nStack is empty\n");
  } else {
    printf("\nStack elements:\n");
    for (int i = stack->currentSize - 1; i >= 0; i--) {
      printf("%d\n", stack->collection[i]);
    }
  }
}
