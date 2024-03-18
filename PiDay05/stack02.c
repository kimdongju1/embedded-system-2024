/* 연결리스트로 구현 */
#include <stdio.h>
#define STACK_SZ 10

int s[STACK_SZ];
int top = -1;

typedef struct STACK
{
	int buf[STACK_SZ];
	int top;
	
}Stack;

void push(Stack* stack, int value);
int pop(Stack* stack);

void main()
{
	Stack s;
	s.top = -1;

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}

void push(Stack* pstk, int value)
{
	//if(isFull()) printf("stack OF!!"\n);
	//else {
	//	pstk->buf[++(pstk->top)] = value;
	//}
	// ptsk->top = 0;
	if (pstk->top == STACK_SZ - 1) {
		printf("메모리 할당 실패\n");
		return ;
	}
	else {
		pstk->top += 1;
		pstk->buf[pstk->top] = value;
		printf("%d 값이 입력되었습니다\n", pstk->buf[pstk->top]);
	}
}
int pop(Stack * pstk)
{	//if(isEmpty(pstk)) printf("stack UF!!\n");
	//return pstk->buf[(pstk->top)--];
	// pstk->top = -1;
	if (pstk->top == 0)
		{
			printf("Stack underflow!\n");
			return -1;
		}
		else {
			int value;
			value = pstk->buf[pstk->top--];
			return value;
		}
		
}