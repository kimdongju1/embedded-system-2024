/* ������Ʈ02. ���Ḯ��Ʈ �ڷᱸ���� �������� ���α׷��� �ۼ��Ͻÿ�. 
 v1-> 
 **** �޴� ****
 1. ��������(���)
 2. �����˻� - �˻��� ������ ������ ����Ѵ�.
 3. ��������
 4. �������
 0. ����
 v2->
 **** �޴� ****
 1. ��������(���)
 2. �����˻� - �˻� �� �뿩�� ����� �����Ѵ�.
 3. ��������
 4. �������
 0. ����
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// å ���� ����ü
typedef struct Book
{
	char title[100];
	char author[100];
	int id;
	struct Book* next;
}Book;

// �������� ����ü
typedef struct Library
{
	Book* head;
}Library;

// ���ο� å ��� ����
Book* createBookNode(char title[], char author[], int id)
{
	Book* newBook = (Book*)malloc(sizeof(Book));
	strcpy(newBook->title, title);
	strcpy(newBook->author, author);
	newBook->id = id;
	newBook->next = NULL;
	return newBook;
}

// ���� �߰�
void addBook(Library* library, char title[], char author[], int id)
{
	Book* newBook = createBookNode(title, author, id);
	if (library->head == NULL)
	{
		library->head = newBook;
	}
	else
	{
		Book* temp = library->head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newBook;
	}
}

// ���� �˻�
int searchBook(Library* library, char title[])
{
	Book* temp = library->head;
	while (temp != NULL)
	{
		if (strcmp(temp->title, title) == 0)
		{
			return 1; // ������ ������
		}
		temp = temp->next;
	}
	return 0; // ������ �������� ����
}

// ���� ����
void deleteBook(Library* library, char title[])
{
	Book* prev = NULL;
	Book* current = library->head;
	while (current != NULL)
	{
		if (strcmp(current->title, title) == 0)
		{
			if (prev == NULL)
			{
				library->head = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
	printf("������ ������ ã�� ���߽��ϴ�.\n");
}

// ���� ���
void printLibrary(Library* library)
{
	Book* temp = library->head;
	if (temp == NULL)
	{
		printf("������ �����ϴ�.\n");
	}
	else 
	{
		printf("���� ���: \n");
		while (temp != NULL)
		{
			printf("����: %s, ����: %s, ������ȣ: %d\n", temp->title, temp->author, temp->id);
			temp = temp->next;
		}
	}
}

// �޴� ���
void printMenu()
{
	printf("**** �޴� ****\n");
	printf("1. ��������(���)\n");
	printf("2. �����˻� - �˻��� ������ ������ ����Ѵ�.\n");
	printf("3. ��������\n");
	printf("4. �������\n");
	printf("0. ����\n");
}

int main()
{
	Library library;
	library.head = NULL;
	int choice;
	char title[100];
	char author[100];
	int id;

	do
	{
		printMenu();
		printf("����: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("���� ����: ");
			scanf("%s", title);
			printf("����: ");
			scanf("%s", author);
			printf("���� ��ȣ: ");
			scanf("%d", &id);
			addBook(&library, title, author, id);
			break;
		case 2:
			printf("�˻��� ���� ����: ");
			scanf("%s", title);
			if (searchBook(&library, title))
			{
				printf("������ �����մϴ�.\n");
			}
			else
			{
				printf("������ �������� �ʽ��ϴ�.\n");
			}
			break;
		case 3:
			printf("������ ���� ����: ");
			scanf("%s", title);
			deleteBook(&library, title);
			break;
		case 4:
			printLibrary(&library);
			break;
		case 0:
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
		}

	} while (choice != 0);

	return 0;
}