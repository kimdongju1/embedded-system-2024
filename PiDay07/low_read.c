/* 앞서 생성한 파일 data.txt에 저장된 데이터를
	read 함수를 이용해서 읽어 들임(리눅스) */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100
void error_handling(char* message);

int main(void)
{
	int fd;
	char buf[BUF_SIZE]

	fd = open("data.txt", O_RDONLY);
	if (fd == -1)
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	if (read(fd, buf, sizeof(buf)) == -1)
		error_handling("write() error!");
	close(fd);
	return 0;
}

void error_handling(char*, message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}