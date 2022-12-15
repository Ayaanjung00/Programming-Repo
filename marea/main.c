#include <stdio.h>
#include <stdlib.h> 
#pragma warning(disable: 4996)

int main()
{
	char** str;
	int i = 0;
	int size = 3;

	FILE* fp = fopen("memory.txt", "r+");
	if (fp == NULL)
		puts("file open error");
	else
		puts("file open success");

	str = malloc(sizeof(char*) * size);
	for (i = 0; i < size; i++) {
		str[i] = malloc(sizeof(char) * 100);
	}

	if (str == NULL)
	{
		printf("동적할당실패");
		exit(1);
	}

	for (i = 0; i < size; i++) {
		gets(str[i]);
		fputs(str[i], fp);
		fputs("\n",fp);
	}

	for (i = 0; i < size; i++) {
		printf("%s\n", str[i]);
	}

	for (i = size; i > 0; i--)
	{
		printf("%s\n", str[i]);
	}
	fclose(fp);

	

	return 0;
}