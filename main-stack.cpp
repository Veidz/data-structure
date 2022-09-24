#include <iostream>
#include "doubly-linked-list.hpp"
using namespace std;

class Stack {
  public:
    DLL* list;

    Stack() {
      list = new DLL();
    }

    void operator + (int value) {
      list->insertBeginning(value);
    }

    void push(int value) {
      list->insertBeginning(value);
    }

    void pop() {
      list->removeNode();
    }

    void print() {
      list->print();
    }
};

int main() {
  Stack* stack = new Stack();
  int choice, value;

  do {
    cout << "\n0 - Exit" << endl;
    cout << "1 - Push" << endl;
    cout << "2 - Push (overload)" << endl;
    cout << "3 - Pop" << endl;
    cout << "4 - Print stack" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        exit(1);
        break;
      case 1:
        cout << "Enter a value to push: ";
        cin >> value;
        stack->push(value);
        break;
      case 2:
        cout << "Enter a value to push (overload): ";
        cin >> value;
        (*stack) + value;
        break;
      case 3:
        stack->pop();
        break;
      case 4:
        stack->print();
        break;
    }

  } while (choice != 0);

  return 0;

  system("pause");
}
