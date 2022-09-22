#include <iostream>
using namespace std;

class Node {
  public:
    int value = 0;
    Node* prev = NULL;
    Node* next = NULL;

    Node(int value) {
      this->value = value;
    }
};

class DLL {
  public:
    Node* start;

    DLL() {
      start = NULL;
    }

    DLL(Node* node) {
      start = node;
    }

    void insertEnd(int value) {
      Node* node = new Node(value);

      if (start == NULL) {
        start = node;
        cout << start->value << " Inserted in the end" << endl;
      } else {
        Node* ptr = start;

        while (ptr->next != NULL) {
          ptr = ptr->next;
        }

        ptr->next = node;
        node->prev = ptr;

        cout << node->value << " Inserted in the end" << endl;
      }
    }
};

int main() {
  DLL* list = new DLL();
  list->insertEnd(10);
  list->insertEnd(5);
  list->insertEnd(22);
}
