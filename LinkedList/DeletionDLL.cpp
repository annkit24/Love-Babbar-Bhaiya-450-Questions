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
    void deletAtBeg(){
    a* temp=head;
    if(temp==NULL){
        head=NULL;
        return;
    }
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return;
    }
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    free(temp);

}
void deletAtEnd(){
     a* temp=head;
    if(temp==NULL){
        head=NULL;
        return;
    }
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return;
    }
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    a* temp1=temp->next;
    temp->next=NULL;
    temp1->prev=NULL;

    free(temp1);
    
}
void deletInMid(int pos){
      a* temp=head;
    if(temp==NULL){
        
        return;
    }
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return;
    }
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    a* temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;
    temp1->prev=NULL;
    temp1->next=NULL;
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
   deletAtBeg();
    display();
    cout<<endl;
    deletAtEnd();
    display();
     deletInMid(3);
    display();
    return 0;
}
