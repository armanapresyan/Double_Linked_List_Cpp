#include "doublelinkedlist.h"
#include <iostream>

Doublelinkedlist::Doublelinkedlist() : size(0), head(nullptr), tail(nullptr) {}

Doublelinkedlist::~Doublelinkedlist() {
    while (head != nullptr) {
        Node* temp = head;  
        head = head->next;  
        delete temp;  
    }
}


void Doublelinkedlist::push_back(int elem) {
     Node* node = new Node();
     node->val = elem;
     if(head == nullptr){
        head = node;
        tail = node;
     }else{
        tail->next = node;
        node->prev = tail;
        tail = node;
     }
   

     ++size;
     
}

void Doublelinkedlist::push_front(int elem) {
    Node* node = new Node();
    node->val = elem;
    node->next = head; 
    node->prev = nullptr;
    head->prev = node;
    head = node;
    ++size;

}


int Doublelinkedlist::get_size(){
    return size;
}



void Doublelinkedlist::insert(int index, int value) {
    if(index == 0){
        push_front(value);
    }else if(index == size - 1){
        push_back(value);
    }else if(index > 0 && index < size){
      
       Node* node = new Node();
       node->val = value;
       Node* current = head;
       
       for(int i = 0; i < index - 1; ++i){
          current = current->next;
       }
        node->prev = current;
        node->next = current->next;
        current->next = node;
        current->next->prev = node;
        ++size;
    }else{
        std::cout<<"Invalid index"<<std::endl;
    }

}

void Doublelinkedlist::remove(int index) {
    
    if(index == 0){
       Node* first = head;
       first->next->prev = nullptr;
       head = first->next;
       delete first;
       --size;
    }else if(index == size - 1){
        Node* last = tail;
        last->prev->next = nullptr;
        tail = last->prev;
        delete last;
        --size;
    }else if(index > 0 && index < size){
      
       Node* current = head;
       
       for(int i = 0; i < index; ++i){
          current = current->next;
       }
       current->prev->next = current->next;
       current->next->prev = current->prev;
       delete current;
       --size;
    }else{
        std::cout<<"Invalid index"<<std::endl;
    }
}


int Doublelinkedlist::get(int index) {
    Node* current = head;
    for(int i = 0; i < index; ++i){
        current = current->next;
    }
    return current->val;
}




void Doublelinkedlist::printList() {
      while(head != nullptr){
        std::cout<<head->val<<" ";
        head = head->next;
      }

}

void Doublelinkedlist::printReverse() {
    while(tail != nullptr){
        std::cout<<tail->val<<" ";
        tail = tail->prev;
    }
}

