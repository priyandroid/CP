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

Node* rec_reverse(Node *p){

  if(p==NULL || p->next==NULL)
  return p;
  Node*rest= rec_reverse(p->next);
  p->next->next=p;
  p->next=NULL;
  
  return rest;

}

int len(Node* head){
  Node* temp=head;
  int x=0;
  while(temp!=NULL){
temp=temp->next;
x++;
  }
  return x;
}

 void print(Node* p){
    if(p==NULL)
    {cout<<"No element in list";
    return;
    }
     Node* curr=p;
     while(curr!=NULL){
       cout<<curr->val<<" ";
       curr=curr->next;
     }
     cout<<"\n";
   }


void isPalindrome(Node* head,int n){
  Node*p=head,*temp=head;
  int i=0,flag=0;
  while(i<((n-1)/2)){
    p=p->next;
    i++;
  }

Node*q=p->next;
p->next=NULL;
q=rec_reverse(q);
Node* r=q;
while(q!=NULL){
  if(temp->val!=q->val){
    flag=1;
    break;
  }
  temp=temp->next;
  q=q->next;
}
r=rec_reverse(r);
p->next=r;
if(flag==1)
cout<<"Not a Palindrome";
else cout<<" List is a Palindrome";

}

void deleteList(Node** head){
  if(head==NULL)
  cout<<"Error :List is empty !!";

  while(head!=NULL){
    Node* p=head;
    
    head=head->next;
    free(p);
  }
}

bool loopDetection(Node* head){
  Node *slow,*fast;
  while(head!=NULL && head->next!=NULL ){
    slow=head, fast =head->next->next;
    if(slow==fast)
    return true;
  head=head->next;
  }
  return false;
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
ll.insert(7);
ll.insert(8);
ll.insert(1);
Node* p=ll.head;
cout<<"Original list : \n";
print(ll.head);
if(loopDetection(ll.head))
cout<<"Loop Detected !!\n";
else cout<<"No loop present !!\n";
return 0;
}
