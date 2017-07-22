//Circular LinkedList

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Node*/
struct Node{
  int data;
  struct Node* next;
};

/*This function traverses the linkedlist*/
void printlist(struct Node* n){
  struct Node* temp= n;
  if(n!=NULL) {
    do{
      printf("%d ",n->data);
      n=n->next;
     }
    while(n!=temp);
  }
       
}

/*This function creates a new head node for linkedlist*/
void insert_first(struct Node** n,int value){
  struct Node* n1=*n;
  struct Node* new_head=(struct Node*)malloc(sizeof(struct Node));
  new_head->data=value;
  new_head->next=n1;
  *n=new_head;
  struct Node* temp=n1;

  while((n1->next)!=temp){
    n1=n1->next;
  }
  n1->next=new_head;
}

/*This function creates a new end node for linkedlist*/
void insert_end(struct Node *n,int value){
  struct Node* temp=n;
  struct Node* end= (struct Node*)malloc(sizeof(struct Node));
  end->data=value;
  end->next=temp;
  
  while((n->next)!=temp){
    n=n->next;
  }
  n->next=end;

}

/*This function inserts a new node after a given value*/
void insert_after_value(struct Node* n,int value,int new_value){
  struct Node* temp=n;

  struct Node* temp2= (struct Node*)malloc(sizeof(struct Node));
 
  struct Node* temp3=NULL;
  if(n==NULL)
    return;

  while((n->data)!=value){
    n=n->next;
  }
  temp3=n->next;
  n->next=temp2;
  temp2->data=new_value;
  temp2->next=temp3;
  
}

/*This function inserts a new node at given position*/
void insert_at_position(struct Node** n,int position,int new_value){
  struct Node* n1=*n;
  struct Node* temp=n1;
  struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
  struct Node* temp2=NULL;

  new_node->data=new_value;

  if(position==0){
    insert_first(&n1,new_value);
    *n=n1;
    return;
  }
  
  int length=find_length(n1);
  int count=0;

  if(position<=(length-1)){
    while(count!=position-1){
      n1=n1->next;
      count++;
    } 
    temp2=n1->next;
    n1->next=new_node;
    new_node->next=temp2;
    *n=temp;      

  }
}

/*This function finds the length of linked list*/
int find_length(struct Node *n){
  struct Node* temp =n;
  int length=0;
  if(n==NULL){
    length=0;
  }
  else{
    n=n->next;
    length=1;
  }
  
  while(n!=temp){
    length++;
    n=n->next;
  }
  return length;
}
  
/*This function splits the linkedlistin two halves*/
struct Node* split(struct Node* n){
  int length=find_length(n);
  struct Node* temp=NULL;
  struct Node* temp2=n;
  struct Node* temp3=NULL;

  if(length % 2==0)
    length=length/2;
  else
    length=(length/2)+1;

  int count=0;

  if(length<2)
    return;
 
  while(length!=(count+1)){
    count++;
    n=n->next;
  }

  if(length==(count+1)){
      temp3=n->next;
      n->next=temp2;
  }
  
  struct Node* n2=temp3;

  while((n2->next)!=temp2){
    n2=n2->next;
  }
  n2->next=temp3;

  return temp3;

}


int main()
{

  /*Node pointers and dynamic memory allocation*/
  struct Node* head=(struct Node*)malloc(sizeof(struct Node));
  struct Node* second=(struct Node*)malloc(sizeof(struct Node));
  struct Node* third=(struct Node*)malloc(sizeof(struct Node));

  /*Linkedlist create*/
  head->data=3;
  head->next=second;
  second->data=6;
  second->next=third;
  third->data=9;
  third->next=head;

  printf("\nTraversing the linkedlist\n");
  printlist(head);

  int value1=1;
  printf("\nInserting %d at front\n",value1);
  insert_first(&head,value1);
  printlist(head);

  int value2=2;
  printf("\nInserting %d at end\n",value2);
  insert_end(head,value2);
  printlist(head);

  int length;
  length=find_length(head);
  printf("\nThe length of circulr linkedlist is %d\n",length);

  int value3=9;
  int value4=0;
  printf("\nInserting %d after %d value\n",value4,value3);
  insert_after_value(head,value3,value4);
  printlist(head);

  int value5=5;
  int position=5;
  printf("\nInserting %d at position %d\n",value5,position);
  insert_at_position(&head,position,value5);
  printlist(head);
  
  printf("\nSplitting the circular linkedlist\n");
  struct Node* new_head=split(head);
  printlist(head);
  printf("\n");
  printlist(new_head);  

}


