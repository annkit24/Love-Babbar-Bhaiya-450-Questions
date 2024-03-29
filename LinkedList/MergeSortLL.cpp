 Node* merge(Node* l1,Node* l2){
        
        
        if(!l1)  
        return l2;
        if(!l2) 
        return l1;
        
        if(l1->data < l2->data){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast!=NULL ){
        
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        Node* newHead=slow->next;
        slow->next=NULL;
        
        return merge(mergeSort(head),mergeSort(newHead));
    }
