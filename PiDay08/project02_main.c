/*	File : project02_main.c
    Created: 24-03-27
    Author : �赿��
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book.h"

void main() {
    Library library;
    library.head = NULL;
    int choice;
    char title[100];
    char author[100];
    int id;

    do {
        printMenu();
        printf("����: ");
        scanf("%d", &choice);

        switch (choice) {
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
            Book* foundBook = searchBook(&library, title);
            if (foundBook != NULL) {
                if (foundBook->isBorrowed) {
                    printf("�ش� ������ �̹� �뿩 ���Դϴ�.\n");
                }
                else {
                    printf("������ �뿩�Ͻðڽ��ϱ�? (1: ��, 0: �ƴϿ�): ");
                    int borrowChoice;
                    scanf("%d", &borrowChoice);
                    if (borrowChoice == 1) {
                        foundBook->isBorrowed = 1;
                        printf("������ �뿩�߽��ϴ�.\n");
                    }
                    else {
                        printf("���� �뿩�� ����߽��ϴ�.\n");
                    }
                }
            }
            else {
                printf("������ �������� �ʽ��ϴ�.\n");
            }
            break;
        case 3:
            printf("������ ���� ����: "); +
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