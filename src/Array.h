#pragma once


class Array{
public:
    Array();
    ~Array();

    void Run();
    static void print_array(int *arr, int n);
    
private:
    int MaxSumOfContiguousArray(int* arr, int n);
};
