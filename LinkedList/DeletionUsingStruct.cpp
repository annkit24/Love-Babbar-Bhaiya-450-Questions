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
 void deleteAtBeg(){
     a* temp=head;
     if(temp==NULL){
         cout<<"Linked List is Empty\n";
         return;
     }
     head=head->next;
     free(temp);
 }
 void deleteAtEnd(){
     a* temp=head;
     if(temp==NULL){
         cout<<"Linked List is Empty\n";
         return;
     }
     if(temp->next==NULL){
         head=NULL;
         free(temp);
         return;
     }
     while(temp->next->next!=NULL){
         temp=temp->next;
     }
     a* temp1=temp->next;
     temp->next=NULL;
     free(temp1);
 }
 void deleteInMid(int pos){

      a* temp=head;
     if(temp==NULL){
         cout<<"Linked List is Empty\n";
         return;
     }
     if(temp->next==NULL){
         head=NULL;
         free(temp);
         return;
     }
     int count=1;
     while(count<pos-1){
         count++;
         temp=temp->next;
     }
     a* temp1=temp->next;
     temp->next=temp1->next;
     free(temp1);

 }
 void display(){
     a* temp;
     temp=head;
     while(temp!=NULL){
         cout<<temp->data<<" ";
         temp=temp->next;
     }
 }

int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
       int data;
        cin>>data;
        insertAtBeg(data);
    }
    display();
    cout<<endl;
    deleteInMid(3);
    display();
    return 0;
}
