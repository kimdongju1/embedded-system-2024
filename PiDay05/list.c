#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
    int data;
    struct NODE* next;
}node;

typedef struct {
    node* head; // headNode�� ����ü ������ node����ü�� ��� ���� Ȱ�� ����
}headNode;

headNode* createHeadNode(void) {
    headNode* newHead = malloc(sizeof(headNode));
    newHead->head = NULL;       // newHead -> head �� NUll���� ����
    return  newHead;
}

void ShowNode(headNode* pnode) {
    node* curr = pnode->head;
    int i = 0;
    while (curr != NULL) {
        i += 1;
        printf("%d��° ������ �� : %d\n", i, curr->data);
        curr = curr->next;
    }
}

void pre_addNode(headNode* pnode, int _data) {
    node* newnode = malloc(sizeof(node));
    // if (newnode == NULL) return -1;
    if (newnode != NULL) {
        newnode->next = pnode->head;// pnode -> head ->next�ϸ� �ȵ�
        // pnode -> head ������ �ؾ� �޸� �Ҵ��� ����
        pnode->head = newnode;
        newnode->data = _data;
        printf("��尡 �����Ǿ����ϴ�\n");
    }

}

void rearNode(headNode* pnode, int _data) {
    node* newnode = malloc(sizeof(node));
    if (newnode != NULL) {
        newnode->data = _data;
        newnode->next = NULL;
        node* curr = pnode->head; // pnode(head)�� next���� ������ִ� ���� �ƴ϶�
        // pnode->head �� ����Ǿ� �ִ�
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newnode;


    }

}

void allFreeNode(headNode* pnode) {
    node* curr = pnode->head;
    while (curr != NULL) {
        node* dn = curr;
        curr = curr->next;
        printf("������ ����\n");
        free(dn);
    }
    pnode->head->next = NULL;
    printf("head -> next : %d,  head->data: %d \n", pnode->head->next, curr);
    free(pnode);
}
void searchNode(headNode* pnode, int _data) {
    int count = 0;
    node* search = malloc(sizeof(node));
    search = pnode->head;
    while (search->next != NULL) {
        search = search->next;
        count += 1;
        if (search->data == _data) {
            count += 1;
            break;
        }
    }


    printf("%d �����ʹ� %d ��° ��忡�� �߰ߵǾ����ϴ�.\n", _data, count);
}



void main() {

    //  node*head = (node*)malloc(sizeof(node));
     //  head->next=NULL
    headNode* newhead = createHeadNode();
    pre_addNode(newhead, 10);
    pre_addNode(newhead, 20);
    pre_addNode(newhead, 30);
    rearNode(newhead, 11);
    rearNode(newhead, 22);
    rearNode(newhead, 100);

    searchNode(newhead, 11);
    node* curr = newhead->head;



    while (curr != NULL) {
        printf("�����ʹ� %d\n", curr->data);
        curr = curr->next;
    }
    printf("-------�Լ� ȣ��----------\n");
    ShowNode(newhead);
    allFreeNode(newhead);
}


