#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
  char *data;
  struct element *next;
} Element;

typedef struct {
  Element *first;
  Element *last;
  int size;
} Queue;

Queue* createQueue();
void initializeQueue(Queue *queue);

Element* createElement(char *data);

void enqueue(Queue *queue, Element *last, char *data);
void dequeue(Queue *queue);

void printQueue(Queue *queue);

void main() {
  Queue *queue = createQueue();
  char *data = (char*)malloc(50*sizeof(char));

  int choice;

  do {
    printf("\n0 - Exit\n");
    printf("1 - Insert\n");
    printf("2 - Remove\n");
    printf("3 - Print\n\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter an element: ");
        scanf("%s", data);
        enqueue(queue, queue->last, data);
        break;
      case 2:
        dequeue(queue);
        break;
      case 3:
        printQueue(queue);
        break;
      default:
         if (choice != 0) printf("Invalid choice\n");
    }
  } while(choice != 0);
}

Queue* createQueue() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  initializeQueue(queue);
  return queue;
}

void initializeQueue(Queue *queue) {
  queue->first = NULL;
  queue->last = NULL;
  queue->size = 0;
}

Element* createElement(char *data) {
  Element *newElement = (Element*)malloc(sizeof(Element));
  newElement->data = (char*)malloc(50 * sizeof(char));
  strcpy(newElement->data, data);
  newElement->next = NULL;
  return newElement;
}

void enqueue(Queue *queue, Element *last, char *data) {
  Element *newElement = createElement(data);

  if(last == NULL) {
    if(queue->size == 0) {
      queue->last = newElement;
    }
    newElement->next = queue->first;
    queue->first = newElement;
  } else {
    if(last->next == NULL) {
      queue->last = newElement;
    }
    newElement->next = last->next;
    last->next = newElement;
  }
  queue->size++;
}

void dequeue(Queue *queue) {
  Element *removeElement;

  if(queue->size != 0) {
    removeElement = queue->first;
    queue->first = queue->first->next;
    free(removeElement->data);
    free(removeElement);
    queue->size--;
  } else {
    printf("Queue is empty\n");
  }
}

void printQueue(Queue *queue) {
  Element *aux;
  int i;
  aux = queue->first;

  for(i = 0; i < queue->size; i++) {
    printf("Value: %s\n", aux->data);
    aux = aux->next;
  }
}
