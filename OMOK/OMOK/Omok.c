#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#include "OmokPlaying.h"
#include "ThreeCheck.h"
#define MAX 19	 // �� ũ��

HANDLE COUT = 0;    // �ܼ� ��� ��ġ
HANDLE CIN = 0;        // �ܼ� �Է� ��ġ

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

void gotoxy(int x, int y)      // ��ǥ ������ gotoxy
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
	char boad[MAX][MAX][MAX];								// �ʿ� ����

	DWORD mode;
	WORD key;
	COORD pos;

	int event;        // ���콺 �̺�Ʈ�� �̿�
	int x;            // ���콺�� x��ǥ �����
	int y;            // ���콺�� y��ǥ �����

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// ���콺 Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);


	while (1) {	// ���ӽ���
		system("cls");
		printf("		 * ���� * (���ַ�)");
		DWORD CIN;
		DWORD mode;
		CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
		GetConsoleMode(CIN, &mode);
		SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

		printf("\n	    ����(1�� : �� , 2�� : �� )\n		- ");
		scanf_s("%d", &attack);

		Iniboad(boad);
		Printboad(boad);

		if (attack == 1) {
			first = 1;
			gotoxy(40, 8);
			printf("	%d�� �÷��̾� �� ( �� )", attack);
		}
		else {
			first = 2;
			gotoxy(40, 8);
			printf("	%d�� �÷��̾� �� ( �� )", attack);
		}

		do
		{
			if (be_input()) {
				if (get_input(&key, &pos) != 0)
				{
					first++;
					MOUSE_EVENT;
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;

					if (first % 2 == 0) {
							if (Playchoice1(boad, x, y) == 1) {
								first++;
								continue;
							}
						if (Matchplay1(boad) == 1) {
							score1++;
							printf("\n						���� ���ھ�\n						�÷��̾�1 - %d : �÷��̾�2 - %d\n						�ٽ��ϱ�: 1 ������: 0\n								_", score1, score2);
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
							printf("\n						���� ���ھ�\n						�÷��̾�1 - %d : �÷��̾�2 - %d\n						�ٽ��ϱ�: 1 ������: 0\n								_", score1, score2);
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