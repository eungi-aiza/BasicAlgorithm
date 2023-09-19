#include <stdio.h>
#include <stdlib.h>

/* A structure to represent a stack */
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
 
/* Function to create a stack of given capacity. 
   It initializes size of stack as 0  */
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
 
/* Function to check if the stack is full
   Stack is full when top is equal to the last index  */
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

/* Function to check if the stack is empty
   Stack is empty when top is equal to -1  */
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
/* Function to add an item to stack. It increases the value of top by 1
   If stack is full, it does not add any value to stack */
void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
 
/* Function to remove an item from stack. 
   It returns top element and decreases the value of top by 1 
   If stack is empty, it just returns '0'  */
char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return '0';
    return stack->array[stack->top--];
}
// 3번문제 코드
int main(int argc, char* argv[])
{  

  /* Variable for storing parentheses  */
  char* strInput = argv[1];
  /* Variable for final return value. 0 on success, -1 on failure */
  int success = 0; 

  /* Write your code here */
  char cid[] = "{[(*)]}";
  int stk[1000], para[1000], len=0, pos, i;

  while(strInput[len]) {
    for (pos=0; pos<7; pos++)
      if (cid[pos] == strInput[len]) break;
    para[len++] = pos-3;
  }
  
  pos = 0;
  for (i=0; i<len; i++) {
    if (para[i]<0) {
      stk[pos++] = para[i];
    }
    else {
      pos--;
      if (pos<0) {
        success = -1;
        break;
      }
      if (stk[pos] != -para[i]) {
        success = -1;
        break;
      }
    }
  }
  if (pos) success = -1;
  
	/* Do not modify below */	
  printf("%d\n", success);

  return 0;

}
