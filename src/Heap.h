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
        while(i!=0 && data[parent(i)] > data[i]){
            swap(&data[i], &data[parent(i)]); 
            i = parent(i);
        }
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

        HeapifyUp(i);
    }

    int extractMin(){
        if(heap_size<=0) 
            return -1; // or INT_MAX 
        if(heap_size==1){
            heap_size = 0;
            return data[0];
        }

        // extract from top, 
        // move last value to the top, 
        // then continue heapify
        int root = data[0];
        data[0] = data[heap_size-1];
        heap_size--;
        HeapifyDown(0);
        return  root;
    }


    /* starting from the root, 
    find index of the smallest child, 
    if the smallest child is smaller than parent, then swap and continue
    */
    void HeapifyDown(int i){
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
            HeapifyDown(smallest); 
        }     
    }

    void print(){
        for(auto i : data)
            std::cout << i << " ";
        std::cout << std::endl;    
    }

    // This function deletes key at index i. It first reduced value to minus
    // infinite, then calls extractMin()
    void deleteKey(int i)
    {
        decreaseKey(i, -1);
        extractMin();
    }


  
    // Decreases value of key at index 'i' to new_val.  It is assumed that 
    // new_val is smaller than data[i]. 
    void decreaseKey(int i, int new_val){
        data[i] = new_val; 
        while (i != 0 && data[parent(i)] > data[i]) 
        { 
            swap(&data[i], &data[parent(i)]); 
            i = parent(i); 
        }  

    }


    ~MinHeap();

    static void Run();
private:
};
