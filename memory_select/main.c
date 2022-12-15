#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main() {
    char** info;
    int i = 0;
    FILE* fp = fopen("mystory.txt", "r");
    if (fp == NULL)puts("file open error!!");
    else puts("file open success!!");
    info = malloc(sizeof(char*) * 10);//2차원 배열 할당
    for (int i = 0; i < 10; i++) {
        info[i] = malloc(sizeof(char) * 100);
    }
    //printf("%d\n", sizeof(info));   //포인터니까!!!!!!!! 8이 나오지
    if (info == NULL) {
        printf("동적할당 실패\n");
        exit(1);
    }
    while (fgets(info[i], strlen(info[i]), fp) != NULL) {
        //첨에 sizeof(info[i])로했는데 이상했는데 포인터 크기는 8이니까 8로 돼있던겨
        printf("%d %s", i + 1, info[i]);
        i++;
        if (i == 3) { //d여기는 아님 
            info = realloc(sizeof(char), 10);
            for (int j = i; j < 10; i++) {
                info[i] = realloc(sizeof(char), 100);
            }
        }
    }
    printf("%d\n", i);
    while (i > 0) {
        i--;
        printf("%s", info[i]);
    }

    fclose(fp);
    for (int j = 0; j < i; j++) {
        free(info[j]);
    }
    free(info);
}