#include <stdio.h>											//1���� ������ (1~9������)


/*
float change(float k);										// 1�� cm -> m ��ȯ

int main(void)
{
	float k = 0;
	float a = 0;
	printf("Ű�� �Է��ϼ��� (cm) : ");
	scanf_s("%f", &k);										// �Ǽ� �Է�
	
	change(k);												// �Լ� change ȣ��
	return 0;
}

float change(float k)
{
	float a = k / 100;										// ����
	printf("%0.2f", a);
}
*/

/*
float sum(float a, float b);								// 2�� �հ� ����� ���� �Լ��� �̿��Ͽ� ���
float ave(float a, float b);

int main(void)
{
	float a = 0;
	float b = 0;
	printf("�� ���� �Ǽ��� �Է��ϼ��� : ");
	scanf_s("%f %f", &a, &b);								// �Ǽ� �Է�

	sum(a, b);												// �Լ� ȣ��
	ave(a, b);												// �Լ� ȣ��

	return 0;
}

float sum(float a, float b)
{
	float c = 0;											// ����
	c = a + b;
	printf("�� �Ǽ��� ���� %0.2f�Դϴ�.\n", c);
}
float ave(float a, float b)
{
	float d = 0;
	d = (a + b)/2;
	printf("�� �Ǽ��� ����� %0.2f�Դϴ�.\n", d);
}
*/

/*
float cal(float a, float b, char op);						// 3�� �����ڸ� �Է¹޾� �հ� ����� �ϳ��� �Լ��� �̿��Ͽ� ���

int main(void)
{
	float a = 0;
	float b = 0;
	char op;
	printf("�� ���� �Ǽ��� �Է��ϼ��� : ");
	scanf_s("%f %f", &a, &b);								// �Ǽ� �Է�

	getchar();												// scanf �Ǽ� �Է� �� ����ϴ� enter �� ���� getchar();�� ���ؼ� �����͸� �޾���

	printf("�����ڸ� �Է��ϼ��� : ");
	scanf_s("%c", &op);										// ������ �Է�

	cal(a, b, op);

	return 0;
}

float cal(float a, float b, char op)
{

	if (op == '+')
	{
		printf("�� �Ǽ��� ���� %0.2f�Դϴ�.", a+b);
	}
	else if(op=='#')
	{
		printf("�� �Ǽ��� ����� %0.2f�Դϴ�.", (a + b) / 2);
	}
}*/

/*
int sum(int a);												// 4�� ������ �Է¹޾� 1���� �Է¹��� �������� ��
															// 5�� ��� ����, 1000�� �Ѿ�� �ջ��� ����
int main()
{
	int a;

	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &a);
	printf("\n");

	sum(a);
}

int sum(int a)
{
	int sum = 0;
	for (int i = 1; i <= a; i++)
	{
		if (i % 5 != 0)										// 5�� ����� �ƴѰ�� ���տ� ���ϱ� ����
		{
			sum += i;
		}
		else if (i % 5 == 0)								// 5�� ����� ��� �н�
		{
			continue;
		}

		if (sum > 1000)										// �հ谡 000�� �Ѿ�� ��� ���ϱ� ������ �ߴ��ϰ� ���°���� 1000�� �Ѿ���� ǥ��
		{
			printf("%d�� ���ؼ� ���� 1000�� �Ѿ����ϴ�.", i);
			break;
		}
	}
	printf("%d", sum);
}
*/

/*
int sum(int a);												// 5-1�� ������ �Է¹޾� 1���� �Է¹��� �������� ��
															// �ݺ���
int main()
{
	int a;

	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &a);										// �Ǽ� �Է�
	printf("\n");

	sum(a);													// �Լ� ȣ��
}

int sum(int a)
{
	int sum = 0;
	for (int i = 1; i <= a; i++)							// �Է¹��� �������� �ݺ������� ���ϱ� ����
	{
		sum+=i;
	}
	printf("%d", sum);
}
*/

