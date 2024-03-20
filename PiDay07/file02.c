/* file descriptor */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> // 리눅스만 적용되는듯

void main()
{
	char msg = "Linux Test!!";
	int fd;

	fd = open("test02.txt", O_CREAT | O_WRONLY); // 리눅스 전용 함수
	if (fd == -1)
	{
		printf("file open error");
		exit(1);
	}
	printf("file descriptor: %d\n", fd);

	if (write(fd, msg, sizeof(msg)) == -1)
	{
		printf("file write error");
	}
	close(fd);


}