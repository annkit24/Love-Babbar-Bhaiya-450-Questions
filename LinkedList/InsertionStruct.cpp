#include<iostream>
using namespace std;
typedef struct a{
    int data;
    struct a* next;
}a;
 a* head=NULL;

 void insertAtBeg(int data){

     a* nn=new a;
     nn->data=data;
     nn->next=head;
     head=nn;

 }
 void insertAtEnd(int data){
     a* nn =new a;
     nn->data=data;
     nn->next=NULL;

     a* temp=head;
     if(temp==NULL){
         head=nn;
         return;
     }
     while(temp->next!=NULL){
         temp=temp->next;
     }
     
     temp->next=nn;
 }
 void display(){
     a* temp;
     temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
 }
 void insertAtMid(int pos,int data){
     a* temp=head;
     a* nn = new a;
     nn->data=data;
     nn->next=NULL;
     if(temp==NULL){
         head=nn;
         return;
     }
     int count=1;
     while(count<pos && temp->next!=NULL){
         count++;
         temp=temp->next;
     }
    if(temp->next==NULL){
        temp->next=nn;
        return;
    }
    nn->next=temp->next;
    temp->next=nn;

 }

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       int data;
        cin>>data;
        insertAtEnd(data);
    }
    display();
    cout<<endl;
    int pos;
    cin>>pos;
    int data;
    cin>>data;
    insertAtMid(pos,data);
    display();
    return 0;
}
