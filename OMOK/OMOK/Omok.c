#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#define MAX 19	 // 판 크기

void gotoxy(int x, int y);
int Matchplay1( char boad[MAX][MAX][MAX]);
void Iniboad( char boad[MAX][MAX][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			strcpy(boad[i][j], "┼ ");
}
// 오목판 초기화
int whithCheck(char boad[MAX][MAX][MAX], int a, int b)
{
	int result = 0;
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 가로 case 1
		for (int i = 0; i < 3; i++)
		{
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}	
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 가로 case 2
		for (int i = -1; i < 2; i++)
		{
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) { // 가로 case 3
		for (int i = -2; i < 1; i++)
		{
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
}
// 가로 검사
int HeightCheck(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 세로 case 1
		for (int i = 0; i < 3; i++)
		{
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 세로 case 2
		for (int i = -1; i < 2; i++)
		{
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && strcmp(boad[a][b], "○") == 0) { // 세로 case 3
		for (int i = -2; i < 1; i++)
		{
			if (HeightThreecheck(boad, a, b + i) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
}
// 세로 검사
int diagonalCheck1(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 대각선 case 1
		for (int i = 0; i < 3; i++)
		{
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 대각선 case 2
		for (int i = -1; i < 2; i++)
		{
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) { // 대각선 case 3
		for (int i = -2; i < 1; i++)
		{
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a, b + i);
		}
		return result;
	}
}
// 대각선 검사 1
int diagonalCheck2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 가로 case 1
		for (int i = 0; i < 3; i++)
		{
			if (diagonalThreecheck2(boad, a, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 가로 case 2
		for (int i = -1; i < 2; i++)
		{
			if (diagonalThreecheck2(boad, a, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) { // 가로 case 3
		for (int i = -2; i < 1; i++)
		{
			if (diagonalThreecheck2(boad, a, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
}
// 대각선 검사
int whithThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) ||						// 세로 검사
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) ||		// 대각선 1 검사
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) ||		// 대각선 2 검사
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0))
		return 1;
}
// 33가로 검사
int HeightThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) ||					// 가로 검사
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) ||		// 대각선 1 검사
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) ||		// 대각선 2 검사
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0))
		return 1;
}
// 33세로 검사
int diagonalThreecheck1(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) ||					// 세로 검사
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0))
		return 1;

	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) ||					// 가로 검사
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) ||		// 대각선 2 검사
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0))
		return 1;
}
// 33대각선1 검사
int diagonalThreecheck2(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) ||					// 가로 검사
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) ||		// 대각선 1 검사
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) ||					// 세로 검사
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0))
		return 1;

}
// 33대각선2 검사
								//	33검사 Case 1
