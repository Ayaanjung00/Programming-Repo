#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gsp(char str[])
{
    int len, i;
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            return i;
    }
}

int cn(char str1[], char str2[])
{
    int idx1 = gsp(str1);
    int idx2 = gsp(str2);

    if (idx1 != idx2)
        return 0;

    else
        return !strncmp(str1, str2, idx1);
}

int ca(char str1[], char str2[])
{
    int idx1 = gsp(str1);
    int idx2 = gsp(str2);
    int ag1, ag2;

    ag1 = atoi(&str1[idx1 + 1]);
    ag2 = atoi(&str2[idx2 + 1]);

    if (ag1 == ag2)
        return 1;

    else
        return 0;
}

int main(void)
{
    char str1[30];
    char str2[30];
    char str3[30];

    printf("첫 번째 사람 정보 입력: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1) - 1] = 0;

    printf("두 번째 사람 정보 입력: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2) - 1] = 0;

    printf("세 번째 사람 정보 입력: ");
    fgets(str3, sizeof(str3), stdin);
    str3[strlen(str3) - 1] = 0;

    if (cn(str1, str2))
    {
        puts("이름이 동일합니다.");
    }
    else
    {
        puts("이름이 동일하지 않습니다.");
    }

    if (ca(str1, str2))
    {
        puts("나이가 동일합니다.");
    }
    else
    {
        puts("나이가 동일하지않습니다.");
    }
    return 0;
}
