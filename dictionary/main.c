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
    printf("뜻 입력:");
    gets(dictionary[c].meaning);
    //printf("%s", dictionary[c].meaning);

    printf("==등록결과==\n%d번\n단어:%s\n뜻:%s", c + 1, d, dictionary[c].meaning);
    //printf("%d",cnt);

}

int main() {

    while (1) {
        printf("\n단어 입력:");
        gets(dictionary[cnt].word);
        //printf("%s", dictionary[cnt].word);

        if (cnt == 0) {
            printf("등록되지 않은 단어입니다.\n");
            add(cnt, dictionary[cnt].word);
        }

        else if (cnt > 0) {
            for (int i = 0; i <= cnt; i++) {
                if (strcmp(dictionary[cnt].word,dictionary[i].word)==0) {
                    printf("이미 등록된 단어입니다.\n단어:%s\n뜻:%s", dictionary[i].word, dictionary[i].meaning);
                    break;
                }
                else {
                    printf("else 내에서 등록되지 않은 단어입니다..\n");
                    add(cnt, dictionary[cnt].word);
                    break;
                }
            }
        }
    }
}




