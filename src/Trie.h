#pragma once
#include <string>
#include <unordered_map>

// implemented from geeksforgeek
/*const int ALPH_SIZE = 26;
struct TrieNode{
    struct TrieNode* children[ALPH_SIZE];
    bool bIsEndOfWord;

    TrieNode(){
        for(int i=0; i<ALPH_SIZE; i++) children[i] = nullptr;
        bIsEndOfWord = false;
    }
};*/

struct TrieNode{
    bool bIsEndOfWord;
    std::unordered_map<char, TrieNode*> map;
};

class Trie{
public:
    Trie();
    ~Trie();

    static TrieNode* createNode(){
        TrieNode* node = new TrieNode;
        node->bIsEndOfWord = false;
        return node;
    }

    static void insert(TrieNode*& root, std::string str){
        if(!root) root = createNode();

        TrieNode* temp = root;
        for(int i=0; i<(int)str.length(); i++){
            char c = str[i];
            if( temp->map.find(c) == temp->map.end())
                temp->map[c] = createNode();

            temp=temp->map[c];
        }
        temp->bIsEndOfWord = true;
    }

    
    static bool search(TrieNode* root, std::string key){
        if(!root) return false;
        TrieNode* temp = root;
        for(int i=0; i<(int)key.length(); i++){
            char c = key[i];
            if(!temp->map[c]) return false;
            temp = temp->map[c];
        }
        return temp && temp->bIsEndOfWord;
    }


    /*static void        insert(TrieNode* root, std::string key);
    static bool        search(TrieNode* root, std::string key);
    static void        clear(TrieNode* root);
    static TrieNode*   createNode();
    static bool        isEmpty(TrieNode* root);
    static TrieNode*   remove(TrieNode* root, std::string key, int depth = 0); */
    static void Run();
private:
};
