#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "struct.h"
#include "defall.h"

void main() {
    int i = 0;
    char quit[5] = { 0, };
    P* head = NULL, * list = NULL, * choicehead = NULL, * relist = NULL;
    head = input();
    list = head;

    while (1) {
        if (i >= 4) {
            printf("5���� �Է��ϼ̽��ϴ�(q �Է� �� ���� / ��� �Է½� pass):");
            scanf("%s", quit);
            if (strcmp(quit, "q") == 0)break;
        }
        list->next = input();
        list = list->next;
        i++;
    }
    choicehead = output(head); //���
    choice(choicehead); //����
    sick(head); //���»��
    del(head);
    //�޸�����
    P* clear = relist;
    while (relist->next != NULL) {
        clear = relist->next;
        free(relist);
        relist = clear;

    }
}
