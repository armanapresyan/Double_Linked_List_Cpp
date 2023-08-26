class Doublelinkedlist{

public:
  Doublelinkedlist(int size, Node* head, Node* tail);
 ~Doublelinkedlist();
  

public:
   void push_front(int value);
   void push_back(int value);
   void insert(int index, int value);
   void remove(int index);
   int get(int index);
   void printList();
   void printReverse();

private:
    struct Node{
         int val;
         Node* next;
         Node* prev;
    };

    int size;
    Node* head;
    Node* tail;
    
};