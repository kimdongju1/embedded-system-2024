/* ������Ʈ01. ���̵�� ��й�ȣ�� �Է��Ͽ� ������ 
			   ������ ������ ����� ������ open �Ѵ�.
			   ���ϸ� : myinfo.txt */
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

	printf("���̵�� ��й�ȣ�� �Է��ϼ���.\n");
	printf("���̵� �Է� : ");
	scanf("%s", id);
	printf("��й�ȣ �Է� : ");
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

		printf("�� ����:\n$s\n", buffer);

		close(fd);

	}
	else
	{
		printf("���̵� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n");
	}

	return 0;

}