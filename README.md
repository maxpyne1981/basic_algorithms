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
    unique_ptr<>            : exclusive ownership
    shared_ptr<>            : shared ownership, reference counting, 
    weak_ptr<>              : temporary ownership, 
    
    unique_ptr
        std::unique_ptr<int> up1(new int(2011));
        //std::unique_ptr<int> up2 = up1;            // ERROR
        std::unique_ptr<int> up3 = std::move(up1); // OK
    
   std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq)); 
   
   Callables:
        functions foo
        function objects foo()
        lambdas
        
    algorithms:
        execution policy: std::execution::seq, par, par_unseq c++17
        
        
   directive    using namespace std;
   declaration  using std::cout;
   
   new containers:  std::array, std::tuple, 
   libraries:       regex, multithreading
   cpp11:           algo, multithreading, smart pointers
   cpp14:           tuple, 
   cpp17:           std::any, std::optional, std::variant
   
   
   
