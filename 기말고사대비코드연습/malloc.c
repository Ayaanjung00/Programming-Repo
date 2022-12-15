#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 30
#define SLINE 10

void inputSs(){
	char* str;
	int i;

	FILE* fp = fopen("sentence.txt", "wt");
	if (fp == NULL) {
		printf("File Open Error\n");
		return;
	}

	str = (char*)malloc(sizeof(char) * SLEN);
	for (i = 0; i < SLINE; i++) {
		fputc("%d", i);
	}
	fclose(fp);
}