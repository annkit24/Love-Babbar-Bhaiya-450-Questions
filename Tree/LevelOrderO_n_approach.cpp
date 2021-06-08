#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* buildTree(){
    int d;
    cin>>d;
    node* root;
    if(d==-1){
        return NULL;
    }
    root=new node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
int height(node * root){
    if(root==NULL){
        return 0;
    }
    int ls=height(root->left);
    int rs=height(root->right);
    return max(ls,rs)+1;
}
void printKthLevel(node* root,int k){
 if(root==NULL){
     return;
 }   
 if(k==1){
     cout<<root->data<<" ";
     return;
 }
 printKthLevel(root->left,k-1);
 printKthLevel(root->right,k-1);
 
}
void printAllLeve(node *root){
    int H=height(root);
    
    for(int i=1;i<=H;i++){
        printKthLevel(root,i);
        cout<<endl;
    }
    return;
}
void bfs(node *root){
    queue<node*> q;
    q.push(root);
    
    while(q.empty()==false){
        node* f=q.front();
        cout<<f->data<<" ";
        q.pop();
        
        if(f->left){
            q.push(f->left);
        }
          if(f->right){
            q.push(f->right);
        }
    }
    return;
}
int main(){

    node* root=buildTree();
 //   printAllLeve(root);
 bfs(root);
    return 0;
}
/*
INPUT:8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
O/P:8 10 3 1 6 14 9 7 13 

*/
