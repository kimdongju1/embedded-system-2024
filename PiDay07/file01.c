/* 파일 저장해서 값만 불러오기 (표준입출력) */
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char msg[20] = "File Test!!!";

	FILE * fp;		// 파일포인터
	fp = fopen("test.txt", "w");	// 파일 오픈
	if (fp == NULL)
	{
		fprintf(stderr, "Error");
		exit(1);
	}
	fprintf(fp, "%s", msg);		// 파일로 출력
	printf("%s", msg);

	fclose(fp);

} 
// cat test.txt 로 불러오면 File Test!!! 결과 불러옴