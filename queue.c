#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *start;
  Node *end;
} Queue;

void initQueue(Queue *queue);

void insert(Queue *queue, int value);
int dequeue(Queue *queue);

void printQueue(Queue *queue);

int main () {
  Queue *queue = (Queue*)malloc(sizeof(Queue));

  if (queue != NULL) {
    initQueue(queue);

    insert(queue, 10);
    insert(queue, 20);
    insert(queue, 30);

    printQueue(queue);
  } else {
    printf("Error allocating memory");
    return 1;
  }

  return 0;
}

void initQueue(Queue *queue) {
  queue->start = NULL;
  queue->end = NULL;
}

void insert(Queue *queue, int value) {
  Node *node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Error allocating memory");
  } else {
    node->value = value;
    node->next = NULL;

    if (queue->start == NULL) {
      queue->start = node;
    } else {
      queue->end->next = node;
    }

    queue->end = node;
  }
}

int dequeue(Queue *queue) {
  Node *node = queue->start;
  int value;

  if (node != NULL) {
    queue->start = node->next;
    node->next = NULL;
    value = node->value;

    free(node);

    if (queue->start == NULL) {
      queue->end = NULL;
    }
    return value;
  } else {
    printf("Queue is empty");
  }
}

void printQueue(Queue *queue) {
  Node *node = queue->start;

  if (node != NULL) {
    while (node != NULL) {
      printf("%d ", node->value);
      node = node->next;
    }
  } else {
    printf("Queue is empty");
    return;
  }
}
