#include <stdio.h>
#define N 6


#define BLACK 1
#define WHITE 0
#define	EMPTY 2



//오델로 판 함수  
void print_othello (void)	;

//오델로 초기화 함수  
void init_othello (void)	;

//배치할 좌표 입력이 적절한지 체크하는 함수  
int check_put_othello (int x, int y)	;


//배치할 수 있는 공간이 있는지 체크하는 함수  
int exist_space (void)	;

//입력받은 좌표로 돌을 뒤집는 함수  
void put_mine (int x, int y)	;

//돌을 뒤집은 후 turn을 바꿔주는 함수  
void turn_pass (void)	;

//결과를 출력하는 함수  
void check_result (void) ;

//게임 종료조건을 가지는 함수  
int isGameEnd (void)	;
