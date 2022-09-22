class Node {
  public:
    int value;
    Node* prev = nullptr;
    Node* next = nullptr;

    Node(int value);
};

class DLL {
  public:
    Node* start;

    DLL();
    DLL(Node* node);

    void insertBeginning(int value);

    void insertEnd(int value);

    void removeNode();

    void print();
};
