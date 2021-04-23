# Solution hints

### stack
- min stack: use stack<value, min> to keep track of data and current minima, 

### linked list
- cycle in a list: use slow and fast ptrs
- delete given node without head, copy over next to node, create next and node, and use node as prev to delete it, 
- palindrome: use slow and fast pointer to find mid, reverse 2nd half, traverese and check if  they are equal, othersiwe return false, remember to reverse 2nd half, 
- reverse : use prev, cur, next and 4 steps to reverse, 
- rotate list: calculate length, rotate %= length, connect head to tail, rotate, 
- start of a cycle in a linked list: usual slow / fast ptr to find where they intersect, then start two ptrs from head
  and intersect, move until they meet, that's the beginning of cycle,



### string
- palindrome: string that reads same fwd and backwrd. use two pointers, start and end 
- anagran: two strings whose characters are jumbled up, use sorting or hash table to find out if two string has same number of characters, 
- str to num: loop over chars, check if char in set{0,1,...9}, start from right, then add power of 10 
- reverse a string without using string functions: push it to a stack, pop and print, 
- word ladder: bfs + take each word, for all char, for all alphabate, update one char at a time, if present in the dict, push it in the queue, continue bfs, 
- longest palindromic substring: for i, max( expandFromMiddle(i,i) and expandFromMiddle(i, i+1), calculate start and end based on len, 
- longest substring with K distinct element / fruit in a basket: sliding window + char freq map, keep adding end char,
  when map.size() > K, start shifting start window, remove if count == 0, return length;
- longest substring without repeating chars: (a) map<char, lastpos> + sliding window, if you find a char, check length =
  max(length, right - left + 1), (b) map<char, count>, move left as if you hit repeating char, move left till it is
  gone, take max length
- valid parenthesis string: use two stacks to keep track of "(" and "*" separately, if one is empty, use * to close as
  many ( as possible, 
- min deletion to get good string: all char with diff freq: create char map, go over freqs, check if present in freq set, keep reducing, check again, add it to set if not zero,  
- [largest alphabaric char](https://www.geeksforgeeks.org/find-the-largest-alphabetic-character-present-in-the-string/): 
-  Maximum Length of a Concatenated String with Unique Characters: start from index 0, recurse, use dfs, create all possible string, check if uniq, keep track of maxlenth. Recursion + backtrack;
- backspace + string equivalent: use stack to prune chars in string A and B, check if A == B, 
- almost palindrome: remove each char, if palindrome, return true, else, add back, at the end check if original string
  is palindrome,
- basic calculator: +:1, -:-1; left to right, at ( push sum and sign to stack and evaluate everything inside, then at ) pop stack and sign  

### binary tree
- countNode() -> count(left) + count(right) + 1;
- lowest common ancestor: search for either node, if found, return non null node to parent, if a node gets 2 non null node from two leaves, then it is the LCA.
- count node on a compelet tree: all levels are full, except for the last level where the nodes are pushed to left, find H, count # of nodes upto H-1, run binary search for the last level, check the right most node that exist, (two binary search, one for tree, one for the lowest level) and then add upper count + lower count, 
- minimum depth of a tree: level order, count depth, return when first node whole !left && !right.

### binary search tree
- validate: recurse(node, min, max), check if value is within min and max, then recurse recurse(left, min, val) + recurse(right, val, max);
- The left subtree of a node contains only nodes with keys lesser than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.
- use inorder traversal to print values in sorted order.
- can be constructed from pre / post order traversal, 
- inorder - sorted ascending for BST, 

### sums
- two sum: use hash table / sort + two pointer
- three sum: sort, start from left, them perfrom two pointer two sum on remaining items, handle duplicates, 
- Partition to K Equal Sum Subsets: target = sum / k; create vector<int> v(k), recursively search starting from index 0, for every group, add currEleme, recurse, otherwise remove, continue;

### binary searc
- find range in sorted array: run two binary search to find start and end index of the value, use same helper function
  with a bool flag searchLeft = false. 

### hints for uncommon problems
- stock price: single pass, keep track of min price or max profit, return max profit, 
- Morris number, count and say: 1->11 (one 1) -> 21 (two 1) etc, solve recursively, convert into string, then count
  chars, 
- LRU cache: map<key, list_iterator>, list<vector<key, value>>, reorder the list as the key is polled, erase based on v[0] and v[1].  
- trapping rainwater: use two pointer, strat with lower height, if left < maxLeft, trap water total += maxLeft - left, or update maxLeft, move
  left, 
- robot return to zero: sum(up + down) == 0 && sum(left + right) == 0;  
- wave array : A. O(nlogn) sort and swap pairwise, B. O(n) loop over all even pos elem, compare with prev, compare with next, and swap, 
- # of uniq paths, robot move from TL to BR: use dp grid, cell-ij=sum(up + left), first row/ col all 1, because there is only one way to reach those cells, 

### intervals
- Merging internals : sort by start, go over the intervals, keep merging,
- Meeting rooms: map, add +1 when meeting starts, -1 when end, add rooms, and keep track of max, 
- insert new interval: process all intervals before new.start and after new.end; for intervals start <= new.end, merge all intervals, and push to merged list, 
- only intersect from two lists: use two indices, 

### sliding window
- Sliding window: if window is fixed, use for, if window is changine, use for + while;

### next greatest element
  - start from right
  - use a stack to find next greatest

### subsets 
- sbsets: start with empty set, loop over array, copy data into existing sets, and insert into set
- subset with duplicates: sort, if adding a duplicate, only add it to the sets added in last iteration, otherwise add to all existing sets, 
- permutations: push empty set ino queue, pop each vector, insert new element in all possible places, if size == n, push to result, otherwise, push to queue, 

### heap
- connect ropes: push all lengths into a maxHeap, take top 2, sum , add to result, push result back to the heap, 

### arrays

### Two pointer
  - use for: sorted array, do something upto number n
  - remove unique in place, use slow and fast pointer, and keep shifting left when a duplicate is found
  - Container With Most Water: use two pointer, calculate H and W, vol = max(vol, W*H), move pointer with lower height, 
  
### Hints
  - perfect number; num = sum of proper divisor, 28 = 1 + 2 + 4 + 7 + 14, count upto sqrt(n) and add i and num/i
  - broken calculator, *2 or -1, go X->Y; start from Y and go back to X

### Happy number:
  - iterate (sum of sq of digits) = 1, example 25
  - if not a happy number, then it creates a cyclic linked list, use slow / fast pointer,

### Strobogrammatic number
  - is a number that looks the same when rotated 180 degrees (looked at upside down).

### GCD / LCM : LCM(a,b) = a*b/GCD(a,b)    
  - GCD of array: for(i = 1 .. N) result = gcd(arr[i], result);

### Binomial coefficient
  - C(n, k) = C(n-1, k-1) + C(n-1, k)
  - C(n, 0) = C(n, n) = 1

### Median of a series of number: insert(), findMedian()
   - create two heaps, 
   - push data into a heap, 
    - rebalance,
    - return average of the top of two heaps, 
    
### Greedy algoritms
   - at each step, small local optical choice ir order to get a global optimal solution

### Top K elements
   - use Heap/ priority queue
   - frequent:  use haspmap to find freq and priority queue to find top K,
   - 
### breadth first search
  - add staring node to a queue, 
  - go through the queue until empty, process each children and add them to the queue, 

### Binary Search Tree
  
### Greedy algorithm
  - "Find minimum/maximum number of something to do something" - type question
  - need to sort the data based on some criteria - O(nlogn)
  - start finding local minima until global min is found, 

### Dynamic programming
  - [LC](https://leetcode.com/problems/house-robber/) rob house 


### study materials
- [MIT OpenCourse](https://www.youtube.com/watch?v=HtSuA80QTyo)

### kth largest element
    ```
    int findKthLargest(vector<int>& nums, int k) {
        
        auto f = [](int a, int b){return a > b;};
        priority_queue<int, vector<int>, decltype(f)> queue(f);
        
        for(auto n : nums){
            queue.push(n);
            if(queue.size() > k)
                queue.pop();
        }
            
        return queue.top();
    }
    ```
    
### LCA binary tree
```
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(!node) return nullptr;
        if(node==p || node==q) return node;
        
        TreeNode* fromLeft = lowestCommonAncestor(node->left, p, q);
        TreeNode* fromRight = lowestCommonAncestor(node->right, p, q);
        
        if(fromLeft && fromRight) return node; // LCA found
        if(!fromLeft && !fromRight) return nullptr; // LCA is not in this branch
        
        return fromLeft ? fromLeft : fromRight;
        
    }
```
