#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
  struct node* prev;
} Node;

void deallocate(Node** tail, Node** head);
void initializeList(Node **tail, Node**head, int value);
void insertBeggining(Node** tail, int value);
void insertEnd(Node** head, int value);
void insertAfter(Node* node, int value);
void removeNode(Node* node);

int main() {
  Node* tail = NULL; // beginning
  Node* head = tail; // end

  initializeList(&tail, &head, 0);
  insertBeggining(&tail, 3);
  insertEnd(&head, 5);
  insertAfter(head, 4);
  insertAfter(tail, 2);
  removeNode(tail->next);

  for (Node* current = tail; current != NULL; current = current->next) {
    printf("%d\n", current->value);
  }

  deallocate(&tail, &head);

  return 0;
}

void deallocate(Node** tail, Node** head) {
  if (*tail == NULL) {
    return;
  }

  Node* current = *tail;
  while (current->next != NULL) {
    current = current->next;
    free(current->prev);
  }
  free(current);

  *tail = NULL;
  *head = NULL;
}

void initializeList(Node **tail, Node**head, int value) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    *tail = newNode;
    *head = newNode;

  } else {
    printf("Memory not allocated\n");
    exit(1);
  }
}

void insertBeggining(Node** tail, int value) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = *tail;
    
    if (*tail != NULL) {
      (*tail)->prev = newNode;
    }
    *tail = newNode;
  } else {
    printf("Memory not allocated\n");
    exit(1);
  }
}

void insertEnd(Node** head, int value) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = *head;
    (*head)->next = newNode;
    *head = newNode;
  } else {
    printf("Memory not allocated\n");
    exit(1);
  }
}

void insertAfter(Node* node, int value) {
  Node* newNode = malloc(sizeof(Node));
  if (newNode != NULL) {
    newNode->value = value;
    newNode->prev = node;
    newNode->next = node->next;
    
    if (node->next != NULL) { // Node is head
      node->next->prev = newNode;
    }
    node->next = newNode;

  } else {
    printf("Memory not allocated\n");
    exit(1);
  }
}

void removeNode(Node* node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }

  free(node);
}
