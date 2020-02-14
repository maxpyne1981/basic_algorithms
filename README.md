# basic_algorithms
c++ implementations of basic  algorithms



space and time complexity
binary search: time O(logn)




C++/ STL References



Stack
'''
    constructor
    empty()
    size()
    top()
    push()
    emplace()
    pop()
    swap() #fooStk.swap(barStk)
'''


set (unordered_set)
'''
    empty()
    size()
    max_size()
    insert()
    erase()
    clear()
    find()
    count()
'''
* set is a balanced tree O(log n)
* unordered_set is a hash table O(1)
* set<int> s(v.begin(), v.end()); // construct set from vector

map
'''
    empty()
    size()
    insert(std::pair<>)
    find()
    clear()
    emplate()
    count()
    *it.first, *it.second or it->first, it->second
    erase(key)
'''

vector
'''
    vector<int> v
    vector<int> v(n, val)
    vector<int> v(v1.begin(), v1.end())
'''
priority_queue<int>, container adapter
'''
    priority_queue<int> maxHeap;                             // containing first half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;  // containing second half of numbers
    empty()
    size()
    push()
    pop()
    
'''

Array
'''
    int foo[] = { 10, 20, 30 };
    int foo[5];   
    int jimmy [HEIGHT][WIDTH];
        int n,m;

        int main ()
        {
        for (n=0; n<HEIGHT; n++)
            for (m=0; m<WIDTH; m++)
                jimmy[n][m]=(n+1)*(m+1);
        }
        
    function: void printarray (int arg[], int length)
    
    char myword[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char myword[] = "Hello"; 
    
'''

String
''' 
    stoi()
    stol() etc
    insert(pos, str, substr, sublen)
    size(), length()
    front(), back(), 
    at[], operator[]
    str.erase (str.begin()+9); 
    swap()
    empty(), clear()
    str.find_first_not_of(' ');
'''

Time complexity:
'''
Heap
    - insertion: O(logK)
    - retrieve smallest / largest element O(1)

Binary search
    - search O(logN)
    
Array  / linked list
    - insert O(1)
    - search O(N)
    - remove O(N)
    
Sorted array
    - search O(logN)
    
Binary search tree
    - insert O(logN)
    - search O(logN)
    - remove O(logN)    
'''

===========================================================
Algorithms
    std::accumulate(first, last, init_value, operator);
        int sum     = std::accumulate(v.begin(), v.end(), 0);
        int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
Sort
    O(nlogn)- quicksort, merge sort
    O(n^2) - selction sort, insertion sort, bubble sort, , space O(1)
    QuickSort
        - pick a pivot, at end, pivot is at the rightplace, left all smaller, right all larger, 
        - time O(nlogn), space O(1)
    BubbleSort
        - push largest elemnt to the right

===========================================================
Trie
    Trie is an efficient information reTrieval data structure.
    M*logN, M = max length of string, N = number of keys
    insert+search O(key_length), however the memory requirements of Trie is O(ALPHABET_SIZE * key_length * N) 


===========================================================
Time and space complexity

Problems:

Happy number:
    iterate (sum of sq of digits) = 1, example 25
    if not a happy number, then it creates a cyclic linked list, use slow / fast pointer,

Palindrome
    string that reads same fwd and backwrd
    use two pointers, start and end 
   
Anagram 
    two strings whose characters are jumbled up, 
    use sorting or hash table to find out if two string has same number of characters, 

Strobogrammatic number
    is a number that looks the same when rotated 180 degrees (looked at upside down).


GCD / LCM : LCM(a,b) = a*b/GCD(a,b)    
GCD of array: for(i = 1 .. N) result = gcd(arr[i], result);

