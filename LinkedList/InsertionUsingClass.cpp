#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    } 
};
void InsertAtBeg(node*&head,int data){

    node* n =new node(data);
    n->next=head;
    head=n;
}
int length(node *head){
    int len=0;
    while(head !=NULL){
        ++len;
        head=head->next;
    }
    return len;
}
void insertAtEnd(node*&head,int data){
   node*tail=head;
    node* n =new node(data);
    if(tail==nullptr){
        head=n;
        return;
    }
   
    
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=n;
    
    return;

}
void insertAtmid(node*&head,int d,int p){

     int len=length(head);
    if(head==NULL || p==0){
        InsertAtBeg(head,d);
    }
    else if(p>len){
        insertAtEnd(head,d);
    }
    else{
    int steps=1;
    node*temp=head;
    while(steps<=p-1){
        temp=temp->next;
        steps+=1;
    }

    node*n =new node(d);
    n->next=temp->next;
    temp->next=n;

    }
}
void print(node*head){

    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtEnd(head,1);
    insertAtEnd(head,2);

    insertAtEnd(head,3);
    insertAtEnd(head,4);
    insertAtEnd(head,5);
    insertAtEnd(head,6);
    InsertAtBeg(head,0);
    insertAtmid(head,1,1);


    print(head);
    return 0;
    }
