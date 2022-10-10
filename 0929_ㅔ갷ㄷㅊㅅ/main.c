#include <stdio.h>

/*
int main(void)
{
	int gugu[3][9];
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			gugu[j][i] = (j + 2) * (i + 1);
		}
	}
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			printf("%d ", gugu[j][i]);
		}
		printf("\n");
	}
}
*/

int main(void)
{
	int ch, cs, yh, ys = 0;
	int kor, mat, eng, his = 0;
	int total[5][5];
	int subtotal[5][5];

	int grade[5][5];
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf_s("%d", &grade[j][i]);
			total[j][5] += grade[j][i];
		}
	}
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("%d ", grade[j][i]);
		}
		printf("%d\n",total[j][5]);
	}

}