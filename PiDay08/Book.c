/*	File : Book.c
    Created: 24-03-27
    Author : 김동주
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book.h"

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
