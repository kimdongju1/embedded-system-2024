/*	File : Book.h
    Created: 24-03-27
    Author : 김동주
*/

#ifndef BOOK_H
#define BOOK_H

// 책 정보 구조체z
typedef struct Book {
    char title[100];
    char author[100];
    int id;
    int isBorrowed; // 대여 여부를 나타내는 필드 추가
    struct Book* next;
} Book;

// 도서관리 구조체z
typedef struct Library {
    Book* head;
} Library;


Book* createBookNode(char title[], char author[], int id);
Book* searchBook(Library* library, char title[]);
void addBook(Library* library, char title[], char author[], int id);
void deleteBook(Library* library, char title[]);
void printLibrary(Library* library);
void printMenu();

#endif