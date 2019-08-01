#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
: head(nullptr)
{
    ;
}
LinkedList::~LinkedList(){
    ;
}

void LinkedList::Run(){
    cout << "\nrunning linked list test"<<endl;

    LinkedList l;
    l.append(3);
    l.append(5);
    l.append(7);
    l.append(9);
    l.print();
}

void LinkedList::append(int a){
    Node* node = new Node;
    node->data = a;
    if(!head){ 
        head = node;
        return;
    }
    Node* end = last();
    end->next = node;
}

Node* LinkedList::last(){
    if(!head) return nullptr;
    Node* cur(head);
    while(cur->next)
        cur = cur->next;
    return cur;    
}

void LinkedList::print(){
    cout << "linked list:   ";
    print(head);
    cout << endl;
}
void LinkedList::print(Node* node){
    if(!node) return;
    Node* cur(node);
    while(cur){
        cout << cur->data << ", ";
        cur = cur->next;
    }
}
