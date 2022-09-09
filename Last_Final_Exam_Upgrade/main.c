#include <stdio.h>

int giftlist[10]; // ����2, �������� ���� 


int check_shoes(int gift) { // ����3, �Լ� ���� 
//    if(gift==5) 
//		return 1;
//    else 
//		return 0;
	return !(gift % 5);
}

int main(void)
{

	// ���� 1: ����ڷκ��� ���� �ڵ� 1���� �Է� �޾� gift��� ������ �����Ͻÿ�.
	//         (���� ����, ������Է��Լ� ���)
	int gift;
	printf("���� �ڵ带 �Է��ϼ���: ");
	scanf_s("%d", &gift);
	printf("�����ڵ�:%d\n", gift); // Ȯ�ο� 

	// ���� 2: ����ڷκ��� 10���� ������ ���� �ڵ带 �Է� �޾� giftlist��� �̸����� ������ �� �ֵ��� �����Ͻÿ�.
	// giftlist������������ �����Ͻÿ�. (��������, �迭, �ݺ��� ���)
	int i;
	printf("���� �ڵ� 10���� �Է��ϼ���: ");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &giftlist[i]);
	}

	// Ȯ�ο� 
	for (i = 0; i < 10; i++) {
		printf("%d ", giftlist[i]);
	}

	// ���� 3: 
	// (1) ���� �ڵ带 �Ű������� �޾Ƽ� �̰��� �����̸� 1, 
	//     �ƴϸ� 0�� ��ȯ�ϴ� �Լ�check_shoes()�� ����� ȣ���Ͻÿ�.   
	//     1�ܰ迡�� �Է� �޾Ҵ� gift������ ����� ���� ����մϴ�. 
	printf("\n���� ����: %d\n", check_shoes(gift));

	//     giftlist�� ��� 10���� Ȯ���� ���� 
	for (i = 0; i < 10; i++) {
		printf("%d ", check_shoes(giftlist[i]));
	}
	printf("\n");

	// (2) �����Լ������� ���� check_shoes()���� ��ȯ���� ���� 1�̶��
	// "�̰��� ��ȯ�� �����Դϴ�." ��� ����Ͻÿ�.
	if (check_shoes(gift)) {
		printf("�̰��� ��ȯ�� �����Դϴ�\n");
	}
	for (i = 0; i < 10; i++) {
		if (check_shoes(giftlist[i])) {
			printf("[gift %d]�̰��� ��ȯ�� �����Դϴ�\n", giftlist[i]);
		}
	}


	// ���� 4: 
	// (1) ��ȯ ����� ������ �迭 exchange�� �����ϰ�, 
	//     �����ͷ� ������ �� �ֵ��� ������ ���� ptr�� �����մϴ�.
	int exchange[10] = { 0, };
	int* ptr;
	// (2) ������ ������ ������ ������ ��ȯ ��� �迭�� ����Ű�� �մϴ�.
	ptr = exchange;


	// ���� 5:
	// (1) giftlist���� �����ڵ带 �ϳ��� ������ 
	//     ó�� ���� �����̸� �״�� �ΰ�, 
	//     �Ʊ� ���� �����̰ų� ���θ� ��ȯ��Ͽ� ����մϴ�. (��ȯ����� �����ͷ� ����)
	int count[5] = { 0, };

	for (i = 0; i < 10; i++) {
		// // �����̰ų� ó�� ���� ������ �ƴϸ� ����Ѵ�       	
		if ((count[giftlist[i]] != 0) || check_shoes(giftlist[i])) {
			*ptr = giftlist[i];
			ptr++;
		}
		else {
			count[giftlist[i] - 1]++;
		}
	}

	// (2) ��ȯ��Ͽ� �ִ� ���� ȭ�鿡 ����մϴ�. 
	printf("��ȯ ��� ���:");
	i = 0;
	while (exchange[i] != 0) {
		printf(" %d", exchange[i]);
		i++;
	}
	// (��ǰ������ ����ϸ� ������ �ֽ��ϴ�)
	char* items[5] = { "����", "����", "����", "�ȭ", "����" };
	printf("\n��ȯ ��� ���:");
	i = 0;
	while (exchange[i] != 0) {
		printf(" %s", items[exchange[i] - 1]);
		i++;
	}

	// ��ȯ���� ���� ���� ���. �̰��� �׳� ����� �� 
	printf("\n��ȯ���� ���� ���� ��� ���: ");
	for (i = 0; i < 5; i++) {
		if (count[i] != 0) {
			printf("%s ", items[i]);
		}
	}
	return 0;
}


