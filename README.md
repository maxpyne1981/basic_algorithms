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

