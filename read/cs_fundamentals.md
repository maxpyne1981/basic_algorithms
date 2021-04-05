# CS Fundamentals

## Time complexity of standard algorithms
### Heap
    - insertion: O(logK)
    - retrieve smallest / largest element O(1)

### Binary search
    - search O(logN)
    
### Array  / linked list
    - insert O(1)
    - search O(N)
    - remove O(N)
    
### Sorted array
    - search O(logN)
    
### Binary search tree
    - insert O(logN)
    - search O(logN)
    - remove O(logN)    
### Trie
    Trie is an efficient information reTrieval data structure.
    M*logN, M = max length of string, N = number of keys
    insert+search O(key_length), however the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) 


    
## Sort
    - O(nlogn)- quicksort, merge sort
    - O(n^2) - selction sort, insertion sort, bubble sort, , space O(1)
### QuickSort
    - pick a pivot, at end, pivot is at the rightplace, left all smaller, right all larger, 
    - time O(nlogn), space O(1)
### BubbleSort
    - push largest elemnt to the right


### multiprocess vs multithread
- ref [blog](https://techdifferences.com/difference-between-multiprocessing-and-multithreading.html)
Multiprocessing can be classified as symmetric multiprocessing and asymmetric multiprocessing. In symmetric multiprocessing, all processors are free to run any process in a system. In Asymmetric multiprocessing, there is a master-slave relationship among the processors. The master processor is responsible for allotting the process to slave processors.

Thread of execution is the smallest sequence of programmed instructions that can be managed independently by scheduler. Thread is a component of process and so multiple threads can be associated in a process. Linux doesn’t have a separate threads per process limit, but has a limit on the total number of processes on the system (as threads just processes with a shared address space on Linux).

In computing, a context switch is the process of storing the state of a process or of a thread, so that it can be restored and execution resumed from the same point later. This allows multiple processes to share a single CPU, and is an essential feature of a multitasking operating system.

### Stack Unwinding in C++
The process of removing function entries from function call stack at run time is called Stack Unwinding. Stack Unwinding is generally related to Exception Handling. In C++, when an exception occurs, the function call stack is linearly searched for the exception handler, and all the entries before the function with exception handler are removed from the function call stack. So exception handling involves Stack Unwinding if exception is not handled in same function (where it is thrown).

### Inline function
The inline functions are a C++ enhancement feature to increase the execution time of a program. Functions can be instructed to compiler to make them inline so that compiler can replace those function definition wherever those are being called.
Inline functions are those functions whose definition is small and can be substituted at the place where its function call is made. Basically they are inlined with its function call.

Compiler interprets the inline keyword as a request to substitute the code of function into its function call. Usually people say that having an inline function increases performance by saving time of function call overhead (i.e. passing arguments variables, return address, return value) but whether an inline function serves your purpose in a positive or in a negative way depends purely on your code design and is largely debatable.

Compiler does inlining for performing optimizations. If compiler optimization has been disabled, then inline functions would not serve their purpose and their function call would not be replaced by their function definition.


### stack vs heap
Stack Allocation : The allocation happens on contiguous blocks of memory. We call it stack memory allocation because the allocation happens in function call stack. The size of memory to be allocated is known to compiler and whenever a function is called, its variables get memory allocated on the stack. And whenever the function call is over, the memory for the variables is deallocated. This all happens using some predefined routines in compiler. Programmer does not have to worry about memory allocation and deallocation of stack variables.
Heap Allocation : The memory is allocated during execution of instructions written by programmers. Note that the name heap has nothing to do with heap data structure. It is called heap because it is a pile of memory space available to programmers to allocated and de-allocate. If a programmer does not handle this memory well, memory leak can happen in the program.



### cpu
- registers: small fast memory, 
- opcode + register code + instruction address register, 
- cpu cycle, fetch , decode, execute, write
- load-a, load-b, store, add, 
- 64 bit registers, 
- 256 bit memory + matrix config + multiplexer, 
- 4 cores , 8 threadfs => 8 logical cores, 
- thredas  > cores, switch context, gives core time to fetch data etc, core works at one thread at a time,   
- 4 core 8 thredas, not parallel, rather concurrant, does switching, appears like a  


### agile
- scope, schedule, resources, quality
- Fixed scope, firm schedule, flexible scope, 



### Vtune amplifier, 
- core, socket, nodes, 
- qopt_report = 5





### ref
1. cpu perf questions [ref](https://www.wisdomjobs.com/e-university/cpu-interview-questions.html)




## OpenMP
- [ref](https://hpc.llnl.gov/openmp-tutorial)
- uniform mempry access / non uniform memory access (numa)
- 
