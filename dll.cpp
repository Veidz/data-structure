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

int main() {
  DLL* list = new DLL();
  int choice, value;

  do {
    cout << "\n0 - Exit" << endl;
    cout << "1 - Insert Beggining" << endl;
    cout << "2 - Insert End" << endl;
    cout << "3 - Print List" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        exit(1);
        break;
      case 1:
        break;
      case 2:
        cout << "Enter a value to insert at the end: ";
        cin >> value;
        list->insertEnd(value);
        break;
      case 3:
        list->print();
        break;
    }

  } while (choice != 0);

  return 0;
}
