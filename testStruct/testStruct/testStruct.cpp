// testStruct.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

#include "testStruct.h"

// 함수설명 : 배열에 있는 도서정보를 이진파일로 저장함
int	saveBook(tBookArray *lib)
{
	FILE *filePointer;
	int		i;

	// 1. 텍스트 파일 이름을 입력받는다.  
	// 2. 텍스트 파일을 오픈하다. fopen()
	fopen_s(&filePointer, BINFILENAME, "wb");
	if (filePointer == NULL) {
		printf("파일이 열리지 않습니다.\n");
		return -10;					// errorCode : text file open error
	};

	//3. 텍스트파일에서 도서구조체로 값을 읽어들인다.
	for (i = 0; i < lib->bookArrayCount; i++) {
		fwrite(&lib->bookData[i], sizeof(tBook), 1, filePointer);
	}

	fclose(filePointer);

	return 1;
}

int loadBook(tBookArray *lib)
{
	FILE *filePointer;

	// 1. 이진파일 이름을 입력받는다.  
	// 2. 이진파일을 오픈하다. fopen()
	fopen_s(&filePointer, BINFILENAME, "rb");
	if ( filePointer == NULL) {
		printf("파일이 열리지 않습니다.\n");
		return -10;					// errorCode : text file open error
	};

	// lib->bookArrayCount(도서수) --> 0으로 한다.
	//4. 이진파일에서 도서구조체를 배열로 읽어들인다.
	lib->bookArrayCount = 0;
	while (!feof(filePointer)) {
		fread(&lib->bookData[lib->bookArrayCount++], sizeof(tBook), 1, filePointer);
	}

	fclose(filePointer);

	return 1;


}

// 함수설명 : 메뉴를 출력하고 사용자의 선택을 받아 선택된 번호를 리턴함
// 함수인자 : void
// 리턴값   :  선택된 번호
// 에러코드 : 없음
int choiceMenu(void)
{
	int		choiceNumber = 0;

	for(;;) {			// while(1)
		// 1. 메뉴를 출력한다.
		system("cls");
		printf("   도서 관리 메뉴  \n");
		printf("====================\n");
		printf("  1. 도서입력 \n");
		printf("  2. 도서삭제 \n");
		printf("  3. 도서수정 \n");
		printf("  4. 도서검색 \n");
		printf("  5. 도서 출력 \n");
		printf("  6. 이진파일로 저장하기 \n");
		printf("  7. 이진파일에서 불러오기 \n");
		printf("  0. 종 료 \n\n");
		printf(" # 메뉴를 선택하세요 ==> ");
		// 2. 번호를 입력받는다.
		scanf_s("%d", &choiceNumber);

		// 2.1 선택된 번호를 검사한다. (0 ~ 7)
		if ((choiceNumber < 0) || (choiceNumber > 7)) {
			printf(" 잘못된 번호입니다.");
		} else {
			break;
		}
	}
	// 3. 선택된 번호를 리턴한다.	   
	return choiceNumber;
}

int choiceInsertMenu()
{
	int		choiceInsertNumber = 0;

	for (;;) {			// while(1)
		// 1. 메뉴를 출력한다.
		system("cls");
		printf("   도서입력 메뉴  \n");
		printf("====================\n");
		printf("  1. 직접입력하기\n");
		printf("  2. 텍스트 파일에서 입력하기 \n");
		printf("  0. 메인 메뉴로 돌아가기 \n\n");
		printf(" # 메뉴를 선택하세요 ==> ");
		// 2. 번호를 입력받는다.
		scanf_s("%d", &choiceInsertNumber);

		// 2.1 선택된 번호를 검사한다. (0 ~ 2)
		if ((choiceInsertNumber < 0) || (choiceInsertNumber > 2)) {
			printf(" 잘못된 번호입니다.");
		}
		else {
			break;
		}
	}
	// 3. 선택된 번호를 리턴한다.	   
	return choiceInsertNumber;
}

