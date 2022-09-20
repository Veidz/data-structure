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

void insert(Queue *queue, int value);
void remove(Queue *queue);

int main () {

}

void insert(Queue *queue, int value) {
  Node *node = (Node*)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Error allocating memory");
    return;
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

void remove(Queue *queue) {
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
