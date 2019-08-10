#include <iostream>
#include "Array.h"
using namespace std;

Array::Array()
{
    ;
}
Array::~Array(){
    ;
}

void Array::print_array(int *arr, int n){
    cout <<"array ";
    for(int i=0;i<n;i++){
        cout << arr[i]<<",";
    }
    cout << endl;
}

int Array::MaxSumOfContiguousArray(int* arr, int n){
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

void Array::Run(){
    int arr[] = {3,4,-5,6,3,-8};
    //int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n);

    cout << "MaxSumOfContiguousArray :"<< MaxSumOfContiguousArray(arr, n) << endl;
}

