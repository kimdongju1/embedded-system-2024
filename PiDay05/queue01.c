#include <stdio.h>

#define Q_SIZE 10

int queue[Q_SIZE];
int front = -1;
int rear = -1;
void enqueue(int _data)
{
	if (rear = Q_SIZE - 1)
	{
		printf("QUEUE OF!!\n");
		return;
	}
	queue[++rear] = _data;		
}
int dequeue(int *data)
{
	if (rear == front)
	{
		printf("QUEUE UF!!\n");
		return -1;
	}
	return queue[++front];
	
}

void main()
{
	//int rear = -1;
	//int front = -1;
	//int queue[Q_SIZE];

	enqueue(10);
	enqueue(20);
	enqueue(30);

	printf("%d\n", dequeue(10));		// 10
	printf("%d\n", dequeue(20));		// 20

}