# Solution hints

### stack
- min stack: use stack<value, min> to keep track of data and current minima, 

### linked list
- cycle in a list: use slow and fast ptrs
- delete given node without head, copy over next to node, create next and node, and use node as prev to delete it, 

### string
- reverse a string without using string functions: push it to a stack, pop and print, 

### binary tree
- countNode() -> count(left) + count(right) + 1;

### binary search tree
- validate: recurse(node, min, max), check if value is within min and max, then recurse recurse(left, min, val) + recurse(right, val, max);

### longest palindromic substring
- for i, max( expandFromMiddle(i,i) and expandFromMiddle(i, i+1), calculate start and end based on len, 

### sums
- two sum: use hash table / sort + two pointer
- three sum: sort, start from left, them perfrom two pointer two sum on remaining items, handle duplicates, 

### stock price
- single pass, keep track of min price or max profit, return max profit, 

### intervals
- Merging internals : sort by start, go over the intervals, keep merging,
- Meeting rooms: map, add +1 when meeting starts, -1 when end, add rooms, and keep track of max, 

### sliding window
- Sliding window: if window is fixed, use for, if window is changine, use for + while;


### linked list
- palindrome: use slow and fast pointer to find mid, reverse 2nd half, traverese and check if  they are equal, othersiwe return false, remember to reverse 2nd half, 
- reverse : use prev, cur, next and 4 steps to reverse, 

### next greatest element
  - start from right
  - use a stack to find next greatest

### Two pointer
  - use for: sorted array, do something upto number n
  - remove unique in place, use slow and fast pointer, and keep shifting left when a duplicate is found
  
### Hints
  - perfect number; num = sum of proper divisor, 28 = 1 + 2 + 4 + 7 + 14, count upto sqrt(n) and add i and num/i
  - broken calculator, *2 or -1, go X->Y; start from Y and go back to X

### Happy number:
    - iterate (sum of sq of digits) = 1, example 25
    - if not a happy number, then it creates a cyclic linked list, use slow / fast pointer,

### Palindrome
    - string that reads same fwd and backwrd
    - use two pointers, start and end 
   
### Anagram 
    - two strings whose characters are jumbled up, 
    - use sorting or hash table to find out if two string has same number of characters, 

### Strobogrammatic number
    - is a number that looks the same when rotated 180 degrees (looked at upside down).


### GCD / LCM : LCM(a,b) = a*b/GCD(a,b)    
    - GCD of array: for(i = 1 .. N) result = gcd(arr[i], result);

### Binomial coefficient
    - C(n, k) = C(n-1, k-1) + C(n-1, k)
    - C(n, 0) = C(n, n) = 1

### String to number
- loop over chars, check if char in set{0,1,...9}, start from right, then add power of 10 

### Median of a series of number: insert(), findMedian()
    create two heaps, 
    push data into a heap, 
    rebalance,
    return average of the top of two heaps, 
    
### Greedy algoritms
    at each step, small local optical choice ir order to get a global optimal solution

### Find top K elements
    - use Heap/ priority queue
    
### Find top K frequent elemennt
    - use haspmap to find freq and priority queue to find top K,

### breadth first search
  - add staring node to a queue, 
  - go through the queue until empty, process each children and add them to the queue, 

### Binary Search Tree
  - The left subtree of a node contains only nodes with keys lesser than the node’s key.
  - The right subtree of a node contains only nodes with keys greater than the node’s key.
  - The left and right subtree each must also be a binary search tree.
  - use inorder traversal to print values in sorted order.
  - can be constructed from pre / post order traversal, 
  - inorder - sorted ascending for BST, 
  
### Greedy algorithm
  - "Find minimum/maximum number of something to do something" - type question
  - need to sort the data based on some criteria - O(nlogn)
  - start finding local minima until global min is found, 

### Dynamic programming
  - [LC](https://leetcode.com/problems/house-robber/) rob house 


### study materials
- [MIT OpenCourse](https://www.youtube.com/watch?v=HtSuA80QTyo)
