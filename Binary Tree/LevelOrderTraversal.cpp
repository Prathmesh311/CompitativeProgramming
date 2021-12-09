#include<iostream>
#include<queue>
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

void bfs(node* root){
    queue<node*> q;       //make queue for node address
    q.push(root);

    while (!q.empty())
    {
        //pop node from front and print data
        node* p = q.front();   

        if(p == NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else
        {
            cout<<p->data<<" ";
            q.pop();
            
            //push childs of node in queue
            if(p->left){
                q.push(p->left);
            }
            if(p->right){
                q.push(p->right);
            }
        }
    }
}


int main(){
    node* root = buildTree();

    bfs(root);

    return 0;
}