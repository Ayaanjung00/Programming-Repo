#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.c"

char name[50];
char number[50];

int main(void) {

    PhoneList* head;
    printf("�̸��� ����ó�� �Է��ϼ���!\n");
    head = insertList();
    if (head == 0) {
        printf("�����Ҵ��� �����߽��ϴ�.\n");
        printf("�����մϴ�.\n");
        return 0;
    }
    if (checkMoreInsert(head) == 0) {
        return 0;
    }
    printList(head);
    removeData(head);
    return 0;
}