Binomial coefficient
C(n, k) = C(n-1, k-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1

Median of a series of number: insert(), findMedian()
    create two heaps, 
    push data into a heap, 
    rebalance,
    return average of the top of two heaps, 
    
Greedy algoritms
    at each step, small local optical choice ir order to get a global optimal solution


Warmup questions:
1. string to number: loop over chars, check if char in set{0,1,...9}, start from right, then add power of 10 


Types of problems
    Find top K elements: use Heap/ priority queue
    Find top K frequent elemennt: use haspmap to find freq and priority queue to find top K,



Syntax used for capturing variables :
      [&] : capture all external variable by reference
      [=] : capture all external variable by value
      [a, &b] : capture a by value and b by reference

A lambda with empty capture clause [ ] can access only those variable which are local to it.
Capturing ways are demonstrated below :


CS Basics
    OOP
        The basic OOPS principle are as follows,
        Encapsulation
        Abstraction
        Inheritance
        Polymorphism
        
Advance CPP
    STL: container + iterator + algorithms, 
    sequential container    : vector, array, list
    associative container   : set, map, multimap
    container adapter       : stack, queue, priority_queue
    operators               : extraction >>, insertion << 
    stream                  : stringstream, fstream, 
    threading               : atomic, thread, lock, condition
    preprocessor            : include
    namespace alias         : namespace sysClock= std::chrono::system_clock;
    std::move               : moves data to a new object, faster, cheaper, source goes back to default state
    std::forward            : forward arg in generic templated function (?)
    std::swap               : swaps value of two objets using std::move semantics
    std::bind, function     : create new function object and bind them to a variable, 
    std::pair               : pp.first, pp.second, or std::get<0>(pp), std::get<1>(pp)
    std::tuple              :
    
    <memory> smart ptrs RAII    Resource acquisition is initialization
    unique_ptr<>            : exclusive ownership, get, release, reset, swap, get_deleter
    shared_ptr<>            : shared ownership, reference counting, atomic, large overhead, get, release, swap, unique,
                              use_count, get_deleter
    weak_ptr<>              : temporary ownership, expired, lock, reset, swap,  
    
    unique_ptr
        std::unique_ptr<int> up1(new int(2011));
        //std::unique_ptr<int> up2 = up1;            // ERROR
        std::unique_ptr<int> up3 = std::move(up1); // OK
        std::unique_ptr<int> up = std::make_unique<int>(2014)
    
   std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq)); 
   
   Callables:
        functions foo
        function objects foo()
        lambdas
        
    algorithms:
        execution policy: std::execution::seq, par, par_unseq c++17
        
    shared_ptr
        uses atomic call to reference counter, hence more overhead,
        auto sharPtr= std::make_shared<SharedInt>(1998);

    weak_ptr
        breaks cycle of shared_ptr


    Time library            : Time point, duration, clock

    std::any                : type safe container for any variable that is copy contructible, any_cast<type>(),  anyVec[0].type().name() 
    std::optional           : safely return default is quiry fails
    std::variant            :          

        
   directive    using namespace std;
   declaration  using std::cout;
   
   new containers:  std::array, std::tuple, 
   libraries:       regex, multithreading
   cpp11:           algo, multithreading, smart pointers
   cpp14:           tuple, 
   cpp17:           std::any, std::optional, std::variant
   
   iterator with std::advance(it, n)
       auto it = data.begin();
       std::advance(it , n);
 
references
1. multiprocess vs multithread https://techdifferences.com/difference-between-multiprocessing-and-multithreading.html
Multiprocessing can be classified as symmetric multiprocessing and asymmetric multiprocessing. In symmetric multiprocessing, all processors are free to run any process in a system. In Asymmetric multiprocessing, there is a master-slave relationship among the processors. The master processor is responsible for allotting the process to slave processors.

Thread of execution is the smallest sequence of programmed instructions that can be managed independently by scheduler. Thread is a component of process and so multiple threads can be associated in a process. Linux doesn’t have a separate threads per process limit, but has a limit on the total number of processes on the system (as threads just processes with a shared address space on Linux).

In computing, a context switch is the process of storing the state of a process or of a thread, so that it can be restored and execution resumed from the same point later. This allows multiple processes to share a single CPU, and is an essential feature of a multitasking operating system.

Stack Unwinding in C++
The process of removing function entries from function call stack at run time is called Stack Unwinding. Stack Unwinding is generally related to Exception Handling. In C++, when an exception occurs, the function call stack is linearly searched for the exception handler, and all the entries before the function with exception handler are removed from the function call stack. So exception handling involves Stack Unwinding if exception is not handled in same function (where it is thrown).

inline function
The inline functions are a C++ enhancement feature to increase the execution time of a program. Functions can be instructed to compiler to make them inline so that compiler can replace those function definition wherever those are being called.
Inline functions are those functions whose definition is small and can be substituted at the place where its function call is made. Basically they are inlined with its function call.

Compiler interprets the inline keyword as a request to substitute the code of function into its function call. Usually people say that having an inline function increases performance by saving time of function call overhead (i.e. passing arguments variables, return address, return value) but whether an inline function serves your purpose in a positive or in a negative way depends purely on your code design and is largely debatable.

Compiler does inlining for performing optimizations. If compiler optimization has been disabled, then inline functions would not serve their purpose and their function call would not be replaced by their function definition.


stack vs heap
Stack Allocation : The allocation happens on contiguous blocks of memory. We call it stack memory allocation because the allocation happens in function call stack. The size of memory to be allocated is known to compiler and whenever a function is called, its variables get memory allocated on the stack. And whenever the function call is over, the memory for the variables is deallocated. This all happens using some predefined routines in compiler. Programmer does not have to worry about memory allocation and deallocation of stack variables.
Heap Allocation : The memory is allocated during execution of instructions written by programmers. Note that the name heap has nothing to do with heap data structure. It is called heap because it is a pile of memory space available to programmers to allocated and de-allocate. If a programmer does not handle this memory well, memory leak can happen in the program.


template
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
 
 
 // how to use heap
vector<int> minHeap(nums.begin(), nums.begin() + k);
make_heap(minHeap.begin(), minHeap.end(), greater());
pop_heap(minHeap.begin(), minHeap.end(), greater());
minHeap.pop_back();
minHeap.push_back(nums[i]);
push_heap(minHeap.begin(), minHeap.end(), greater());
    
// how to use priority_queue
struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };
priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;
