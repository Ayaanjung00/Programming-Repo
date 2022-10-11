#include <stdio.h>

#include <stdlib.h>  // rand()함수를 포함하는 라이브러리

#include <time.h>   // time()함수를 포함하는 라이브러리

#include <string.h>	// strcmp()함수를 포함하는 라이브러리

int win = 0;
int draw = 0;

int game(int player, int ai);

int main(void) {

	char sel[][7] = { NULL };
	srand(time(NULL));
	char rsp[3][7] = { "바위", "가위", "보" };
	
	while(1)
	{
		int ai, player = 0;
		ai = (rand() % 3 + 1);

		printf("선택하시오\n1. 바위 2. 가위, 3. 보 : ");
		scanf_s("%s", &sel, 7);

		for (int i = 0; i < 3; i++) {
			int num = strcmp(sel[0], rsp[i]);
			if (num == 0) {
				player = i + 1;
			}

		}
		printf("나의 선택은 %d번 '%s'입니다.\n", player, sel);
		if (game(player, ai) == 0) break;
	}
	printf("게임의 결과 : %d승 %d무", win, draw);
}

int game(int player, int ai) 
{
	if (player == 1) {
		printf("당신은 바위를 선택, ");
		if (ai == 1) {
			printf("컴퓨터는 바위를 선택, ");
			printf("비겼습니다.\n");
			draw++;
		}
		else if (ai == 2) {
			printf("컴퓨터는 가위를 선택, ");
			printf("이겼습니다.\n");
			win++;
		}
		else if (ai == 3) {
			printf("컴퓨터는 보를 선택, ");
			printf("졌습니다.\n");
			return 0;
		}
	}
	if (player == 2) {
		printf("당신은 가위를 선택, ");
		if (ai == 1) {
			printf("컴퓨터는 바위를 선택, ");
			printf("졌습니다.\n");
			return 0;
		}
		else if (ai == 2) {
			printf("컴퓨터는 가위를 선택, ");
			printf("비겼습니다.\n");
			draw++;
		}
		else if (ai == 3) {
			printf("컴퓨터는 보를 선택, ");
			printf("이겼습니다.\n");
			win++;
		}
	}
	if (player == 3) {
		printf("당신은 보를 선택, ");
		if (ai == 1) {
			printf("컴퓨터는 바위를 선택, ");
			printf("이겼습니다.\n");
			win++;
		}
		else if (ai == 2) {
			printf("컴퓨터는 가위를 선택, ");
			printf("졌습니다.\n");
			return 0;
		}
		else if (ai == 3) {
			printf("컴퓨터는 보를 선택, ");
			printf("비겼습니다.\n");
			draw++;
		}
	}	
}



