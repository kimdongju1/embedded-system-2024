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
	char intputId[BUF_SIZE];
	char intputPassword[BUF_SIZE];
	char buffer[1024];

	printf("아이디와 비밀번호를 입력하세요.\n");
	printf("아이디 입력 : ");
	scanf("%s", id);
	printf("비밀번호 입력 : ");
	scanf("%s", password);

	if (strcmp(id, "your_id") == 0 && strcmp(password, "your_password") == 0)
	{
		fd = open("myinfo.txt", O_RDONLY);
		if (fd < 0)
		{
			perror("File Open Error");
			exit(1);
		}

		int bytesRead = read(fd, buffer, sizeof(buffer));
		if (bytesRead < 0)
		{
			perror("File Read Error");
			exit(1);
		}

		printf("내 정보:\n$s\n", buffer);

		close(fd);

	}
	else
	{
		printf("아이디나 비밀번호가 일치하지 않습니다.\n");
	}

	return 0;

}