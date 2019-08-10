#include <iostream>
#include "Search.h"
using namespace std;

Search::Search()
{
    ;
}
Search::~Search(){
    ;
}

int Search::BinarySearch(int* arr, int start, int end, int what){
    if(end < start) return -1;
    int mid = start + (end - start)/2;
    cout << "mid "<< mid << endl;
    if(arr[mid] ==  what) return mid;

    if(what < arr[mid]) return BinarySearch(arr, start, mid-1, what);
    return BinarySearch(arr, mid+1, end, what);
}

int Search::ExponentialSearch(int* arr, int n, int what){
    if( arr[0] == what) return 0;

    // get rid of k elements where arr[k] < what
    int i=1;
    while(i < n && arr[i] <= what)
        i = i*2;
    
    return BinarySearch(arr, i/2, min(i,n), what);

}
bool Search::SublistSearch(Node* first, Node* second){
    Node* ptr1 = first;
    Node* ptr2 = second;

    // both lists are empty
    if(first == nullptr && second == nullptr)
        return true;
   
    // if one is empty and not other then false
    if( (first == nullptr && second != nullptr) || (first != nullptr && second == nullptr) )
        return false;


    while(second != nullptr){
        ptr2 = second;

        while(ptr1!=nullptr){
            if( ptr2 == nullptr){ 
                return false;
            }else if(ptr1->data==ptr2->data){
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }else{
                break;
            }
        }
        // exhausted first list
        if(ptr1==nullptr)
            return true;

        ptr1=first;
        second=second->next;
    }
    return false;
}
void Search::Run(){


    // array search
    int arr[] = {1,2,3,4,5,6,7,8,10,11,12,13,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Binary search:         "<< BinarySearch(arr, 0, n-1, 4)            << endl;
    cout << "Exponential search:    "<< ExponentialSearch(arr, n, 12)         << endl;

    // linkedlist search
    LinkedList* list1 = new LinkedList();
    LinkedList* list2 = new LinkedList();

    list1->append(3);
    list1->append(4);
    list2->append(0);
    list2->append(1);
    list2->append(2);
    list2->append(3);
    list2->append(4);

    cout << "Sublist search (list1 in list2):    "<< SublistSearch(list1->head,list2->head)         << endl;
}

