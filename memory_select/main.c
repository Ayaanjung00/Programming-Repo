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
    info = malloc(sizeof(char*) * 10);//2���� �迭 �Ҵ�
    for (int i = 0; i < 10; i++) {
        info[i] = malloc(sizeof(char) * 100);
    }
    //printf("%d\n", sizeof(info));   //�����ʹϱ�!!!!!!!! 8�� ������
    if (info == NULL) {
        printf("�����Ҵ� ����\n");
        exit(1);
    }
    while (fgets(info[i], strlen(info[i]), fp) != NULL) {
        //÷�� sizeof(info[i])���ߴµ� �̻��ߴµ� ������ ũ��� 8�̴ϱ� 8�� ���ִ���
        printf("%d %s", i + 1, info[i]);
        i++;
        if (i == 3) { //d����� �ƴ� 
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