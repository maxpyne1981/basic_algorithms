#include <iostream>
#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

Trie::Trie()
{
}
Trie::~Trie(){
    ;
}
TrieNode* Trie::createNode(){
    TrieNode* root = new TrieNode();
    return root;
}
void Trie::insert(TrieNode* root, std::string key){
    if(!root) return; // use asert, throw exception, return false, 
    cout << "Trie : inserting : "<< key << endl;
    struct TrieNode* pCrawl = root;

    for(int i=0; i<(int)key.length();i++){
        int index = key[i] - 'a';    
        if(!pCrawl->children[index])
            pCrawl->children[index] = Trie::createNode();
        pCrawl = pCrawl->children[index];
    }
    if(pCrawl)
        pCrawl->bIsEndOfWord = true;
}


//  keep on moving through cildren 
bool Trie::search(struct TrieNode* root, string key){
    if(!root) return false; // use asert, throw exception, return false, 
    cout << "Trie : searching : "<< key << endl;
    struct TrieNode* pCrawl = root;

    for(int i=0; i<(int)key.length();i++){
        int index = key[i] - 'a';    
        if(!pCrawl->children[index]) return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl && pCrawl->bIsEndOfWord);
}

void Trie::Run(){
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };

    int n = sizeof(keys)/sizeof(keys[0]);
    cout << "Trie: size of 1st element : "<< sizeof(keys[0]) << endl;
    cout << "Trie: number of elements : "<< n << endl;

    struct TrieNode *root = Trie::createNode(); 
    cout << "Trie: root : "<< root << endl;
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : cout << "No\n"; 

    clear(root);
}
void Trie::clear(TrieNode* root){
    if(!root) return;
    for(int i=0; i<ALPH_SIZE; i++)
        clear(root->children[i]);
    delete root;
    root = nullptr;
}
