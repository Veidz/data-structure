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
