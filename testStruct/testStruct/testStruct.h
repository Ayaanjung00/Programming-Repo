#pragma once

//  헤더파일
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 상수정의 
#define		MAX			80
#define		BOOK_MAX	100			// 도서배열의 최대크기
#define		TXTFILENAME		"book.txt"
#define		BINFILENAME		"book.bok"

// 사용자 자료형 정의
typedef struct tBook {
	int		bookId;
	char	bookTitle[MAX];
	int		bookPages;
} tBook;

typedef struct tBookArray {
	int		bookArrayMax;		// 배열의 크기
	int		bookArrayCount;		// 배열에 저장되어 있는 데이터의 개수
	tBook	bookData[BOOK_MAX];
} tBookArray;


// 함수의 원형 정의
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





