# C++ notes

### oop

### advanced topics in C++
- base class ptr calls base class method, unless declared virtual,
- if you have a virtual function, add a virtual d'tor

### library methods
- std::numeric_limits<double>::max() //  #include <limits>
- std::numeric_limits<double>::min() //  #include <limits>

### algorithms
- std::for_each(v.begin(), v.end(), lambda_fn);
- std::sort(container.begin(), container.end(), lambda_fn);
- std::reverse(container.begin(), container.end());
- int n = std::count(container.begin(), container.end(), value);
- int n = std::count_if(container.begin(), container.end(), lambda_fn);
- auto last = std::unique(v.begin(), v.end()); v.erase(last, v.end());
- std::copy(from_vector.begin(), from_vector.end(), std::back_inserter(to_vector));
- std::accumulate(first, last, init_value, operator);
- int sum     = std::accumulate(v.begin(), v.end(), 0);                          # use this for an array sum etc
- int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
- std::next_permutation(A.begin(), A.end()) # rearranges data in lexicographical order
- std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq)); 


### search algos
- binary_search(vec.begin(), vec.end(), value); # return true / false
- auto it = lower_bound(vec.begin(), vec.end(), value); # first ocurrance 
- auto it = upper_bound(vec.begin(), vec.end(), value); # one past last ocurrance
- auto pp = equal_range(vec.begin(), vec.end(), value); # both upper and lower bound, 
- auto it = std::find(vec.begin(), vec.end(), value); ;
- find_if(vec.begin(), vec.end(), predicate/lambda); # find first ocurrance
- find_if_not(vec.begin(), vec.end(), predicate/lambda); # find first ocurrance
- search(big.begin(), big.end(), small.begin(), small.end()); # search small container within the big container, 

### count algos
- int n = count(vec.begin(), vec.end(), value); 
- int n = count_if(vec.begin(), vec.end(), predicate/lambda); 

### replace / remove algos
- replace(vec.begin(), vec.end(), fromValue, toValue); 
- replace_if(vec.begin(), vec.end(), is_even<int>, 99); 
- auto it  = remove(vec.begin(), vec.end(), valueToRemove); # use iterator to resize vector
- auto it = remove_if(vec.begin(), vec.end(), is_even<int>, 99);
- auto it = unique(vec.begin(), vec.end());   
   
### modification algorithm
- copy(src.begin(), src.end(), dest.begin());
- copy_n(src.begin(), nItemsToCopy, dest.begin());
- copy_backwards(src.begin(), src.end(), dest.end()); # algo copies from end to start, result same as copy

- reverse_copy(src.begin(), src.end(), dest.begin()); # copies reverse
- reverse(src.begin(), src.end()); # reverses data, uses swap

- fill(src.begin(), src.end()-10, 100); # fills with 100
- fill(src.begin(), src.end()-10, 100); # fills with 100
- generate(v,begin(), v,end(), []()->int {return rand() % 100;});

- random_shuffle(v,begin(), v,end(), []()->int {return rand() % 100;}); # C++17 depricated
- random_shuffle(v,begin(), v,end());

- partition(v.begin(), v.end(), predicate/lambda); # true elemenets moved to front 
- stable_partition(v.begin(), v.end(), predicate/lambda); # true elemenets moved to front in order, slower
- partition_copy(src.begin(), src.end(), partition1.begin(), partition2.begin(), predicate/lambda); # partition then  copies, make use to resize dest vectors

### sorting
- sort(v.begin(), v.end(), comp / lambda);
- bool b = is_sorted(v.begin(), v.end());

### merge
- merge(src1.begin(), src1.end(), src2.begin(), src2.end(), dest.begin()); # src1, src2 needs to be sorted, dest will also be sorted




   

### range based algos
- all_of(vec.begin(), vec.end(), lambda); # returns true is all elements satisfies condition, 
- any_of(vec.begin(), vec.end(), lambda);
- none_of(vec.begin(), vec.end(), lambda);
- all_of(vec.begin(), vec.end(), lambda);


### lambda functions
```
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
}

sort(v.begin(), v.end(), [](const int& a, const int& b) -> bool
    { 
        return a > b; 
    }); 
```

### Syntax
      - [&] : capture all external variable by reference;
      - [=] : capture all external variable by value;
      - [a, &b] : capture a by value and b by reference;
      - A lambda with empty capture clause [ ] can access only those variable which are local to it;

### std::string
   - std::to_string(int) # int to string
   - toupper(char)  returns the uppercase of arg sent toupper('a'); -> 'A'
   - tolower(char)  similar
   - isupper(char)  returns bool: true if uppercase isupper('a'); -> false
   - islower(char)  similar
   - isalpha(char)  similar
   - isdigit(char)  similar
   - ispunct(char)  returns bool: true if punctuation ispunct('!'); -> true
   - isspace(char)  returns bool: true if whitespace – space, newline, tab
   - reverse(str.begin(), str.end()); # reverse a string
   - add char to string, s += c;
   
### tokenize a string
```
   vector<string> split(string path, char delim){
        vector<string> result;
        stringstream ss(path);
        
        string item;
        while (getline (ss, item, delim)) {
            if(!item.empty())
                result.push_back (item);
        }

        return result;
    }
```
   
