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


int len(Node* head){
    int x=0;
    while(head!=NULL){
    head=head->next;
    x++;
    }
    return x;
}

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
   int findIntersection(Node* head1,Node* head2){
       int len1=len(head1), len2= len(head2);
     if(len1>len2){
       int k=len1-len2;
       for(int i=0;i<k;i++)
       head1=head1->next;
     }
     else{
       int k=len2-len1;
       for(int i=0;i<k;i++)
       head2=head2->next;
     }
     
     while(head1!=head2 && head1!=NULL && head2!=NULL){
       head1=head1->next;
       head2=head2->next;
     }
  if(head1!= NULL)
  return head1->val;
  return -1;
   }
   
int main(){
LinkedList ll;
ll.insert(1);
ll.insert(2);
ll.insert(3);
ll.insert(4);
ll.insert(5);
ll.insert(6);
ll.insert(7);
LinkedList ll2;
ll2.insert(22);
ll2.insert(13);

ll.head->next->next->next->next=ll2.head->next;
cout<<"List1\n";

print(ll.head);
cout<<"List2\n";

print(ll2.head);
cout<<"Intersection Point : "<<findIntersection(ll.head,ll2.head);
}

