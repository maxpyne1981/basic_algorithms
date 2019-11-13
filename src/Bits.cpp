#include <iostream>
#include <bits/stdc++.h>
#include "Bits.h"
using namespace std;

Bits::Bits()
{
    ;
}
Bits::~Bits(){
    ;
}

// show bytes, 
typedef unsigned char *pointer;
void show_bytes(pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("0x%p\t0x%.2x\n",
                start+i, start[i]);
    printf("\n");
}


void print_bits(int n){
    if(n>1) 
        print_bits(n/2);
    cout << n%2;    
}
int countBits_(int n){
    int c(0);
    while(n){
        if(n&1) c++;
        n >>= 1; // devide
    }
    return c;
}



void Bits::Run(){
    cout << " Welcome to bits manipulation"<< endl;
    int i = 16;
    cout << "i = "<< i << endl;

    i = i << 2;
    cout << "i << 2  = "<< i << endl;

    i = i >> 2;
    cout << "i >>  2  = "<< i << endl;
    
    int a = 15213;
    printf("int a = 15213;\n");
    show_bytes((pointer) &a, sizeof(int));

    print_bits(8);
    cout << endl;

    print_bits(1024);
    cout << endl;
}

