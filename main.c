#include "board.h"




/* run this program using the console pauser or add your own getch, system("pause") or input loop */











/*int print_put_othello (int turn) {
	
	int x,y	;

	
	if ( turn == 0)
	{
		printf("put a new white othello : ")	;
		scanf("%d %d", &x, &y)	;
	
	}
	
	else if (turn == 1)
	{
		printf("put a new balck othello : ")	;
		scanf("%d %d", &x, &y)	;
	
	}
	
	return board[x][y]	;
}
*/




//return 값이 1이면 해당 칸은 돌을 놓을 수 있음  

		
		







	
 
 




void main () {
	
	int x, y	;
	turn = WHITE	;
	opposite = BLACK	;
	
	//초기화 
	init_othello ()	;
	
	while (isGameEnd()==1){
	
		print_othello ()	;
	
		if(exist_space() == 0){
			turn_pass ()	;
			end ++	;
			break	;
			}
		
		else if (exist_space() == 1)	{
		
	
	
	
	if( turn == WHITE )
	{
		printf("put a new white othello : ")	;
		scanf("%d %d", &x ,&y)	;	}
	else if (turn == BLACK)
	{
		printf("put a new black othello : ")	;
		scanf("%d %d", &x ,&y)	; 
	} 
	
	
	if(check_put_othello (x,y)==1) {
	
		
	put_mine (x,y)	;
		turn_pass ()	;
	}
	else if (check_put_othello (x,y)== 0){
		printf("invalid input! \n")	;
		continue	;
	}
 
}
}
	print_othello()	;
	
	check_result ()	;
}


	

	
	
	

	




