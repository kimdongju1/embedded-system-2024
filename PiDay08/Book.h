/*	File : Book.h
    Created: 24-03-27
    Author : �赿��
*/

#ifndef BOOK_H
#define BOOK_H

// å ���� ����üz
typedef struct Book {
    char title[100];
    char author[100];
    int id;
    int isBorrowed; // �뿩 ���θ� ��Ÿ���� �ʵ� �߰�
    struct Book* next;
} Book;

// �������� ����üz
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