#include <stdio.h>
#define N 6

int board[N][N]	;

void print_othello (void)	;
void init_othello (void)	;

int check_put_othello (int x, int y)	;

void flip_try_white (int x, int y)	;
void flip_try_black (int x, int y)	;
