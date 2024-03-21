#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
	int fd1, fd2;
	char str[] = "wonderful day!!";
	char buf[1024];
	fd1 = open("mytest.txt", O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd1 < 0) printf("Open Error");
	if (write(fd1, str, stdlen(str)) < 0) printf("Write Error");
	close(fd1);

	fd1 = open("mytest.txt", O_RDONLY);
	if (read(fd1, buf, 1024) < 0) printf("Read Error");

	printf("%s\n", buf);

	fd2 = open("mytest_copy.txt", O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd2 < 0) printf("Open Error");
	if (write(fd2, buf, strlen(buf)) < 0) printf("Write Error");
	
	close(fd1);
	close(fd2);
}