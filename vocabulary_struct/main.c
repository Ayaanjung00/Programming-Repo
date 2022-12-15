#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int cnt = 0;
FILE* fp;

typedef struct oneword {
	char word[20];
	char meaning[100];
}OneWord;

OneWord dictionary[100];

// 단어장 보기
void list(){	
	if (cnt == 0)
		printf("등록된 단어가 없습니다.\n\n");
	else {
		printf("\n단어 \t 뜻\n");

		for (int i = 0; i < cnt; i++) {
			printf("%s    %s\n", dictionary[i].word, dictionary[i].meaning);
		}
	}
}

// 단어 추가
void append() {
	cnt++;
	
	printf("단어 : "); scanf_s("%s", dictionary[cnt-1].word, 20);
	fputs("\n", fp);
	fputs(dictionary[cnt - 1].word, fp);
	printf("뜻 : "); scanf_s("%s", dictionary[cnt-1].meaning, 100);
	fputs(" ", fp);
	fputs(dictionary[cnt - 1].meaning, fp);
	
	printf("=====추가완료=====\n");
}

// 단어 검색
void search() {
	char word_search[20];
	printf("검색할 단어 : ");  scanf_s("%s", word_search, 20);
	for (int i = 0; i < cnt; i++) {
		if (strcmp(word_search, dictionary[i].word) == 0) {
			printf("단어를 확인하였습니다. \n단어 : %s\n뜻 : %s\n", dictionary[i].word, dictionary[i].meaning);
			return;
		}
		else
			continue;
	}
	printf("\n해당 단어를 확인할 수 없습니다. 단어를 추가로 입력합니다.\n\n");
	printf("==================\n");
	cnt++;
	strcpy(dictionary[cnt - 1].word, word_search);
	fputs("\n", fp);
	fputs(dictionary[cnt - 1].word, fp);
	printf("뜻 : "); scanf_s("%s", dictionary[cnt - 1].meaning, 100);
	fputs(" ", fp);
	fputs(dictionary[cnt - 1].meaning, fp);
	

	printf("=====추가완료=====\n");
}

void menu(){
	int choice=0;
	do
	{
		printf("\n\n====================================================================\n");
		printf("============================단어장 메뉴=============================\n");

		printf("[1]목록보기 [2]단어 추가 [3]단어 검색 [4]종료   저장된 단어개수 : %d\n", cnt);
		printf("\n====================================================================\n");

		scanf_s("%d", &choice);
		getchar();

		switch (choice)
		{
		case 1: list(); break;
		case 2: append(); getchar(); break;
		case 3: search(); getchar(); break;
		case 4: printf("\n주소록 프로그램을 종료합니다.\n"); return;

		default: printf("메뉴 번호를 다시 확인해주세요\n");
		}
	} while (choice != 4 || cnt <= 100);
}

int main()
{
	fp = fopen("dictionary.txt", "r+");
	if (fp == NULL)
	{
		printf("error 파일 읽기 실패");

		return 0;
	}
	while (feof(fp) == 0)
	{
		fscanf(fp, "%s %s", dictionary[cnt].word, dictionary[cnt].meaning);
		cnt++;
	}
	menu();
	fclose(fp);
}