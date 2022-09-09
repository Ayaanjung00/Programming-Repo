#include <stdio.h>

int check_code(int gift, int giftlist[5]);


int main(void)
{
	char gift;
	int giftlist[5];
	
	printf("insert gift code : ");
	scanf_s("%d", &gift);
	printf("\n%d", gift);

	printf("\ninsert giftcode list\n");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &giftlist[i]);
	}

	printf("\ncheck giftcode list\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d", &giftlist[i]);
	}

	printf("1. money  2. cloth  3. bag  4. wallet  5. food\n");
}
/*
int check_code(int gift, int giftlist[5])
{
	for (int j = 1; j < 6; j++)
	{
		if (gift == giftlist[j])
		{
			printf
		}
	}
}*/