#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct oneword {
	char word[20];
	char mean[100];
}Oneword;

void addword(Oneword* ptr);
void printword(Oneword* ptr);
int checkword(Oneword* dptr, char* wptr, int cnt);
void addlist(Oneword* dptr, char* wptr);
void readDict(Oneword* dptr, int* cptr);
void printDict(Oneword* dptr, int cnt);
void writeDict(Oneword* dptr, int cnt);

int main(void)
{
	Oneword dict[100];
	char in_word[20];
	int cnt = 0;

	readDict(dict, &cnt);

	printDict(dict, cnt);


	while (1) {
		printf("If you want insert stop? You have to insert 'q'\n");
		printf("name\n");
		fgets(in_word, sizeof(in_word), stdin);
		in_word[strlen(in_word) - 1] = '\0';

		if ((strcmp((in_word), "q"))==0)
			break;

		if (	checkword(dict, in_word, cnt)) {
			continue;
		}
		addlist(dict + cnt, in_word);

		printf("[No. %2d word] %s : %s\n\n", cnt + 1, dict[cnt].word, dict[cnt].mean);
		cnt++;
	}
	writeDict(dict, cnt);
	return 0;
}

void addword(Oneword* ptr) {
	printf("name\n");
	fgets(ptr->word, sizeof(ptr->word), stdin);
	ptr->word[strlen(ptr->word) - 1] = '\0';

	printf("mean\n");
	fgets(ptr->mean, sizeof(ptr->mean), stdin);
	ptr->mean[strlen(ptr->mean) - 1] = '\0';

	return;
}

void printword(Oneword* ptr) {
	printf("%s : %s\n", ptr->word, ptr->mean);
	return;
}

int checkword(Oneword* dptr, char *wptr, int cnt) {
	for (int i = 0; i < cnt; i++) {
		if (strcmp((dptr + i)->word, wptr)==0)
		{
			printf("이미 존재하는 단어입니다.\n%s : %s\n",(dptr+i)->word, (dptr+i)->mean);
			return 1;
		}
	}
	return 0;
}

void addlist(Oneword* dptr, char* wptr)
{
	strcpy(dptr->word, wptr);

	printf("mean : ");
	fgets(dptr->mean, sizeof(dptr->mean), stdin);
	dptr->mean[strlen(dptr->mean) - 1] = '\0';

	return;
}

void readDict(Oneword* dptr, int *cptr)
{
	int i;
	FILE* fp = fopen("dict.dat", "rb");
	if (fp == NULL) {
		printf("File Open error or File is None\n");
		return;
	}
	for (i = 0; (i < 100) && (feof(fp)==0); i++) {
		fread((Oneword*)(dptr + i), sizeof(Oneword), 1, fp);
	}
	fclose(fp);
	*cptr = i - 1;
}
void printDict(Oneword* dptr, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++) {
		printf("[No. %2d word] %s : %s\n\n", i + 1, (dptr+i)->word, (dptr+i)->mean);
	}
	return;
}
void writeDict(Oneword* dptr, int cnt)
{
	int i;
	FILE* fp = fopen("dict.dat", "wb");
	if (fp == NULL) {
		printf("File Open error or File is None\n");
		return;
	}
	for (int i = 0; i < cnt; i++)
	{
		fwrite((Oneword*)(dptr + i), sizeof(Oneword), 1, fp);
	}
}






