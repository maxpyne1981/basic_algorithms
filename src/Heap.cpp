#include <iostream>
#include <bits/stdc++.h>
#include "Heap.h"
#include "Array.h"
using namespace std;

MinHeap::~MinHeap(){
    ;
}


/*void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}*/

void MinHeap::Run(){
    cout << "Run: MinHeap example "<< endl;
    MinHeap heap(10);
    heap.insertKey(1);
    heap.insertKey(2);
    heap.insertKey(3);
    heap.insertKey(4);
    heap.insertKey(3);
    heap.print();

    
    /*MinHeap h(11); 
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 

    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); */
}
