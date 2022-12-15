#include <stdio.h>

//1번 문항
/*
void print_ddarr(int(*pa)[4]);
int main(void)
{
	int arr[3][4] = { {1,2},{3,4,5},{6,7,8,9} };
	int(* pa)[4] = arr;
	print_ddarr(*pa);

	return 0;
}

void print_ddarr(int(*pa)[4])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < sizeof(*pa)/sizeof(int); j++) {
			printf("%d ", (*(pa + i))[j]);
		}
		printf("\n");
	}
}
*/

// 2번 문항

void swap(char* str1, char* str2);
int main()
{
	char s1[20];
	gets(s1);
	char s2[20];
	gets(s2);

	char* str1 = s1;
	char* str2 = s2;
	printf("str1 = %s , str2 = %s ", str1, str2);
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
