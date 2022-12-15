#include <stdio.h>

// 1week Q1 
/*
float change(float h);
int main(void){
	float h = 0;
	printf("Insert Heigh for cm : ");
	scanf_s("%f", &h);
	change(h);
}
float change(float h) {
	float ch = 0;
	ch = h / 100;
	printf("%0.2f cm => %0.2f m", h, ch);
	return 0;
}
*/

// 1week Q2
/*
float sum(float a, float b);
float ave(float a, float b);
int main(void) {
	float a = 0;
	float b = 0;

	printf("insert 2 numbers : ");
	scanf_s("%f %f", &a, &b);
	printf("sum = %0.2f\n",sum(a, b));
	printf("ave = %0.2f\n",ave(a, b));
}
float sum(float a, float b) {
	return a + b;
}
float ave(float a, float b) {
	return (a + b) / 2;
}
*/

// 1week Q3
/*
float cal(float a, float b);
int main(void) {
	float a = 0;
	float b = 0;

	printf("insert 2 numbers : ");
	scanf_s("%f %f", &a, &b);
	cal(a, b);
}
float cal(float a, float b) {
	float sum = a + b;
	float ave = (a + b) / 2;
	printf("sum = %0.2f\n", sum);
	printf("ave = %0.2f\n", ave);
}
*/

// 1week Q4
/*
int hap( int snum, int sum);
int main(void)
{
	int num = 0;
	int snum = 0;
	int sum = 0;

	printf("insert number : ");
	scanf_s("%d", &snum);

	hap(snum, sum);
}

int hap(int snum, int sum) {
	int i = 0;
	for ( i = 1; i <= snum; i++) {
		if (i % 5 == 0)
			continue;
		sum += i;
		if (sum > 1000) {
			printf("1000을 초과하였습니다. 연산을 중지합니다.\n");
			break;
		}
	}
	printf("%d번째 정수까지 합은 %d입니다.", i-1, sum);
}
*/

// 1week Q5
/*
int hap(int snum);
int main(void)
{
	int snum = 0;

	printf("insert number : ");
	scanf_s("%d", &snum);

	hap(snum);
	printf("%d", hap(snum));
}

int hap(int snum) {
	if (snum > 1)
		return(snum + hap(snum - 1));
}
*/

// 1week Q6
/*
int main(void)
{
	int a = 100;
	int* p = &a;
	*p = 200;
	printf("%d", a);
	printf("%d", (*p) + a);
}*/

/*
// 1week Q7
int main(void)
{
	int a = 100;
	int* p = &a;
	double* pd;
	pd = p;
	printf(
	*/

