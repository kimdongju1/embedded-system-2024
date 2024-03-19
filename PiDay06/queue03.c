/* 연결자료구조를 이용한 큐 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE* link;
}node;	// 연결 리스트 갖추기 위한 구조체
typedef struct
{
	node* front;
	node* rear;

}linkQ;	// 큐 형태 갖추기 위한 구조체

linkQ* createLinkQ();
void enQueue(linkQ* alq, int data);
int deQueue(linkQ* alq);
void printQ(linkQ* alq);


void main()
{
	linkQ* q = createLinkQ();
	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);
	deQueue(q);
	deQueue(q);
	deQueue(q);

	printQ(q);

	
}


linkQ* createLinkQ()
{
	linkQ* lq = (linkQ*)malloc(sizeof(linkQ));
	if (lq == NULL) exit(1);
	lq->front = NULL;
	lq->rear = NULL;
	return lq;
}
void enQueue(linkQ* alq, int data)
{
	node* temp = (node*)malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("isFull\n");
		exit(1);
	}
	temp->data = data;
	temp->link = NULL;

	if (alq->rear == NULL)
	{
		alq->front = temp;
		alq->rear = temp;
	}
	else
	{
		alq->rear->link = temp;
		alq->rear = temp;
	}
	printf("%d 값이 큐에 입력되었습니다.\n", data);
}

int deQueue(linkQ* alq)
{
	if (alq->front == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}

	int data = alq->front->data;
	node* temp = alq->front;
	alq->front = alq->front->link;
	free(temp);

	if (alq->front == NULL)
	{
		alq->rear = NULL;
	}

	printf("%d 값이 큐에서 제거되었습니다.\n", data);
	return data;
}
void printQ(linkQ* alq)
{
	printf("출력되는 큐값 ");
	node* curr = alq->front;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->link;
	}
	printf("\n");
}





