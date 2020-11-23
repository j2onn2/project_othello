#include "board.h"

void	init_othello	( ) {
	
		int x , y	;
		
		//행과 열 for문으로 초기조건 표현함 
		for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{board [x][y]= EMPTY;}	
			}
		
		// 첫 실행에 정중앙 4칸에 흰색과 검정색 알 2개씩 놈 
		//print 함수에서 1을 O 2를 X로 쓸 것이므로 초기조건을 이렇게 지정해줌 
		
		board [N/2-1][N/2-1] = WHITE	;
		board [N/2-1][N/2] = BLACK	;
		board [N/2][N/2-1] = BLACK	;
		board [N/2][N/2] = WHITE	;
		num[WHITE] = 2	;
		num[BLACK] = 2	;
	}
	
int	check_put_othello ( int x, int y) {
	
	
		int i	;
		
		//빈칸일 경우에  
		if(board [x][y] == EMPTY){
			
			//처음 정의했던 direction[8][2]를 이용하여 모든 방향일때를 for문을 돌려 표현  
			for (i=0; i<8; i++){
				int d_x = x+direction[i][0]	;
				int d_y = y+direction[i][1]	;
				
				if(( d_x >=0 || d_y >= 0)&& board [d_x][d_y] == opposite){
					do{
						d_x += direction [i][0]	;
						d_y += direction [i][1]	;
					} while (board[d_x][d_y] == opposite)	;
					
					if(board[d_x][d_y] == turn)
						return	1	;
				}
				
			}
			
		
			return 0	;
		}
		
		else if(x>=N || y>= N)
		{
			printf("(should be less than %d)\n", N)	;
			return 0	;
		}
		else
		return 0	;
	}
	
int exist_space (){
	int i ,j	;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			if(board [i][j] == EMPTY && check_put_othello(i,j)==1)
			return 1	;
		}
	}
	return 0	;
}


void put_mine (int x, int y){
	int dir[8] = {0,}	;
	int tot = 0	;
	int i 	;
	
	for(i=0; i<8; i++){
		int d_x = x+direction [i][0]	;
		int d_y = y+direction [i][1]	;
		int r_x = x	;
		int r_y = y	;
		
		if(d_x >= 0&&d_y >= 0 &&(board[d_x][d_y] == opposite)) {
			
			do {
				d_x += direction[i][0]	;
				d_y += direction[i][1]	;
			}	while (board[d_x][d_y]== opposite)	;
			
			if (board [d_x][d_y] == turn) {
				do{
					if(board[r_x][r_y] == EMPTY)
					num[turn]++	;
					else if (board [r_x][r_y] == opposite){
						num[turn] ++	;
						num[opposite] -- 	;
						dir [i] ++	;
					}
			board[r_x][r_y] = turn	;
			
			r_x += direction [i][0]	;
			r_y += direction [i][1]	;
			
				} while (board[r_x][r_y] == opposite)	;
				//return;
			}
		}
		
		tot += dir[i]	;
	}
	
	printf(":: flip result ::\n")	;
	printf("W : %d, E : %d, N : %d, S : %d, NW : %d, NE : %d, SW : %d, SE : %d\n ", dir[0], dir[1], dir[2], dir[3], dir[4],dir[5], dir[6], dir[7])	;
	
	printf("\n")	;
	if (turn == WHITE){
	
	printf("WHITE has flipped %d othellos! \n", tot)	;
	}
	
	if (turn == BLACK ) {
		printf("BLACK has flipped %d othellos! \n", tot)	;
	}
}	



void check_result (){
	
	if(num[WHITE] > num[BLACK])
	printf("White win \n")	;
	
	else
	printf("Black win \n")	;
}


void turn_pass (){
	
	int tmp = turn	;
	turn = opposite	;
	opposite = tmp	;
}

int isGameEnd (){
	int x, y	;

	
	for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{
				if(board [x][y] == EMPTY)	
					{
						return 1	;
					}
					
			}
			}
			
			
			
	return 0	; 
			
}


