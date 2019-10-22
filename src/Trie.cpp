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
/*TrieNode* Trie::createNode(){
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
bool Trie::isEmpty(TrieNode* root){
    if(!root) return true;
    for(int i=0;i<ALPH_SIZE; i++)
        if(root->children[i]) return false;
    return true;
}

void Trie::clear(TrieNode* root){
    if(!root) return;
    for(int i=0; i<ALPH_SIZE; i++)
        clear(root->children[i]);
    delete root;
    root = nullptr;
}

TrieNode* Trie::remove(TrieNode* root, std::string key, int depth){
    if(!root) return nullptr;
    
    // start deleting from end
    // if processing last char of string key
    if(depth == (int)key.size()){
        
        // not end of the word any more
        if(root->bIsEndOfWord)
            root->bIsEndOfWord = false;

        //if it is not a prefix of any other word, then delete
        if(isEmpty(root)){
            delete root;
            root = nullptr;
        }
        return root;
    }


    // if not the last char, recur
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if(isEmpty(root) && !root->bIsEndOfWord){
        delete root;
        root = nullptr;
    }
    return root;
}*/

///////////////////////////////////////
////////////// RUN ////////////////////
///////////////////////////////////////
void Trie::Run(){
    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane" };


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
    search(root, "hero")? cout << "Yes\n" : cout << "No\n"; 
    search(root, "heri")? cout << "Yes\n" : cout << "No\n"; 

    //remove(root, "heroplane"); 
    //search(root, "hero") ? cout << "Yes\n" : cout << "No\n"; 
    //clear(root);
}
