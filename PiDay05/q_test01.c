#include <stdio.h>

void main()
{
	int ary[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int queue[20];
	int rear = 0, front = 0;		// �Ա�(rear)�� ����
								// �ⱸ(front)�� ���	
	int size = sizeof(ary) / sizeof(ary[0]);
	// ť�� ����
	for(int i = 0; i < size; i++)
	{
		queue[rear++] = ary[i];
	}

	// ť���� ����
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", queue[front++]);
	}

}