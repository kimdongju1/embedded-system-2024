/* ���� Ž�� */
#include <stdio.h>

int lSearch(int ary[], int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (ary[i] == target)
		{
			return i;
		}
	}
	return -1;
}

void main()
{
	int ary[] = { 3, 5, 2, 4, 9, 8, 1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int target = 9;
	int ridx;

	ridx = lSearch(ary, size, target);

	if (ridx == -1) printf("ã�� ���Ұ� �����ϴ�\n");
	else
	{
		printf("ã�� �ε��� : %d\n", target, ridx);

	}
}