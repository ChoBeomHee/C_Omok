#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#include "OmokPlaying.h"
#include "ThreeCheck.h"
#define MAX 19	 // 판 크기

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


	while (1) {	// 게임시작
		system("cls");
		printf("		 * 오목 * (렌주룰)");
		DWORD CIN;
		DWORD mode;
		CIN = GetStdHandle(STD_INPUT_HANDLE); //마우스 재활성화
		GetConsoleMode(CIN, &mode);
		SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

		printf("\n	    선공(1번 : ○ , 2번 : ● )\n		- ");
		scanf_s("%d", &attack);

		Iniboad(boad);
		Printboad(boad);

		if (attack == 1) {
			first = 1;
			gotoxy(40, 8);
			printf("	%d번 플레이어 턴 ( ○ )", attack);
		}
		else {
			first = 2;
			gotoxy(40, 8);
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
							if (Playchoice1(boad, x, y) == 1) {
								first++;
								continue;
							}
						if (Matchplay1(boad) == 1) {
							score1++;
							printf("\n						현재 스코어\n						플레이어1 - %d : 플레이어2 - %d\n						다시하기: 1 끝내기: 0\n								_", score1, score2);
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
							printf("\n						현재 스코어\n						플레이어1 - %d : 플레이어2 - %d\n						다시하기: 1 끝내기: 0\n								_", score1, score2);
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