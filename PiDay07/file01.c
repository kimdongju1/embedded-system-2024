/* ���� �����ؼ� ���� �ҷ����� (ǥ�������) */
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char msg[20] = "File Test!!!";

	FILE * fp;		// ����������
	fp = fopen("test.txt", "w");	// ���� ����
	if (fp == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	fprintf(fp, "%s", msg);		// ���Ϸ� ���
	printf("%s", msg);

	fclose(fp);

} 
// cat test.txt �� �ҷ����� File Test!!! ��� �ҷ���