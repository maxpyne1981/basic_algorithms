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
    static void print(Node* node);

    static Node* reverse(Node* head);
    
    Node* head;
};
