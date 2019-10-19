#pragma once
#include <string>

// implemented from geeksforgeek
const int ALPH_SIZE = 26;
struct TrieNode{
    struct TrieNode* children[ALPH_SIZE];
    bool bIsEndOfWord;

    TrieNode(){
        for(int i=0; i<ALPH_SIZE; i++) children[i] = nullptr;
        bIsEndOfWord = false;
    }
};

class Trie{
public:
    Trie();
    ~Trie();


    static void        insert(TrieNode* root, std::string key);
    static bool        search(TrieNode* root, std::string key);
    static void        clear(TrieNode* root);
    static TrieNode*   createNode();
    static bool        isEmpty(TrieNode* root);
    static TrieNode*   remove(TrieNode* root, std::string key, int depth = 0); 
    static void Run();
private:
};
