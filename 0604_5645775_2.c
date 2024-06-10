﻿#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void insert_first(DListNode* head, element data) {
    dinsert(head, data);
}

void insert_last(DListNode* head, element data) {
    dinsert(head->llink, data);
}

element ddelete(DListNode* head, DListNode* removed) {
    element r;
    if (removed == head) return -1;
    r = removed->data;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
    return r;
}

void delete_first(DListNode* head) {
    if (head->rlink == head) {
        printf("리스트가 비어 있습니다.\n");
    }
    else {
        ddelete(head, head->rlink);
    }
}

void delete_last(DListNode* head) {
    if (head->llink == head) {
        printf("리스트가 비어 있습니다.\n");
    }
    else {
        ddelete(head, head->llink);
    }
}

void print_dlist(DListNode* head) {
    DListNode* p;
    for (p = head->rlink; p != head; p = p->rlink) {
        printf(" %d -> ", p->data);
    }
    printf("(head)\n");
}

void menu() {
    printf("\n메뉴:\n");
    printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
    printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
    printf("3. 리스트 처음 노드 삭제\n");
    printf("4. 리스트 마지막 노드 삭제\n");
    printf("5. 리스트 프린트\n");
    printf("6. 종료\n");
    printf("선택: ");
}

int main() {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    int choice, data;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            insert_first(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &data);
            insert_last(head, data);
            break;
        case 3:
            delete_first(head);
            break;
        case 4:
            delete_last(head);
            break;
        case 5:
            print_dlist(head);
            break;
        case 6:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 입력해주세요.\n");
            break;
        }
    }

    return 0;
}