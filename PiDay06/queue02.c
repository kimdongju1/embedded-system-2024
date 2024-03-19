#include <stdio.h>
#include<stdlib.h>
#define QSIZE 10

typedef struct
{
	int front;
	int rear;
	char queue[QSIZE];
}queue;

queue* create();
void enqueue(queue* q, char data);
char dequeue(queue* q);
void printQueue(queue* q);

void main()
{
	queue* qa = create();
	enqueue(qa, 'A');
	enqueue(qa, 'B');
	enqueue(qa, 'C');

	//printf("Dequeued: %c\n", dequeue(qa));
	//printf("Dequeued: %c\n", dequeue(qa));
	//printf("Dequeued: %c\n", dequeue(qa));
	
	printQueue(qa);

	return 0;
}

queue* create()
{
	queue* q = malloc(sizeof(queue));	// 동적할당
	if (q == NULL) {
		exit(1);
	}
	else {
		q->front = -1;
		q->rear = -1;
		return q;
	}

}

void enqueue(queue* q, char data)
{
	if (q->rear == QSIZE - 1)
	{
		printf("Queue is FULL!\n");
		return;
	}
	else {
		q->rear++;
		q->queue[q->rear] = data;
		printf("%c\n", q->queue[q->rear]);
	}
}

char dequeue(queue* q)
{
	char data;
	if (q->front == q->rear)
	{
		printf("UF\n");
		return -1;
	}
	data = q->queue[q->front];
	q->front++;
	return data;

}

void printQueue(queue* q)
{
	
	for (int i = q->front + 1; i <= q->rear; i++)
	{
		printf("%c\n", q->queue[i]);
	}
	printf("\n");

}