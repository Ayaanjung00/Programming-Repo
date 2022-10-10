#include <stdio.h>

/*
int sum(int x, int y);
int minus(int x, int y);
int multi(int x, int y);
int max(int x, int y);
int min(int x, int y);

int main(void)
{
    int num1;
    int num2;
    int select;
    int (*pnum)(int, int);

    while (-1)
    {
        printf("아래 항목 중 원하는 연산을 선택하세요\n");
        printf("[1]SUM [2]MINUS [3]MULTIPLY [4]MAX [5]MIN [0]PROGRAM EXIT: ");
        scanf_s("%d", &select);
        printf("\n");

        if(select == 0)
        {
            printf("프로그램을 종료합니다\n");
            return 0;
        }

        printf("2개의 정수를 입력하세요:");
        scanf_s("%d %d", &num1, &num2);

        switch (select)
        {
        case 1:
            {
                pnum = sum;
                printf("SUM: %d\n\n", pnum(num1, num2));
                break;
            }

        case 2:
            {
                pnum = minus;
                printf("MINUS: %d\n\n", pnum(num1, num2));
                break;
            }

        case 3:
            {
                pnum = multi;
                printf("MULTIPLY:%d\n\n", pnum(num1, num2));
                break;
            }

        case 4:
            {
                pnum = max;
                printf("MAX:%d\n\n", pnum(num1, num2));
                break;
            }

        case 5:
            {
                pnum = min;
                printf("MIN:%d\n\n", pnum(num1, num2));
                break;
            }
        }
    }
}

int sum(int x, int y)
{
    return x + y;
}

int minus(int x, int y)
{
    return x - y;
}

int multi(int x, int y)
{
    return x * y;
}

int max(int x, int y)
{
    if (x > y)
    {
        return x;
    }
    else if (y > x)
    {
        return y;
    }
    else
        return 0;
}

int min(int x, int y)
{
    if (x > y)
    {
        return y;
    }
    else if (y > x)
    { 
        return x;
    }
    else
        return 0;
}
*/

/*
void SimpleFuncOne(int arr1, int arr2);
void SimpleFuncTwo(int (* arr3)[4], int(*arr4)[4]);

int main(void) {

    int arr1[3];

    int arr2[4];

    int arr3[3][4];

    int arr4[2][4];

    int parr1 = &arr1;
    int parr2 = &arr2;
    int parr3 = &arr3;
    int parr4 = &arr4;


    SimpleFuncOne(arr1, arr2);
    SimpleFuncTwo(arr3, arr4);

}*/

/*
void ComplexFuncOne();
void ComplexFuncTwo();

int main(void) {

    int* arr1[3];

    int* arr2[3][5];

    int** arr3[5];

    int*** arr4[3][5];



    ComplexFuncOne(arr1, arr2);

    ComplexFuncTwo(arr3, arr4);

}
*/

/*
void main(void)
{
    int arr[3][2] = { {1,2},{3,4},{5,6} };

    printf("%d %d \n", arr[1][0], arr[0][1]);
    printf("%d %d \n", arr[2]+1, arr);
    printf("%d %d \n", arr[1][0], arr[0][1]);
    printf("%d %d \n", arr[1][0], arr[0][1]);
}
*/

int main(int argc, char* argv[])
{
    int i = 0;
    printf("전달된 문자열의 수 : %d\n", argc);

    for (i = 0; i < argc; i++)
    {
        printf("%d번째 문자열 : %s \n", i + 1, argv[i]);

        return 0;
    }
}