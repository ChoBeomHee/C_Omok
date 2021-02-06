#include<stdio.h>
#include<Windows.h>
#define MAX 10	 // ������ ũ��

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
	if (boad[x][y] == 'O' && boad[x][y] == boad[x][y + 1] && boad[x][y] == boad[x][y + 2]) {	// ������ �˻�
		if (boad[x][y] == 'O' && boad[x][y] == boad[x + 1][y] && boad[x + 2][y] == boad[x][y])	// �������� ���̰� ������ �˻�
			return 1;
		else if (boad[x][y] == 'O' && boad[x - 1][y + 1] == boad[x][y] && boad[x][y] == boad[x - 2][y + 2])	// �������� ���̰� �밢���� �˻�
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
// ������ ���
void Playchoice1(char boad[MAX][MAX]) {
	int a, b;
	printf("		1�� �÷��̾� ��\n ��, �� �Է� :");
	while (1)
	{
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		if (boad[a][b] == 'O' || boad[a][b] == 'X')
			printf("     �ٽ� �Է��ϼ��� :");
		else if (Threethree(a, b, boad) == 1)
			printf("	 33�Դϴ�. �ٽ� �Է��ϼ��� : ");
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
// ù��° �÷��̾� ��
void Playchoice2(unsigned char boad[MAX][MAX]) {

	int a, b;

	printf("		2�� �÷��̾� ��\n ��, �� �Է� :");
	while (1)
	{
		scanf_s("%d", &a);
		scanf_s("%d", &b);

		if (boad[a][b] == 'O' || boad[a][b] == 'X')
			printf("	�ٽ� �Է��ϼ��� :");
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
int main()
{
	int first;
	int again, gamenum = 1, score1 = 0, score2 = 0;
	char boad[MAX][MAX];

	printf("1��°	���� ����!		\n���� ����(1��, 2�� �÷��̾�)");

	while (1)
	{
		Iniboad(boad);
		printf("���� �÷��̾� : ");
		scanf_s("%d", &first);
		Printboad(boad);
		if (first == 1) {
			while (1)
			{
				Playchoice1(boad);
				if (Matchplay1(boad) == 1)
				{
					printf("�÷��̾� 1�� �¸� !\n");
					score1++;
					gamenum++;
					printf("���� ���ھ� %d : %d\n����Ϸ��� 1 �׸��Ϸ��� 0 ", score1, score2);
					scanf_s("%d", &again);
					if (again == 0)
						return 0;
					else
						break;
				}

				Playchoice2(boad);
				if (Matchplay2(boad) == 1)
				{
					printf("�÷��̾� 2�� �¸� !\n");
					score2++;
					gamenum++;
					printf("���� ���ھ� %d :%d\n����Ϸ��� 1 �׸��Ϸ��� 0 ", score1, score2);
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
					printf("�÷��̾� 2�� �¸� !\n");
					score2++;
					gamenum++;
					printf("���� ���ھ� %d :%d\n����Ϸ��� 1 �׸��Ϸ��� 0 ", score1, score2);
					scanf_s("%d", &again);
					if (again == 0)
						return 0;
					else
						break;
				}

				Playchoice1(boad);
				if (Matchplay1(boad) == 1)
				{
					printf("�÷��̾� 1�� �¸� !\n");
					score1++;
					gamenum++;
					printf("���� ���ھ� %d : %d\n����Ϸ��� 1 �׸��Ϸ��� 0 ", score1, score2);
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