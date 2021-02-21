#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h>
#define MAX 19	 // �� ũ��

void gotoxy(int x, int y);
int Matchplay1( char boad[MAX][MAX][MAX]);
void Iniboad( char boad[MAX][MAX][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			strcpy(boad[i][j], "�� ");
}
// ������ �ʱ�ȭ
int whithCheck(char boad[MAX][MAX][MAX], int a, int b)
{
	int result = 0;
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 1
		for (int i = 0; i < 3; i++)
		{
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}	
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 2
		for (int i = -1; i < 2; i++)
		{
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) { // ���� case 3
		for (int i = -2; i < 1; i++)
		{
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
}
// ���� �˻�
int HeightCheck(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 1
		for (int i = 0; i < 3; i++)
		{
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 2
		for (int i = -1; i < 2; i++)
		{
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && strcmp(boad[a][b], "��") == 0) { // ���� case 3
		for (int i = -2; i < 1; i++)
		{
			if (HeightThreecheck(boad, a, b + i) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
}
// ���� �˻�
int diagonalCheck1(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) {	// �밢�� case 1
		for (int i = 0; i < 3; i++)
		{
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && strcmp(boad[a][b], "��") == 0) {	// �밢�� case 2
		for (int i = -1; i < 2; i++)
		{
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) { // �밢�� case 3
		for (int i = -2; i < 1; i++)
		{
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a, b + i);
		}
		return result;
	}
}
// �밢�� �˻� 1
int diagonalCheck2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 1
		for (int i = 0; i < 3; i++)
		{
			if (diagonalThreecheck2(boad, a, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 2
		for (int i = -1; i < 2; i++)
		{
			if (diagonalThreecheck2(boad, a, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) { // ���� case 3
		for (int i = -2; i < 1; i++)
		{
			if (diagonalThreecheck2(boad, a, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
}
// �밢�� �˻�
int whithThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) ||						// ���� �˻�
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) ||		// �밢�� 1 �˻�
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) ||		// �밢�� 2 �˻�
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0))
		return 1;
}
// 33���� �˻�
int HeightThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) ||					// ���� �˻�
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) ||		// �밢�� 1 �˻�
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) ||		// �밢�� 2 �˻�
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0))
		return 1;
}
// 33���� �˻�
int diagonalThreecheck1(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) ||					// ���� �˻�
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0))
		return 1;

	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) ||					// ���� �˻�
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) ||		// �밢�� 2 �˻�
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0))
		return 1;
}
// 33�밢��1 �˻�
int diagonalThreecheck2(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) ||					// ���� �˻�
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) ||		// �밢�� 1 �˻�
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) ||					// ���� �˻�
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0))
		return 1;

}
// 33�밢��2 �˻�
								//	33�˻� Case 1
/*int whithTreeCheckCase2(char boad[MAX][MAX][MAX], int a, int b) {
	if (whithCheck(boad, b, a) != 1)	// 33����� 0�̸�
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
// ������ ���
void Playchoice1(char boad[MAX][MAX][MAX], int a, int b) {
	static int n = 1;
	if (a == 1)
		a = 0;

	else
		a = (a / 2);

	strcpy(boad[b][a], "��");
	if (whithCheck(boad, b, a) == 1 || HeightCheck(boad, b, a) == 1 || diagonalCheck1(boad, b, a) == 1 || diagonalCheck2(boad, b, a) == 1)
		printf("		�׽�Ʈ ����%d", n);
	Printboad(boad);
	if (Matchplay1(boad) == 1)
		printf("	1�� �÷��̾� �¸�! ( �� )");
	else
		printf("	2�� �÷��̾� �� ( �� )");
	n++;
}
// ù��° �÷��̾� ��
void Playchoice2(char boad[MAX][MAX][MAX], int a, int b) {
	if (a == 1)
		a = 0;

	else
		a = (a / 2);

	strcpy(boad[b][a], "��");

	Printboad(boad);
	if (Matchplay2(boad) == 1)
		printf("	2�� �÷��̾� �¸�! ( �� ) ");
	else
		printf("	1�� �÷��̾� �� ( �� )");
}
// �ι�° �÷��̾� ��
int Matchplay1(char boad[MAX][MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[i][j], "��") == 0 && (strcmp(boad[i][j], boad[i][j + 1]) == 0 && strcmp(boad[i][j], boad[i][j + 2]) == 0 && strcmp(boad[i][j], boad[i][j + 3]) == 0 && strcmp(boad[i][j], boad[i][j + 4]) == 0))
			{
				return 1;
			}
		}
	}// ���� 5�� �¸� �˻�
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[j][i], "��") == 0 && (strcmp(boad[j][i], boad[j + 1][i]) == 0 && strcmp(boad[j][i], boad[j + 2][i]) == 0 && strcmp(boad[j][i], boad[j + 3][i]) == 0 && strcmp(boad[j][i], boad[j + 4][i]) == 0))
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "��") == 0 && (strcmp(boad[i][j], boad[i + 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i + 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i + 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i + 4][j + 4]) == 0))
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "��") == 0 && (strcmp(boad[i][j], boad[i - 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i - 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i - 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i - 4][j + 4]) == 0))
			{
				return 1;
			}
		}
	}
}
// ù��° �÷��̾� �¸� �˻�
int Matchplay2( char boad[MAX][MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[i][j], "��") == 0 && (strcmp(boad[i][j], boad[i][j + 1]) == 0 && strcmp(boad[i][j], boad[i][j + 2]) == 0 && strcmp(boad[i][j], boad[i][j + 3]) == 0 && strcmp(boad[i][j], boad[i][j + 4]) == 0))
				return 1;
		}
	}// ���� 5�� �¸� �˻�
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX - 4; j++)
		{
			if (strcmp(boad[j][i], "��") == 0 && (strcmp(boad[j][i], boad[j + 1][i]) == 0 && strcmp(boad[j][i], boad[j + 2][i]) == 0 && strcmp(boad[j][i], boad[j + 3][i]) == 0 && strcmp(boad[j][i], boad[j + 4][i]) == 0))
				return 1;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "��") == 0 && (strcmp(boad[i][j], boad[i + 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i + 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i + 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i + 4][j + 4]) == 0))
				return 1;
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (strcmp(boad[i][j], "��") == 0 && (strcmp(boad[i][j], boad[i - 1][j + 1]) == 0 && strcmp(boad[i][j], boad[i - 2][j + 2]) == 0 && strcmp(boad[i][j], boad[i - 3][j + 3]) == 0 && strcmp(boad[i][j], boad[i - 4][j + 4]) == 0))
				return 1;
		}
	}
}// �¸� ����
// �ι�° �÷��̾� �¸� �˻�
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

	while (1) {
		system("cls");

		DWORD CIN;
		DWORD mode;
		CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
		GetConsoleMode(CIN, &mode);
		SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

		printf("����(1�� : �� , 2�� : �� )\n - ");
		scanf_s("%d", &attack);
	
		Iniboad(boad);
		Printboad(boad);
		
		if (attack == 1) {
			first = 1;
			printf("	%d�� �÷��̾� �� ( �� )", attack);
		}
		else {
			first = 2;
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
						Playchoice1(boad, x, y);
						if (Matchplay1(boad) == 1) {
							score1++;
							printf("\n	���� ���ھ�\n	�÷��̾�1 - %d\n	�÷��̾�2 - %d\n	�ٽ��ϱ�: 1 ������: 0\n  _", score1, score2);
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
							printf("\n	���� ���ھ�\n	�÷��̾�1 - %d\n	�÷��̾�2 - %d\n	�ٽ��ϱ�: 1 ������: 0\n  _", score1, score2);
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