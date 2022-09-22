#include <iostream>
#include "doubly-linked-list.h"
using namespace std;

int main() {
  DLL* queue = new DLL();
  int choice, value;

  do {
    cout << "\n0 - Exit" << endl;
    cout << "1 - Enqueue" << endl;
    cout << "2 - Dequeue" << endl;
    cout << "3 - Print Queue" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        exit(1);
        break;
      case 1:
        cout << "Enter a value to enqueue: ";
        cin >> value;
        queue->insertEnd(value);
        break;
      case 2:
        queue->removeNode();
        break;
      case 3:
        queue->print();
        break;
    }

  } while (choice != 0);

  return 0;

  system("pause");
}
