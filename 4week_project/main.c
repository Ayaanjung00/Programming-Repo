#include <stdio.h>

/*
int main(void)		1-1 한줄로 초기화
{
	char animal[4][10]=
	{
		"dog", "cat", "horse", "elephant"
	};

	printf("%s %s %s %s", animal[0], animal[1], animal[2], animal[3]);
}
*/

/*
int main(void)		1-2 계단식 초기화
{
	char animal[4][10] =
	{
		{"dog"}, 
		{"cat"}, 
		{"horse"},
		{"elephant"}
	};

	printf("%s %s %s %s", animal[0], animal[1], animal[2], animal[3]);
}
*/

/*void nameswap(int** a, int** b);		2 이름바꾸기
void main() {
   char* pa = "dog";
   char* pb = "cat";
   printf("바꾸기 전\n%s %s\n", pa, pb);

   nameswap(&pa, &pb);
   printf("바꾼 후\n%s %s", pa, pb);
}
void nameswap(int** a, int** b) {
   int *temp = *a;
   *a = *b;
   *b = temp;

}*/
/*
void aeiou_count(char (* voca)[20], int *voca1, int *voca2, int count);		3 모음개수 찾기(실패)
void main()
{
	char *voca[2][20];
	int count = 0;
	int* voca1 = 0;
	int* voca2 = 0;
	int c=0;

	for (int i = 0; i < 2; i++)
	{
		scanf_s("%s", &*voca[i],20);
	}
	aeiou_count(voca, &voca1, &voca2, c);
	printf("%d %d", voca1, voca2);
}

void aeiou_count(char(*voca)[20], int* voca1, int* voca2, int count)
{
	int c = 0;
	for (int i = 0; i < count; i++) {
		c = 0;
		for (int j = 0; voca[i][j] != '\0'; j++) {
			if (voca[i][j] == 'a' || voca[i][j] == 'e' || voca[i][j] == 'i' || voca[i][j] == 'o' || voca[i][j] == 'u') {
				c++;
			}
		}
		if (i == 0) {
			*voca1 = c;
		}
		else if (i == 1) {
			*voca2 = c;
		}
	}
}
*/