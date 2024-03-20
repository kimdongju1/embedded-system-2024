/* 이진 탐색 */
#include <stdio.h>

int binarySearch(int ary[], int size, int target)
{
	int first = 0;
	int mid = 0;
	int last = size;

	while (first <= last)
	{
		mid = first + (first + last) / 2;
		if (target == ary[mid]) 
			printf("%d번째\n", ary[mid]);
			
		else if (target > ary[mid])
			first = mid + 1;
		else
			last = mid - 1;
	}
	return -1;
}
void main()
{
	int ary[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int target = 4;
	int ridx;

	ridx = binarySearch(ary, size, target);

	if (ridx == -1)
		printf("찾는 원소가 없습니다.\n");
	else
		printf("찾은 인덱스 : %d\n", target, ridx);
}

