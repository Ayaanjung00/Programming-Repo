#include <stdio.h>

/*		Q1-1
void swap(int x, int y);

int main(void)
{
	int x = 1;
	int y = 2;

	swap(x, y);
}

void swap(int x, int y)
{
	int temp=0;
	temp = x;
	x = y;
	y = temp;

	printf("x=%d y=%d", x, y);
}
*/

/*		Q1-2
void swap(int* num1, int* num2);
int main() {
	int x = 1, y = 2;

	swap(&x, &y);
	printf("");
	printf("x=%d, y=%d\n", x, y);

	return 0;
}

void swap(int* num1, int* num2) 
{
	int temp = 0;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
*/

/*		Q2
void calculation(int* x, int* y);
int main(void)
{
	int x = 0;
	int y = 0;

	scanf_s("%d %d", &x, &y);

	calculation(&x, &y);

	return 0;
}

void calculation(int* x, int* y)
{
	float sum = 0;
	float ave = 0;

	sum = *x + *y;
	ave = sum / 2;

	printf("sum = %0.2f, ave = %0.2f", sum, ave);
}
*/

/*		Q3
void calculation(int* x, int* y);
int main(void)
{
	int x = 0;
	int y = 0;
	float sum=0;
	float ave=0;

	scanf_s("%d %d", &x, &y);

	calculation(&x, &y);
	printf("sum = %0.2f, ave = %0.2f", sum, ave);
	return 0;
}

void calculation(int* x, int* y)
{
	float sum = 0;
	float ave = 0;

	sum = *x + *y;
	ave = sum / 2;

	
	return sum, ave;
}
*/

/*		Q4
int main(void)
{
	int num[100];
	for (int i = 0; i < 100; i++)
	{
		num[i] = i+1;
	}
	for (int j = 2; j < 100; j++)
	{
		if (j % 2 == 0)
		{
			printf("%d\n", num[j]);
		}
	}
}
*/
