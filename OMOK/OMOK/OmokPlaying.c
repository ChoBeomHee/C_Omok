#include "OmokPlaying.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 19

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
int Playchoice1(char boad[MAX][MAX][MAX], int a, int b) {
	if (a == 1)
		a = 0;

	else
		a = (a / 2);

	gotoxy(20, 10);
	printf("				 정수 . 계속 진행하세요.");

	strcpy(boad[b][a], "○");
	if (whithCheckCase2(boad, b, a) == 1 || HeightCheckCase2(boad, b, a) == 1 || diagonalCheckCase12(boad, b, a) == 1 || diagonalCheckCase22(boad, b, a) == 1 ||
		whithCheck(boad, b, a) == 1 || HeightCheck(boad, b, a) == 1 || diagonalCheck1(boad, b, a) == 1 || diagonalCheck2(boad, b, a) == 1) {
		gotoxy(20, 10);
		printf("				 금수 ! 다시 입력하세요.");
		strcpy(boad[b][a], "┼ ");
		return 1;
	}

	Printboad(boad);
	if (Matchplay1(boad) == 1) {
		gotoxy(40, 8);
		printf("	1번 플레이어 승리! ( ○ )");
	}
	else {
		gotoxy(40, 8);
		printf("	2번 플레이어 턴 ( ● )");
	}
}
// 첫번째 플레이어 턴
void Playchoice2(char boad[MAX][MAX][MAX], int a, int b) {
	if (a == 1)
		a = 0;

	else
		a = (a / 2);
	gotoxy(20, 10);
	printf("				 정수 . 계속 진행하세요.");

	strcpy(boad[b][a], "●");

	Printboad(boad);
	if (Matchplay2(boad) == 1) {
		gotoxy(40, 8);
		printf("	2번 플레이어 승리! ( ● ) ");
	}
	else {
		gotoxy(40, 8);
		printf("	1번 플레이어 턴 ( ○ )");
	}
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
int Matchplay2(char boad[MAX][MAX][MAX])
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
void Iniboad(char boad[MAX][MAX][MAX]) {
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			strcpy(boad[i][j], "┼ ");
}
// 오목판 초기화