/* 배열로 구현 */
#include <stdio.h>

#define STACK_SZ 10
#define TRUE 1
#define FALSE 0

int stack[STACK_SZ];
int top = -1;
void push();
int pop();

void main()
{
	push(3);
	push(5);
	push(10);

	printf("%d\n", pop());
	printf("%d\n", pop());

}

int isFull()
{
	if (top == STACK_SZ - 1)
	{
	
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int data)
{
	//if(top == STACK_SZ -1)
	//{
	if(isFull())
	{
		printf("stack overflow!!\n");
		return;

	}
	stack[++top] = data;

}

int isEmpty()
{
	if (top <= -1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int pop()
{
	//if (top == -1)
	//{
	if(isEmpty())
	{
		printf("stack underflow!!\n");
		return -1;
	}
	return stack[top--];
	//top--;

}