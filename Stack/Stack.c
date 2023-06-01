#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE    10u
#define EMPTY_STACK 0u
 typedef  float StackEntry ;
 
 typedef struct 
 {
	int top;
	int size;
	StackEntry* EntryArray;
 }Stack;

 void stackCreate(Stack *ps,int Size)
 {
	ps->top=0;	
	ps->size=Size;
	ps->EntryArray=(StackEntry *)calloc(ps->size,sizeof(StackEntry));
 }
 
  void stackClear(Stack *ps)
 {
	ps->top=0;	
 }
 
 void stackPush(StackEntry pushedElement,Stack *ps) //you must check if the stack is created(that top=0)
 {
	if(ps->top <ps->size)
	{
		ps->EntryArray[ps->top]=pushedElement;
		ps->top ++;		
	}
 }
 
 void stackPop(StackEntry *popedElement,Stack *ps)
 {
	if(ps->top >= EMPTY_STACK)
	{
		ps->top --;
		*popedElement = ps->EntryArray[ps->top];

	}
 }
 
 void stackTop(StackEntry *topElement,Stack *ps)
 {
	if(ps->top >= EMPTY_STACK)
	{
	*topElement= ps->EntryArray[ps->top-1];
	}
 }
 
 int stackSize(Stack *ps)
 {
	return ps->top;
 }
 
 int stackIsFull(Stack *ps)
 {
	char IsFull=0;
	if(ps->top == ps->size)
	{
		IsFull=1;
	}
	return IsFull; 
 }
 
 int stackIsEmpty(Stack *ps)
 {
		char IsEmpty=0;
	if(ps->top == EMPTY_STACK )
	{
		IsEmpty=1;
	}
	return IsEmpty; 
 }
 
 
 void stackTraverse(Stack *ps, void(*pfunc)(StackEntry* stackElement))
 {
	for(int i=ps->top;i>0;i--)
	{
		(pfunc)(&(ps->EntryArray[i-1]));
	}
 }
 
 void Increment(StackEntry* stackElement)
 {
	(*stackElement)++;
	
 }
 
 void Display(StackEntry* stackElement)
 {
	printf("Element %f \n",*stackElement);	
 }
 
 void TopofStack(Stack *ps,StackEntry* topElement)
 {
	stackPop(topElement,ps);
	stackPush(*topElement,ps);	
 }
 
 int main(void)
 {
	Stack s;
	int Stack_s_size=10;
	float topElement,x;
	stackCreate(&s,Stack_s_size); 
	for(char i=10;i<(s.size)+10;i++)
	{
		stackPush(i,&s);
	}
	printf("Using Stack function to know top of stack value\n");

	stackTop(&x,&s);
	printf("Stack Top : %f\n",x);
		
	printf("Using user-defined function to know top of stack value\n");

	TopofStack(&s, &topElement);
	printf("Stack Top : %f\n",topElement);
	
	printf("Using StackTraverse function with Display function to print Stack without affecting Stack size\n");
	stackTraverse(&s,Display);
		
	printf("Using Stack Size function to prove that stack size wasn't changed\n");
	x=stackSize(&s);
	printf("\n Stack Size : %f\n",x);
	
	printf("Using StackTraverse function with Increment function to Increment stack elemnts by 1\n");
	stackTraverse(&s,Increment);
	
	printf("Using Stack function to prove that size of stack wasn't changed but only the value increased by traverse function\n");
	stackTop(&x,&s);
	printf("Stack Top : %f\n",x);
	
	for(char i=0;i<s.size;i++)
	{
		float a;
		stackPop(&a,&s);
		printf("Pop Stack Element %d: %f \n",s.size-i-1,a);
	}
		
	printf("Using Stack Size function to show stack size after poping all its elements \n");
	x=stackSize(&s);
	printf("Stack Size : %f\n",x);

	return 0;
 }