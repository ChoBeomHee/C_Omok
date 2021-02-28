#ifdef OmokPlaying_H
#define OmokPlaying_H

void Iniboad(char boad[MAX][MAX][MAX]);				// 초기화
int Matchplay1(char boad[MAX][MAX][MAX]);			// 플레이어1 승리검사
void Printboad(char boad[MAX][MAX][MAX]);			// 지금 판 출력
int Playchoice1(char boad[MAX][MAX][MAX], int a, int b);	// 1번플레이어 턴
void Playchoice2(char boad[MAX][MAX][MAX], int a, int b);	// 2번 플레이어 턴
int Matchplay2(char boad[MAX][MAX][MAX]);			// 플레이어2 승리검사

}
#endif // OmokPlaying_H


