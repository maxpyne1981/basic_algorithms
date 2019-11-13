#include <iostream>
#include "LinkedList.h" 
#include "Array.h" 
#include "Search.h" 
#include "Bits.h" 
#include "Sort.h" 
#include "BST.h" 
#include "Graph.h" 
#include "Algo.h" 
#include "Trie.h" 
#include "Heap.h" 


#include <utility>
void move_semantics(){
    std::vector<int> myBigVec(10000000, 2011);
    std::vector<int> myVec;

    std::cout << "size before move: source "<< myBigVec.size() <<", dest "<< myVec.size()<<std::endl;
    //myVec = myBigVec;             // copy semantic
    myVec = std::move(myBigVec);  // move semantic
    std::cout << "size after move: source "<< myBigVec.size() <<", dest "<< myVec.size()<<std::endl;
}


int main(){

    move_semantics();

    // linked list
    //LinkedList linkedlist;
    //linkedlist.Run();

    // array
    //Array arr;
    //arr.Run();


    // search
    //Search search;
    //search.Run();


    //Bits bits;
    //bits.Run();

    //Sort sort;
    //sort.Run();

    //BST::Run();

    //Graph::Run(); 

    //Algo algo;
    //algo.Run();

    //Trie::Run();

    //MinHeap::Run();

    //Sudoku sudoku;
    //sudoku.Run();

    //KSRecursive ks;
    //ks.Run();

    //Steps st;
    //st.Run();

    return 0;
}

