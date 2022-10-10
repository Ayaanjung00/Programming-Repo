#include <stdio.h>

#include <stdlib.h>  // rand()함수를 포함하는 라이브러리

#include <time.h>   // time()함수를 포함하는 라이브러리


int main(void) {

	srand(time(NULL)); // 매번 다른 난수가 발생하도록 하기 위해서 사용

	int random = 0;

	for (int i = 0; i < 10; i++) {

		random = rand() % 3;          // 가위, 바위, 보를 위한 3개의 난수 생성

		printf("%d\n", random);

	}

}