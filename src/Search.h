#pragma once
#include "LinkedList.h"

class Search{
public:
    Search();
    ~Search();

    void Run();
    static int BinarySearch(int* arr, int start, int end, int what);
    static int ExponentialSearch(int* arr, int n, int what);

    static bool SublistSearch(Node* first, Node* second);
};
