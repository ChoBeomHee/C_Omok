#ifdef OmokPlaying_H
#define OmokPlaying_H

void Iniboad(char boad[MAX][MAX][MAX]);				// �ʱ�ȭ
int Matchplay1(char boad[MAX][MAX][MAX]);			// �÷��̾�1 �¸��˻�
void Printboad(char boad[MAX][MAX][MAX]);			// ���� �� ���
int Playchoice1(char boad[MAX][MAX][MAX], int a, int b);	// 1���÷��̾� ��
void Playchoice2(char boad[MAX][MAX][MAX], int a, int b);	// 2�� �÷��̾� ��
int Matchplay2(char boad[MAX][MAX][MAX]);			// �÷��̾�2 �¸��˻�

}
#endif // OmokPlaying_H


