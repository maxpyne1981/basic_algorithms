#include <iostream>
#include <bits/stdc++.h>
#include "BST.h"
#include "Array.h"
using namespace std;

BST::BST()
: root(nullptr)
{
    ;
}
BST::~BST(){
    delete_tree();
}
void BST::insert(int key){
    root = insert(root, key);
}

TreeNode* BST::insert(TreeNode* node, int key){
    if(!node){
        node = new TreeNode();
        node->key = key;
    }
    if(key < node->key)
        node->left = insert(node->left, key);
    if(key > node->key)
        node->right =  insert(node->right, key);
    return node;
}
void BST::delete_tree(){
    delete_tree(root);
}
void BST::delete_tree(TreeNode* node){
    if(!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    cout <<"deleting node "<< node->key<<endl;
    delete node;
    node = nullptr;
}
/*
void deletenode(int key){
    deletenode(root, key);
}
TreeNode* deletenode(TreeNode* node, int key){
    if(!node) return node;
    if(key < node->key) 
        node->left = deletenode(node->left);
    if(key > node->key) 
        node->right = deletenode(node->right);


    // fun stuff    
    if(key == node->key){

        if(node->left == nullptr){
            TreeNode* tmp = node->right;
            delete node;
            return tmp;
        }
        if(node->right == nullptr){
            TreeNode* tmp = node->left;
            delete node;
            return tmp;
        }

        TreeNode* tmp = FindMinValue(node, right);
        node->key = temp->key;
        node->right = deletenode(node->right, tmp->key);
    }
    return node;
}
*/
TreeNode* BST::search(int key){
    return search(root, key);
}
TreeNode* BST::search(TreeNode* node, int key){
    if(!node || node->key==key) return node;
    if( key < node->key)
        return search(node->left, key);
    if( key > node->key)
        return search(node->right, key);
    return nullptr;
}
int BST::height(){
    return height(root);
}
int BST::height(TreeNode* node){
    if(!node) return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return max(lh, rh) + 1;
}
void BST::preorder(){
    cout << "preorder ";
    preorder(root);
    cout << endl; 
}
void BST::inorder(){
    cout << "inorder ";
    inorder(root);
    cout << endl; 
}
void BST::postorder(){
    cout << "postorder ";
    postorder(root);
    cout << endl; 
}
void BST::preorder(TreeNode* node){
    if(!node) return;
    cout << node->key<<", ";
    preorder(node->left);
    preorder(node->right);
}
void BST::inorder(TreeNode* node){
    if(!node) return;
    inorder(node->left);
    cout << node->key<<", ";
    inorder(node->right);
}
void BST::postorder(TreeNode* node){
    if(!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->key<<", ";
}
void BST::levelorder(){
    cout << "level order ";
    for(int i= 1; i<=height(); i++){
        levelorder(root, i);
        cout << "\n";
    }
    cout << endl; 
}
void BST::levelorder(TreeNode* node, int level){
    if(!node) return;
    if(level==1){
        cout << node->key <<", ";
    }
    if(level>1){
        levelorder(node->left, level-1);
        levelorder(node->right, level-1);
    }
}
void BST::levelorder_q(){
    cout << "level order using queue ";
    levelorder(root);
    cout << endl;
}

// level order using q
void BST::levelorder(TreeNode* node){
    if(!node) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        if(node)
            cout<<node->key<<", ";
         q.pop();

         if(node->left) q.push(node->left);
         if(node->right) q.push(node->right);
    }
}


//////////// Run tests //////////////////

void BST::Run(){
    cout << " Welcome to BST algorithms"<< endl;
    BST* tree = new BST;
    int arr[] = {4,5,8,23,4,56,6,8,89,0,3,44};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        tree->insert(arr[i]);
    cout <<"search 7 "<< tree->search(7)<<endl;
    cout <<"height "<< tree->height()<<endl;

    tree->preorder();
    tree->inorder();
    tree->postorder();
    tree->levelorder();
    tree->levelorder_q();

    delete tree;
}


