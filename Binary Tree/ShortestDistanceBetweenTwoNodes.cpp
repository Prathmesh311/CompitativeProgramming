#include<iostream>
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


node* lowestCommonAncestor(node* root, int p, int q) {
        //Base Case
        if(root == NULL){
            return NULL;
        }
        
        //Recursive Case
        //if node found return
        if(root->data == p || root->data == q){
            return root;
        }
        
        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);
        
        //If nodes found in left and right subtree return currrent root (it's LCA)
        if(left != NULL && right != NULL){
            return root;
        }
        
        //If node found in only left or right subtree return it;
        if(left != NULL){
            return left;
        }
        return right;
}

int search(node* root, int key, int level){
    if(root ==NULL){
        return -1;
    }

    if(root->data == key){
        return level;
    }

    int left = search(root->left, key, level+1);
    if(left!=-1){
        return level;
    }

    return search(root->right, key, level+1);
    
}

int distanceBetweenNodes(node* root, int p, int q){
    node* LCA = lowestCommonAncestor(root, p, q);
    
    cout<<"LCA "<<LCA->data;
    int l1 = search(LCA, p, 1);
    int l2 = search(LCA, q, 1);

    return l1+l2;
}

int main(){
    node* root = buildTree();
    int p, q;
    cin>>p;
    cin>>q;

    int distance = distanceBetweenNodes(root, p, q);
    cout<<"Distance between two nodes :"<<distance;
    
    return 0;
}
