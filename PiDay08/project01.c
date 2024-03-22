/* 프로젝트01. 아이디와 비밀번호를 입력하여 맞으면 
			   본인의 정보가 저장된 파일을 open 한다.
			   파일명 : myinfo.txt */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 100

void main()
{
	int fd;
	char id[BUF_SIZE];
	char password[BUF_SIZE];
	char inputId[BUF_SIZE];
	char inputPassword[BUF_SIZE];
	char buffer[1024];
	char* info = "김동주, 29세, 남";

	// "myinfo.txt" 파일에 정보를 저장
	fd = open("myinfo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("파일 열기 오류");
		exit(1);
	}
	
	if (write(fd, info, strlen(info)) < 0)
	{
		perror("파일 쓰기 오류");
		exit(1);
	}

	close(fd);

	printf("파일에 정보를 저장했습니다.\n");

	// 아이디와 비밀번호 입력 받기
	printf("아이디와 비밀번호를 입력하세요.\n");
	printf("아이디 입력 : ");
	scanf("%s", inputId);
	printf("비밀번호 입력 : ");
	scanf("%s", inputPassword);

	// 아이디와 비밀번호 확인
	if (strcmp(inputId, "kim") == 0 && strcmp(inputPassword, "1234") == 0)
	{
		fd = open("myinfo.txt", O_RDONLY);
		if (fd < 0)
		{
			perror("파일 열기 오류");
			exit(1);
		}

		// 파일에서 내용 읽기
		int bytesRead = read(fd, buffer, sizeof(buffer));
		if (bytesRead < 0)
		{
			perror("파일 읽기 오류");
			exit(1);
		}

		// 파일 내용 출력
		printf("내 정보:\n$s\n", buffer);

		// 파일 닫기
		close(fd);

	}
	else
	{
		printf("아이디나 비밀번호가 일치하지 않습니다.\n");
	}

	return 0;

}