#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phone {
    char name[20];
    char num[20];
    struct phone* next;
}P;
P* input();
P* output(P* ptr);

void choice(P* ptr);
void sick(P* ptr);
void del(P* ptr);

void main() {
    int i = 0;
    char quit[3] = { 0, };
    P* head = NULL, * list = NULL, * choicehead = NULL;
    head = input();
    list = head;

    while (1) {
        if (i >= 4) {
            printf("5명을 입력하셨습니다(q 입력 시 종료):");
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
    del(head); //삭제함수
    //메모리해제
    P* clear = head;
    while (head->next != NULL) {
        clear = head->next;
        free(head);
        head = clear;

    }
}
P* input() {
    P* temp = malloc(sizeof(P));
    printf("이름을 입력하시오:");
    scanf("%s", temp->name);
    printf("전화번호를 입력하세요:");
    scanf("%s", temp->num);
    temp->next = NULL;
    return temp;
}
P* output(P* ptr) {
    int i = 0;
    printf("\n\n-----------비상연락망------------\n\n");
    P* nlist;
    P* start = ptr;
    while (ptr != NULL) {
        nlist = ptr->next;
        printf("%s는 %s에게 연락해야합니다. %s의 전화번호:%s\n", ptr->name, nlist->name, nlist->name, nlist->num);
        if (nlist->next == NULL) {
            printf("%s가 연락을 받았습니다.모든 구성원이 연락을 받았습니다.\n", nlist->name);

            return start;
        }
        ptr = ptr->next; //마지막에 얠 실행시키면 NULL을 가리킨다 이러면 안됨 
        i++;
    }

}
void choice(P* ptr) {
    P* nlist;
    char name[10] = { 0, };
    printf("\n검색하실 분의 이름을 입력:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s가 연락할 사람이 없습니다\n", ptr->name);
                return;
            }
            nlist = ptr->next;
            printf("\n%s는 %s에게 연락해야합니다 %s님의 전화번호는 %s입니다.\n", ptr->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        ptr = ptr->next;
    }
}
void sick(P* ptr) {
    P* nlist = NULL, * prelist = NULL;
    char name[10] = { 0, };
    printf("아픈사람을 입력하세요:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s가 연락할 사람이 없습니다\n", ptr->name);
                return;
            }
            nlist = ptr->next; //아픈 사람이 연락할 사람의 노드
            printf("\n%s님이 아파서 대신 %s님이 %s에게 연락해야합니다 %s님의 전화번호는 %s입니다.\n", ptr->name, prelist->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        prelist = ptr; //이전 노드의 주소값을 담는다.
        ptr = ptr->next; //
    }
}

/*void del(p* ptr) {
    p* nlist = null, * prelist = null;
    char name[10] = { 0, };
    printf("모임에 빠진사람을 입력하세요:");
    scanf("%s", name);
    while (ptr != null) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == null) {
                printf("%s가 연락할 사람이 없습니다\n", ptr->name);
                return;
            }
            nlist = ptr->next; //아픈 사람이 연락할 사람의 노드
            printf("\n%s님이 탈퇴했습니다.앞으로는 %s가 %s에게 연락해야합니다.\n", ptr->name, prelist->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        prelist = ptr; //이전 노드의 주소값을 담는다.
        ptr = ptr->next; //
    }
}*/