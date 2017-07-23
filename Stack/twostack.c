//This program creates two stacks in an array

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structure to represent two stacks*/
struct twostack{
 int top1,top2;
 int size;
 int *arr;
};

/*Function which creates two stacks*/
struct twostack* CreateStack(int size){
  struct twostack* stack=(struct twostack*)malloc(sizeof(struct twostack));
  stack->top1=-1;
  stack->size=size;
  stack->top2=size;
  stack->arr=(int*) malloc(size*sizeof(int));
  return stack;
}

/*Function which performs push operation for stack 1*/
void push1(struct twostack* stack,int key){
  if(stack->top1<stack->top2){
    stack->top1=stack->top1+1;
    stack->arr[stack->top1]=key;
  }
}

/*Function which performs push operation for stack 2*/
void push2(struct twostack* stack,int key){
  if(stack->top1<stack->top2){
    stack->top2=stack->top2-1;
    stack->arr[stack->top2]=key;
  }
}

/*Function which performs pop operation for stack 1*/
int pop1(struct twostack* stack){
  if(stack->top1>=0){
    int x=stack->arr[stack->top1];
    stack->top1=stack->top1-1;
    return x;
  }
}

/*Function which performs pop operation for stack 2*/
int pop2(struct twostack* stack){
  if(stack->top2<stack->size){
    int x=stack->arr[stack->top2];
    stack->top2=stack->top2+1;
    return x;
  }
}

int main(){
  struct twostack* stack=CreateStack(5);
  push1(stack,2);
  push2(stack,3);
  push2(stack,5);
  int value1=pop2(stack);
  push1(stack,1);
  push2(stack,10);
  push1(stack,7);

  int i;
  printf("The stack elements are : \n");
  for(i=0;i<5;i++){
    printf("%d ",stack->arr[i]);
  }
}

