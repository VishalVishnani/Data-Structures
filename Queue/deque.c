//This code creates a queue where we can add and remove elements from both rear as well as front

/*Includes*/
#include <stdio.h>
#include <stdlib.h>


/*Structure which represents deque*/
struct deque{
  int *arr;
  int front;
  int rear;
  int size;
  int count;
};

/*Function which checks if the queue is full*/
int isfull(struct deque* q){
  if(q->count==q->size)
    return 1;
  else
    return 0;
}

/*Function which checks if the queue is empty*/
int isempty(struct deque* q){
  if(q->count==0)
    return 1;
  else
    return 0;
}

/*Function which creates a deque*/
struct deque* CreateDeque(int size){
  struct deque *q=(struct deque*)malloc(sizeof(struct deque));
  q->arr=(int*)malloc(size*(sizeof(int)));
  q->front=-1;
  q->rear=0;
  q->count=0;
  q->size=size;
  return q;
}

/*Fucntion which inserts a element at front*/
void InsertFront(struct deque* q,int key){
  if(isfull(q))
    return;
  
  if(q->front==-1)
  {
    q->front=0;
    q->rear=0;
  }
  else if(q->front==0)
    q->front=(q->size)-1;
 
  else
    q->front=(q->front)-1;

  q->arr[q->front]=key;
  
  q->count=(q->count)+1;
  
}

/*Function which inserts an element at rear*/
void InsertRear(struct deque *q,int key){
  if(isfull(q))
    return;

  if(q->front==-1){
    q->front=0;
    q->rear=0;
  }
  else if(q->rear==(q->size)-1){
    q->rear=0;
  }
  else
   q->rear=(q->rear)+1;

  q->arr[q->rear]=key;
  q->count=(q->count)+1;
}

/*Function which removes an element from front*/
int DeleteFront(struct deque* q){
  if(isempty(q))
    return;
  
  int temp;
  if(q->count==1){
    temp=q->front;
    q->front=-1;
    q->rear=-1;
    q->count=(q->count)-1;
    return q->arr[temp];
  }
  else if(q->front==(q->size)-1){
    q->front=0;
    q->count=(q->count)-1;
    return q->arr[(q->size)-1];
  }
  else{
   q->front=(q->front)+1;
   q->count=(q->count)-1;
   return q->arr[(q->front)-1];
  }
}

/*Function which removes an element from rear*/
int DeleteRear(struct deque* q){
  if(isempty(q))
    return;

  int temp;
  
  if(q->count==1){
    temp=q->front;
    q->front=-1;
    q->rear=-1;
    q->count=(q->count)-1;
    return q->arr[temp];
  }
  else if (q->rear==0){
    q->rear=(q->size)-1;
    q->count=(q->count)-1;
    return q->arr[0];
  }
  else{
    q->rear=(q->rear)-1;
    q->count=(q->count)-1;
    return q->arr[(q->rear)+1];
  }
}

/*Function which returns the value at front*/   
int getFront(struct deque* q){
  if(isempty(q))
    return -1;

  return q->arr[q->front];
}

/*Function which returns the value at rear*/
int getRear(struct deque* q){
  if(isempty(q))
    return -1;

  return q->arr[q->rear];
}

int main()
{
  struct deque* q= CreateDeque(100);
  InsertRear(q,10);
  int value1=getFront(q);
  int value2=getRear(q);
  printf("Value at front is %d and at rear is %d\n",value1,value2);
  InsertFront(q,20);
  InsertRear(q,11);
  InsertRear(q,19);
  InsertFront(q,6);
  InsertFront(q,9);
  int value3=DeleteFront(q);
  int value4=DeleteRear(q);
  printf("Value removed from front is %d and rear is %d\n",value3,value4);
  printf("Current count value is %d\n",q->count);
}
