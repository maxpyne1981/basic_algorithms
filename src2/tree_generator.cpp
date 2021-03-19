#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <ostream>
#include <unordered_set>
using namespace std;


struct Node{
    Node(int data):val(data),parent(nullptr),children(){;}
    int val; // just for printing values
    Node* parent;
    vector<Node*> children;
};

class Generator{
    unordered_set<string> mTrees;

    public: 
    Generator():mTrees(){;}
    ~Generator(){;}

    void generateTrees(int N, int M);
    static void print(Node*);
    static void printToStr(Node*, string&);

    private:
    bool pushToTree2(Node* root, Node* node, list<Node*>& lNodes, int M, int& treeCount);
    void countLeaves(Node* node, int& count);
    
    // old stuffs
    bool pushToTree(Node* node, list<Node*>& lNodes, int M, int leafCount, int& treeCount);
    vector<Node*> generateChain(int N);
    void recurse(int N, int K, Node* node, int val);
    void generate(int N, int M);
    void generateExact(int N, int M);
};

// post order traversal + print
void Generator::print(Node* node){
    string ss;
    printToStr(node, ss);
    cout << "Tree >>> " << ss << endl;
}
void Generator::printToStr(Node* node, string& ss){
    if(!node) return;
    for(auto& c : node->children)
        printToStr(c, ss);
    ss += to_string(node->val) + ",";
}

void Generator::countLeaves(Node* node, int& count){
    if(!node) return;
    if(node->children.empty()) count++;
    else{
        for(auto& c : node->children)
            countLeaves(c, count);
    }
}

// recurse
bool Generator::pushToTree2(Node* root, Node* node, list<Node*>& lNodes, int M, int& treeCount){
    //cout << "remaining nodes : "<< lNodes.size() << endl;
    if(!node) return false;
    if(lNodes.empty()){
        int leafCount = 0;
        countLeaves(root, leafCount); // O(N), slow, 
        //cout << "# of leaves : "<< leafCount << endl;
        if(leafCount <= M){ 
            string thisTree;
            Generator::printToStr(root, thisTree);
            if(mTrees.find(thisTree) == mTrees.end()){    
                cout << "Tree found, printing: "<< endl;
                cout << "   Uniq tree >>>> "<< thisTree << endl;
                mTrees.insert(thisTree);
                treeCount++;
            }else{
                cout << "same tree revisited. IGNORE."<< endl;
            }
            return true;
        }
        return false;
    }

    // too many redundant recursion trees, speed up
    int childCount = 0;
    while(childCount < lNodes.size()){

        int counter = 0;
        while(counter <= childCount){
            Node* child = lNodes.front();
            lNodes.pop_front();
            node->children.push_back(child);
            counter++;
        }

        for(auto& c : node->children){
            pushToTree2(root, c, lNodes, M, treeCount);
        }

        // backtrack
        counter = 0;
        while(counter <= childCount){
            Node* child = node->children.back(); 
            node->children.pop_back();
            lNodes.push_front(child);
            counter++;
        }
        childCount++;
    }
    return true;
}

void Generator::generateTrees(int N, int M){
    mTrees.clear();
    // create N nodes, 
    list<Node*> lNodes;
    int count = 0;
    while(count < N){
        Node* node = new Node(count);
        lNodes.push_back(node);
        count++;
    }

    // start a tree, start pushing 1, N-1 nodes into the tree, 
    int treeCount = 0;
    Node* root = lNodes.front();
    lNodes.pop_front();
    // recurse and backtrack
    pushToTree2(root, root, lNodes, M, treeCount);
    cout << "number of trees : "<< treeCount << endl;
    // delete nodes to avoid memory leak
}

int main(){
    Generator generator;
    //generator.generateTrees(3,1);
    //generator.generateTrees(4,3);
    //generator.generateTrees(8,5);
    generator.generateTrees(30,3);
    return 0;
}

//////////////////////////////////////////////////////
////////////////// OLD METHODS ///////////////////////
//////////////////////////////////////////////////////
vector<Node*> Generator::generateChain(int N){
    // M = 1, it's a long chain
    Node* root = nullptr;
    Node* curr = nullptr;
    Node* node = nullptr;
    for(int i=0; i<N; i++){
        node = new Node(i);
        if(!root){ root = node;}
        if(!curr){ 
            curr = node;
        }else{
            curr->children.push_back(node);
            node->parent = curr;
            curr = node;
        }
    }
    return {root, curr};
}

void Generator::recurse(int N, int K, Node* node, int val){
    if(N<=0) return;
    for( int i=0; i<min(K, N); i++){
        Node* child = new Node(val++);
        node->children.push_back(child);
        child -> parent = node;
        recurse(N-min(N,K), K, node, val);
    }
}
void Generator::generateExact(int N, int K){
    int val = 0;
    Node* root = new Node(val);
    recurse(N, K, root, val);
    print(root);
    cout << endl;
    //return root;
}

void Generator::generate(int N, int M){
    if(M <= 0) return; // cyclic 
    if(M > N) return;
    
    vector<Node*> vNodes;
    //Node* root; 
    for(int i = 0; i<M; i++){
        generateExact(N, i);
        //print(root)
    }
    //print(root);
    cout << endl;
}

bool Generator::pushToTree(Node* node, list<Node*>& lNodes, int M, int leafCount, int& treeCount){
    cout << "count, leaf "<< lNodes.size() <<", "<< leafCount << endl;
    if(!node) return false;
    if(lNodes.empty()){
        if(leafCount < M){ 
            cout << "Tree is ready, print here" << endl;
            Generator::print(node);
            cout << endl;
            treeCount++;
            return true;
        }
        return false;
    }
    Node* child = lNodes.front();
    lNodes.pop_front();
    cout << "adding child "<< child << endl;

    node->children.push_back(child);
    bool leafAdded = false;
    if(node->children.size() == 1){
        leafCount++;
        leafAdded = true;
    }
    bool state = false;
    for(auto& c : node->children){
        state = pushToTree(c, lNodes, M, leafCount, treeCount);
        if(!state){
            node->children.pop_back();
            lNodes.push_front(child);
            if(leafAdded) leafCount--;
            cout <<"removing child "<< child << endl; 
        }
    }
    return state;
}
