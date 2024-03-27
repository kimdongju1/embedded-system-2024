/*	File : Book.c
    Created: 24-03-27
    Author : �赿��
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book.h"

// ���ο� å ��� ����
Book* createBookNode(char title[], char author[], int id) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->id = id;
    newBook->isBorrowed = 0; // �ʱⰪ: �뿩���� ����
    newBook->next = NULL;
    return newBook;
}

// ���� �߰�
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

// ���� �˻�
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

// ���� ����
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
    printf("������ ������ ã�� ���߽��ϴ�.\n");
}

// ���� ���
void printLibrary(Library* library) {
    Book* temp = library->head;
    if (temp == NULL) {
        printf("������ �����ϴ�.\n");
    }
    else {
        printf("���� ���:\n");
        while (temp != NULL) {
            printf("����: %s, ����: %s, ���� ��ȣ: %d, �뿩 ����: %s\n", temp->title, temp->author, temp->id, temp->isBorrowed ? "�뿩 ��" : "�뿩 ����");
            temp = temp->next;
        }
    }
}

// �޴� ���
void printMenu() {
    printf("**** �޴� ****\n");
    printf("1. ��������(���)\n");
    printf("2. �����˻� - �˻� �� �뿩�� ����� �����Ѵ�.\n");
    printf("3. ��������\n");
    printf("4. �������\n");
    printf("0. ����\n");
}
