#pragma warning(disable: 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "alldef.h"

int main()
{
    man* head;
    man* temp=NULL;
    head = insert();

    for (int i = 1; ; i++)
    {
        if (i >= 5)
        {
            if (temp->name == 'q')
                break;
        }
        man* temp = find_finish(head);
        temp->next = insert();
    }
    printf("\n비상연락망\n");
    while (head != NULL)
    {
        printf("이름 : %s\n", head->name);
        printf("전화번호 : %s\n", head->number);
        head = head->next;
    }
    return 0;
}