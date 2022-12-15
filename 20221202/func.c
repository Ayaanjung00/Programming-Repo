#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

PhoneList* insertList() {
    PhoneList* temp = (PhoneList*)malloc(sizeof(PhoneList));
    if (temp == NULL) {
        printf("메모리 할당 실패");
        return 0;
    }
    printf("이름: ");
    scanf("%s", temp->name);
    printf("전화번호: ");
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
                printf("%s는 %s에게 연락해야합니다.\n", list->name, list->ptr->ptr->name);
                printf("%s의 전화번호는 %s입니다.", list->ptr->ptr->name, list->ptr->ptr->number);
                break;
            }
            else {
                printf("%s는 %s에게 연락해야합니다.\n", list->name, list->ptr->name);
                printf("%s의 전화번호는 %s입니다.", list->ptr->name, list->ptr->number);
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
            printf("최소조건인 5명을 입력하셨습니다.\n");
            printf("입력을 종료하시려면 q를 눌러주세요\n");
            printf("입력: ");
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
                printf("동적할당이 실패했습니다.\n");
                printf("종료합니다.\n");
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
    printf("비상연락망을 찾고싶은 사람의 이름을 입력해주세요\n");
    printf("입력: ");
    getchar();
    scanf("%s", searchName);
    printf("아픈사람을 입력해주세요\n");
    printf("입력: ");
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