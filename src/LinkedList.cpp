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




///////////////////////////////////////////////////////////
/////////////////////ARRAY ////////////////////////////////
///////////////////////////////////////////////////////////
void print_array(int *arr, int n){
    cout <<"array ";
    for(int i=0;i<n;i++){
        cout << arr[i]<<",";
    }
    cout << endl;
}
int MaxSumOfContiguousArray(int* arr, int n){
    if(n<=0) return 0;
    int global_max = arr[0];
    int cur_max = arr[0];

    cout << endl;
    for(int i=1;i<n;i++){
        cur_max = max(cur_max, cur_max + arr[i+1]);
        global_max = max(global_max, cur_max);
        cout <<"cur max, global max, arr[i] "<< cur_max<<", "<< global_max <<", "<<arr[i]<<endl;
    }
    return global_max;
}

void LinkedList::RunArrayTests(){
    int arr[] = {3,4,-5,6,3,-8};
    //int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n);

    cout << "MaxSumOfContiguousArray :"<< MaxSumOfContiguousArray(arr, n) << endl;
}

