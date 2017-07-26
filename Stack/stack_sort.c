//Sorting a stack such that top contains the greatest element

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
void push(struct Stack* stack,int value){
  if(isfull(stack))
    return;
  stack->top=stack->top+1;
  stack->array[stack->top]=value;
  printf("%d pushed to stack\n",value);
}

void sort(struct Stack* stack){

  if((stack->top)<1)
    return;
  
  int i,j;
  int temp;

  
  for(i=0;i<(stack->top);i++){
    for(j=0;j<(stack->top)-i;j++){
      if(stack->array[j]<stack->array[j+1]){
        temp=stack->array[j+1];
        stack->array[j+1]=stack->array[j];
        stack->array[j]=temp; 
      }
    }
  }
}
  
/*This function removes an element from stack and returns it*/
int pop(struct Stack* stack){
  if(isempty(stack))
    return;

  int temp=stack->array[stack->top];
  stack->top--;
  return temp;
}

int main(){
  struct Stack* stack=Create_Stack(100);
  
  push(stack,7);
  push(stack,2);
  push(stack,8);
  push(stack,5);
  push(stack,3);
 
  sort(stack);  

  int temp=pop(stack);
  printf("%d popped from stack\n",temp);
 
  temp=pop(stack);
  printf("%d popped from stack\n",temp);

  temp=pop(stack);
  printf("%d popped from stack\n",temp);

  temp=pop(stack);
  printf("%d popped from stack\n",temp);

  temp=pop(stack);
  printf("%d popped from stack\n",temp);

}


