#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *left, *right;
} Node;

typedef struct Tree {
  Node *root;
} Tree;

Node* createNode(int value);

void handleInsert(Tree* tree, int value);
Node* insertNode(Node* root, int value);

void handleRemove(Tree *tree, int value);
Node* removeNode(Node* root, int value);

void handleSearch(Tree* tree, int value);
Node* searchNode(Node* node, int value);

int height(Node *node);

void inOrder(Node* node);
void preOrder(Node* node);
void postOrder(Node* node);
void printTree(Tree* tree);

int main() {
  Tree tree;
  tree.root = NULL;

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
        handleInsert(&tree, value);
        break;
      case 2:
        printf("\nEnter a value to be searched: ");
        scanf("%d", &value);
        handleSearch(&tree, value);
        break;
      case 3:
        printf("\nEnter a value to be removed: ");
        scanf("%d", &value);
        handleRemove(&tree, value);
        break;
      case 4:
        printf("\nTree height: %d", height(tree.root));
        break;
      case 5:
        printTree(&tree);
        break;
      default:
        if (choice != 0) printf("\nInvalid choice\n");
    }

  } while (choice != 0);

  return 0;
}

Node* createNode(int value) {
  Node* node = (Node*)malloc(sizeof(Node));

  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

Node* insertNode(Node* root, int value) {
  if (root == NULL) {
    return createNode(value);
  } else if (value < root->value) {
    root->left = insertNode(root->left, value);
  } else {
    root->right = insertNode(root->right, value);
  }

  return root;
}

void handleInsert(Tree *tree, int value) {
  if (tree->root == NULL) {
    tree->root = createNode(value);
  } else {
    insertNode(tree->root, value);
  }
}

void handleRemove(Tree *tree, int value) {  
  tree->root = removeNode(tree->root, value);
}

Node* removeNode(Node* root, int value) {
  if (root == NULL) {
    printf("Value not found\n");
    return NULL;
  } else {
    if (root->value == value) {
      if (root->left == NULL && root->right == NULL) {
        free(root);
        printf("Element with no child removed: %d", value);
      } else {
        if (root->left != NULL && root->right != NULL) {
          Node* aux = root->left;

          while (aux->right != NULL) {
            aux = aux->right;
          }

          root->value = aux->value;
          aux->value = value;

          printf("Element swapped: %d\n", value);
          root->left = removeNode(root->left, value);
          return root;
        } else {
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
      if (value < root->value) {
        root->left = removeNode(root->left, value);
      } else {
        root->right = removeNode(root->right, value);
      }

      return root;
    }
  }
}

void handleSearch(Tree* tree, int value) {
  Node* node = searchNode(tree->root, value);

  if (node != NULL) {
    printf("\nValue found: %d", node->value);
  } else {
    printf("\nValue not found\n");
  }
}

Node* searchNode(Node* node, int value) {
  while (node) {
    if (value < node->value) {
      node = node->left;
    } else if (value > node->value) {
      node = node->right;
    } else {
      return node;
    }
  }
  return NULL;
}

int height(Node* node) {
  if (node != NULL) {
    int left  = height(node->left);
    int right = height(node->right);
    
    if (left > right) {
      return left + 1;
    } else {
      return right + 1;
    }
  } else {
    return 0;
  }
}

void printTree(Tree* tree) {
  if (tree != NULL) {
    printf("\nTree in Order\n");
    inOrder(tree->root);

    printf("\nTree Pre Order\n");
    preOrder(tree->root);

    printf("\nTree Pos Order\n");
    postOrder(tree->root);
  }
}

void inOrder(Node* root) {
  // Sub-árvore esquerda -> raíz -> sub-ávore direita
  if (root != NULL) {
    inOrder(root->left);
    printf(" %d ", root->value);
    inOrder(root->right);
  }
}

void preOrder(Node* root) {
  // Raíz -> sub-árvore esquerda -> sub-ávore direita
  if (root != NULL) {
    printf(" %d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(Node* root) {
  // Sub-árvore esquerda -> sub-ávore direita -> raíz
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->value);
  }
}
