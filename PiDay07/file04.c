#include <stdio.h>
#include <stdlib.h>

void main()
{
	char msg[20] = "File Test!!!";

	FILE* fp;		// ����������
	fp = fopen("test.txt", "w");	// ���� ����
	if (fp == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	fprintf(fp, "%s", msg);		// ���Ϸ� ���
	printf("%s", msg);

	if ((fp = fopen("test.txt", "r")) == NULL)
	{
		fprintf(stderr, "ERROR");
		exit(1);
	}
	fscanf(fp, "%s", msg);
	printf("%s\n", msg);

	fclose(fp);

}