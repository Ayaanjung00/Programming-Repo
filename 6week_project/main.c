#include <stdio.h>

#include <stdlib.h>  // rand()�Լ��� �����ϴ� ���̺귯��

#include <time.h>   // time()�Լ��� �����ϴ� ���̺귯��

#include <string.h>	// strcmp()�Լ��� �����ϴ� ���̺귯��

int win = 0;
int draw = 0;

int game(int player, int ai);

int main(void) {

	char sel[][7] = { NULL };
	srand(time(NULL));
	char rsp[3][7] = { "����", "����", "��" };
	
	while(1)
	{
		int ai, player = 0;
		ai = (rand() % 3 + 1);

		printf("�����Ͻÿ�\n1. ���� 2. ����, 3. �� : ");
		scanf_s("%s", &sel, 7);

		for (int i = 0; i < 3; i++) {
			int num = strcmp(sel[0], rsp[i]);
			if (num == 0) {
				player = i + 1;
			}

		}
		printf("���� ������ %d�� '%s'�Դϴ�.\n", player, sel);
		if (game(player, ai) == 0) break;
	}
	printf("������ ��� : %d�� %d��", win, draw);
}

int game(int player, int ai) 
{
	if (player == 1) {
		printf("����� ������ ����, ");
		if (ai == 1) {
			printf("��ǻ�ʹ� ������ ����, ");
			printf("�����ϴ�.\n");
			draw++;
		}
		else if (ai == 2) {
			printf("��ǻ�ʹ� ������ ����, ");
			printf("�̰���ϴ�.\n");
			win++;
		}
		else if (ai == 3) {
			printf("��ǻ�ʹ� ���� ����, ");
			printf("�����ϴ�.\n");
			return 0;
		}
	}
	if (player == 2) {
		printf("����� ������ ����, ");
		if (ai == 1) {
			printf("��ǻ�ʹ� ������ ����, ");
			printf("�����ϴ�.\n");
			return 0;
		}
		else if (ai == 2) {
			printf("��ǻ�ʹ� ������ ����, ");
			printf("�����ϴ�.\n");
			draw++;
		}
		else if (ai == 3) {
			printf("��ǻ�ʹ� ���� ����, ");
			printf("�̰���ϴ�.\n");
			win++;
		}
	}
	if (player == 3) {
		printf("����� ���� ����, ");
		if (ai == 1) {
			printf("��ǻ�ʹ� ������ ����, ");
			printf("�̰���ϴ�.\n");
			win++;
		}
		else if (ai == 2) {
			printf("��ǻ�ʹ� ������ ����, ");
			printf("�����ϴ�.\n");
			return 0;
		}
		else if (ai == 3) {
			printf("��ǻ�ʹ� ���� ����, ");
			printf("�����ϴ�.\n");
			draw++;
		}
	}	
}



