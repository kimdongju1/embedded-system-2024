/*	File : project02_main.c
    Created: 24-03-27
    Author : 김동주
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
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("도서 제목: ");
            scanf("%s", title);
            printf("저자: ");
            scanf("%s", author);
            printf("도서 번호: ");
            scanf("%d", &id);
            addBook(&library, title, author, id);
            break;
        case 2:
            printf("검색할 도서 제목: ");
            scanf("%s", title);
            Book* foundBook = searchBook(&library, title);
            if (foundBook != NULL) {
                if (foundBook->isBorrowed) {
                    printf("해당 도서는 이미 대여 중입니다.\n");
                }
                else {
                    printf("도서를 대여하시겠습니까? (1: 예, 0: 아니오): ");
                    int borrowChoice;
                    scanf("%d", &borrowChoice);
                    if (borrowChoice == 1) {
                        foundBook->isBorrowed = 1;
                        printf("도서를 대여했습니다.\n");
                    }
                    else {
                        printf("도서 대여를 취소했습니다.\n");
                    }
                }
            }
            else {
                printf("도서가 존재하지 않습니다.\n");
            }
            break;
        case 3:
            printf("삭제할 도서 제목: "); +
                scanf("%s", title);
            deleteBook(&library, title);
            break;
        case 4:
            printLibrary(&library);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
    } while (choice != 0);

    return 0;
}