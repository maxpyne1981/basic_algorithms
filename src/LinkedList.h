#pragma once

struct Node{
    Node* next;
    int data;
};

class LinkedList{
public:
    LinkedList();
    ~LinkedList();

    void Run();
    void RunArrayTests();

    void append(int a); 
    Node* last();
    void print();
    void print(Node* node);
    
    Node* head;
};
