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
	char inputId[BUF_SIZE];
	char inputPassword[BUF_SIZE];
	char buffer[1024];
	char* info = "�赿��, 29��, ��";

	// "myinfo.txt" ���Ͽ� ������ ����
	fd = open("myinfo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("���� ���� ����");
		exit(1);
	}
	
	if (write(fd, info, strlen(info)) < 0)
	{
		perror("���� ���� ����");
		exit(1);
	}

	close(fd);

	printf("���Ͽ� ������ �����߽��ϴ�.\n");

	// ���̵�� ��й�ȣ �Է� �ޱ�
	printf("���̵�� ��й�ȣ�� �Է��ϼ���.\n");
	printf("���̵� �Է� : ");
	scanf("%s", inputId);
	printf("��й�ȣ �Է� : ");
	scanf("%s", inputPassword);

	// ���̵�� ��й�ȣ Ȯ��
	if (strcmp(inputId, "kim") == 0 && strcmp(inputPassword, "1234") == 0)
	{
		fd = open("myinfo.txt", O_RDONLY);
		if (fd < 0)
		{
			perror("���� ���� ����");
			exit(1);
		}

		// ���Ͽ��� ���� �б�
		int bytesRead = read(fd, buffer, sizeof(buffer));
		if (bytesRead < 0)
		{
			perror("���� �б� ����");
			exit(1);
		}

		// ���� ���� ���
		printf("�� ����:\n$s\n", buffer);

		// ���� �ݱ�
		close(fd);

	}
	else
	{
		printf("���̵� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.\n");
	}

	return 0;

}