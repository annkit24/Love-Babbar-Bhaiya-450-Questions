#include<iostream>
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
void preprint(node*root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preprint(root->left);
    preprint(root->right);
}
void Inprint(node*root){
    if(root==NULL)
        return;
    
    Inprint(root->left);
    cout<<root->data<<" ";
    Inprint(root->right);
}
void Poprint(node*root){
    if(root==NULL)
        return;
    
    Poprint(root->left);
    Poprint(root->right);
     cout<<root->data<<" ";
}
int main(){

    node* root=buildTree();
    preprint(root);
    cout<<endl;
    Inprint(root);
    cout<<endl;
    Poprint(root);
    cout<<endl;
    return 0;
}

/*
INPUT-8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
O/p
pre->in->post

8 10 1 6 9 7 3 14 13 
1 10 9 6 7 8 3 13 14 
1 9 7 6 10 13 14 3 8 


*/
