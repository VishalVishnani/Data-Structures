//This code creates a queue FIFO using linked list

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structure for linked list node*/
struct Qnode{
  int key;
  struct Qnode* next;
};

/*Structure which represents queue*/
struct Queue{
  struct Qnode *front, *rear;
};

/*Function which creates a queue*/
struct Queue* CreateQueue( ){
  struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
  q->front=q->rear=NULL;
  return q;
}

/*Function which creates a linkedlist node for queue*/
struct Qnode* newNode(int k){
  struct Qnode* temp=(struct Qnode*)malloc(sizeof(struct Qnode));
  temp->key=k;
  temp->next=NULL;
  return temp;
}

/*Function which adds an element to queue*/
void enqueue(struct Queue* q,int k){
  struct Qnode* temp=newNode(k);
  
  if(q->rear==NULL){
    q->rear=q->front=temp;
  }

  q->rear->next=temp;
  q->rear=temp;
}

/*Function which removes an element from queue*/
struct Qnode* dequeue(struct Queue *q){
  if (q->front==NULL)
    return NULL;

  struct Qnode* temp=q->front;
  q->front=q->front->next;
 
  if (q->front==NULL)
    q->rear=NULL;

  return temp;
}

int main()
{
  struct Queue* q=CreateQueue();
  enqueue(q,10);
  enqueue(q,20);
  enqueue(q,30);
  struct Qnode* temp=dequeue(q);
  printf("The item removed is %d\n",temp->key);

  temp=dequeue(q);
  printf("The item removed is %d\n",temp->key);
}
