#include <iostream>
#include "doubly-linked-list.h"
using namespace std;

int main() {
  DLL* list = new DLL();
  int choice, value;

  do {
    cout << "\n0 - Exit" << endl;
    cout << "1 - Push" << endl;
    cout << "2 - Pop" << endl;
    cout << "3 - Print List" << endl;
    cin >> choice;

    switch (choice) {
      case 0:
        exit(1);
        break;
      case 1:
        cout << "Enter a value to push: ";
        cin >> value;
        list->insertBeginning(value);
        break;
      case 2:
        list->removeNode();
        break;
      case 3:
        list->print();
        break;
    }

  } while (choice != 0);

  return 0;

  system("pause");
}
