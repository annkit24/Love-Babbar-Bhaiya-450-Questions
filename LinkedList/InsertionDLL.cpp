#include<iostream>
using namespace std;
typedef struct a{
    int data;
    struct a* next;
    struct a* prev;
    
}a;
 a* head=NULL;

    void insertAtBeg(int data){
        
        a* nn=new a;

        if(head==NULL){
            nn->data=data;
            nn->next=NULL;
            nn->prev=NULL;
            head=nn;
            return;
        }
        nn->data=data;
        nn->next=head;
        nn->prev=NULL;
        head->prev=nn;
        head=nn;
    }
    void insertAtEnd(int data){

        a* nn=new a;
        a* temp=head;
        if(temp==NULL){
            insertAtBeg(data);
            return;
        }

        while(temp->next!=NULL){
            temp=temp->next;
        }
        nn->data=data;
        nn->next=NULL;
        temp->next=nn;
        nn->prev=temp;


    }
    void insertInMid(int pos,int data){
         a* nn=new a;
         nn->data=data;
         nn->next=NULL;
         nn->prev=NULL;

        a* temp=head;
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
            nn->prev=temp;
            return;
        }
       
        nn->next=temp->next;
        nn->prev=temp;
        temp->next->prev=nn;
        temp->next=nn;
        return;
    
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
    insertInMid(6,9);
    display();
    return 0;
}
