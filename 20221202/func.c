#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

PhoneList* insertList() {
    PhoneList* temp = (PhoneList*)malloc(sizeof(PhoneList));
    if (temp == NULL) {
        printf("�޸� �Ҵ� ����");
        return 0;
    }
    printf("�̸�: ");
    scanf("%s", temp->name);
    printf("��ȭ��ȣ: ");
    scanf("%s", temp->number);
    temp->ptr = NULL;
    return temp;
}
PhoneList* findLastList(PhoneList* list) {
    while (1) {
        if ((list->ptr) == NULL) {
            return list;
        }
        list = list->ptr;
    }
}

void SearchList(PhoneList* list, char* name, char* sickName) {
    while (list->ptr != NULL) {
        if (strcmp(list->name, name) == 0) {
            if (strcmp(list->ptr->name, sickName) == 0) {
                printf("%s�� %s���� �����ؾ��մϴ�.\n", list->name, list->ptr->ptr->name);
                printf("%s�� ��ȭ��ȣ�� %s�Դϴ�.", list->ptr->ptr->name, list->ptr->ptr->number);
                break;
            }
            else {
                printf("%s�� %s���� �����ؾ��մϴ�.\n", list->name, list->ptr->name);
                printf("%s�� ��ȭ��ȣ�� %s�Դϴ�.", list->ptr->name, list->ptr->number);
                break;
            }
        }
        else {
            list = list->ptr;
        }
    }

}
int checkMoreInsert(PhoneList* head) {
    char check;
    int i = 0;
    while (1) {
        if (i >= 4) {
            printf("�ּ������� 5���� �Է��ϼ̽��ϴ�.\n");
            printf("�Է��� �����Ͻ÷��� q�� �����ּ���\n");
            printf("�Է�: ");
            getchar();
            scanf("%c", &check);
            if (check == 'q') {
                return 1;
                break;
            }
        }
        else {
            PhoneList* next = findLastList(head);
            next->ptr = insertList();
            if (next->ptr == 0) {
                printf("�����Ҵ��� �����߽��ϴ�.\n");
                printf("�����մϴ�.\n");
                return 0;
                break;
            }
            i++;
        }
    }
}

void printList(PhoneList* head) {
    char searchName[50];
    char sickName[50];
    printf("��󿬶����� ã����� ����� �̸��� �Է����ּ���\n");
    printf("�Է�: ");
    getchar();
    scanf("%s", searchName);
    printf("���»���� �Է����ּ���\n");
    printf("�Է�: ");
    getchar();
    scanf("%s", sickName);
    SearchList(head, searchName, sickName);

}
void removeData(PhoneList* head) {
    PhoneList* pl;
    while (head->ptr != NULL)
    {
        pl = head->ptr;
        free(head);
        PhoneList* head = pl;

    }
}