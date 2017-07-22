//Double Linked List

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Node*/
struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

/*This function traverses the linkedlist*/
void printlist(struct Node* n){
  while(n!=NULL){
    printf("%d ",n->data);
    n=n->next;
  }
}

/*This funstion finds the length of linkedlist*/
int find_length(struct Node* n){
  int count=0;
  while(n!=NULL){
    count++;
    n=n->next;
  }
  return count;
}

/*This function creates a new head node for linkedlist*/
void insert_start(struct Node** n,int value){
  struct Node* n1=*n;
  struct Node* new_head=(struct Node*)malloc(sizeof(struct Node));
  new_head->data=value;
  new_head->prev=NULL;
  new_head->next=n1;
  n1->prev=new_head;
  *n=new_head;  
}

/*This function creates a new end node for linkedlist*/
void insert_end(struct Node* n,int Value){
  struct Node* end=(struct Node*)malloc(sizeof(struct Node));
  if(n==NULL)
    return;
  while((n->next)!=NULL){
    n=n->next;
  }
  end->data=Value;
  end->prev=n;
  end->next=NULL;
  n->next=end;

}

/*This function inserts a new node after a given value*/
void insert_after_value(struct Node* n,int value, int new_value){
  struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
  new_node->data=new_value;
 
  while((n->data)!=value){
    n=n->next;  
  }
  new_node->next=n->next;
  new_node->prev=n;
  n->next=new_node;
  
}

/*This function adds a new node at given position*/
void insert_at_position(struct Node** n,int position,int new_value){
  struct Node *n1=*n;
  struct Node *temp=n1;
  struct Node* n_prev=NULL;
  struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
  new_node->data=new_value;
  if(position==0){
    insert_start(&n1,new_value);
    *n=n1;
     return;
  }
  int length1=find_length(n1);
  int count=0;
  if(position<=(length1-1)){

    while(count!=(position)){
      n_prev=n1;
      n1=n1->next;
      count++;
    } 
    new_node->next=n1;
    new_node->prev=n1->prev;
    n1->prev=new_node;
    n_prev->next=new_node;
    *n=temp;  
  } 
}


int main()
{
  /*Node pointers and dynamic memory allocation*/
  struct Node* head=(struct Node*)malloc(sizeof(struct Node));
  struct Node* first=(struct Node*)malloc(sizeof(struct Node));
  struct Node* second=(struct Node*)malloc(sizeof(struct Node));
 
  /*Linkedlist create*/
  head->data=2;
  head->prev=NULL;
  head->next=first;
  first->data=4;
  first->prev=head;
  first->next=second;
  second->data=6;
  second->prev=first;
  second->next=NULL;

  printf("\nTraversing the double linkedlist\n");
  printlist(head);

  int length=find_length(head);
  printf("\nThe length of the double linkedlist is %d\n",length);

  int value1=8;
  printf("\nInserting %d at start\n",value1);
  insert_start(&head,value1);
  printlist(head);

  int value2=1;
  printf("\nInserting %d at end\n",value2);
  insert_end(head,value2);
  printlist(head);
  
  int value3=4;
  int new_value=3;
  printf("\nInserting %d after value %d\n",new_value,value3);
  insert_after_value(head,value3,new_value);
  printlist(head);

  int value4=7;
  int position=2;
  printf("\nInserting value %d at position %d\n",value4,position);
  insert_at_position(&head,position,value4);
  printlist(head);
}

