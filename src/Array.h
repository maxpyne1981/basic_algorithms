#pragma once


class Array{
public:
    Array();
    ~Array();

    void Run();
    void print_array(int *arr, int n);
    
private:
    int MaxSumOfContiguousArray(int* arr, int n);
};
