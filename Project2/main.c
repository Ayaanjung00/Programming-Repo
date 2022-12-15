#include <stdio.h>

void swap(char* str1, char* str2);
int main()
{
	char s1[20];
	gets(s1);
	char s2[20];
	gets(s2);

	char* str1 = s1;
	char* str2 = s2;

	swap(&str1, &str2);
	printf("str1 = %s , str2 = %s ", str1, str2);

	return 0;
}

void swap(char* str1, char* str2)
{
	char* temp;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}