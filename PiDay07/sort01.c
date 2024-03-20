#include <stdio.h>

void bubbleSort(int ary[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for(j = 0; j < n - i - 1; j++) {
			if (ary[j] > ary[j + 1]) {
				temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	
}

void main()
{
	int ary[] = { 9, 4, 8, 15, 3, 7, 2, 1 };
	// 오름차순으로 정렬 해보시오 
	int n = sizeof(ary) / sizeof(ary[0]);
	printf("원래 배열 :");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");

	bubbleSort(ary, n);

	printf("오름차순 배열 : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");

	return ;
}