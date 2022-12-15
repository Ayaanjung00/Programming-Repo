#pragma once

//  �������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������� 
#define		MAX			80
#define		BOOK_MAX	100			// �����迭�� �ִ�ũ��
#define		TXTFILENAME		"book.txt"
#define		BINFILENAME		"book.bok"

// ����� �ڷ��� ����
typedef struct tBook {
	int		bookId;
	char	bookTitle[MAX];
	int		bookPages;
} tBook;

typedef struct tBookArray {
	int		bookArrayMax;		// �迭�� ũ��
	int		bookArrayCount;		// �迭�� ����Ǿ� �ִ� �������� ����
	tBook	bookData[BOOK_MAX];
} tBookArray;


// �Լ��� ���� ����
int choiceMenu(void);
int insertBook(tBookArray *lib);
tBook insertBookFromKeyboard(void);

int	deleteBook(tBookArray *lib);
int	modifyBook();

int saveBook(tBookArray *lib);
int loadBook(tBookArray *lib);

int	searchBook(tBookArray *lib);
int choiceSearchMenu();
int searchBookByTitle(tBookArray *lib);
int	searchBookByCode(tBookArray *lib);

int	printBook(tBookArray *lib);
void printBookInfo(tBook book);





