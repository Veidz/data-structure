#include "doubly-linked-list.h"
#include <iostream>
using namespace std;

Node::Node(int value) {
  this->value = value;
}

DLL::DLL() {
  start = nullptr;
}

DLL::DLL(Node* node) {
  start = node;
}

void DLL::insertBeginning(int value) {
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

void DLL::insertEnd(int value) {
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

void DLL::removeNode() {
  if (start == nullptr) {
    cout << "List is empty" << endl;
  } else {
    start = start->next;
  }
}

void DLL::print() {
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
