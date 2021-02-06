#include<stdio.h>
#include<Windows.h>
#define MAX 10	 // 오목판 크기

typedef struct {
	int r;
	int c;
}element;

int Matchplay1(unsigned char boad[MAX][MAX]);
void Iniboad(unsigned char boad[MAX][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			boad[i][j] = '*';
}
int Threethree(int x, int y, char boad[MAX][MAX]) {
	if (boad[x][y] == 'O' && boad[x][y] == boad[x][y + 1] && boad[x][y] == boad[x][y + 2]) {	// 가로줄 검사
		if (boad[x][y] == 'O' && boad[x][y] == boad[x + 1][y] && boad[x + 2][y] == boad[x][y])	// 가로줄이 삼이고 세로줄 검사
			return 1;
		else if (boad[x][y] == 'O' && boad[x - 1][y + 1] == boad[x][y] && boad[x][y] == boad[x - 2][y + 2])	// 가로줄이 삼이고 대각선줄 검사
			return 1;
		else if (boad[x][y] == 'O' && boad[x][y] == boad[x + 1][y + 1] && boad[x][y] == boad[x + 2][y + 2])
			return 1;
		else return 2;
	}
}
void Printboad(char boad[MAX][MAX]) {
	printf("\n");
	printf("    0  1  2  3  4  5  6  7  8  9\n");
	printf("  =====================================\n");
	for (int i = 0; i < MAX; i++) {
		printf("%d |", i);
		for (int j = 0; j < MAX; j++)
			printf(" %c ", boad[i][j]);
		printf("\n\n");
	}
	printf("  =====================================\n");
}
// 오목판 출력
void Playchoice1(char boad[MAX][MAX]) {
	int a, b;
	printf("		1번 플레이어 턴\n 행, 열 입력 :");
	while (1)
	{
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		if (boad[a][b] == 'O' || boad[a][b] == 'X')
			printf("     다시 입력하세요 :");
		else if (Threethree(a, b, boad) == 1)
			printf("	 33입니다. 다시 입력하세요 : ");
		else {
			element tmp;
			tmp.c = a;
			tmp.r = b;
			boad[a][b] = 'O';
			break;
		}
	}
	Printboad(boad);
}
// 첫번째 플레이어 턴
void Playchoice2(unsigned char boad[MAX][MAX]) {

	int a, b;

	printf("		2번 플레이어 턴\n 행, 열 입력 :");
	while (1)
	{
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		if (boad[a][b] == 'O' || boad[a][b] == 'X')
			printf("	다시 입력하세요 :");
		else {
			element tmp;
			tmp.c = a;
			tmp.r = b;
			boad[a][b] = 'X';
			break;
		}
	}

	Printboad(boad);
}
// 두번째 플레이어 턴
int Matchplay1(unsigned char boad[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (boad[i][j] == 'O' && (boad[i][j] == boad[i][j + 1] && boad[i][j] == boad[i][j + 2] && boad[i][j] == boad[i][j + 3] && boad[i][j] == boad[i][j + 4]))
				return 1;
		}
	}// 가로 5개 승리 검사
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
	}// 가로 5개 승리 검사
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[j][i] == 'X' && (boad[j][i] == boad[j + 1][i] && boad[j][i] == boad[j + 2][i] && boad[j][i] == boad[j + 3][i] && boad[j][i] == boad[j + 4][i]))
				return 1;
		}
	}// 세로 5개 승리 검사
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[i][j] == 'X' && (boad[i][j] == boad[i + 1][j + 1] && boad[i][j] == boad[i + 2][j + 2] && boad[i][j] == boad[i + 3][j + 3] && boad[i][j] == boad[i + 4][j + 4]))
				return 1;
		}
	}// 대각선 5개 승리 검사
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (boad[i][j] == 'X' && (boad[i][j] == boad[i - 1][j + 1] && boad[i][j] == boad[i - 2][j + 2] && boad[i][j] == boad[i - 3][j + 3] && boad[i][j] == boad[i - 4][j + 4]))
				return 1;
		}
	}// 대각선 5개 승리 검사
}// 승리 조건
int main()
{
	int first;
	int again, gamenum = 1, score1 = 0, score2 = 0;
	char boad[MAX][MAX];

	printf("1번째	게임 시작!		\n선공 선택(1번, 2번 플레이어)");

	while (1)
	{
		Iniboad(boad);
		printf("선공 플레이어 : ");
		scanf_s("%d", &first);
		Printboad(boad);
		if (first == 1) {
			while (1)
			{
				Playchoice1(boad);
				if (Matchplay1(boad) == 1)
				{
					printf("플레이어 1의 승리 !\n");
					score1++;
					gamenum++;
					printf("현재 스코어 %d : %d\n계속하려면 1 그만하려면 0 ", score1, score2);
					scanf_s("%d", &again);
					if (again == 0)
						return 0;
					else
						break;
				}

				Playchoice2(boad);
				if (Matchplay2(boad) == 1)
				{
					printf("플레이어 2의 승리 !\n");
					score2++;
					gamenum++;
					printf("현재 스코어 %d :%d\n계속하려면 1 그만하려면 0 ", score1, score2);
					scanf_s("%d", &again);
					if (again == 0)
						return 0;
					else
						break;
				}
			}
		}
		else
		{
			while (1)
			{
				Playchoice2(boad);
				if (Matchplay2(boad) == 1)
				{
					printf("플레이어 2의 승리 !\n");
					score2++;
					gamenum++;
					printf("현재 스코어 %d :%d\n계속하려면 1 그만하려면 0 ", score1, score2);
					scanf_s("%d", &again);
					if (again == 0)
						return 0;
					else
						break;
				}

				Playchoice1(boad);
				if (Matchplay1(boad) == 1)
				{
					printf("플레이어 1의 승리 !\n");
					score1++;
					gamenum++;
					printf("현재 스코어 %d : %d\n계속하려면 1 그만하려면 0 ", score1, score2);
					scanf_s("%d", &again);
					if (again == 0)
						return 0;
					else
						break;
				}
			}
		}
	}
	return 0;

}