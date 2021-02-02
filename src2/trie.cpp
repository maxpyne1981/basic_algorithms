#include <vector>
#include <iostream>
using namespace std;


struct Node{
    bool isEnd;
    vector<Node*> data;

    Node(): isEnd(false){
        data.resize(26);
    }
};

class Trie{
    Node* root;
public:
    Trie();
    ~Trie();
    void insert(string word);
    bool search(string word);
    bool prefix(string word);
};

Trie::Trie(){
    root = new Node();
}

Trie::~Trie(){
    cout << "to be implemented "<< endl;
}
void Trie::insert(string word){
    Node* curr = root;
    for(auto c : word){
        if(!curr->data[c-'a']){
            curr->data[c-'a'] = new Node;
        }
        curr = curr->data[c-'a'];
    }
    curr->isEnd = true;
}

bool Trie::search(string word){
    Node* curr = root;
    for(auto c : word){
        if(!curr->data[c-'a']) return false;
        curr = curr->data[c-'a'];
    }
    return curr->isEnd;
}

bool Trie::prefix(string word){
    Node* curr = root;
    for(auto c : word){
        if(!curr->data[c-'a']) return false;
        curr = curr->data[c-'a'];
    }
    return true;
}

int main(){

    Trie trie;
    trie.insert("apple");
    cout << "search apple:      "<< (trie.search("apple") ? "true ":"false")        << endl;;
    cout << "search applegate:  "<< (trie.search("applegate") ? "true ":"false")    << endl;
    cout << "search app:        "<< (trie.search("app")    ? "true ":"false")       << endl;;
    cout << "prefix apple:      "<< (trie.prefix("apple") ? "true ":"false")        << endl;;
    cout << "prefix applegate:  "<< (trie.prefix("applegate") ? "true ":"false")    << endl;
    cout << "prefix app:        "<< (trie.prefix("app")    ? "true ":"false")       << endl;;


    return 0;
}