### containers

### stack and queue
- container adapter
- default: uses deque as underlying container, 
- you can use any container

### std::stack
    - constructor
    - empty()
    - size()
    - top()
    - push()
    - emplace()
    - pop()
    - swap() #fooStk.swap(barStk)

### std::set or std::unordered_set
    - empty()
    - size()
    - max_size()
    - insert()
    - erase()
    - clear()
    - find()
    - count()

    - set is a balanced tree O(log n)
    - unordered_set is a hash table O(1)
    - set<int> s(v.begin(), v.end()); // construct set from vector

### std::map
    - empty()
    - size()
    - insert(std::pair<>)
    - find()
    - clear()
    - emplate()
    - count()
    - *it.first, *it.second or it->first, it->second
    - erase(key)

### std::vector
    - vector<int> v
    - vector<int> v(n, val)
    - vector<int> v(v1.begin(), v1.end())

### std::priority_queue<int>
    - container adapter
    - priority_queue<int> maxHeap;                             // containing first half of numbers
    - priority_queue<int, vector<int>, greater<int>> minHeap;  // containing second half of numbers
    - empty()
    - size()
    - push()
    - pop()

### Heap    
    - vector<int> minHeap(nums.begin(), nums.begin() + k);
    - make_heap(minHeap.begin(), minHeap.end(), greater()); // rearranges elements in heap
    - pop_heap(minHeap.begin(), minHeap.end(), greater()); // does not change size, moves hightest element to last place, use pop_back()
    - minHeap.pop_back();  
    - minHeap.push_back(nums[i]); 
    - push_heap(minHeap.begin(), minHeap.end(), greater()); // heapify the last added element
    - goes together: pop_heap() + pop_back()
    - goes together: push_back() + push_heap()
    - sort_heap() ; // rearranges elements in ascending order, 
    - make_heap(), push_heap(), pop_heap(), sort_heap(), is_heap, is_heap_until()
    

### std::array
```
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
```    

### std::string
    - stoi()
    - stol() etc
    - insert(pos, str, substr, sublen)
    - size(), length()
    - front(), back(), 
    - at[], operator[]
    - str.erase (str.begin()+9); 
    - swap()
    - empty(), clear()
    - str.find_first_not_of(' ');
    
   
   
### How to copy data from one container to another
```
    std::set<string> output;
    std::vector<string> result;   
    result.resize(output.size());
    std::copy(output.begin(), output.end(), result.begin());
```

### <memory> smart ptrs RAII    Resource acquisition is initialization
- unique_ptr<>            : exclusive ownership, get, release, reset, swap, get_deleter
- shared_ptr<>            : shared ownership, reference counting, atomic, large overhead, get, release, swap, unique,
                          use_count, get_deleter
- weak_ptr<>              : temporary ownership, expired, lock, reset, swap,  
                           breaks cycle of shared_ptr

- unique_ptr
    std::unique_ptr<int> up1(new int(2011));
    //std::unique_ptr<int> up2 = up1;            // ERROR
    std::unique_ptr<int> up3 = std::move(up1); // OK
   up3.reset()
   up3.reset(new int(1234));
   up3.release(); only releases from managed memory, 
    std::unique_ptr<int> up = std::make_unique<int>(2014)
- shared_ptr
    uses atomic call to reference counter, hence more overhead,
    auto sharPtr= std::make_shared<SharedInt>(1998);
    
### Callables:
- functions foo
- function objects foo()
- lambdas
  
### algorithms:
- execution policy: std::execution::seq, par, par_unseq c++17
     
### Time library
- Time point
- duration
- clock

### advanced types
- std::any  type safe container for any variable that is copy contructible, any_cast<type>(),  anyVec[0].type().name() 
- std::optional safely return default is quiry fails
- std::variant            

     
### directive
- using namespace std;

### declaration
- using std::cout;

### new containers and libraries
- std::array, std::tuple, 

- libraries:       regex, multithreading
- cpp11:           algo, multithreading, smart pointers
- cpp14:           tuple, 
- cpp17:           std::any, std::optional, std::variant

- iterator with std::advance(it, n)
    auto it = data.begin();
    std::advance(it , n);
 
```
template
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
 
 
// how to use priority_queue
struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };
priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

```


### Advance CPP
- STL: container + iterator + algorithms, 
- sequential container    : vector, array, list
- associative container   : set, map, multimap
- container adapter       : stack, queue, priority_queue
- operators               : extraction >>, insertion << 
- stream                  : stringstream, fstream, 
- threading               : atomic, thread, lock, condition
- preprocessor            : include
- namespace alias         : namespace sysClock= std::chrono::system_clock;
- std::move               : moves data to a new object, faster, cheaper, source goes back to default state
- std::forward            : forward arg in generic templated function (?)
- std::swap               : swaps value of two objets using std::move semantics
- std::bind, function     : create new function object and bind them to a variable, 
- std::pair               : pp.first, pp.second, or std::get<0>(pp), std::get<1>(pp)
- std::tuple              :