/*int whithTreeCheckCase2(char boad[MAX][MAX][MAX], int a, int b) {
	if (whithCheck(boad, b, a) != 1)	// 33결과가 0이면
		if (strcmp(boad[a][b], boad[a][b + 2] == 0 || strcmp(boad[a][b], boad[a][b + 2] == 0)))
			return 1;
}
int HeightCheckCase2(char boad[MAX][MAX][MAX], int a, int b) {

}
int diagonalTreeCheckCase12(char boad[MAX][MAX][MAX], int a, int b) {

}
int diagonalTreeCheckCase22(char boad[MAX][MAX][MAX], int a, int b) {

}*/
void Printboad(char boad[MAX][MAX][MAX]) {
	gotoxy(0, 0);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			fputs(boad[i][j], stdout);
		}
		printf("\n");
	}
}
// 오목판 출력
void Playchoice1(char boad[MAX][MAX][MAX], int a, int b) {
	static int n = 1;
	if (a == 1)
		a = 0;

	else
		a = (a / 2);

	strcpy(boad[b][a], "○");
	if (whithCheck(boad, b, a) == 1 || HeightCheck(boad, b, a) == 1 || diagonalCheck1(boad, b, a) == 1 || diagonalCheck2(boad, b, a) == 1)
		printf("		테스트 성공%d", n);
	Printboad(boad);
	if (Matchplay1(boad) == 1)
		printf("	1번 플레이어 승리! ( ○ )");
	else
		printf("	2번 플레이어 턴 ( ● )");
	n++;
}
// 첫번째 플레이어 턴
void Playchoice2(char boad[MAX][MAX][MAX], int a, int b) {
	if (a == 1)
		a = 0;

	else
		a = (a / 2);

	strcpy(boad[b][a], "●");

	Printboad(boad);
	if (Matchplay2(boad) == 1)
		printf("	2번 플레이어 승리! ( ● ) ");
	else
		printf("	1번 플레이어 턴 ( ○ )");
}
// 두번째 플레이어 턴
int Matchplay1(char boad[MAX][MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[i][j], "○") == 0 && (strcmp(boad[i][j], boad[i][j + 1]) == 0 && strcmp(boad[i][j], boad[i][j + 2]) == 0 && strcmp(boad[i][j], boad[i][j + 3]) == 0 && strcmp(boad[i][j], boad[i][j + 4]) == 0))
			{
				return 1;
			}
		}
	}// 가로 5개 승리 검사
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[j][i], "○") == 0 && (strcmp(boad[j][i], boad[j + 1][i]) == 0 && strcmp(boad[j][i], boad[j + 2][i]) == 0 && strcmp(boad[j][i], boad[j + 3][i]) == 0 && strcmp(boad[j][i], boad[j + 4][i]) == 0))
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "○") == 0 && (strcmp(boad[i][j], boad[i + 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i + 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i + 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i + 4][j + 4]) == 0))
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "○") == 0 && (strcmp(boad[i][j], boad[i - 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i - 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i - 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i - 4][j + 4]) == 0))
			{
				return 1;
			}
		}
	}
}
// 첫번째 플레이어 승리 검사
int Matchplay2( char boad[MAX][MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[i][j], "●") == 0 && (strcmp(boad[i][j], boad[i][j + 1]) == 0 && strcmp(boad[i][j], boad[i][j + 2]) == 0 && strcmp(boad[i][j], boad[i][j + 3]) == 0 && strcmp(boad[i][j], boad[i][j + 4]) == 0))
				return 1;
		}
	}// 가로 5개 승리 검사
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[j][i], "●") == 0 && (strcmp(boad[j][i], boad[j + 1][i]) == 0 && strcmp(boad[j][i], boad[j + 2][i]) == 0 && strcmp(boad[j][i], boad[j + 3][i]) == 0 && strcmp(boad[j][i], boad[j + 4][i]) == 0))
				return 1;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "●") == 0 && (strcmp(boad[i][j], boad[i + 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i + 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i + 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i + 4][j + 4]) == 0))
				return 1;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "●") == 0 && (strcmp(boad[i][j], boad[i - 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i - 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i - 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i - 4][j + 4]) == 0))
				return 1;
		}
	}
}// 승리 조건
// 두번째 플레이어 승리 검사
HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치
int be_input()
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}
int get_input(WORD* vkey, COORD* pos)
{
	INPUT_RECORD input_record;
	DWORD input_count;

	ReadConsoleInput(CIN, &input_record, 1, &input_count);
	switch (input_record.EventType) {
	case MOUSE_EVENT:
		if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);

			*pos = input_record.Event.MouseEvent.dwMousePosition;
			pos->X -= csbi.srWindow.Left;
			pos->Y -= csbi.srWindow.Top;

			return MOUSE_EVENT;
		}
		break;

	}

	FlushConsoleInputBuffer(CIN);
	return 0;
}
void gotoxy(int x, int y)      // 좌표 보내기 gotoxy
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
int main()
{

	int first;
	int attack;
	int again = 2, score1 = 0, score2 = 0;
	 char boad[MAX][MAX][MAX];								// 필요 변수

	DWORD mode;
	WORD key;
	COORD pos;

	int event;        // 마우스 이벤트에 이용
	int x;            // 마우스의 x좌표 저장소
	int y;            // 마우스의 y좌표 저장소

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) {
		system("cls");

		DWORD CIN;
		DWORD mode;
		CIN = GetStdHandle(STD_INPUT_HANDLE); //마우스 재활성화
		GetConsoleMode(CIN, &mode);
		SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

		printf("선공(1번 : ○ , 2번 : ● )\n - ");
		scanf_s("%d", &attack);
	
		Iniboad(boad);
		Printboad(boad);
		
		if (attack == 1) {
			first = 1;
			printf("	%d번 플레이어 턴 ( ○ )", attack);
		}
		else {
			first = 2;
			printf("	%d번 플레이어 턴 ( ● )", attack);
		}

		do
		{
			if (be_input()) {
				if (get_input(&key, &pos) != 0)
				{
					first++;
					MOUSE_EVENT;
					x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
					y = pos.Y;

					if (first % 2 == 0) {
						Playchoice1(boad, x, y);
						if (Matchplay1(boad) == 1) {
							score1++;
							printf("\n	현재 스코어\n	플레이어1 - %d\n	플레이어2 - %d\n	다시하기: 1 끝내기: 0\n  _", score1, score2);
							scanf_s("%d", &again);
							if (again == 1)
								break;
							else
								return 0;
						}
					}
					else {
						Playchoice2(boad, x, y);
						if (Matchplay2(boad) == 1) {
							score2++;
							printf("\n	현재 스코어\n	플레이어1 - %d\n	플레이어2 - %d\n	다시하기: 1 끝내기: 0\n  _", score1, score2);
							scanf_s("%d", &again);
							if (again == 1) 
								break;
							else
								return 0;
						}
					}
				}
			}
		} while (1);
	}
	return 0;
}