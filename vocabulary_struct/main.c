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

// �ܾ��� ����
void list(){	
	if (cnt == 0)
		printf("��ϵ� �ܾ �����ϴ�.\n\n");
	else {
		printf("\n�ܾ� \t ��\n");

		for (int i = 0; i < cnt; i++) {
			printf("%s    %s\n", dictionary[i].word, dictionary[i].meaning);
		}
	}
}

// �ܾ� �߰�
void append() {
	cnt++;
	
	printf("�ܾ� : "); scanf_s("%s", dictionary[cnt-1].word, 20);
	fputs("\n", fp);
	fputs(dictionary[cnt - 1].word, fp);
	printf("�� : "); scanf_s("%s", dictionary[cnt-1].meaning, 100);
	fputs(" ", fp);
	fputs(dictionary[cnt - 1].meaning, fp);
	
	printf("=====�߰��Ϸ�=====\n");
}

// �ܾ� �˻�
void search() {
	char word_search[20];
	printf("�˻��� �ܾ� : ");  scanf_s("%s", word_search, 20);
	for (int i = 0; i < cnt; i++) {
		if (strcmp(word_search, dictionary[i].word) == 0) {
			printf("�ܾ Ȯ���Ͽ����ϴ�. \n�ܾ� : %s\n�� : %s\n", dictionary[i].word, dictionary[i].meaning);
			return;
		}
		else
			continue;
	}
	printf("\n�ش� �ܾ Ȯ���� �� �����ϴ�. �ܾ �߰��� �Է��մϴ�.\n\n");
	printf("==================\n");
	cnt++;
	strcpy(dictionary[cnt - 1].word, word_search);
	fputs("\n", fp);
	fputs(dictionary[cnt - 1].word, fp);
	printf("�� : "); scanf_s("%s", dictionary[cnt - 1].meaning, 100);
	fputs(" ", fp);
	fputs(dictionary[cnt - 1].meaning, fp);
	

	printf("=====�߰��Ϸ�=====\n");
}

void menu(){
	int choice=0;
	do
	{
		printf("\n\n====================================================================\n");
		printf("============================�ܾ��� �޴�=============================\n");

		printf("[1]��Ϻ��� [2]�ܾ� �߰� [3]�ܾ� �˻� [4]����   ����� �ܾ�� : %d\n", cnt);
		printf("\n====================================================================\n");

		scanf_s("%d", &choice);
		getchar();

		switch (choice)
		{
		case 1: list(); break;
		case 2: append(); getchar(); break;
		case 3: search(); getchar(); break;
		case 4: printf("\n�ּҷ� ���α׷��� �����մϴ�.\n"); return;

		default: printf("�޴� ��ȣ�� �ٽ� Ȯ�����ּ���\n");
		}
	} while (choice != 4 || cnt <= 100);
}

int main()
{
	fp = fopen("dictionary.txt", "r+");
	if (fp == NULL)
	{
		printf("error ���� �б� ����");

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