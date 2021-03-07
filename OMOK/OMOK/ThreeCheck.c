#include "ThreeCheck.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 19

int whithCheck(char boad[MAX][MAX][MAX], int a, int b)
{
	int result = 0;
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 1
		if (strcmp(boad[a][b + 3], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (whithThreecheck(boad, a, b + i) == 1)
					result = whithThreecheck(boad, a, b + i);
			}
		}		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 2
		if (strcmp(boad[a][b - 2], "��") != 0 && strcmp(boad[a][b + 2], "��") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (whithThreecheck(boad, a, b + i) == 1)
					result = whithThreecheck(boad, a, b + i);
			}
		}		return result;
	}
	else if ((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) { // ���� case 3
		if (strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (whithThreecheck(boad, a, b + i) == 1)
					result = whithThreecheck(boad, a, b + i);
			}
		}		return result;
	}
}
// ���� �˻�
int HeightCheck(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && strcmp(boad[a][b], "��") == 0) {// ���� case 1
		if (strcmp(boad[a + 3][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (HeightThreecheck(boad, a + i, b) == 1)
					result = HeightThreecheck(boad, a + i, b);
			}
		}
		return result;
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && strcmp(boad[a][b], "��") == 0) {	// ���� case 2
		if (strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 2][b], "��") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (HeightThreecheck(boad, a + i, b) == 1)
					result = HeightThreecheck(boad, a + i, b);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && strcmp(boad[a][b], "��") == 0) { // ���� case 3
		if (strcmp(boad[a - 3][b], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (HeightThreecheck(boad, a + i, b) == 1)
					result = HeightThreecheck(boad, a + i, b);
			}
			return result;
		}
	}
}
// ���� �˻�
int diagonalCheck1(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) {	// �밢�� case 1
		if (strcmp(boad[a + 1][b - 1], "��") != 0 && strcmp(boad[a - 3][b + 3], "��") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (diagonalThreecheck1(boad, a - i, b + i) == 1)
					result = diagonalThreecheck1(boad, a - i, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && strcmp(boad[a][b], "��") == 0) {	// �밢�� case 2
		if (strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (diagonalThreecheck1(boad, a - i, b + i) == 1)
					result = diagonalThreecheck1(boad, a, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) { // �밢�� case 3
		if (strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 1][b + 1], "��") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (diagonalThreecheck1(boad, a - i, b + i) == 1)
					result = diagonalThreecheck1(boad, a, b + i);
			}
			return result;
		}
	}
}
// �밢�� �˻� 1
int diagonalCheck2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if ((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) {	// �밢��2 case 1
		if (strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0) {
			for (int i = 0; i < 3; i++)
			{
				if (diagonalThreecheck2(boad, a + i, b + i) == 1)
					result = diagonalThreecheck2(boad, a + i, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && strcmp(boad[a][b], "��") == 0) {	// �밢��2 case 2
		if (strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) {
			for (int i = -1; i < 2; i++)
			{
				if (diagonalThreecheck2(boad, a + i, b + i) == 1)
					result = diagonalThreecheck2(boad, a + i, b + i);
			}
			return result;
		}
	}
	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) { // �밢��2 case 3
		if (strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) {
			for (int i = -2; i < 1; i++)
			{
				if (diagonalThreecheck2(boad, a + i, b + i) == 1)
					result = diagonalThreecheck2(boad, a + i, b + i);
			}
			return result;
		}
	}
}
// �밢�� �˻� 2


int whithThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if (((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && (strcmp(boad[a + 3][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0)) ||				// ���� �˻�
		((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && (strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 2][b], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && (strcmp(boad[a - 3][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0)))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && ((strcmp(boad[a + 1][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) && strcmp(boad[a + 4][b], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && ((strcmp(boad[a - 1][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0) && strcmp(boad[a - 4][b], "��") != 0))		// ���� �˻� 2(New)
		return 1;


	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a + 1][b], "��") != 0 && strcmp(boad[a + 3][b], "��") != 0) && strcmp(boad[a - 2][b], "��") != 0)) ||
			 ((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a - 1][b], "��") != 0 && strcmp(boad[a - 3][b], "��") != 0) && strcmp(boad[a + 2][b], "��") != 0)))		// ���� �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) && strcmp(boad[a + 4][b], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a - 2][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0) && strcmp(boad[a - 4][b], "��") != 0))		// ���� �˻� 4(New)
		return 1;
	//���� �˻�
	else if
		((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && (strcmp(boad[a - 3][b + 3], "��") != 0 && strcmp(boad[a + 1][b - 1], "��") != 0) ||				// �밢�� 1 �˻�
			(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && (strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) ||
			(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && (strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 1][b + 1], "��") != 0))
		return 1;

	/*else if
		((strcmp(boad[a][b], boad[a - 3][b + 3]) == 0 && ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a - 1][b + 1], "��") != 0) || (strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a - 2][b + 2], "��") != 0))) ||
		 (strcmp(boad[a][b], boad[a + 3][b - 3]) == 0 && ((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a + 1][b - 1], "��") != 0) || (strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a + 2][b - 2], "��") != 0))))		// �밢��1 �˻� 2
		return 1;
	else if
		(((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && strcmp(boad[a + 1][b - 1], "��") != 0) ||
			(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a - 1][b + 1], "��") != 0)						// �밢��1 �˻� 3
		return 1;*/
	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 2][b + 2], "��") != 0 && strcmp(boad[a - 4][b + 4], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a + 4][b - 4], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0))		// �밢��1 �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 1][b - 1], "��") != 0 && strcmp(boad[a + 4][b - 4], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0)) ||
			 ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 1][b + 1], "��") != 0 && strcmp(boad[a - 4][b + 4], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0)))		// �밢��1 �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && ((strcmp(boad[a - 3][b + 3], "��") != 0 && strcmp(boad[a + 2][b - 2], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && ((strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0))		// �밢��1 �˻� 4(New)
		return 1;


	// �밢��1 �˻�

	else if
		((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && (strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) ||	// �밢�� 2 �˻�
			(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && (strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) ||
			(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && (strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 2][b - 2], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) && strcmp(boad[a - 4][b - 4], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0) && strcmp(boad[a + 4][b + 4], "��") != 0))		// �밢��2 �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 1][b + 1], "��") != 0 && strcmp(boad[a + 4][b + 4], "��") != 0) && strcmp(boad[a - 1][b - 1], "��") != 0)) ||
			 ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 1][b - 1], "��") != 0 && strcmp(boad[a - 4][b - 4], "��") != 0) && strcmp(boad[a + 1][b + 1], "��") != 0)))		// �밢��1 �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && ((strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 2][b + 2], "��") != 0) && strcmp(boad[a - 1][b - 1], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && ((strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) && strcmp(boad[a + 1][b + 1], "��") != 0))		// �밢��2 �˻� 4(New)
		return 1;

	// �밢��2 �˻�

	/*else if
		((strcmp(boad[a][b], boad[a - 3][b - 3]) == 0 && ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a - 1][b - 1], "��") != 0) || (strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a - 2][b - 2], "��") != 0))) ||
			(strcmp(boad[a][b], boad[a + 3][b + 3]) == 0 && ((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a + 1][b + 1], "��") != 0) || (strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a + 2][b + 2], "��") != 0))))		// �밢��2 �˻� 2
		return 1;
	else if
		((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && (strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a - 1][b - 1], "��") != 0)) ||
			(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && (strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a + 1][b + 1], "��") != 0)))						// �밢��2 �˻� 3
		return 1;*/
}
// 33���� �˻�
int HeightThreecheck(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && (strcmp(boad[a][b + 3], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) ||		// ���� �˻�
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && (strcmp(boad[a][b + 2], "��") != 0 && strcmp(boad[a][b - 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && (strcmp(boad[a][b - 3], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && ((strcmp(boad[a][b + 1], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) && strcmp(boad[a][b + 4], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && ((strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) && strcmp(boad[a][b - 4], "��") != 0))		// ���� �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b + 1], "��") != 0 && strcmp(boad[a][b + 3], "��") != 0) && strcmp(boad[a][b - 2], "��") != 0)) ||
			 ((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b - 3], "��") != 0) && strcmp(boad[a][b + 2], "��") != 0)))		// ���� �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b + 2], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) && strcmp(boad[a][b + 4], "��") != 0) ||
			 (strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b - 2], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) && strcmp(boad[a][b - 4], "��") != 0))		// ���� �˻� 4(New)
		return 1;
	// ���� �˻�

	 else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && (strcmp(boad[a - 3][b + 3], "��") != 0 && strcmp(boad[a + 1][b - 1], "��") != 0) ||				// �밢�� 1 �˻�
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && (strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && (strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 1][b + 1], "��") != 0))
		return 1;

	 else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 2][b + 2], "��") != 0 && strcmp(boad[a - 4][b + 4], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0) ||
		 (strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a + 4][b - 4], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0))		// �밢��1 �˻� 2(New)
		return 1;

	 else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 1][b - 1], "��") != 0 && strcmp(boad[a + 4][b - 4], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0)) ||
		 ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 1][b + 1], "��") != 0 && strcmp(boad[a - 4][b + 4], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0)))		// �밢��1 �˻� 3(New)
		return 1;

	 else if ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && ((strcmp(boad[a - 3][b + 3], "��") != 0 && strcmp(boad[a + 2][b - 2], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0) ||
		 (strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && ((strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0))		// �밢��1 �˻� 4(New)
		return 1;
	// �밢��1 �˻�

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && (strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) ||	// �밢�� 2 �˻�
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && (strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && (strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 2][b - 2], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) && strcmp(boad[a - 4][b - 4], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0) && strcmp(boad[a + 4][b + 4], "��") != 0))		// �밢��2 �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 1][b + 1], "��") != 0 && strcmp(boad[a + 4][b + 4], "��") != 0) && strcmp(boad[a - 1][b - 1], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 1][b - 1], "��") != 0 && strcmp(boad[a - 4][b - 4], "��") != 0) && strcmp(boad[a + 1][b + 1], "��") != 0)))		// �밢��1 �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && ((strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 2][b + 2], "��") != 0) && strcmp(boad[a - 1][b - 1], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && ((strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) && strcmp(boad[a + 1][b + 1], "��") != 0))		// �밢��2 �˻� 4(New)
		return 1;

	// �밢��2 �˻�
}
// 33���� �˻�
int diagonalThreecheck1(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && (strcmp(boad[a + 3][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) ||				// ���� �˻�
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && (strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 2][b], "��") != 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && (strcmp(boad[a - 3][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && ((strcmp(boad[a + 1][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) && strcmp(boad[a + 4][b], "��") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && ((strcmp(boad[a - 1][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0) && strcmp(boad[a - 4][b], "��") != 0))		// ���� �˻� 2(New)
		return 1;


	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a + 1][b], "��") != 0 && strcmp(boad[a + 3][b], "��") != 0) && strcmp(boad[a - 2][b], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a - 1][b], "��") != 0 && strcmp(boad[a - 3][b], "��") != 0) && strcmp(boad[a + 2][b], "��") != 0)))		// ���� �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) && strcmp(boad[a + 4][b], "��") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a - 2][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0) && strcmp(boad[a - 4][b], "��") != 0))		// ���� �˻� 4(New)
		return 1;

	//���� �˻�

	else if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && (strcmp(boad[a][b + 3], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) ||		// ���� �˻�
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && (strcmp(boad[a][b + 2], "��") != 0 && strcmp(boad[a][b - 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && (strcmp(boad[a][b - 3], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && ((strcmp(boad[a][b + 1], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) && strcmp(boad[a][b + 4], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && ((strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) && strcmp(boad[a][b - 4], "��") != 0))		// ���� �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b + 1], "��") != 0 && strcmp(boad[a][b + 3], "��") != 0) && strcmp(boad[a][b - 2], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b - 3], "��") != 0) && strcmp(boad[a][b + 2], "��") != 0)))		// ���� �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b + 2], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) && strcmp(boad[a][b + 4], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b - 2], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) && strcmp(boad[a][b - 4], "��") != 0))		// ���� �˻� 4(New)
		return 1;

	// ���� �˻�

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && (strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) ||	// �밢�� 2 �˻�
		(strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && (strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && (strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 2][b - 2], "��") != 0 && strcmp(boad[a + 1][b + 1], "��") != 0) && strcmp(boad[a - 4][b - 4], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 2][b + 2], "��") != 0 && strcmp(boad[a - 1][b - 1], "��") != 0) && strcmp(boad[a + 4][b + 4], "��") != 0))		// �밢��2 �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && ((strcmp(boad[a + 1][b + 1], "��") != 0 && strcmp(boad[a + 4][b + 4], "��") != 0) && strcmp(boad[a - 1][b - 1], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && ((strcmp(boad[a - 1][b - 1], "��") != 0 && strcmp(boad[a - 4][b - 4], "��") != 0) && strcmp(boad[a + 1][b + 1], "��") != 0)))		// �밢��1 �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b + 1]) == 0) && ((strcmp(boad[a - 3][b - 3], "��") != 0 && strcmp(boad[a + 2][b + 2], "��") != 0) && strcmp(boad[a - 1][b - 1], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && ((strcmp(boad[a + 3][b + 3], "��") != 0 && strcmp(boad[a - 2][b - 2], "��") != 0) && strcmp(boad[a + 1][b + 1], "��") != 0))		// �밢��2 �˻� 4(New)
		return 1;

	// �밢��2 �˻�
}
// 33�밢��1 �˻�
int diagonalThreecheck2(char boad[MAX][MAX][MAX], int a, int b) {
	if ((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && (strcmp(boad[a][b + 3], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) ||		// ���� �˻�
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && (strcmp(boad[a][b + 2], "��") != 0 && strcmp(boad[a][b - 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && (strcmp(boad[a][b - 3], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && ((strcmp(boad[a][b + 1], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) && strcmp(boad[a][b + 4], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && ((strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) && strcmp(boad[a][b - 4], "��") != 0))		// ���� �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b + 1], "��") != 0 && strcmp(boad[a][b + 3], "��") != 0) && strcmp(boad[a][b - 2], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b - 1], "��") != 0 && strcmp(boad[a][b - 3], "��") != 0) && strcmp(boad[a][b + 2], "��") != 0)))		// ���� �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a][b + 3]) == 0 && strcmp(boad[a][b], boad[a][b + 1]) == 0) && ((strcmp(boad[a][b + 2], "��") != 0 && strcmp(boad[a][b - 1], "��") != 0) && strcmp(boad[a][b + 4], "��") != 0) ||
		(strcmp(boad[a][b], boad[a][b - 3]) == 0 && strcmp(boad[a][b], boad[a][b - 1]) == 0) && ((strcmp(boad[a][b - 2], "��") != 0 && strcmp(boad[a][b + 1], "��") != 0) && strcmp(boad[a][b - 4], "��") != 0))		// ���� �˻� 4(New)
		return 1;

	// ���� �˻�

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && (strcmp(boad[a - 3][b + 3], "��") != 0 && strcmp(boad[a + 1][b - 1], "��") != 0) ||				// �밢�� 1 �˻�
		(strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && (strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b - 2]) == 0) && (strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 1][b + 1], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 2][b + 2], "��") != 0 && strcmp(boad[a - 4][b + 4], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 2][b - 2], "��") != 0 && strcmp(boad[a + 4][b - 4], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0))		// �밢��1 �˻� 2(New)
		return 1;

	else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b - 3]) == 0) && ((strcmp(boad[a + 1][b - 1], "��") != 0 && strcmp(boad[a + 4][b - 4], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && ((strcmp(boad[a - 1][b + 1], "��") != 0 && strcmp(boad[a - 4][b + 4], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0)))		// �밢��1 �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && ((strcmp(boad[a - 3][b + 3], "��") != 0 && strcmp(boad[a + 2][b - 2], "��") != 0) && strcmp(boad[a - 1][b + 1], "��") != 0) ||
		(strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && ((strcmp(boad[a + 3][b - 3], "��") != 0 && strcmp(boad[a - 2][b + 2], "��") != 0) && strcmp(boad[a + 1][b - 1], "��") != 0))		// �밢��1 �˻� 4(New)
		return 1;

	//�밢��1 �˻�

	else if ((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && (strcmp(boad[a + 3][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) ||				// ���� �˻�
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && (strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 2][b], "��") != 0) ||
		(strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && (strcmp(boad[a - 3][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0))
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && ((strcmp(boad[a + 1][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) && strcmp(boad[a + 4][b], "��") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && ((strcmp(boad[a - 1][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0) && strcmp(boad[a - 4][b], "��") != 0))		// ���� �˻� 2(New)
		return 1;


	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a + 1][b], "��") != 0 && strcmp(boad[a + 3][b], "��") != 0) && strcmp(boad[a - 2][b], "��") != 0)) ||
		((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a - 1][b], "��") != 0 && strcmp(boad[a - 3][b], "��") != 0) && strcmp(boad[a + 2][b], "��") != 0)))		// ���� �˻� 3(New)
		return 1;

	else if ((strcmp(boad[a][b], boad[a + 3][b]) == 0 && strcmp(boad[a][b], boad[a + 1][b]) == 0) && ((strcmp(boad[a + 2][b], "��") != 0 && strcmp(boad[a - 1][b], "��") != 0) && strcmp(boad[a + 4][b], "��") != 0) ||
		(strcmp(boad[a][b], boad[a - 3][b]) == 0 && strcmp(boad[a][b], boad[a - 1][b]) == 0) && ((strcmp(boad[a - 2][b], "��") != 0 && strcmp(boad[a + 1][b], "��") != 0) && strcmp(boad[a - 4][b], "��") != 0))		// ���� �˻� 4(New)
		return 1;
}
// 33�밢��2 �˻�
int whithCheckCase2(char boad[MAX][MAX][MAX], int a, int b) {
	int result = 0;
	if (((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b + 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a][b + 2], "��") != 0) {	// ���� case 1
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;

			else if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a][b + 1], "��") != 0) {	// ���� case 2
		for (int i = -1; i < 2; i++)
		{
			if (i == 1)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b - 2]) == 0 && strcmp(boad[a][b], boad[a][b - 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a][b - 1], "��") != 0) { // ���� case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -1)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a][b + 2]) == 0 && strcmp(boad[a][b], boad[a][b + 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a][b + 1], "��") != 0) { // ���� case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b + 1]) == 0 && strcmp(boad[a][b], boad[a][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a][b - 1], "��") != 0) { // ���� case 5
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;

			if (whithThreecheck(boad, a, b + i) == 1)
				result = whithThreecheck(boad, a, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a][b - 1]) == 0 && strcmp(boad[a][b], boad[a][b - 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a][b - 2], "��") != 0) { // ���� case 6
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
	if (((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a + 3][b]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 2][b], "��") != 0) {	//case 1
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;

			else if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a + 2][b]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 1][b], "��") != 0) {	//case 2
		for (int i = -1; i < 3; i++)
		{
			if (i == 1)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 2][b]) == 0 && strcmp(boad[a][b], boad[a - 3][b]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b], "��") != 0) { // case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -1)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a + 2][b]) == 0 && strcmp(boad[a][b], boad[a + 3][b]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 1][b], "��") != 0) { // case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 1][b]) == 0 && strcmp(boad[a][b], boad[a - 2][b]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b], "��") != 0) { // case 5
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;

			if (HeightThreecheck(boad, a + i, b) == 1)
				result = HeightThreecheck(boad, a + i, b);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 1][b]) == 0 && strcmp(boad[a][b], boad[a - 3][b]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 2][b], "��") != 0) { // case 6
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
	if (((strcmp(boad[a][b], boad[a - 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b + 1], "��") != 0) {	// case 1
		for (int i = 0; i < 4; i++) {
			if (i == 1)
				continue;

			else if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 1][b + 1]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 1][b - 1], "��") != 0) { // case 2
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 3][b - 3]) == 0 && strcmp(boad[a][b], boad[a + 1][b - 1]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 2][b - 2], "��") != 0) { // case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -2)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a - 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 3][b + 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 2][b + 2], "��") != 0) { // case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 2)
				continue;
			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b + 1], "��") != 0) { // case 5
		for (int i = -1; i < 3; i++)
		{
			if (i == 1)
				continue;

			if (diagonalThreecheck1(boad, a - i, b + i) == 1)
				result = diagonalThreecheck1(boad, a - i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 3][b + 3]) == 0 && strcmp(boad[a][b], boad[a - 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b + 1], "��") != 0) { // case 6
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
	if (((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 2][b + 2], "��") != 0) {	// case 1
		for (int i = 0; i < 4; i++) {
			if (i == 2)
				continue;

			else if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 1][b - 1]) == 0 && strcmp(boad[a][b], boad[a + 2][b + 2]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 1][b + 1], "��") != 0) { // case 2
		for (int i = -1; i < 3; i++)
		{
			if (i == 1)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 2][b - 2]) == 0 && strcmp(boad[a][b], boad[a - 3][b - 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b - 1], "��") != 0) { // case 3
		for (int i = -3; i < 1; i++)
		{
			if (i == -1)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}

	else if (((strcmp(boad[a][b], boad[a + 2][b + 2]) == 0 && strcmp(boad[a][b], boad[a + 3][b + 3]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a + 1][b + 1], "��") != 0) { // case 4
		for (int i = 0; i < 4; i++)
		{
			if (i == 1)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a + 1][b + 1]) == 0 && strcmp(boad[a][b], boad[a - 2][b - 2]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 1][b - 1], "��") != 0) { // case 5
		for (int i = -2; i < 2; i++)
		{
			if (i == -1)
				continue;

			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
	else if (((strcmp(boad[a][b], boad[a - 3][b - 3]) == 0 && strcmp(boad[a][b], boad[a - 1][b - 1]) == 0) && strcmp(boad[a][b], "��") == 0) && strcmp(boad[a - 2][b - 2], "��") != 0) { // case 6
		for (int i = -3; i < 1; i++) {
			if (i == -2)
				continue;
			if (diagonalThreecheck2(boad, a + i, b + i) == 1)
				result = diagonalThreecheck2(boad, a + i, b + i);
		}
		return result;
	}
}