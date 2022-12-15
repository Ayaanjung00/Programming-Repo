#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

man* insert()
{
	man* temp = (man*)malloc(sizeof(man));
	char name[20];
	char number[20];
	printf("이름 : ");
	scanf("%s", temp->name);
	printf("전화번호 : ");
	scanf("%s", temp->number);
	temp->next = NULL;
	return temp;
}

man* find_finish(man* node)
{
	while (1)
	{
		if (node->next == NULL)
			return node;
		node = node->next;
	}
}