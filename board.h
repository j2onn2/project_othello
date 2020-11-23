#include <stdio.h>
#define N 6


#define BLACK 1
#define WHITE 0
#define	EMPTY 2


int board[N][N]	;
int turn	;
int opposite	;
int end = 0	;

int num[2]	;	//num[0]은 흰돌 수, num [1]은 검은돌 수 

//8개의 방향 E,W,N,S,NE,NW,SE,SW 순서 
int direction [8][2] =  { {0, -1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1 }, {1,-1}, {1,1}}	;

void print_othello (void)	;
void init_othello (void)	;

int check_put_othello (int x, int y)	;

int exist_space (void)	;
void put_mine (int x, int y)	;
void check_result (void) ;

void turn_pass (void)	;
int isGameEnd (void)	;
