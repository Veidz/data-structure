#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackElement {
  char *data;
  struct stackElement *next;
} Element;

typedef struct stackPointer {
  Element *top;
  int size;
} Stack;

void initializeStack(Stack *stack) {
  stack->top = NULL;
  stack->size = 0;
}

Stack* createStack() {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  initializeStack(stack);
  return stack;
}

Element* initializeElement(char *data) {
  Element *newElement = (Element*)malloc(sizeof(Element));
  newElement->data = (char *)malloc(50 * sizeof(char));
  strcpy(newElement->data, data);
  return newElement;
}

void push(Stack *stack, char* data);
void pop(Stack *stack);

void printStack(Stack *stack);

void main() {
  Stack *stack = createStack();
  int choice;
  
  char *data = (char*)malloc(50*sizeof(char));

  do {
    printf("\n0 - Exit\n");
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - Print\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter an element: ");
        scanf("%s", data);
        push(stack, data);
        break;
      case 2:
        pop(stack);
        break;
      case 3:
        printStack(stack);
        break;
      default:
        if (choice != 0) printf("Invalid choice\n");
    }
  } while(choice != 0);
}

void printStack(Stack *stack) {
  Element *aux;
  int i;
  aux = stack->top;

  for(i = 0; i < stack->size; i++) {
    printf("Value: %s\n", aux->data);
    aux = aux->next;
  }
}

void push(Stack *stack, char* data) {
  Element *newElement = initializeElement(data);
  newElement->next = stack->top;
  stack->top = newElement;
  stack->size++;
}

void pop(Stack *stack) {
  Element *remove_Element;
  if(stack->size != 0) {
    remove_Element = stack->top;
    stack->top = stack->top->next;
    free(remove_Element->data);
    free(remove_Element);
    stack->size--;
  } else {
    printf("Stack is empty\n");
  }
}
