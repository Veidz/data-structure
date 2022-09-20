#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *left, *right;
} NodeTree;

void insert(NodeTree **root, int value);
void printTree(NodeTree *root);

int main() {
  NodeTree *root = NULL;
  int choice, value;

  do {
    printf("\n0 - Exit");
    printf("\n1 - Insert");
    printf("\n2 - Print\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter a value: ");
        scanf("%d", &value);
        insert(&root, value);
        break;
      case 2:
        printTree(root);
        break;
      default:
        if (choice != 0) printf("\nInvalid choice\n");
    }

  } while (choice != 0);

  return 0;
}

void insert(NodeTree **root, int value) {
  if (*root == NULL) { // Nenhum elemento na árvore
    *root = malloc(sizeof(NodeTree));
    (*root)->value = value;
    (*root)->left = NULL;
    (*root)->right = NULL;
  } else {
    if (value < (*root)->value) { // Valor da root é menor que o valor a ser inserido? (insere na esquerda)
      insert(&((*root)->left), value);
    } else { // Valor da root é maior que o valor a ser inserido? (insere na direita)
      insert(&((*root)->right), value);
    }
  }
}

void printTree(NodeTree *root) {
  if (root != NULL) {
    printTree(root->left);
    printf(" %d ", root->value);
    printTree(root->right);
  }
}

