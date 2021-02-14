#include <stdio.h> 
#include <Windows.h>
#define MAX 19	 // ������ ũ��


typedef struct {
	int r;
	int c;
}element;
void gotoxy(int x, int y);
void clearconsole() {
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Coor, &dw);
}
int Matchplay1(unsigned char boad[MAX][MAX]);
void Iniboad(unsigned char boad[MAX][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			boad[i][j] = '*';
}
void Printboad(char boad[MAX][MAX]) {
	gotoxy(0, 0);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)
			printf("%c", boad[i][j]);
		printf("\n");
	}
}
// ������ ���
void Playchoice1(char boad[MAX][MAX], int a, int b) {
	

	element tmp;
	tmp.c = b;
	tmp.r = a;
	boad[b][a] = 'O';

	Printboad(boad);
	if (Matchplay1(boad) == 1)
		printf("1�� �÷��̾� �¸�!");
	else
		printf("2�� �÷��̾� ��");
}
// ù��° �÷��̾� ��
void Playchoice2(char boad[MAX][MAX], int a, int b) {
	element tmp;
	tmp.c = b;
	tmp.r = a;
	boad[b][a] = 'X';

	Printboad(boad);
	if (Matchplay2(boad) == 1)
		printf("2�� �÷��̾� �¸�!");
	else
		printf("1�� �÷��̾� ��");
}
// �ι�° �÷��̾� ��
int Matchplay1(unsigned char boad[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (boad[i][j] == 'O' && (boad[i][j] == boad[i][j + 1] && boad[i][j] == boad[i][j + 2] && boad[i][j] == boad[i][j + 3] && boad[i][j] == boad[i][j + 4]))
				return 1;
		}
	}// ���� 5�� �¸� �˻�
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[j][i] == 'O' && (boad[j][i] == boad[j + 1][i] && boad[j][i] == boad[j + 2][i] && boad[j][i] == boad[j + 3][i] && boad[j][i] == boad[j + 4][i]))
				return 1;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[i][j] == 'O' && (boad[i][j] == boad[i + 1][j + 1] && boad[i][j] == boad[i + 2][j + 2] && boad[i][j] == boad[i + 3][j + 3] && boad[i][j] == boad[i + 4][j + 4]))
				return 1;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[i][j] == 'O' && (boad[i][j] == boad[i - 1][j + 1] && boad[i][j] == boad[i - 2][j + 2] && boad[i][j] == boad[i - 3][j + 3] && boad[i][j] == boad[i - 4][j + 4]))
				return 1;
		}
	}
}
int Matchplay2(unsigned char boad[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (boad[i][j] == 'X' && (boad[i][j] == boad[i][j + 1] && boad[i][j] == boad[i][j + 2] && boad[i][j] == boad[i][j + 3] && boad[i][j] == boad[i][j + 4]))
				return 1;
		}
	}// ���� 5�� �¸� �˻�
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[j][i] == 'X' && (boad[j][i] == boad[j + 1][i] && boad[j][i] == boad[j + 2][i] && boad[j][i] == boad[j + 3][i] && boad[j][i] == boad[j + 4][i]))
				return 1;
		}
	}// ���� 5�� �¸� �˻�
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[i][j] == 'X' && (boad[i][j] == boad[i + 1][j + 1] && boad[i][j] == boad[i + 2][j + 2] && boad[i][j] == boad[i + 3][j + 3] && boad[i][j] == boad[i + 4][j + 4]))
				return 1;
		}
	}// �밢�� 5�� �¸� �˻�
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[i][j] == 'X' && (boad[i][j] == boad[i - 1][j + 1] && boad[i][j] == boad[i - 2][j + 2] && boad[i][j] == boad[i - 3][j + 3] && boad[i][j] == boad[i - 4][j + 4]))
				return 1;
		}
	}// �밢�� 5�� �¸� �˻�
}// �¸� ����

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
	int again =2, gamenum = 1, score1 = 0, score2 = 0;
	char boad[MAX][MAX];								// �ʿ� ����

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

	while (1) {
		system("cls");

		DWORD CIN;
		DWORD mode;
		CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
		GetConsoleMode(CIN, &mode);
		SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

		printf("���� : ");
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
					x = pos.X;    // ���콺Ŭ������ x,y������ ����ǵ�����
					y = pos.Y;
					gotoxy(0, 0);
					if (first % 2 == 0) {
						Playchoice1(boad, x, y);
						if (Matchplay1(boad) == 1) {
							score1++;
							printf("\n���� ���ھ�\n �÷��̾�1 - %d\n �÷��̾�2 - %d\n�ٽ��ϱ�: 1 ������: 0\n  _", score1, score2);
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
							printf("\n���� ���ھ�\n �÷��̾�1 - %d\n �÷��̾�2 - %d\n�ٽ��ϱ�: 1 ������: 0\n  _", score1, score2);
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

