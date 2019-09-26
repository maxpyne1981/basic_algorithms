#pragma once


////////////  Binary search tree //////////////////
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int key;
};

class BST{
public:
    BST();
    ~BST();

    void insert(int key);
    void delete_tree();
    //void deletenode(int key);
    TreeNode* search(int key);

    int height();
    
    // dfs
    void preorder();
    void inorder();
    void postorder();

    // bfs
    void levelorder();
    void levelorder_q();

    static void Run();
private:
    TreeNode* root;
    TreeNode* insert(TreeNode* node, int n);
    void delete_tree(TreeNode* node);
    //TreeNode* deletenode(TreeNode* node, int n);
    TreeNode* search(TreeNode* node, int key);
    int height(TreeNode* node);
   
    //dfs 
    void preorder(TreeNode* node);
    void inorder(TreeNode* node);
    void postorder(TreeNode* node);


    // bfs
    void levelorder(TreeNode* node, int level);
    void levelorder(TreeNode* node);
};
