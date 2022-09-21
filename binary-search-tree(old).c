#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *left, *right;
} NodeTree;

void insert(NodeTree **root, int value);
NodeTree* searchNode(NodeTree *root, int value);
NodeTree* removeNode(NodeTree *root, int value);
int height(NodeTree *root);

void printTreeOrder(NodeTree *root);
void printTreePreOrder(NodeTree *root);
void printTreePosOrder(NodeTree *root);

// Struct da árvore
// altura
// pré ordem/ordem/pós ordem

int main() {
  NodeTree *root = NULL, *search;
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
        insert(&root, value);
        break;
      case 2:
        printf("\nEnter a value to be searched: ");
        scanf("%d", &value);
        search = searchNode(root, value);
        if (search != NULL) {
          printf("\nValue found: %d", search->value);
        } else {
          printf("\nValue not found\n");
        }
        break;
      case 3:
        printf("\nEnter a value to be removed: ");
        scanf("%d", &value);
        root = removeNode(root, value);
        break;
      case 4:
        printf("\nTree height: %d", height(root));
        break;
      case 5:
        printf("\nTree In Order\n");
        printTreeOrder(root);
        printf("\nTree Pre Order\n");
        printTreePreOrder(root);
        printf("\nTree Pos Order\n");
        printTreePosOrder(root);
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

NodeTree* searchNode(NodeTree *root, int value) {
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

NodeTree* removeNode(NodeTree *root, int value) {
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
          NodeTree *aux = root->left;
          while (aux->right != NULL) {
            aux = aux->right;
          }
          root->value = aux->value;
          aux->value = value;
          printf("Element swapped: %d\n", value);
          root->left = removeNode(root->left, value);
          return root;
        } else { // Nós que possuem apenas 1 filho
          NodeTree *aux;
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

int height(NodeTree *root) {
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

void printTreeOrder(NodeTree *root) {
  // Sub-árvore esquerda -> raíz -> sub-ávore direita
  if (root != NULL) {
    printTreeOrder(root->left);
    printf(" %d ", root->value);
    printTreeOrder(root->right);
  }
}

void printTreePreOrder(NodeTree *root) {
  // Raíz -> sub-árvore esquerda -> sub-ávore direita
  if (root != NULL) {
    printf(" %d ", root->value);
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
  }
}

void printTreePosOrder(NodeTree *root) {
  // Sub-árvore esquerda -> sub-ávore direita -> raíz
  if (root != NULL) {
    printTreePosOrder(root->left);
    printTreePosOrder(root->right);
    printf(" %d ", root->value);
  }
}

