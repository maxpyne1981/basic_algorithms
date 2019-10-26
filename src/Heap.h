#pragma once


class MinHeap{
    std::vector<int> data;
    int capacity;
    int heap_size;
    void swap(int* x, int* y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
public:
    MinHeap(int capacity){
        heap_size = 0;
        this->capacity = capacity;
        data = std::vector<int>(capacity, 0);
        std::cout << "a min heap is created with capacity "<< capacity << std::endl;
    }


    int parent(int i)   {return (i-1)/2;}
    int left(int i)     {return 2*i+1;}
    int right(int i)    {return 2*i+2;}

    void insertKey(int key){
        if(heap_size == capacity) 
            return;

        heap_size++;
        int i = heap_size -1;
        data[i] = key;


        while(i!=0 && data[parent(i)] > data[i]){
            swap(&data[i], &data[parent(i)]); 
            i = parent(i);
        }
    }

    int extractMin(){
        if(heap_size<=0) 
            return -1; // or INT_MAX 
        if(heap_size==1){
            heap_size = 0;
            return data[0];
        }

        int root = data[0];
        data[0] = data[heap_size-1];
        heap_size--;
        MinHeapify(0);
        return  root;
    }

    void MinHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap_size && data[l] < data[i]) 
            smallest = l;
        if(r < heap_size && data[r] < data[smallest]) 
            smallest = r;
        if (smallest != i) 
        { 
            swap(&data[i], &data[smallest]); 
            MinHeapify(smallest); 
        }     
    }

    void print(){
        for(auto i : data)
            std::cout << i << " ";
        std::cout << std::endl;    
    }

    


    ~MinHeap();

    static void Run();
private:
};
