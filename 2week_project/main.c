#include <stdio.h>

int main(void)
{
	// 1. 다음 코드의 실행 결과를 예측해 보고, 코드를 직접 실행해본 결과와 일치하는지 확인하세요.
	
	/*
	int arr[3];										// int 형에 할당되는 메모리 크기는 int 형 하나당 4이다. 배열이 3개 정의되었으므로 3x4=12 12가 출력될 것이다.
	int* pa = arr;									// arr 배열을 포인터 *pa로 정의하였다. 
	printf("%d %d", sizeof(arr), sizeof(pa));		// 예상 출력결과 12 4 | 실제 출력결과 12 8
	*/

	// 2. 다음 코드의 실행 결과를 예측해 보고, 코드를 직접 실행해본 결과와 일치하는지 확인하세요.		(코드가 실행되지 않습니다)
	
	/*
	int arr[3];
	int* pa = arr;
	printf("%u\n", pa);
	pa = pa + 1;
	arr[3] = arr[3+1];
	printf("%u ", arr[3]);
	*/
	
	// 3. 다음과 같은 배열이 있습니다. 포인터 pb를 사용해서 배열 요소를 처음부터 끝까지 출력하는 프로그램을 작성하세요.
	
	/*
	double arrd[4] = { 12.4, 23.1, 15.7, 31.2 };
	double* pb = arrd;
	for (int i = 0; i < 4; i++)
	{
		printf("%0.1f\n", *(pb+i));
	}
	*/

	// 4.  문자열 "banana"를 가리키는 포인터 p가 다음과 같이 선언되었습니다. 
	
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

	// 5. 문자열 "computerprogramming"에서 'e'가 처음으로 나타나는 위치를 찾아서 출력하는 프로그램을 작성하세요. (5-1)

	/*
	char str1[20]="computerprogramming";
	printf("%s\n\n", str1);
	for (int i = 0; i < 20; i++)
	{
		if ('e' == str1[i])
			printf("%d번째 index입니다.",i + 1);
	}
	*/

	// 5. 문자열 "computerprogramming"에서 'e'가 처음으로 나타나는 위치를 찾아서 출력하는 프로그램을 작성하세요. (5-1)

	
	char* str2 = "computerprogramming";
	printf("%s\n\n", str2);
	for (int i = 0; i < 20; i++)
	{
		if ('e' == *str2++)
		{
			printf("%d번째 index입니다.", i + 1);
			break;
		}
	}

}