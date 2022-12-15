#include <stdio.h>

int main()
{
	char arr[20];
	int sum = 0;
	printf("inset data\n");
	scanf_s("%s", &arr, 20);

	for (int i = 0; i < 20; i++) {
		if (arr[i] >= 48 && arr[i] <= 57) {
			printf("%d", arr[i]);
		}
	}
	
}