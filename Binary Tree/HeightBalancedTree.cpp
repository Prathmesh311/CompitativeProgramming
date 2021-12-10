#include<iostream>
#include <cstdlib>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if(d == -1){
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    
    return root;
}

class Pair{
    public:
        int height;
        bool isBalanced;
};

Pair heightBalancedTree(node *root){
    Pair p;
    if(root == NULL){
        p.height = 0;
        p.isBalanced = true;
        return p;
    }

    Pair left = heightBalancedTree(root->left);
    Pair right = heightBalancedTree(root->right);

    if(abs(left.height - right.height) <= 1 && left.isBalanced && right.isBalanced){
            p.isBalanced = true;
    }else{
        p.isBalanced = false;
    }

    p.height = max(left.height, right.height) + 1;
    return p;
}

int main(){
    node* root = buildTree();

    Pair p = heightBalancedTree(root);
    
    if(p.isBalanced){
        cout<<"Tree is height balanced";
    }else{
        cout<<"Tree is not height balanced";
    }

    return 0;
}