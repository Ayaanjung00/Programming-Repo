#include <stdio.h>

int main(void)
{
	// 1. ���� �ڵ��� ���� ����� ������ ����, �ڵ带 ���� �����غ� ����� ��ġ�ϴ��� Ȯ���ϼ���.
	
	/*
	int arr[3];										// int ���� �Ҵ�Ǵ� �޸� ũ��� int �� �ϳ��� 4�̴�. �迭�� 3�� ���ǵǾ����Ƿ� 3x4=12 12�� ��µ� ���̴�.
	int* pa = arr;									// arr �迭�� ������ *pa�� �����Ͽ���. 
	printf("%d %d", sizeof(arr), sizeof(pa));		// ���� ��°�� 12 4 | ���� ��°�� 12 8
	*/

	// 2. ���� �ڵ��� ���� ����� ������ ����, �ڵ带 ���� �����غ� ����� ��ġ�ϴ��� Ȯ���ϼ���.		(�ڵ尡 ������� �ʽ��ϴ�)
	
	/*
	int arr[3];
	int* pa = arr;
	printf("%u\n", pa);
	pa = pa + 1;
	arr[3] = arr[3+1];
	printf("%u ", arr[3]);
	*/
	
	// 3. ������ ���� �迭�� �ֽ��ϴ�. ������ pb�� ����ؼ� �迭 ��Ҹ� ó������ ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
	
	/*
	double arrd[4] = { 12.4, 23.1, 15.7, 31.2 };
	double* pb = arrd;
	for (int i = 0; i < 4; i++)
	{
		printf("%0.1f\n", *(pb+i));
	}
	*/

	// 4.  ���ڿ� "banana"�� ����Ű�� ������ p�� ������ ���� ����Ǿ����ϴ�. 
	
	/*
	char* p = "banana";
	for (int j = 0; j < 6; j++)
	{
		for (int i = j; i < 6; i++)
		{
			printf("%c", *(p + i));
		}
		printf("\n\n");
	}
	*/

	// 5. ���ڿ� "computerprogramming"���� 'e'�� ó������ ��Ÿ���� ��ġ�� ã�Ƽ� ����ϴ� ���α׷��� �ۼ��ϼ���. (5-1)

	/*
	char str1[20]="computerprogramming";
	printf("%s\n\n", str1);
	for (int i = 0; i < 20; i++)
	{
		if ('e' == str1[i])
			printf("%d��° index�Դϴ�.",i + 1);
	}
	*/

	// 5. ���ڿ� "computerprogramming"���� 'e'�� ó������ ��Ÿ���� ��ġ�� ã�Ƽ� ����ϴ� ���α׷��� �ۼ��ϼ���. (5-1)

	
	char* str2 = "computerprogramming";
	printf("%s\n\n", str2);
	for (int i = 0; i < 20; i++)
	{
		if ('e' == *str2++)
		{
			printf("%d��° index�Դϴ�.", i + 1);
			break;
		}
	}

}