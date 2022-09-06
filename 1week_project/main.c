#include <stdio.h>											//1주차 과제물 (1~9번까지)


/*
float change(float k);										// 1번 cm -> m 변환

int main(void)
{
	float k = 0;
	float a = 0;
	printf("키를 입력하세요 (cm) : ");
	scanf_s("%f", &k);										// 실수 입력
	
	change(k);												// 함수 change 호출
	return 0;
}

float change(float k)
{
	float a = k / 100;										// 연산
	printf("%0.2f", a);
}
*/

/*
float sum(float a, float b);								// 2번 합과 평균을 각각 함수를 이용하여 출력
float ave(float a, float b);

int main(void)
{
	float a = 0;
	float b = 0;
	printf("두 개의 실수를 입력하세요 : ");
	scanf_s("%f %f", &a, &b);								// 실수 입력

	sum(a, b);												// 함수 호출
	ave(a, b);												// 함수 호출

	return 0;
}

float sum(float a, float b)
{
	float c = 0;											// 연산
	c = a + b;
	printf("두 실수의 합은 %0.2f입니다.\n", c);
}
float ave(float a, float b)
{
	float d = 0;
	d = (a + b)/2;
	printf("두 실수의 평균은 %0.2f입니다.\n", d);
}
*/

/*
float cal(float a, float b, char op);						// 3번 연산자를 입력받아 합과 평균을 하나의 함수를 이용하여 출력

int main(void)
{
	float a = 0;
	float b = 0;
	char op;
	printf("두 개의 실수를 입력하세요 : ");
	scanf_s("%f %f", &a, &b);								// 실수 입력

	getchar();												// scanf 실수 입력 후 사용하는 enter 의 값을 getchar();를 통해서 데이터를 받아줌

	printf("연산자를 입력하세요 : ");
	scanf_s("%c", &op);										// 연산자 입력

	cal(a, b, op);

	return 0;
}

float cal(float a, float b, char op)
{

	if (op == '+')
	{
		printf("두 실수의 합은 %0.2f입니다.", a+b);
	}
	else if(op=='#')
	{
		printf("두 실수의 평균은 %0.2f입니다.", (a + b) / 2);
	}
}*/

/*
int sum(int a);												// 4번 정수를 입력받아 1부터 입력받은 정수까지 합
															// 5의 배수 제외, 1000을 넘어가면 합산을 정지
int main()
{
	int a;

	printf("정수를 입력하세요 : ");
	scanf_s("%d", &a);
	printf("\n");

	sum(a);
}

int sum(int a)
{
	int sum = 0;
	for (int i = 1; i <= a; i++)
	{
		if (i % 5 != 0)										// 5의 배수가 아닌경우 총합에 더하기 연산
		{
			sum += i;
		}
		else if (i % 5 == 0)								// 5의 배수인 경우 패스
		{
			continue;
		}

		if (sum > 1000)										// 합계가 000이 넘어가는 경우 더하기 연산을 중단하고 몇번째에서 1000이 넘어갔는지 표시
		{
			printf("%d를 더해서 합이 1000을 넘었습니다.", i);
			break;
		}
	}
	printf("%d", sum);
}
*/

/*
int sum(int a);												// 5-1번 정수를 입력받아 1부터 입력받은 정수까지 합
															// 반복문
int main()
{
	int a;

	printf("정수를 입력하세요 : ");
	scanf_s("%d", &a);										// 실수 입력
	printf("\n");

	sum(a);													// 함수 호출
}

int sum(int a)
{
	int sum = 0;
	for (int i = 1; i <= a; i++)							// 입력받은 정수까지 반복문으로 더하기 연산
	{
		sum+=i;
	}
	printf("%d", sum);
}
*/

/*
int sum(int a);												// 5-2번 정수를 입력받아 1부터 입력받은 정수까지 합
															// 재귀함수
int main()
{
	int a;

	printf("정수를 입력하세요 : ");
	scanf_s("%d", &a);										// 입력받을 정수의 개수를 입력
	printf("\n");

	printf("합은 %d입니다.", sum(a));						// 함수를 호출한 값을 main에서 출력
}

int sum(int a)
{

	if (a <= 0)												// a가 0보다 작거나 같을때까지 반복을 진행
	{
		
		return 0;
	}
	return a + sum(a - 1);									// 재귀함수를 통해서 a가 0보다 작거나 같아질때까지 a-1만큼의 연산을 반복
}
*/

/*
int main(void)												// 6번 실행결과 예측 후 일치하는지 확인
{
	int a = 100;											// 예상과 일치한다
	int* p = &a;
	*p = 200;
	printf("%d", a);										// 주솟값을 200으로 정의하였다.
	printf("%d", (*p) + a);									// a라는 공간에 200을 저장하였기에 주솟값 + a 변수의 값은 400

	return 0;
}
*/

/*
int main(void)												// 7번 실행결과 예측 후 일치하는지 확인
{
	int a = 100;											// 예상과 일치한다
	int* p = &a;
	double* pd;												// 메모리 구간의 수가 일치하지 않아 오류가 발생한다.
	pd = p;													
	printf("%lf", *pd);

	return 0;
}
*/

/*
void swap(int x, int y);									// 8-1번 포인터를 사용하지 않고 두 값 바꾸기
int main(void)
{
	int x=5;
	int y=10;

	swap(x, y);												// 함수 호출
}

void swap(int x, int y)
{
	printf("처음 x의 값은 %d, y의 값은 %d이다.\n", x, y);
	int temp;												// 데이터가 없는 빈 공간을 정의하여 추가
	temp = x;												// 빈 공간에 x값을 저장한다
	x = y;													// x의 공간에 y값을 저장한다
	y = temp;												// y의 공간에 빈공간에 저장해둔 x값을 저장한다

	printf("교환된 x의 값은 %d, y의 값은 %d이다.", x, y);
}
*/

/*
void swap(int* x, int* y);									// 8-2번 포인터를 사용해서 두 값 바꾸기
int main()
{
	int x = 5;
	int y = 10;

	printf("처음 x의 값은 %d, y의 값은 %d이다.\n", x, y);
	swap(&x, &y);											// 함수 호출
	printf("교환된 x의 값은 %d, y의 값은 %d이다.", x, y);

	return 0;
}

void swap(int* x, int* y)
{
	int temp;												// 주솟값을 통해서 값을 저장하지만 옮기는 과정은 동일하다
	temp = *x;
	*x = *y;
	*y = temp;
}
*/

/*
float cal(float *a, float *b);								// 9번 합과 평균을 함수를 이용하여 출력
															// 포인터를 사용
int main(void)
{
	float a = 0;
	float b = 0;
	printf("두 개의 실수를 입력하세요 : ");
	scanf_s("%f %f", &a, &b);								// 주솟값에 해당하는 실수를 입력받는다.

	cal(&a, &b);

	return 0;
}

float cal(float *a, float *b)
{
	float c = 0;
	float d = 0;	
	c = *a + *b;
	printf("두 실수의 합은 %0.2f입니다.\n", c);
	d = (*a + *b) / 2;
	printf("두 실수의 평균은 %0.2f입니다.\n", d);
}
*/