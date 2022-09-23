#include <iostream>
#include "doubly-linked-list.hpp"
using namespace std;

class Queue {
  public:
    DLL* list;

    Queue() {
      list = new DLL();
    }

    void operator + (int value) {
      list->insertEnd(value);
    }

    void enqueue(int value) {
      list->insertEnd(value);
    }

    void dequeue() {
      list->removeNode();
    }

    void print() {
      list->print();
    }
};

int main() {
  Queue* queue = new Queue();
  int choice, value;

  do {
    cout << "\n0 - Exit" << endl;
    cout << "1 - Enqueue" << endl;
    cout << "2 - Enqueue (overload)" << endl;
    cout << "3 - Dequeue" << endl;
    cout << "4 - Print Queue" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        exit(1);
        break;
      case 1:
        cout << "Enter a value to enqueue: ";
        cin >> value;
        queue->enqueue(value);
        break;
      case 2:
        cout << "Enter a value to enqueue (overload): ";
        cin >> value;
        (*queue) + value;
        break;
      case 3:
        queue->dequeue();
        break;
      case 4:
        queue->print();
        break;
    }

  } while (choice != 0);

  return 0;

  system("pause");
}
