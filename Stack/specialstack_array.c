//Code to create special stack which has getMin function which gives minimum value present in the stack

/*Includes*/
#include <stdio.h>
#include <stdlib.h>

/*Structure to represent stack*/
struct Stack{
  int top;
  unsigned capacity;
  int* array;
};

/*This function creates stack of given capacity*/
struct Stack* Create_Stack(unsigned capacity){
  struct Stack* stack=(struct Stack*)malloc(sizeof(struct Stack));
  stack->top=-1;
  stack->capacity=capacity;
  stack->array=(int*)malloc((stack->capacity)*sizeof(int));
  return stack;
}

/*This function checks if the stack is full*/
int isfull(struct Stack* stack){
  if(((stack->capacity)-1)==(stack->top))
    return 1;
  else
    return 0;
}

/*This function checks if the stack is empty*/
int isempty(struct Stack* stack){
  if((stack->top)==-1)
    return 1;
  else
    return 0;
}

/*This function adds an element to stack*/
void push(struct Stack* stack, struct Stack* stack1,int value){
  if(isfull(stack))
    return;
  
  static int min=100;
  if(isempty(stack)){
    min=value;
    stack->top=stack->top+1;
    stack->array[stack->top]=value;
    stack1->top=stack1->top+1;
    stack1->array[stack1->top]=value;
    printf("%d pushed to stack\n",value);
    printf("%d pushed to stack1\n",value);
  }
  else{
    if(value<min){
      min=value;
      stack->top=stack->top+1;
      stack->array[stack->top]=value;
      stack1->top=stack1->top+1;
      stack1->array[stack1->top]=value;
      printf("%d pushed to stack\n",value);
      printf("%d pushed to stack1\n",value);
    }    
    else{
      stack->top=stack->top+1;
      stack->array[stack->top]=value;
      stack1->top=stack1->top+1;
      stack1->array[stack1->top]=min;
      printf("%d pushed to stack\n",value);
      printf("%d pushed to stack1\n",min);
    }  

  }

}

/*This function removes an element from stack and returns it*/
int pop(struct Stack* stack,struct Stack* stack1){
  if(isempty(stack))
    return;

  int temp=stack->array[stack->top];
  stack->top--;
  stack1->top--;
  return temp;
}

/*This function returns the minimum value present in the stack*/
int getMin(struct Stack* stack1){
  return stack1->array[stack1->top];
}

int main(){
  struct Stack* stack=Create_Stack(100);
  struct Stack* stack1=Create_Stack(100);
  
  push(stack,stack1,10);
  push(stack,stack1,20);
  push(stack,stack1,15);
 
  push(stack,stack1,8);
  int min=getMin(stack1);
  printf("%d is the min value in the stack\n",min);
  
  int temp=pop(stack,stack1);
  printf("%d popped from stack\n",temp);

  min=getMin(stack1);
  printf("%d is the min value in the stack\n",min);

}


