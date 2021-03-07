#include "ThreeCheck.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 19

int whithCheck(char boad[MAX][MAX][MAX], int a, int b)
{
	int result = 0;
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 가로 case 1
		if (strcmp(boad[a][b + 3], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (whithThreecheck(boad, a, b + i) == 1)
					result = whithThreecheck(boad, a, b + i);
			}
		}		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 가로 case 2
		if (strcmp(boad[a][b - 2], "●") != 0 && strcmp(boad[a][b + 2], "●") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (whithThreecheck(boad, a, b + i) == 1)
					result = whithThreecheck(boad, a, b + i);
			}
		}		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) { // 가로 case 3
		if (strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (whithThreecheck(boad, a, b + i) == 1)
					result = whithThreecheck(boad, a, b + i);
			}
		}		return result;
	}
}
// 가로 검사
int HeightCheck(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && strcmp(boad[a][b], "○") == 0) {// 세로 case 1
		if (strcmp(boad[a + 3][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (HeightThreecheck(boad, a + i, b) == 1)
					result = HeightThreecheck(boad, a + i, b);
			}
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 세로 case 2
		if (strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 2][b], "●") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (HeightThreecheck(boad, a + i, b) == 1)
					result = HeightThreecheck(boad, a + i, b);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && strcmp(boad[a][b], "○") == 0) { // 세로 case 3
		if (strcmp(boad[a - 3][b], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (HeightThreecheck(boad, a + i, b) == 1)
					result = HeightThreecheck(boad, a + i, b);
			}
			return result;
		}
	}
}
// 세로 검사
int diagonalCheck1(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 대각선 case 1
		if (strcmp(boad[a + 1][b - 1], "●") != 0 && strcmp(boad[a - 3][b + 3], "●") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (diagonalThreecheck1(boad, a - i, b + i) == 1)
					result = diagonalThreecheck1(boad, a - i, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 대각선 case 2
		if (strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (diagonalThreecheck1(boad, a - i, b + i) == 1)
					result = diagonalThreecheck1(boad, a, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) { // 대각선 case 3
		if (strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 1][b + 1], "●") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (diagonalThreecheck1(boad, a - i, b + i) == 1)
					result = diagonalThreecheck1(boad, a, b + i);
			}
			return result;
		}
	}
}
// 대각선 검사 1
int diagonalCheck2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 대각선2 case 1
		if (strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (diagonalThreecheck2(boad, a + i, b + i) == 1)
					result = diagonalThreecheck2(boad, a + i, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && strcmp(boad[a][b], "○") == 0) {	// 대각선2 case 2
		if (strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (diagonalThreecheck2(boad, a + i, b + i) == 1)
					result = diagonalThreecheck2(boad, a + i, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) { // 대각선2 case 3
		if (strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (diagonalThreecheck2(boad, a + i, b + i) == 1)
					result = diagonalThreecheck2(boad, a + i, b + i);
			}
			return result;
		}
	}
}
// 대각선 검사 2


int whithThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if (((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && (strcmp(boad[a + 3][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0)) ||				// 세로 검사
		((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && (strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 2][b], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && (strcmp(boad[a - 3][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0)))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && ((strcmp(boad[a + 1][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) && strcmp(boad[a + 4][b], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && ((strcmp(boad[a - 1][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0) && strcmp(boad[a - 4][b], "●") != 0))		// 세로 검사 2(New)
		return 1;


	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a + 1][b], "●") != 0 && strcmp(boad[a + 3][b], "●") != 0) && strcmp(boad[a - 2][b], "●") != 0)) ||
			 ((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a - 1][b], "●") != 0 && strcmp(boad[a - 3][b], "●") != 0) && strcmp(boad[a + 2][b], "●") != 0)))		// 세로 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) && strcmp(boad[a + 4][b], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a - 2][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0) && strcmp(boad[a - 4][b], "●") != 0))		// 세로 검사 4(New)
		return 1;
	//세로 검사
	else if
		((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && (strcmp(boad[a - 3][b + 3], "●") != 0 && strcmp(boad[a + 1][b - 1], "●") != 0) ||				// 대각선 1 검사
			(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && (strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) ||
			(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && (strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 1][b + 1], "●") != 0))
		return 1;

	/*else if
		((strcmp(boad[a][b], boad[a - 3][b + 3]) == 0 && ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a - 1][b + 1], "●") != 0) || (strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a - 2][b + 2], "●") != 0))) ||
		 (strcmp(boad[a][b], boad[a + 3][b - 3]) == 0 && ((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a + 1][b - 1], "●") != 0) || (strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a + 2][b - 2], "●") != 0))))		// 대각선1 검사 2
		return 1;
	else if
		(((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && strcmp(boad[a + 1][b - 1], "●") != 0) ||
			(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a - 1][b + 1], "●") != 0)						// 대각선1 검사 3
		return 1;*/
	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 2][b + 2], "●") != 0 && strcmp(boad[a - 4][b + 4], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a + 4][b - 4], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0))		// 대각선1 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 1][b - 1], "●") != 0 && strcmp(boad[a + 4][b - 4], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0)) ||
			 ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 1][b + 1], "●") != 0 && strcmp(boad[a - 4][b + 4], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0)))		// 대각선1 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && ((strcmp(boad[a - 3][b + 3], "●") != 0 && strcmp(boad[a + 2][b - 2], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && ((strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0))		// 대각선1 검사 4(New)
		return 1;


	// 대각선1 검사

	else if
		((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && (strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) ||	// 대각선 2 검사
			(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && (strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) ||
			(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && (strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 2][b - 2], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) && strcmp(boad[a - 4][b - 4], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0) && strcmp(boad[a + 4][b + 4], "●") != 0))		// 대각선2 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 1][b + 1], "●") != 0 && strcmp(boad[a + 4][b + 4], "●") != 0) && strcmp(boad[a - 1][b - 1], "●") != 0)) ||
			 ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 1][b - 1], "●") != 0 && strcmp(boad[a - 4][b - 4], "●") != 0) && strcmp(boad[a + 1][b + 1], "●") != 0)))		// 대각선1 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && ((strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 2][b + 2], "●") != 0) && strcmp(boad[a - 1][b - 1], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && ((strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) && strcmp(boad[a + 1][b + 1], "●") != 0))		// 대각선2 검사 4(New)
		return 1;

	// 대각선2 검사

	/*else if
		((strcmp(boad[a][b], boad[a - 3][b - 3]) == 0 && ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a - 1][b - 1], "●") != 0) || (strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a - 2][b - 2], "●") != 0))) ||
			(strcmp(boad[a][b], boad[a + 3][b + 3]) == 0 && ((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a + 1][b + 1], "●") != 0) || (strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a + 2][b + 2], "●") != 0))))		// 대각선2 검사 2
		return 1;
	else if
		((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && (strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a - 1][b - 1], "●") != 0)) ||
			(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && (strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a + 1][b + 1], "●") != 0)))						// 대각선2 검사 3
		return 1;*/
}
// 33가로 검사
int HeightThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && (strcmp(boad[a][b + 3], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) ||		// 가로 검사
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && (strcmp(boad[a][b + 2], "●") != 0 && strcmp(boad[a][b - 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && (strcmp(boad[a][b - 3], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && ((strcmp(boad[a][b + 1], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) && strcmp(boad[a][b + 4], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && ((strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) && strcmp(boad[a][b - 4], "●") != 0))		// 가로 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b + 1], "●") != 0 && strcmp(boad[a][b + 3], "●") != 0) && strcmp(boad[a][b - 2], "●") != 0)) ||
			 ((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b - 3], "●") != 0) && strcmp(boad[a][b + 2], "●") != 0)))		// 가로 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b + 2], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) && strcmp(boad[a][b + 4], "●") != 0) ||
			 (strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b - 2], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) && strcmp(boad[a][b - 4], "●") != 0))		// 가로 검사 4(New)
		return 1;
	// 가로 검사

	 else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && (strcmp(boad[a - 3][b + 3], "●") != 0 && strcmp(boad[a + 1][b - 1], "●") != 0) ||				// 대각선 1 검사
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && (strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && (strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 1][b + 1], "●") != 0))
		return 1;

	 else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 2][b + 2], "●") != 0 && strcmp(boad[a - 4][b + 4], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0) ||
		 (strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a + 4][b - 4], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0))		// 대각선1 검사 2(New)
		return 1;

	 else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 1][b - 1], "●") != 0 && strcmp(boad[a + 4][b - 4], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0)) ||
		 ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 1][b + 1], "●") != 0 && strcmp(boad[a - 4][b + 4], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0)))		// 대각선1 검사 3(New)
		return 1;

	 else if ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && ((strcmp(boad[a - 3][b + 3], "●") != 0 && strcmp(boad[a + 2][b - 2], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0) ||
		 (strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && ((strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0))		// 대각선1 검사 4(New)
		return 1;
	// 대각선1 검사

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && (strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) ||	// 대각선 2 검사
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && (strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && (strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 2][b - 2], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) && strcmp(boad[a - 4][b - 4], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0) && strcmp(boad[a + 4][b + 4], "●") != 0))		// 대각선2 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 1][b + 1], "●") != 0 && strcmp(boad[a + 4][b + 4], "●") != 0) && strcmp(boad[a - 1][b - 1], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 1][b - 1], "●") != 0 && strcmp(boad[a - 4][b - 4], "●") != 0) && strcmp(boad[a + 1][b + 1], "●") != 0)))		// 대각선1 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && ((strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 2][b + 2], "●") != 0) && strcmp(boad[a - 1][b - 1], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && ((strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) && strcmp(boad[a + 1][b + 1], "●") != 0))		// 대각선2 검사 4(New)
		return 1;

	// 대각선2 검사
}
// 33세로 검사
int diagonalThreecheck1(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && (strcmp(boad[a + 3][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) ||				// 세로 검사
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && (strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 2][b], "●") != 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && (strcmp(boad[a - 3][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && ((strcmp(boad[a + 1][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) && strcmp(boad[a + 4][b], "●") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && ((strcmp(boad[a - 1][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0) && strcmp(boad[a - 4][b], "●") != 0))		// 세로 검사 2(New)
		return 1;


	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a + 1][b], "●") != 0 && strcmp(boad[a + 3][b], "●") != 0) && strcmp(boad[a - 2][b], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a - 1][b], "●") != 0 && strcmp(boad[a - 3][b], "●") != 0) && strcmp(boad[a + 2][b], "●") != 0)))		// 세로 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) && strcmp(boad[a + 4][b], "●") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a - 2][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0) && strcmp(boad[a - 4][b], "●") != 0))		// 세로 검사 4(New)
		return 1;

	//세로 검사

	else if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && (strcmp(boad[a][b + 3], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) ||		// 가로 검사
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && (strcmp(boad[a][b + 2], "●") != 0 && strcmp(boad[a][b - 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && (strcmp(boad[a][b - 3], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && ((strcmp(boad[a][b + 1], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) && strcmp(boad[a][b + 4], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && ((strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) && strcmp(boad[a][b - 4], "●") != 0))		// 가로 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b + 1], "●") != 0 && strcmp(boad[a][b + 3], "●") != 0) && strcmp(boad[a][b - 2], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b - 3], "●") != 0) && strcmp(boad[a][b + 2], "●") != 0)))		// 가로 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b + 2], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) && strcmp(boad[a][b + 4], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b - 2], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) && strcmp(boad[a][b - 4], "●") != 0))		// 가로 검사 4(New)
		return 1;

	// 가로 검사

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && (strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) ||	// 대각선 2 검사
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && (strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && (strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 2][b - 2], "●") != 0 && strcmp(boad[a + 1][b + 1], "●") != 0) && strcmp(boad[a - 4][b - 4], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 2][b + 2], "●") != 0 && strcmp(boad[a - 1][b - 1], "●") != 0) && strcmp(boad[a + 4][b + 4], "●") != 0))		// 대각선2 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 1][b + 1], "●") != 0 && strcmp(boad[a + 4][b + 4], "●") != 0) && strcmp(boad[a - 1][b - 1], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 1][b - 1], "●") != 0 && strcmp(boad[a - 4][b - 4], "●") != 0) && strcmp(boad[a + 1][b + 1], "●") != 0)))		// 대각선1 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && ((strcmp(boad[a - 3][b - 3], "●") != 0 && strcmp(boad[a + 2][b + 2], "●") != 0) && strcmp(boad[a - 1][b - 1], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && ((strcmp(boad[a + 3][b + 3], "●") != 0 && strcmp(boad[a - 2][b - 2], "●") != 0) && strcmp(boad[a + 1][b + 1], "●") != 0))		// 대각선2 검사 4(New)
		return 1;

	// 대각선2 검사
}
// 33대각선1 검사
int diagonalThreecheck2(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && (strcmp(boad[a][b + 3], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) ||		// 가로 검사
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && (strcmp(boad[a][b + 2], "●") != 0 && strcmp(boad[a][b - 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && (strcmp(boad[a][b - 3], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && ((strcmp(boad[a][b + 1], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) && strcmp(boad[a][b + 4], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && ((strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) && strcmp(boad[a][b - 4], "●") != 0))		// 가로 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b + 1], "●") != 0 && strcmp(boad[a][b + 3], "●") != 0) && strcmp(boad[a][b - 2], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b - 1], "●") != 0 && strcmp(boad[a][b - 3], "●") != 0) && strcmp(boad[a][b + 2], "●") != 0)))		// 가로 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b + 2], "●") != 0 && strcmp(boad[a][b - 1], "●") != 0) && strcmp(boad[a][b + 4], "●") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b - 2], "●") != 0 && strcmp(boad[a][b + 1], "●") != 0) && strcmp(boad[a][b - 4], "●") != 0))		// 가로 검사 4(New)
		return 1;

	// 가로 검사

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && (strcmp(boad[a - 3][b + 3], "●") != 0 && strcmp(boad[a + 1][b - 1], "●") != 0) ||				// 대각선 1 검사
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && (strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && (strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 1][b + 1], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 2][b + 2], "●") != 0 && strcmp(boad[a - 4][b + 4], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 2][b - 2], "●") != 0 && strcmp(boad[a + 4][b - 4], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0))		// 대각선1 검사 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 1][b - 1], "●") != 0 && strcmp(boad[a + 4][b - 4], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 1][b + 1], "●") != 0 && strcmp(boad[a - 4][b + 4], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0)))		// 대각선1 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && ((strcmp(boad[a - 3][b + 3], "●") != 0 && strcmp(boad[a + 2][b - 2], "●") != 0) && strcmp(boad[a - 1][b + 1], "●") != 0) ||
		(strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && ((strcmp(boad[a + 3][b - 3], "●") != 0 && strcmp(boad[a - 2][b + 2], "●") != 0) && strcmp(boad[a + 1][b - 1], "●") != 0))		// 대각선1 검사 4(New)
		return 1;

	//대각선1 검사

	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && (strcmp(boad[a + 3][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) ||				// 세로 검사
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && (strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 2][b], "●") != 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && (strcmp(boad[a - 3][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && ((strcmp(boad[a + 1][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) && strcmp(boad[a + 4][b], "●") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && ((strcmp(boad[a - 1][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0) && strcmp(boad[a - 4][b], "●") != 0))		// 세로 검사 2(New)
		return 1;


	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a + 1][b], "●") != 0 && strcmp(boad[a + 3][b], "●") != 0) && strcmp(boad[a - 2][b], "●") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a - 1][b], "●") != 0 && strcmp(boad[a - 3][b], "●") != 0) && strcmp(boad[a + 2][b], "●") != 0)))		// 세로 검사 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a + 2][b], "●") != 0 && strcmp(boad[a - 1][b], "●") != 0) && strcmp(boad[a + 4][b], "●") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a - 2][b], "●") != 0 && strcmp(boad[a + 1][b], "●") != 0) && strcmp(boad[a - 4][b], "●") != 0))		// 세로 검사 4(New)
		return 1;
}
// 33대각선2 검사
int whithCheckCase2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if (((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a][b + 2], "●") != 0) {	// 가로 case 1
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;

			else if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a][b + 1], "●") != 0) {	// 가로 case 2
		for (int i = -1; i < 2; i++)
		{
			if (i == 1)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b - 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a][b - 1], "●") != 0) { // 가로 case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -1)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b + 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a][b + 1], "●") != 0) { // 가로 case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a][b - 1], "●") != 0) { // 가로 case 5
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;

			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a][b - 2], "●") != 0) { // 가로 case 6
		for (int i = -3; i < 1; i++) {
			if (i == -2)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
}
int HeightCheckCase2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if (((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 3][b]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 2][b], "●") != 0) {	//case 1
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;

			else if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 1][b], "●") != 0) {	//case 2
		for (int i = -1; i < 3; i++)
		{
			if (i == 1)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a - 3][b]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b], "●") != 0) { // case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -1)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a + 3][b]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 1][b], "●") != 0) { // case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b], "●") != 0) { // case 5
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;

			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 3][b]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 2][b], "●") != 0) { // case 6
		for (int i = -3; i < 1; i++) {
			if (i == -2)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
}
int diagonalCheckCase12(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if (((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b + 1], "●") != 0) {	// case 1
		for (int i = 0; i < 4; i++) {
			if (i == 1)
				continue;

			else if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 1][b - 1], "●") != 0) { // case 2
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 3][b - 3]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 2][b - 2], "●") != 0) { // case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -2)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 2][b + 2], "●") != 0) { // case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b + 1], "●") != 0) { // case 5
		for (int i = -1; i < 3; i++)
		{
			if (i == 1)
				continue;

			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 3][b + 3]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b + 1], "●") != 0) { // case 6
		for (int i = -3; i < 1; i++) {
			if (i == -1)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
}
int diagonalCheckCase22(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if (((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 2][b + 2], "●") != 0) {	// case 1
		for (int i = 0; i < 4; i++) {
			if (i == 2)
				continue;

			else if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 1][b + 1], "●") != 0) { // case 2
		for (int i = -1; i < 3; i++)
		{
			if (i == 1)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b - 1], "●") != 0) { // case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -1)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a + 1][b + 1], "●") != 0) { // case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 1][b - 1], "●") != 0) { // case 5
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;

			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 3][b - 3]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && strcmp(boad[a][b], "○") == 0) && strcmp(boad[a - 2][b - 2], "●") != 0) { // case 6
		for (int i = -3; i < 1; i++) {
			if (i == -2)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
}