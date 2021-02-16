#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#define MAX 19	 // 판 크기


typedef struct {
	int r;
	int c;
}element;
void gotoxy(int x, int y);
int Matchplay1(unsigned char boad[MAX][MAX][MAX]);
void Iniboad(unsigned char boad[MAX][MAX][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			strcpy(boad[i][j], "┼ ");
}

void Draw_BadukBoard()
{

	int i;
	int j;
	//int I;                                                
	printf("┌");
	for (i = 0; i < 14; i++)
		printf(" ┬");
	printf(" ┐\n");

	for (i = 0; i < 14; i++) {
		printf("├");
		for (j = 0; j < 14; j++)
			printf(" ┼");
		printf(" ┤\n");
	}

	printf("└");
	for (i = 0; i < 14; i++)
		printf(" ┴");
	printf(" ┘");
}

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
	if (a == 1)
		a = 0;

	else
		a = (a / 2);

	strcpy(boad[b][a], "○");

	Printboad(boad);
	if (Matchplay1(boad) == 1)
		printf("	1번 플레이어 승리!");
	else
		printf("	2번 플레이어 턴");
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
		printf("	2번 플레이어 승리!");
	else
		printf("	1번 플레이어 턴");
}
// 두번째 플레이어 턴
int Matchplay1(unsigned char boad[MAX][MAX][MAX])
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
int Matchplay2(unsigned char boad[MAX][MAX][MAX])
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
	int again =2, gamenum = 1, score1 = 0, score2 = 0;
	unsigned char boad[MAX][MAX][MAX];								// 필요 변수

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

		printf("선공 : ");
		scanf_s("%d", &attack);
	
		Iniboad(boad);
		Printboad(boad);

		if (attack == 1)
			first = 1;
		else
			first = 2;
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
							if (again == 1) {
								break;
							}
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

