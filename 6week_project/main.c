#include <stdio.h>

#include <stdlib.h>  // rand()�Լ��� �����ϴ� ���̺귯��

#include <time.h>   // time()�Լ��� �����ϴ� ���̺귯��


int main(void) {

	srand(time(NULL)); // �Ź� �ٸ� ������ �߻��ϵ��� �ϱ� ���ؼ� ���

	int random = 0;

	for (int i = 0; i < 10; i++) {

		random = rand() % 3;          // ����, ����, ���� ���� 3���� ���� ����

		printf("%d\n", random);

	}

}