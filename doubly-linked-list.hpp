#include <iostream>
using namespace std;

class Node {
  public:
    int value;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int value) {
      this->value = value;
    }
};

class DLL {
  public:
    Node* start;

    DLL() {
      start = nullptr;
    }
    DLL(Node* node) {
      start = node;
    }

    void insertBeginning(int value) {
      Node* node = new Node(value);

      if (start == nullptr) {
        start = node;
        cout << start->value << " Inserted" << endl;
      } else {
        start->prev = node;
        node->next = start;
        start = node;
        
        cout << node->value << " Inserted" << endl;
      }
    }

    void insertEnd(int value) {
      Node* node = new Node(value);

      if (start == nullptr) {
        start = node;
        cout << start->value << " Inserted" << endl;
      } else {
        Node* ptr = start;

        while (ptr->next != NULL) {
          ptr = ptr->next;
        }

        ptr->next = node;
        node->prev = ptr;

        cout << node->value << " Inserted" << endl;
      }
    }

    void removeNode() {
      if (start == nullptr) {
        cout << "List is empty" << endl;
      } else {
        cout << start->value << " Removed" << endl;
        start = start->next;
      }
    }

    void print() {
      if (start == NULL) {
        cout << "List is empty" << endl;
      } else {
        cout << "List values: " << endl;
        Node* aux = start;

        while (aux != NULL) {
          cout << "Value: " << aux->value << endl;
          aux = aux->next;
        }
      }
    }
};
