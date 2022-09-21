#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *left, *right;
} Node;

typedef struct Tree {
  Node *root;
} Tree;

void insert(Node **root, int value);
Node* searchNode(Node *root, int value);
Node* removeNode(Node *root, int value);
int height(Node *root);

void printTreeOrder(Node *root);
void printTreePreOrder(Node *root);
void printTreePosOrder(Node *root);


int main() {
  Tree tree;
  tree.root = NULL;

  Node *search;

  int choice, value;

  do {
    printf("\n0 - Exit");
    printf("\n1 - Insert");
    printf("\n2 - Search");
    printf("\n3 - Remove");
    printf("\n4 - Height");
    printf("\n5 - Print\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter a value to insert: ");
        scanf("%d", &value);
        insert(&tree.root, value);
        break;
      case 2:
        printf("\nEnter a value to be searched: ");
        scanf("%d", &value);
        search = searchNode(tree.root, value);
        if (search != NULL) {
          printf("\nValue found: %d", search->value);
        } else {
          printf("\nValue not found\n");
        }
        break;
      case 3:
        printf("\nEnter a value to be removed: ");
        scanf("%d", &value);
        removeNode(tree.root, value);
        break;
      case 4:
        printf("\nTree height: %d", height(tree.root));
        break;
      case 5:
        printf("\nTree In Order\n");
        printTreeOrder(tree.root);
        printf("\nTree Pre Order\n");
        printTreePreOrder(tree.root);
        printf("\nTree Pos Order\n");
        printTreePosOrder(tree.root);
        break;
      default:
        if (choice != 0) printf("\nInvalid choice\n");
    }

  } while (choice != 0);

  return 0;
}

void insert(Node **root, int value) {
  if (*root == NULL) { // Nenhum elemento na árvore
    *root = malloc(sizeof(Node));
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

Node* searchNode(Node *root, int value) {
  if (root != NULL) {
    if (value == root->value) { // Valor é a raíz?
      return root;
    } else if (value < root->value) { // Valor é menor que a raíz?
      return searchNode(root->left, value);
    } else {
      return searchNode(root->right, value); // Valor é maior que a raíz
    }
  }
  return NULL;
}

Node* removeNode(Node *root, int value) {
  if (root == NULL) {
    printf("Value not found\n");
    return NULL;
  } else {
    if (root->value == value) { // Valor é a raiz?
      if (root->left == NULL && root->right == NULL) { // Remove nós sem filhos
        free(root);
        printf("Element with no child removed: %d", value);
        return NULL;
      } else {
        if (root->left != NULL && root->right != NULL) { // Nós que possuem 2 filhos
          Node *aux = root->left;
          while (aux->right != NULL) {
            aux = aux->right;
          }
          root->value = aux->value;
          aux->value = value;
          printf("Element swapped: %d\n", value);
          root->left = removeNode(root->left, value);
          return root;
        } else { // Nós que possuem apenas 1 filho
          Node *aux;
          if (root->left != NULL) {
            aux = root->left;
          } else {
            aux = root->right;
          }
          free(root);
          printf("Element with 1 child removed: %d", value);
          return aux;
        }
      }
    } else {
      if (value < root->value) { // Valor é menor que a raíz?
        root->left = removeNode(root->left, value);
      } else { // Valor é maior que a raíz
        root->right = removeNode(root->right, value);
      }
      return root;
    }
  }
}

int height(Node *root) {
  if (root != NULL) {
    int left = height(root->left);
    int right = height(root->right);
    if (left > right) {
      return left + 1;
    } else {
      return right + 1;
    }
  } else {
    return 0;
  }
}

void printTreeOrder(Node *root) {
  // Sub-árvore esquerda -> raíz -> sub-ávore direita
  if (root != NULL) {
    printTreeOrder(root->left);
    printf(" %d ", root->value);
    printTreeOrder(root->right);
  }
}

void printTreePreOrder(Node *root) {
  // Raíz -> sub-árvore esquerda -> sub-ávore direita
  if (root != NULL) {
    printf(" %d ", root->value);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
  }
}

void printTreePosOrder(Node *root) {
  // Sub-árvore esquerda -> sub-ávore direita -> raíz
  if (root != NULL) {
    printTreePosOrder(root->left);
    printTreePosOrder(root->right);
    printf(" %d ", root->value);
  }
}