//함수설명 : 도서정보를 직접입력 받아서 구조체 변수에 입력하고 그 결과를 리턴한다.
//함수인자 : viod
//리턴값 : 입력받은 tBook 변수값
tBook insertBookFromKeyboard(void)
{
	tBook	aBook;
	
	printf(" # 도서정보를 입력하세요 \n");
	printf("\n1. 도서 고유코드 : "); scanf_s("%d", &aBook.bookId);
	printf("\n2. 도서명 : "); scanf_s("%s", aBook.bookTitle, sizeof(aBook.bookTitle));   // char [] --> &를 사용하지 않음
	printf("\n3. 도서 페이지 : "); scanf_s("%d", &aBook.bookPages);
	
	return  aBook;
}
// 함수설명 : 텍스트파일에서 도서 정보를 읽어서 도서배열에 저장하는 함수
// 함수인자 : 도서배열
int insertBookFromTextFile(tBookArray *lib)
{
	FILE  *txtFilePointer;
	tBook	aBook;

	// 1. 텍스트 파일 이름을 입력받는다.  
	// 2. 텍스트 파일을 오픈하다. fopen()
	if ((fopen_s(&txtFilePointer, TXTFILENAME, "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		return -10;					// errorCode : text file open error
	};
	
	//3. 텍스트파일에서 도서구조체로 값을 읽어들인다.
	while (!feof(txtFilePointer)) {
		fscanf_s(txtFilePointer, "%d %s %d\n", &aBook.bookId, 
			aBook.bookTitle, sizeof(aBook.bookTitle), &aBook.bookPages);
		lib->bookData[lib->bookArrayCount] = aBook;
		lib->bookArrayCount++;
	}
	return 1;
}


// 함수설명 : 도서데이터를 입력하는 메인함수
//         입력방식 - 1. 직접입력, 2.텍스트 파일에서 입력
// 함수인자 : 도서배열 구조체의 포인터
// 리턴값 : 1  - 성공
//          -1  - 실패(Arrary Full)
int insertBook(tBookArray *lib)
{
	int	choiceInsertNumber = 0;
	// 0. 도서배열의 크기를 초과하는 지를 검사
	if (lib->bookArrayCount >= lib->bookArrayMax) {
		printf("\n !!! 도서배열이 꽉차있습니다. \n");
		return -1;
	}
	// 1. 검색 메뉴를 선택한다.(도서명, 코드, ...)
	// 2. 검색함수를 수행한다. 
	choiceInsertNumber = choiceInsertMenu();
	switch (choiceInsertNumber) {
		//1. insertBookFromKeyboard();  1. 직접입력
	case 1:
		lib->bookData[lib->bookArrayCount] = insertBookFromKeyboard();
		lib->bookArrayCount++;
		break;

		//2. insertBookFromTextFile(); 2. 텍스트 파일에서 입력
	case 2:
		insertBookFromTextFile(lib);
		break;

		//0. retrun; - 메인메뉴로
	case 0:
		return 0;
	}
}

int	deleteBook(tBookArray *lib)
{
	int		bookId = 0;
	int		index;
	int		moveIndex;
	// 1. 삭제할 도서 번호를 입력받는다.
	// 2. 배열에서 해당 도서를 찾는다.
	// 3.1 해당도서를 발견하면 배열에서 삭제한다.
	// 3.2 해당도서가 없으면 리턴한다.
	system("cls");
	printf("\n		도서삭제 메뉴 \n\n");
	printf("# 삭제할 도서번로를 입력하세요 ==> ");
	scanf_s("%d", &bookId);

	for (index = 0; lib->bookArrayCount; index++) {
		if (lib->bookData[index].bookId == bookId) {    // 삭제할 도서를 발견한 경우 3.1
			for (moveIndex = index; moveIndex < lib->bookArrayCount-1; moveIndex++) {
				lib->bookData[moveIndex] = lib->bookData[moveIndex + 1];
			}
			lib->bookArrayCount = lib->bookArrayCount-1;
			return 1;
		}
	}
	// 3.2 삭제할 해당도서가 없음
	printf(" 도서번호 %d인 도서가 존재하지 않습니다.\n ", bookId);

 	return 1;
}
int	modifyBook()
{
	return 1;
}

int choiceSearchMenu() 
{
	int		choiceSearchNumber = 0;

	for (;;) {			// while(1)
		// 1. 메뉴를 출력한다.
		system("cls");
		printf("   도서 검색 메뉴  \n");
		printf("====================\n");
		printf("  1. 책 이름으로 검색하기 \n");
		printf("  2. 책 코드로 검색하기 \n");
		printf("  0. 메인 메뉴로 돌아가기 \n\n");
		printf(" # 메뉴를 선택하세요 ==> ");
		// 2. 번호를 입력받는다.
		scanf_s("%d", &choiceSearchNumber);

		// 2.1 선택된 번호를 검사한다. (0 ~ 2)
		if ((choiceSearchNumber < 0) || (choiceSearchNumber > 2)) {
			printf(" 잘못된 번호입니다.");
		}
		else {
			break;
		}
	}
	// 3. 선택된 번호를 리턴한다.	   
	return choiceSearchNumber;
}

int searchBookByTitle(tBookArray *lib)
{
	char	bookTitle[MAX];
	int		i;

	printf("\n\n   도서번호로 검색하기 \n");
	printf("=================================\n");

	if (lib->bookArrayCount == 0) {
		printf(" 저장된 도서의 정보가 없습니다.\n");
	}
	// 1. 검색할 도서번호를 입력받는다.
	printf("# 검색할 도서명(책이름)을 입력하세요(예 :철학에세이) ==>");
	scanf_s("%s", bookTitle, sizeof(bookTitle));

	// 2. 도서배열에서 입력된 도서번호를 찾기  (for 0 ~ count-1)
	//    2.1 해당 도서 정보를 출력(printBookInfo())
	for (i = 0; i < lib->bookArrayCount; i++)
	{
		if(strcmp(bookTitle, lib->bookData[i].bookTitle) == 0) {			// 문자열(strig) 비교
			printBookInfo(lib->bookData[i]);
		}
	}
	system("pause");
	return 1;
}
// 함수설명 : 도서번호로 검색하는 함수
// 함수인자 : 도서 배열
int	searchBookByCode(tBookArray *lib)
{
	int		bookCode = 0;
	int		i;

	printf("\n\n   도서번호로 검색하기 \n");
	printf("=================================\n");

	if (lib->bookArrayCount == 0) {
		printf(" 저장된 도서의 정보가 없습니다.\n");
	}
	// 1. 검색할 도서번호를 입력받는다.
	printf("# 검색할 도서번호를 입력하세요(예 : 123456) ==>");
	scanf_s("%d", &bookCode);

	// 2. 도서배열에서 입력된 도서번호를 찾기  (for 0 ~ count-1)
	//    2.1 해당 도서 정보를 출력(printBookInfo())
	for (i = 0; i < lib->bookArrayCount; i++)
	{
		if (bookCode == lib->bookData[i].bookId) {			// 정수값 비교
			printBookInfo(lib->bookData[i]);
			system("pause");
			return 1;
		}
	}
	printf("해당도서는 존재하지 않습니다.\n");

	return 1;
}
// 함수설명 : 도서를 검색하는 함수 (1. 도서번호로 검색, 2. 도서명으로 검색)
// 함수인자 : 도서배열
int	searchBook(tBookArray *lib)
{
	int	choiceSearchNumber = 0;
	// 1. 검색 메뉴를 선택한다.(도서명, 코드, ...)
	// 2. 검색함수를 수행한다. 
	choiceSearchNumber = choiceSearchMenu();
	switch (choiceSearchNumber) {
		//1. searchBookByTitle();  책이름
	case 1:
		searchBookByTitle(lib);
		break;

		//2. searchBookByCode(); 책 코드
	case 2:
		searchBookByCode(lib);
		break;

		//0. retrun; - 메인메뉴로
	case 0:
		return 0;
	}
}
// 함수설명 : 책한권의 정보를 출력하는 함수
// 함수인자 : 도서구조체
// 
void printBookInfo(tBook book)
{
	printf("* 도서번호 : %d\n", book.bookId);
	printf("* 도 서 명 : %s\n", book.bookTitle);
	printf("* 페이지수 : %d\n", book.bookPages);
}
// 함수설명: 도서배열에 저장되어 있는 도서정보를 출력하는 함수
// 함수인자: 도서배열
// 
int	printBook(tBookArray *lib)
{
	int		i;
	if (lib->bookArrayCount == 0) {
		printf(" 저장된 도서의 정보가 없습니다.\n");
	}

	for (i = 0; i < lib->bookArrayCount; i++)
	{
		printBookInfo(lib->bookData[i]);
	}
	system("pause");
	return 1;
}

int main()
{
	// 도서배열을 선언
	tBookArray		SeowonLib;			// 지역변수
	int	choiceNumber = 0;

	// 초기화
	SeowonLib.bookArrayMax = BOOK_MAX;
	SeowonLib.bookArrayCount = 0;

	for (;;) {
		choiceNumber = choiceMenu();
		switch (choiceNumber) {
			//1. insertBook();
		case 1:
			insertBook(&SeowonLib);				// call by reference
			// SeowonLib = insertBook(SeowonLib);  // 함수인자, 리턴값 (x)
			break;

			//2. deleteBook();
		case 2:
			deleteBook(&SeowonLib);
			break;

			//3. modifyBook();
		case 3:
			modifyBook();
			break;

			//4. search();
		case 4:
			searchBook(&SeowonLib);
			break;

			//5. print();
		case 5:
			printBook(&SeowonLib);
			break;

			// 배열을 이진파일로 저장하기
		case 6:
			saveBook(&SeowonLib);
			break;
			
			// 이진파일에서 배열로 불러오기
		case 7:
			loadBook(&SeowonLib);
			break;

			//0. retrun; - 종료
		case 0:
			return 1;
		}
	}
}