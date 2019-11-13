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

//////////////////////////////////////////
//////////// Bubble Sort /////////////////
//////////////////////////////////////////
void Sort::BubbleSort(int arr[], int n){
    cout << "Bubble sort"<< endl;
    int i, j;
    bool swapped;

    for(i = 0; i<n-1; i++){
        swapped = false;
        for(j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[i], &arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
void Sort::BubbleSort_Recursive(int arr[], int n){
    if(n==1) return;
    for(int i=0; i<n-1; i++){ // push largest element to the end of the array
        if(arr[i] > arr[i+1]){
            swap(&arr[i], &arr[i+1]);
        }

    }
    BubbleSort_Recursive(arr, n-1);
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

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l: left index
// r: right index
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}
/////////////////////////////////////////
//////////// Insertion sort /////////////
/////////////////////////////////////////
void Sort::InsersionSort(int arr[], int n){
    cout << "applying insertion sort "<< endl;

    int i,j;
    int key;

    for(i=1; i<n; i++){
        key = arr[i];   // take an element from 1 to n-1
        j=i-1;          // start the 2nd loop from left of i,
        while(j>=0 && arr[j] > key){ // move left with index j
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
}

/////////////////////////////////////////
//////////// Merge sort /////////////////
/////////////////////////////////////////
void Sort::Run(){
    cout << " Welcome to sort algorithms"<< endl;
    int arr[] = {3,4,-5,6,3,-8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout <<"unsorted array of size "<< n << endl;
    Array::print_array(arr, n);

    //SelectionSort(arr, n);
    //QuickSort(arr, 0, n);
    //mergeSort(arr, 0, n-1);
    //BubbleSort(arr, n);
    //BubbleSort_Recursive(arr, n);
    InsersionSort(arr, n);
    cout <<"sorted array array"<< endl;
    Array::print_array(arr, n);
}


