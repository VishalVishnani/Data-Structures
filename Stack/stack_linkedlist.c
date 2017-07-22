//This is a basic code which creates stack LIFO using linkedlist

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structure used to represent stack*/
struct StackNode{
  int data;
  struct StackNode *next;
};

/*This function creates a new node for stack including the head node*/
struct StackNode* newNode(int value){
  struct StackNode* stacknode=(struct StackNode*)malloc(sizeof(struct StackNode));
  stacknode->data=value;
  stacknode->next=NULL;
  return stacknode;
}

/*This function checks if the stack is empty*/
int isempty(struct StackNode *root){
  if(root==NULL)
    return 1;
  else
    return 0;  
}

/*This function adds an element to stack*/
void push(struct StackNode **root, int data){
  struct StackNode* stacknode=newNode(data);
  stacknode->next=*root;
  *root=stacknode;
  printf("%d pushed to stack\n",data);
}

/*This function removes an element from stack and returns it*/
int pop(struct StackNode **root){
  if(isempty(*root))
    return;

  int data=(*root)->data;
  struct StackNode* temp=*root;
  *root=(*root)->next;
  free(temp);
  return data;
}
 
int main()
{
  struct StackNode* root=NULL;
  
  push(&root,10);
  push(&root,20);
  push(&root,30);

  int popped=pop(&root);
  printf("%d popped from stack\n",popped);
}
