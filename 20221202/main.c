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
    printf("이름과 연락처를 입력하세요!\n");
    head = insertList();
    if (head == 0) {
        printf("동적할당이 실패했습니다.\n");
        printf("종료합니다.\n");
        return 0;
    }
    if (checkMoreInsert(head) == 0) {
        return 0;
    }
    printList(head);
    removeData(head);
    return 0;
}