/*
int sum(int a);												// 5-2�� ������ �Է¹޾� 1���� �Է¹��� �������� ��
															// ����Լ�
int main()
{
	int a;

	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &a);										// �Է¹��� ������ ������ �Է�
	printf("\n");

	printf("���� %d�Դϴ�.", sum(a));						// �Լ��� ȣ���� ���� main���� ���
}

int sum(int a)
{

	if (a <= 0)												// a�� 0���� �۰ų� ���������� �ݺ��� ����
	{
		
		return 0;
	}
	return a + sum(a - 1);									// ����Լ��� ���ؼ� a�� 0���� �۰ų� ������������ a-1��ŭ�� ������ �ݺ�
}
*/

/*
int main(void)												// 6�� ������ ���� �� ��ġ�ϴ��� Ȯ��
{
	int a = 100;											// ����� ��ġ�Ѵ�
	int* p = &a;
	*p = 200;
	printf("%d", a);										// �ּڰ��� 200���� �����Ͽ���.
	printf("%d", (*p) + a);									// a��� ������ 200�� �����Ͽ��⿡ �ּڰ� + a ������ ���� 400

	return 0;
}
*/

/*
int main(void)												// 7�� ������ ���� �� ��ġ�ϴ��� Ȯ��
{
	int a = 100;											// ����� ��ġ�Ѵ�
	int* p = &a;
	double* pd;												// �޸� ������ ���� ��ġ���� �ʾ� ������ �߻��Ѵ�.
	pd = p;													
	printf("%lf", *pd);

	return 0;
}
*/

/*
void swap(int x, int y);									// 8-1�� �����͸� ������� �ʰ� �� �� �ٲٱ�
int main(void)
{
	int x=5;
	int y=10;

	swap(x, y);												// �Լ� ȣ��
}

void swap(int x, int y)
{
	printf("ó�� x�� ���� %d, y�� ���� %d�̴�.\n", x, y);
	int temp;												// �����Ͱ� ���� �� ������ �����Ͽ� �߰�
	temp = x;												// �� ������ x���� �����Ѵ�
	x = y;													// x�� ������ y���� �����Ѵ�
	y = temp;												// y�� ������ ������� �����ص� x���� �����Ѵ�

	printf("��ȯ�� x�� ���� %d, y�� ���� %d�̴�.", x, y);
}
*/

/*
void swap(int* x, int* y);									// 8-2�� �����͸� ����ؼ� �� �� �ٲٱ�
int main()
{
	int x = 5;
	int y = 10;

	printf("ó�� x�� ���� %d, y�� ���� %d�̴�.\n", x, y);
	swap(&x, &y);											// �Լ� ȣ��
	printf("��ȯ�� x�� ���� %d, y�� ���� %d�̴�.", x, y);

	return 0;
}

void swap(int* x, int* y)
{
	int temp;												// �ּڰ��� ���ؼ� ���� ���������� �ű�� ������ �����ϴ�
	temp = *x;
	*x = *y;
	*y = temp;
}
*/

/*
float cal(float *a, float *b);								// 9�� �հ� ����� �Լ��� �̿��Ͽ� ���
															// �����͸� ���
int main(void)
{
	float a = 0;
	float b = 0;
	printf("�� ���� �Ǽ��� �Է��ϼ��� : ");
	scanf_s("%f %f", &a, &b);								// �ּڰ��� �ش��ϴ� �Ǽ��� �Է¹޴´�.

	cal(&a, &b);

	return 0;
}

float cal(float *a, float *b)
{
	float c = 0;
	float d = 0;	
	c = *a + *b;
	printf("�� �Ǽ��� ���� %0.2f�Դϴ�.\n", c);
	d = (*a + *b) / 2;
	printf("�� �Ǽ��� ����� %0.2f�Դϴ�.\n", d);
}
*/