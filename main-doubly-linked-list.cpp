#include <iostream>
#include "doubly-linked-list.hpp"
using namespace std;

int main() {
  DLL* list = new DLL();
  int choice, value;

  do {
    cout << "\n0 - Exit" << endl;
    cout << "1 - Insert Beginning" << endl;
    cout << "2 - Insert End" << endl;
    cout << "3 - Remove" << endl;
    cout << "4 - Print List" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        exit(1);
        break;
      case 1:
        cout << "Enter a value to insert at the beginning: ";
        cin >> value;
        list->insertBeginning(value);
        break;
      case 2:
        cout << "Enter a value to insert at the end: ";
        cin >> value;
        list->insertEnd(value);
        break;
      case 3:
        list->removeNode();
        break;
      case 4:
        list->print();
        break;
    }

  } while (choice != 0);

  return 0;

  system("pause");
}
