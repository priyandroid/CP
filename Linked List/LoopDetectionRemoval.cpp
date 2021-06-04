#include<bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node* next;
  Node(int val){
    this->val=val;
    next=NULL;
  } 
};
 

struct LinkedList{
  Node*head;
  LinkedList(){
    head=NULL;
  }
   void insert(int val){
     Node* curr= new Node(val);
     if(head==NULL)
      head=curr;
      else{
        Node* tp=head;
        while(tp->next!=NULL){
          tp=tp->next;
        }
        tp->next= curr;
      }
    
   }
   
};




 void print(Node* p){
    if(p==NULL)
    {cout<<"No element in list\n";
    return;
    }
     Node* curr=p;
     while(curr!=NULL){
       cout<<curr->val<<" ";
       curr=curr->next;
     }
     cout<<"\n";
   }
   

void removeLoop(Node* p,Node* head){
    Node* loop_node,*curr=head;
    while(1){
        loop_node=p;
        while(loop_node->next!=p && loop_node->next!=curr){
        
        loop_node=loop_node->next;
        }
        if(loop_node->next==curr)
        break;
        curr=curr->next;
    }
   
      
   loop_node->next=NULL;
}

void DetectRemoveLoop(Node* head){
  Node *slow=head ,*fast = head;
  while(slow && fast && fast->next ){
     
     slow=slow->next, fast =fast->next->next;
     
     if(slow==fast){
     cout<<"Loop Detected\n";
       removeLoop(slow,head);
       
       return;
    }
  }
  cout<<"Loop not present";

}
   
   
int main(){
LinkedList ll;
ll.insert(1);
ll.insert(2);
ll.insert(3);
ll.insert(4);
ll.insert(5);


cout<<"List wihout loop : \n";
print(ll.head);
//deleteList(&ll.head);
(ll.head)->next->next->next->next->next=(ll.head)->next;
DetectRemoveLoop(ll.head);
print(ll.head);
return 0;
}