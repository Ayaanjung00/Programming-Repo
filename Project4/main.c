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
            printf("5명을 입력하셨습니다(q 입력 시 종료 / 계속 입력시 pass):");
            scanf("%s", quit);
            if (strcmp(quit, "q") == 0)break;
        }
        list->next = input();
        list = list->next;
        i++;
    }
    choicehead = output(head); //출력
    choice(choicehead); //선택
    sick(head); //아픈사람
    del(head);
    //메모리해제
    P* clear = relist;
    while (relist->next != NULL) {
        clear = relist->next;
        free(relist);
        relist = clear;

    }
}
