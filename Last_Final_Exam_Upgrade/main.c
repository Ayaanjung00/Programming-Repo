#include <stdio.h>

int giftlist[10]; // 문제2, 전역변수 선언 


int check_shoes(int gift) { // 문제3, 함수 정의 
//    if(gift==5) 
//		return 1;
//    else 
//		return 0;
	return !(gift % 5);
}

int main(void)
{

	// 문제 1: 사용자로부터 선물 코드 1개를 입력 받아 gift라는 변수에 저장하시오.
	//         (변수 선언, 사용자입력함수 사용)
	int gift;
	printf("선물 코드를 입력하세요: ");
	scanf_s("%d", &gift);
	printf("선물코드:%d\n", gift); // 확인용 

	// 문제 2: 사용자로부터 10개의 선물에 대한 코드를 입력 받아 giftlist라는 이름으로 접근할 수 있도록 저장하시오.
	// giftlist는전역변수로 선언하시오. (전역변수, 배열, 반복문 사용)
	int i;
	printf("선물 코드 10개를 입력하세요: ");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &giftlist[i]);
	}

	// 확인용 
	for (i = 0; i < 10; i++) {
		printf("%d ", giftlist[i]);
	}

	// 문제 3: 
	// (1) 선물 코드를 매개변수로 받아서 이것이 구두이면 1, 
	//     아니면 0을 반환하는 함수check_shoes()를 만들고 호출하시오.   
	//     1단계에서 입력 받았던 gift변수에 저장된 값을 사용합니다. 
	printf("\n구두 여부: %d\n", check_shoes(gift));

	//     giftlist에 담긴 10개도 확인해 보자 
	for (i = 0; i < 10; i++) {
		printf("%d ", check_shoes(giftlist[i]));
	}
	printf("\n");

	// (2) 메인함수에서는 만일 check_shoes()에서 반환받은 값이 1이라면
	// "이것은 교환할 예정입니다." 라고 출력하시오.
	if (check_shoes(gift)) {
		printf("이것은 교환할 예정입니다\n");
	}
	for (i = 0; i < 10; i++) {
		if (check_shoes(giftlist[i])) {
			printf("[gift %d]이것은 교환할 예정입니다\n", giftlist[i]);
		}
	}


	// 문제 4: 
	// (1) 교환 목록을 저장할 배열 exchange를 선언하고, 
	//     포인터로 접근할 수 있도록 포인터 변수 ptr도 선언합니다.
	int exchange[10] = { 0, };
	int* ptr;
	// (2) 위에서 선언한 포인터 변수가 교환 목록 배열을 가리키게 합니다.
	ptr = exchange;


	// 문제 5:
	// (1) giftlist에서 선물코드를 하나씩 꺼내서 
	//     처음 받은 선물이면 그대로 두고, 
	//     아까 받은 선물이거나 구두면 교환목록에 기록합니다. (교환목록은 포인터로 접근)
	int count[5] = { 0, };

	for (i = 0; i < 10; i++) {
		// // 구두이거나 처음 받은 선물이 아니면 기록한다       	
		if ((count[giftlist[i]] != 0) || check_shoes(giftlist[i])) {
			*ptr = giftlist[i];
			ptr++;
		}
		else {
			count[giftlist[i] - 1]++;
		}
	}

	// (2) 교환목록에 있는 것을 화면에 출력합니다. 
	printf("교환 목록 출력:");
	i = 0;
	while (exchange[i] != 0) {
		printf(" %d", exchange[i]);
		i++;
	}
	// (물품명으로 출력하면 가산점 있습니다)
	char* items[5] = { "셔츠", "바지", "모자", "운동화", "구두" };
	printf("\n교환 목록 출력:");
	i = 0;
	while (exchange[i] != 0) {
		printf(" %s", items[exchange[i] - 1]);
		i++;
	}

	// 교환하지 않을 선물 목록. 이것은 그냥 출력해 봄 
	printf("\n교환하지 않을 선물 목록 출력: ");
	for (i = 0; i < 5; i++) {
		if (count[i] != 0) {
			printf("%s ", items[i]);
		}
	}
	return 0;
}


