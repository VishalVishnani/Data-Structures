//Single Linked List

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Linkedlist node*/
struct Node{
  int data;
  struct Node* next;
};

/*This function is used to traverse a linkedlist*/
void printlist(struct Node *n){
  while((n)!=NULL){
    printf("%d ",n->data);
    n=n->next;
  }
}

/*This function creates a new head or adds an element at start*/
void addstart(struct Node* new_head,struct Node* head,int value){
  new_head->data=value;
  new_head->next=head;
}

/*This function creates a new end or adds an element to the end*/
void addend(struct Node* head,int value){
  struct Node* end= (struct Node*)malloc(sizeof(struct Node));
  while((head->next)!=NULL){
    head=head->next;
  }
  head->next=end;
  end->data=value;
  end->next=NULL;
}

/*This function adds an element after a particular node*/
void insertbet(struct Node* n,int value){
  struct Node* random=(struct Node*)malloc(sizeof(struct Node));
  random->data=value;
  random->next=n->next;
  n->next=random;
}

/*This function deletes a particular node based on key value*/
void deletenode(struct Node** n1,int key){
  struct Node* n=*n1;
  struct Node* n_prev=NULL;
  if((n->data)==key && n!= NULL){
    *n1=n->next;
    free(n);
    return;
  }

  while((n->data)!=key && n!=NULL){
    n_prev=n;
    n=n->next;
  }
  n_prev->next=n->next;
  free(n);
  
  if(n==NULL)
    return;
}

/*This function deletes the node at a particular position*/
void delete_node_position(struct Node** n1,int position){
  struct Node* n= *n1;
  struct Node* n_prev=NULL;
  if(position==0 && n!=NULL){
    *n1=n->next;
    free(n);
    return;
  }
  int count=0;
  while(n!=NULL && count!=position){
    count++;
    n_prev=n;
    n=n->next;
  }
  if(n==NULL){
    return;
  }

  if(count==position){
    n_prev->next=n->next;
    free(n);
  }
}

/*This function reverses a linked list*/
void reverse(struct Node** n){
  struct Node* current=*n ;
  struct Node* prev=NULL;
  struct Node* ahead=NULL;
  while(current!=NULL){
    ahead=current->next;
    current->next=prev;
    prev=current;
    current=ahead;
  }
  *n=prev;   
}

/*This function rotates the linkedlist left based on given amount*/
void rotate_left(struct Node** n, int position){
  struct Node* n1=*n;
  struct Node* temp=NULL;
  struct Node* temp2=NULL;

  int i;
  for(i=0;i<position;i++){
    temp=n1;
    temp2=n1->next;
    while((n1->next)!=NULL){
      n1=n1->next;
    }
    n1->next=temp;
    n1=n1->next;
    n1->next=NULL;
    n1=temp2;
    *n=temp2;
  }
 
}

/*This function rotates a linked list right by a given amount*/
void rotate_right(struct Node**n,int position){
  struct Node* n1=*n;
  struct Node* temp=NULL;
  struct Node* n2=NULL;
  
  int i;
  for(i=0;i<position;i++){
    temp=n1;
    while((n1->next)!=NULL){
      n2=n1;
      n1=n1->next;
      
    }
    n2->next=NULL;
    n1->next=temp;
    *n=n1;
  }
}

/*This function finds the length of the linked list*/
int find_length(struct Node* n){
  int count=0;
  while(n!=NULL){
    count++;
    n=n->next;
  }
  return count;
}

/*This function swaps two nodes based on the data values*/
void swap_node(struct Node** n,int value1,int value2){
  struct Node* n1=*n;
  struct Node* n2=*n;
  struct Node* temp2=*n;
  struct Node* n3=NULL;
  struct Node* n4=NULL;
  struct Node* temp=NULL;
  while((n1->data)!=value1){
    n3=n1;
    n1=n1->next;
  }
  while((n2->data)!=value2){
    n4=n2;
    n2=n2->next;
  }

  if(n1->data==value1 && n2->data==value2){

    if(n3==NULL){
      *n=n2;
      temp=n2->next;
      n2->next=n1->next;
      n4->next=n1;
      n1->next=temp;
    }
    else if(n4==NULL){
      *n=n1; 
      temp=n1->next;
      n1->next=n2->next;
      n3->next=n2;
      n2->next=temp;
    }
    else{
      n3->next=n2;
      temp=n2->next; 
      n2->next=n1->next;
      n4->next=n1;
      n1->next=temp;
      *n=temp2;
    }
  }

}

int main()
{
  /*Structure Pointers for linked list nodes*/
  struct Node *head=NULL;
  struct Node *second=NULL;
  struct Node *third=NULL;
  struct Node *new_head=NULL;

  /*Dynamic memory allocation*/
  head=(struct Node*)malloc(sizeof(struct Node));
  second=(struct Node*)malloc(sizeof(struct Node));
  third=(struct Node*)malloc(sizeof(struct Node));
  new_head=(struct Node*)malloc(sizeof(struct Node));  

  /*Create linkedlist*/
  head->data=1;
  head->next=second;
  second->data=2;
  second->next=third;
  third->data=3;
  third->next=NULL;

  /*Add an element at start and traverse it to print the linkedlist*/
  addstart(new_head,head,(int)0);
  printf("\nadd start\n");
  printlist(new_head);
  
  /*Add an element at end and traverse it to print the linkedlist*/
  printf("\nadd end\n");
  addend(new_head,(int)4);
  printlist(new_head);
  
  printf("\nInsert in between\n");
  insertbet(second,(int)9);
  printlist(new_head);
  
  printf("\nDelete node\n");
  deletenode(&new_head,(int)0);
  printlist(new_head);
  
  printf("\nlength of list ");
  int count=find_length(new_head);
  printf("%d\n",count);
  
  int position=2;
  printf("deleting node at position %d\n",position);
  delete_node_position(&new_head,position);
  printlist(new_head);
  
  printf("\nafter reversing\n");
  reverse(&new_head);
  printlist(new_head);
  
  int r_left=1;
  int r_right=2;
  printf("\nAfter rotating left by %d\n",r_left);
  rotate_left(&new_head,r_left);
  printlist(new_head);
  printf("\nAfter rotating right by %d\n",r_right);
  rotate_right(&new_head,r_right);
  printlist(new_head);
  
  int value1=2;
  int value2=3;
  printf("\nSwap nodes with values %d and %d\n",value1,value2);
  swap_node(&new_head,value1,value2);
  printlist(new_head);

  return 0;
}

