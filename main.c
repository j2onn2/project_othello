#include "board.h"

#define N 6


#define BLACK 1
#define WHITE 0
#define	EMPTY 2

int turn	;
int opposite	;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 


void main () {
	
	int x, y	;
	turn = WHITE	;
	opposite = BLACK	;
	
	//초기화하는 함수  
	init_othello ()	;
	
	
	while (isGameEnd()==0){
	
		//배치가 가능한 칸이 있는지 확인하는 함수  
		if(exist_space() == 0){
			
			//배치가 불가능하면 turn pass  
			turn_pass ()	;
			printf("Can't put stone. Automatically turn pass\n")	;
			
			//두 player다 배치가 불가능 하면 반복문 빠져나감  
			break	;
			}
		
		//배치가 가능하면 게임을 시작  
		else if (exist_space() == 1)	{
		
		//오델로 판 출력  
		print_othello ()	;
		
		//만약 흰색돌 차례라면  
		if( turn == WHITE )
		{
			printf("put a new white othello : ")	;	//흰색 돌의 배치 좌표를 입력받음  
			scanf("%d %d", &x ,&y)	;
		}
		
		//만약 검은색돌 차례라면  
		else if (turn == BLACK)
		{
			printf("put a new black othello : ")	; //검은색 돌의 배치 좌표를 입력 받음  
			scanf("%d %d", &x ,&y)	; 
		} 
	
	
		//배치할 좌표 입력이 적절한지 체크  
		if(check_put_othello (x,y)==1) 	//적절하다면 돌을 뒤집고 turn을 넘김  
		{
			put_mine (x,y)	;
			turn_pass ()	;
		}
		else if (check_put_othello (x,y)== 0)	//적절하지 않다면 부적절한 입력임을 내보내고 다시 함  
		{
			printf("invalid input! \n")	;
			continue	;
		}
 
		}
		}
	print_othello ()	;	//게임이 종료할 때 마지막 판을 보여줌  
	
	check_result ()	;	//게임 결과를 나타냄  
}


	

	
	
	

	




