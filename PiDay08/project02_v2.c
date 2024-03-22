#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 책 정보 구조체
typedef struct Book {
    char title[100];
    char author[100];
    int id;
    int isBorrowed; // 대여 여부를 나타내는 필드 추가
    struct Book* next;
} Book;

// 도서관리 구조체
typedef struct Library {
    Book* head;
} Library;

// 새로운 책 노드 생성
Book* createBookNode(char title[], char author[], int id) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->id = id;
    newBook->isBorrowed = 0; // 초기값: 대여되지 않음
    newBook->next = NULL;
    return newBook;
}

// 도서 추가
void addBook(Library* library, char title[], char author[], int id) {
    Book* newBook = createBookNode(title, author, id);
    if (library->head == NULL) {
        library->head = newBook;
    }
    else {
        Book* temp = library->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// 도서 검색
Book* searchBook(Library* library, char title[]) {
    Book* temp = library->head;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// 도서 삭제
void deleteBook(Library* library, char title[]) {
    Book* prev = NULL;
    Book* current = library->head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                library->head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("삭제할 도서를 찾지 못했습니다.\n");
}

// 도서 출력
void printLibrary(Library* library) {
    Book* temp = library->head;
    if (temp == NULL) {
        printf("도서가 없습니다.\n");
    }
    else {
        printf("도서 목록:\n");
        while (temp != NULL) {
            printf("제목: %s, 저자: %s, 도서 번호: %d, 대여 여부: %s\n", temp->title, temp->author, temp->id, temp->isBorrowed ? "대여 중" : "대여 가능");
            temp = temp->next;
        }
    }
}

// 메뉴 출력
void printMenu() {
    printf("**** 메뉴 ****\n");
    printf("1. 도서구입(등록)\n");
    printf("2. 도서검색 - 검색 후 대여의 기능을 구현한다.\n");
    printf("3. 도서삭제\n");
    printf("4. 도서출력\n");
    printf("0. 종료\n");
}

int main() {
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
            printf("삭제할 도서 제목: ");
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
