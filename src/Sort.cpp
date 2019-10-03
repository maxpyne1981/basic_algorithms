#include <iostream>
#include <bits/stdc++.h>
#include "Sort.h"
#include "Array.h"
using namespace std;

Sort::Sort()
{
    ;
}
Sort::~Sort(){
    ;
}


void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//////////// Selection Sort //////////////////
/*
1. loop over every element
2. find the smallest element in the remaining sub array
3. replace with ith element 
4. keep repeating
*/
void SelectionSort(int arr[], int n){
    cout << "selection sort"<<endl;
    
    int min_idx(0);
    for(int i=0; i<n-1; i++){
        min_idx = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}
//////////////////////////////////////////
//////////// Quick Sort //////////////////
//////////////////////////////////////////
// start with last element and then try to place it to the correct place
// https://www.geeksforgeeks.org/quick-sort/
int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i  = low -1;
    for(int j=low; j < high-1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }

    }
    swap(&arr[i+1], &arr[high]); // placing pivot at the right place
    return i+1;
}
void QuickSort(int arr[], int low, int high){
    cout << "Running quicksort"<< endl;
    if(low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}   
//////////////////////////////////////////
//////////// Merge Sort //////////////////
//////////////////////////////////////////
void Merge(int arr[], int low, int mid, int high){
    //cout << "Merge in merge sort"<< endl;
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    
    // create two temp arrays
    int L[n1], R[n2];

    for(i=0; i<n1; i++)
        L[i] = arr[low + i];

    for(j=0; j<n2; j++)
        R[j] = arr[ mid + 1 + j];

    // now sort and merge
    i = 0; j = 0; k = 0;
    while( i < n1 && j < n2){
        if( L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 

}
void MergeSort(int arr[], int low, int high){
    //cout << "Running Merge sort"<< endl;
    if(low < high){
        int mid = low + (high-low)/2;

        MergeSort(arr,  low,     mid);
        MergeSort(arr,  mid+1,   high);

        Merge(arr, low, mid, high);
    }
}   


//////////// Run tests //////////////////
void Sort::Run(){
    cout << " Welcome to sort algorithms"<< endl;
    int arr[] = {3,4,-5,6,3,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<"unsorted array of size "<< n << endl;
    Array::print_array(arr, n);

    //SelectionSort(arr, n);
    //QuickSort(arr, 0, n);
    MergeSort(arr, 0, n-1);
    cout <<"sorted array array"<< endl;
    Array::print_array(arr, n);
}


