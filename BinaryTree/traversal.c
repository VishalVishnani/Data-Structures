//This is basic program which creates a binary tree and performs depth first and breadth first traversals

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structure which represents binary tree*/
struct Node{
  int data;
  struct Node* left;
  struct Node* right;
};

/*Function which adds an element to queue for level order traversal*/
void enqueue(struct Node** queue,int* rear,struct Node* new_node){
  queue[*rear]=new_node;
  (*rear)++;

}

/*Function which removes an elemnt from queue for level order traversal*/
struct Node* dequeue(struct Node** queue,int* front){
  (*front)++;
  return queue[(*front)-1];
}

/*Queue created to store nodes of binary tree for level order traversal*/
struct Node** CreateQueue(int* front, int* rear){
  struct Node** queue=(struct Node**)malloc(100*sizeof(struct Node*));
  *front=*rear=0;
  return queue;
}

/*Function which performs level order traversal using queue*/
void LevelOrderQueue(struct Node* node){
  int rear,front;
  struct Node **queue=CreateQueue(&front,&rear);
  struct Node* temp_node=node;

  while(temp_node!=NULL){
    printf("%d ",temp_node->data);

    if(temp_node->left!=NULL)
      enqueue(queue,&rear,temp_node->left);
    
    if(temp_node->right!=NULL)
      enqueue(queue,&rear,temp_node->right);

    temp_node=dequeue(queue,&front);
   }
}

/*Function which finds the height of the tree*/
int height(struct Node* node){
  if(node==NULL)
    return 0;

  int lheight=height(node->left);
  int rheight=height(node->right);

  if(lheight>rheight)
    return lheight+1;
  else
    return rheight+1;

}

/*Function which performs level order traversal*/
void PrintLevelOrder(struct Node* node){
  int length=height(node);
  int i;
  for(i=1;i<=length;i++){
    PrintGivenLevel(node,i);
  }
}

/*Function which prints the nodes at a given level*/
void PrintGivenLevel(struct Node* node, int level){
  if(node==NULL)
    return;
 
  if(level==1)
    printf("%d ",node->data);
  else{
    PrintGivenLevel(node->left,level-1);
    PrintGivenLevel(node->right,level-1);
  }
}
    
/*Function which creates a new node for binary tree*/
struct Node* newNode(int data){
  struct Node* node=(struct Node*)malloc(sizeof(struct Node));
  node->data=data;
  node->left=NULL;
  node->right=NULL;
}

/*Function which performs Post Order Traversal*/
void printPostOrder(struct Node* node){
  if(node==NULL)
    return;
 
  printPostOrder(node->left);
 
  printPostOrder(node->right);

  printf("%d ",node->data);

}

/*Function which performs Pre Order Traversal*/
void printPreOrder(struct Node* node){
  if(node==NULL)
    return;
  
  printf("%d ",node->data);

  printPreOrder(node->left);

  printPreOrder(node->right);
}

/*Function which performs In Order Traversal*/
void printInOrder(struct Node* node){
  if(node==NULL)
    return;

  printInOrder(node->left);
 
  printf("%d ",node->data);

  printInOrder(node->right);
  
}

int main()
{
  struct Node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  
  root->left->left=newNode(4);
  root->left->right=newNode(5);

  printf("Post Order Traversal: ");
  printPostOrder(root);

  printf("\nPre Order Traversal: ");
  printPreOrder(root);  

  printf("\nIn Order Traversal: ");
  printInOrder(root);

  printf("\nHeight of tree is %d ",height(root));

  printf("\nLevel Order Traversal: ");
  PrintLevelOrder(root);

  printf("\nLevel order traversal using queue: ");
  LevelOrderQueue(root);
  return 0;
 
}

