#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H


class Doublelinkedlist{

public:
  Doublelinkedlist();
 ~Doublelinkedlist();
  

public:
   void push_back(int value);
   void push_front(int value);
   void insert(int index, int value);
   void remove(int index);
   int get(int index);
   int get_size();
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

#endif // DOUBLELINKEDLIST_H