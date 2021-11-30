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


void inOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    node* root = buildTree();

    cout<<"InOrder: ";
    inOrderTraversal(root);

    cout<<endl<<"PostOrder";
    postOrderTraversal(root);

    return 0;
}