#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phone {
    char name[20];
    char num[20];
    struct phone* next;
}P;
P* input();
P* output(P* ptr);

void choice(P* ptr);
void sick(P* ptr);
void del(P* ptr);

void main() {
    int i = 0;
    char quit[3] = { 0, };
    P* head = NULL, * list = NULL, * choicehead = NULL;
    head = input();
    list = head;

    while (1) {
        if (i >= 4) {
            printf("5���� �Է��ϼ̽��ϴ�(q �Է� �� ����):");
            scanf("%s", quit);
            if (strcmp(quit, "q") == 0)break;
        }
        list->next = input();
        list = list->next;
        i++;
    }
    choicehead = output(head); //���
    choice(choicehead); //����
    sick(head); //���»��
    del(head); //�����Լ�
    //�޸�����
    P* clear = head;
    while (head->next != NULL) {
        clear = head->next;
        free(head);
        head = clear;

    }
}
P* input() {
    P* temp = malloc(sizeof(P));
    printf("�̸��� �Է��Ͻÿ�:");
    scanf("%s", temp->name);
    printf("��ȭ��ȣ�� �Է��ϼ���:");
    scanf("%s", temp->num);
    temp->next = NULL;
    return temp;
}
P* output(P* ptr) {
    int i = 0;
    printf("\n\n-----------��󿬶���------------\n\n");
    P* nlist;
    P* start = ptr;
    while (ptr != NULL) {
        nlist = ptr->next;
        printf("%s�� %s���� �����ؾ��մϴ�. %s�� ��ȭ��ȣ:%s\n", ptr->name, nlist->name, nlist->name, nlist->num);
        if (nlist->next == NULL) {
            printf("%s�� ������ �޾ҽ��ϴ�.��� �������� ������ �޾ҽ��ϴ�.\n", nlist->name);

            return start;
        }
        ptr = ptr->next; //�������� �� �����Ű�� NULL�� ����Ų�� �̷��� �ȵ� 
        i++;
    }

}
void choice(P* ptr) {
    P* nlist;
    char name[10] = { 0, };
    printf("\n�˻��Ͻ� ���� �̸��� �Է�:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s�� ������ ����� �����ϴ�\n", ptr->name);
                return;
            }
            nlist = ptr->next;
            printf("\n%s�� %s���� �����ؾ��մϴ� %s���� ��ȭ��ȣ�� %s�Դϴ�.\n", ptr->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        ptr = ptr->next;
    }
}
void sick(P* ptr) {
    P* nlist = NULL, * prelist = NULL;
    char name[10] = { 0, };
    printf("���»���� �Է��ϼ���:");
    scanf("%s", name);
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == NULL) {
                printf("%s�� ������ ����� �����ϴ�\n", ptr->name);
                return;
            }
            nlist = ptr->next; //���� ����� ������ ����� ���
            printf("\n%s���� ���ļ� ��� %s���� %s���� �����ؾ��մϴ� %s���� ��ȭ��ȣ�� %s�Դϴ�.\n", ptr->name, prelist->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        prelist = ptr; //���� ����� �ּҰ��� ��´�.
        ptr = ptr->next; //
    }
}

/*void del(p* ptr) {
    p* nlist = null, * prelist = null;
    char name[10] = { 0, };
    printf("���ӿ� ��������� �Է��ϼ���:");
    scanf("%s", name);
    while (ptr != null) {
        if (strcmp(ptr->name, name) == 0) {
            if (ptr->next == null) {
                printf("%s�� ������ ����� �����ϴ�\n", ptr->name);
                return;
            }
            nlist = ptr->next; //���� ����� ������ ����� ���
            printf("\n%s���� Ż���߽��ϴ�.�����δ� %s�� %s���� �����ؾ��մϴ�.\n", ptr->name, prelist->name, nlist->name, nlist->name, nlist->num);
            return;
        }
        prelist = ptr; //���� ����� �ּҰ��� ��´�.
        ptr = ptr->next; //
    }
}*/