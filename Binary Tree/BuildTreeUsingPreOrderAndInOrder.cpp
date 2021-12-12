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

void bfs(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* p = q.front();
        q.pop();

        if(p == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{

            cout<<p->data<<" ";

            if(p->left){
                q.push(p->left);
            }

            if(p->right){
                q.push(p->right);
            }
        }
    }
}


node* buildTreeUsingPreOrderAndInOrder(int *pre, int *in, int start, int end){
    static int i = 0;

    //Base Case
    if(start > end){
        return NULL;
    }

    //Recursive Case
    node* root = new node(pre[i]);

    int index = -1;
    for(int j = start; j <= end; j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;

    root->left = buildTreeUsingPreOrderAndInOrder(pre, in, start, index-1);
    root->right = buildTreeUsingPreOrderAndInOrder(pre, in, index+1, end);

    return root;

}

int main(){
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int n = sizeof(in)/sizeof(int);

    node* root = buildTreeUsingPreOrderAndInOrder(pre, in, 0, n-1);

    bfs(root);

    return 0;
}