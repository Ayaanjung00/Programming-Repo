# include <stdio.h>
#include <string.h>

int cnt = 0;

typedef struct OneWord {

    char word[20];
    char meaning[100];

}OW;

OW dictionary[100];

void add(int c, char* d) {

    cnt++;
    d = dictionary[cnt].word;
    printf("�� �Է�:");
    gets(dictionary[c].meaning);
    //printf("%s", dictionary[c].meaning);

    printf("==��ϰ��==\n%d��\n�ܾ�:%s\n��:%s", c + 1, d, dictionary[c].meaning);
    //printf("%d",cnt);

}

int main() {

    while (1) {
        printf("\n�ܾ� �Է�:");
        gets(dictionary[cnt].word);
        //printf("%s", dictionary[cnt].word);

        if (cnt == 0) {
            printf("��ϵ��� ���� �ܾ��Դϴ�.\n");
            add(cnt, dictionary[cnt].word);
        }

        else if (cnt > 0) {
            for (int i = 0; i <= cnt; i++) {
                if (strcmp(dictionary[cnt].word,dictionary[i].word)==0) {
                    printf("�̹� ��ϵ� �ܾ��Դϴ�.\n�ܾ�:%s\n��:%s", dictionary[i].word, dictionary[i].meaning);
                    break;
                }
                else {
                    printf("else ������ ��ϵ��� ���� �ܾ��Դϴ�..\n");
                    add(cnt, dictionary[cnt].word);
                    break;
                }
            }
        }
    }
}




