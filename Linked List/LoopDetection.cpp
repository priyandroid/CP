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
   /*
   
   Node* reverseAltK(Node*head,int k){
    Node*curr=head,*prev=NULL,*nxt;
    if(head==NULL)
    return head;

     int cnt=0;
     while(curr!=NULL && cnt<k){
       nxt=curr->next;
       curr->next=prev;
       prev=curr;
       curr=nxt;
       cnt++;
     }
     head->next=nxt;
     while(cnt<2*k-1 && nxt!=NULL){
       cnt++;
       nxt=nxt->next;
     }
     if(nxt!=NULL)
      head=nxt;
  head->next=reverseAltK(head->next,k);
  return prev;

   }



Node* SegregateOddEven(Node* head){
 
 Node*end=head,*curr=head;
  int cnt=0,len=0;

  while(end->next!=NULL){
    if(end->val &1)cnt++;
   end=end->next;
   len++;
 }
  if(cnt==len || cnt==0)return head;
  
  Node* curr_end=end,*prev;
  while(curr!= end ){
  
    if(curr->val & 1 ){
       
        if(curr==head){
         head=curr->next;
       }
       else  prev->next=curr->next;
     
     curr_end->next = curr;
     curr=curr->next;
     curr_end->next->next=NULL;
     curr_end=curr_end->next;
     
     
  }
  else{
   prev=curr;
   curr=curr->next;
  }
   
 }

 if(end->val & 1){
   
   prev->next=end->next;
   curr_end->next=end;
   curr_end=curr_end->next;
   curr_end->next=NULL;
 }
 return head;

}

Node* AltOddEven(){
  Node* evenStart=NULL,* evenEnd,* oddStart=NULL,*oddEnd, *temp=head;
  while(temp!=NULL){
    if(temp->val %2==0){

    if(evenStart==NULL)
    {evenStart=temp;
    evenEnd=temp;
    }
    else {evenEnd->next=temp;
    evenEnd=evenEnd->next;
    }
  }

  else{

    if(oddStart==NULL){
    oddStart=temp;
    oddEnd=temp;
    }
    else {
      oddEnd->next=temp;
      oddEnd=oddEnd->next;
    }
  }
  temp=temp->next;
  }

  temp=evenStart;  
  while(evenStart!=NULL){
    Node* p=evenStart->next,*q= oddStart->next;
    evenStart->next=oddStart;
    oddStart->next=p;
    evenStart=p;
    oddStart=q;
  }
  return temp;

  }



Node* deleteAlt(Node* head){
  Node*curr=head->next,*prev=head;

  while(curr!=NULL && prev!=NULL){
    
    prev->next=curr->next;
    free(curr);
    prev=prev->next;
    if(prev!=NULL)
    curr=prev->next;
  }
  return head;
}

void AltSplit(Node** a,Node** b){
Node* temp=head;
*a=temp,*b=temp->next;
Node*e1=*a,*e2=*b;
int t=1;
temp=temp->next->next;
while(temp!=NULL){
  if(t==1){
    e1->next=temp;
    e1=e1->next;
  }
  else 
  {e2->next=temp;
    e2=e2->next;
    }
    t*=-1;
    temp=temp->next;
}
e1->next=NULL,e2->next=NULL;	
}
*/

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