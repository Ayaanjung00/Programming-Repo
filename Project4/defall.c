#ifndef _DEFALL_
#define _DEFALL_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"


P* input() {
    P* temp = malloc(sizeof(P));
    printf("�̸��� �Է��Ͻÿ�:");
    scanf("%s", temp->name);
    printf("��ȭ��ȣ�� �Է��ϼ���:");
    scanf("%s", temp->num);
    temp->next = NULL;
    return temp;
}
P* output(P* ptr) {
    int i = 0;
    printf("\n\n-----------��󿬶���------------\n\n");
    P* nlist;
    P* start = ptr;
    while (ptr != NULL) {
        nlist = ptr->next;
        printf("%s�� %s���� �����ؾ��մϴ�. %s�� ��ȭ��ȣ:%s\n", ptr->name, nlist->name, nlist->name, nlist->num);
        if (nlist->next == NULL) {
            printf("%s�� ������ �޾ҽ��ϴ�.��� �������� ������ �޾ҽ��ϴ�.\n", nlist->name);

            return start;
        }
        ptr = ptr->next; //�������� �� �����Ű�� NULL�� ����Ų�� �̷��� �ȵ� 
        i++;
    }

}
void choice(P* ptr) {
    P* nlist;
    char name[10] = { 0, };
    printf("\n�˻��Ͻ� ���� �̸��� �Է�:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s�� ������ ����� �����ϴ�\n", ptr->name);
                return;
            }
            nlist = ptr->next;
            printf("\n%s�� %s���� �����ؾ��մϴ� %s���� ��ȭ��ȣ�� %s�Դϴ�.\n", ptr->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        ptr = ptr->next;
    }
}
void sick(P* ptr) {
    P* nlist = NULL, * prelist = NULL;
    char name[10] = { 0, };
    printf("���»���� �Է��ϼ���:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s�� ������ ����� �����ϴ�\n", ptr->name);
                return;
            }
            nlist = ptr->next; //���� ����� ������ ����� ���
            printf("\n%s���� ���ļ� ��� %s���� %s���� �����ؾ��մϴ� %s���� ��ȭ��ȣ�� %s�Դϴ�.\n", ptr->name, prelist->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        prelist = ptr; //���� ����� �ּҰ��� ��´�.
        ptr = ptr->next; //
    }
}
P* del(P* ptr) {
    P* nlist = NULL, * prelist = NULL, * head = ptr;
    char name[10] = { 0, };
    printf("���ӿ� ��������� �Է��ϼ���:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s�� ������ ����� �����ϴ�\n", ptr->name);
                free(ptr);
                prelist->next = NULL;
                output(head);
                return;
            }
            nlist = ptr->next; //���� ����� ������ ����� ���
            printf("\n%s���� Ż���߽��ϴ�.�����δ� %s�� %s���� �����ؾ��մϴ�.\n", ptr->name, prelist->name, nlist->name, nlist->name, nlist->num);
            prelist->next = nlist;
            printf("%s��\n", prelist->name);
            free(ptr);
            return head;
        }
        prelist = ptr; //���� ����� �ּҰ��� ��´�.
        ptr = ptr->next; //
    }
}

#endif;