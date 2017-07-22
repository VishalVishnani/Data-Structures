//This is a basic code which creates a queue FIFO using array

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structure to represent queue*/
struct Queue{
  int front,rear,size;
  unsigned capacity;
  int* array;
};

/*This function creates a queue of given capacity*/
struct Queue* createQueue(unsigned capacity){
  struct Queue* queue=(struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity=capacity;
  queue->front=queue->size=0;
  queue->rear=capacity-1;
  queue->array=(int*)malloc(capacity*sizeof(int));
  
}

/*This function checks if the queue is full*/
int isfull(struct Queue* queue){
  if(queue->capacity==queue->size)
    return 1;
  else
    return 0;
}

/*This function checks if the queue is empty*/
int isempty(struct Queue* queue){
  if(queue->size==0)
    return 1;
  else
    return 0;
}

/*This function adds an element to queue*/
void enqueue(struct Queue* queue,int item){
  if(isfull(queue))
    return;

  queue->rear=(queue->rear+1)%(queue->capacity);
  queue->size=queue->size+1;
  queue->array[queue->rear]=item;
  printf("%d added to queue\n",item);
}

/*This function removes an element from queue and returns it*/
int dequeue(struct Queue* queue){
  if(isempty(queue))
    return;
  int item=queue->array[queue->front];
  queue->front=(queue->front+1)%(queue->capacity);
  queue->size=queue->size-1;
  return item;
}
  
int main(){
  struct Queue* queue=createQueue(100);
  enqueue(queue,10);
  enqueue(queue,20);
  enqueue(queue,30);

  int item=dequeue(queue);
  printf("%d removed from queue\n",item);

}`
