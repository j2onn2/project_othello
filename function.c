#include "board.h"

int board[N][N]	;
int turn	;
int opposite	;


int num[2]	;	//num[0]은 흰돌, num [1]은 검은돌 

//8개의 방향 E,W,N,S,NE,NW,SE,SW 순서 
int direction [8][2] =  { {0, -1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1 }, {1,-1}, {1,1}}	;


//초기화 함수  
void	init_othello	( ) {
	
		int x , y	;
		
		//행과 열 for문으로 초기조건 표현함 
		for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{board [x][y]= EMPTY;}	
			}
		
		// 첫 실행에 정중앙 4칸에 흰색과 검정색 알 2개씩 놈 
		//print 함수에서 0을 O 1를 X로 쓸 것이므로 초기조건을 이렇게 지정해줌 
		
		board [N/2-1][N/2-1] = WHITE	;
		board [N/2-1][N/2] = BLACK	;
		board [N/2][N/2-1] = BLACK	;
		board [N/2][N/2] = WHITE	;
		num[WHITE] = 2	;
		num[BLACK] = 2	;
	}


//돌을 놓을 수 있는지 확인하는 함수 	
int	check_put_othello ( int x, int y) {
	
	
		int i	;
		
		//빈칸일 경우에  
		if(board [x][y] == EMPTY){
			
			//처음 정의했던 direction[8][2]를 이용하여 모든 방향일때를 for문을 돌려 표현  
			for (i=0; i<8; i++){
				int d_x = x+direction[i][0]	;
				int d_y = y+direction[i][1]	;
			//주변에 돌이 있는지 확인하기 위해 새로운 변수를 정의 	
				
				//0보다 많이 갔을 때 상대돌이 주변에 있을 경우 반환값 1을줌   
				if( d_x >=0 && d_y >= 0&& board [d_x][d_y] == opposite){
					do{
						d_x += direction [i][0]	;
						d_y += direction [i][1]	;
					} while (board[d_x][d_y] == opposite)	; //반대돌이 나올떄까지 감  
					
					if(board[d_x][d_y] == turn)
						return	1	;		 
				}
				
			}
			
		
			return 0	;
		}
		
		else if(x>=N || y>= N)	//판보다 큰 수를 입력하면 놓지 못 함  
		{
			printf("(should be less than %d)\n", N)	;
			return 0	;
		}
		else if (board[x][y]!= EMPTY)	//이미 돌이 있는 경우 놓지 못 함  
		{
			printf("already occupied!\n")	;
		}
		return 0	;
	}
	
// 반환값이 1인 경우 놓읈 수 있음 
int exist_space (){
	int i ,j	;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			if(board [i][j] == EMPTY && check_put_othello(i,j)==1)	//판이 비어있고 돌을 놓을 수 있는 상태이면 반환값 1을 줌  
			return 1	;
		}
	}
	return 0	; // 그렇지 않은 경우 반환값 0 을 주어 못 놓게 함  
}


//내 돌을 놓는 함수  
void put_mine (int x, int y){
	
	int dir[8] = {0,}	;
	int tot = 0	;	//총 뒤집은 돌의 갯수를 세기 위한 변수  
	int i 	;
	
	for(i=0; i<8; i++){
		int d_x = x+direction [i][0]	;
		int d_y = y+direction [i][1]	;
		int r_x = x	;
		int r_y = y	;
		
		if(d_x >= 0&&d_y >= 0 &&(board[d_x][d_y] == opposite)) { //주위에 상대돌이 있을 경우 
			
			do {
				d_x += direction[i][0]	;
				d_y += direction[i][1]	;
			}	while (board[d_x][d_y]== opposite)	;	//반대돌이라면 계속 감  
			
			if (board [d_x][d_y] == turn) {
				do{
					if (board [r_x][r_y] == opposite){
						dir [i] ++	;			//뒤집은 상대돌의 갯수를 세기 위해 dir[i]를 상대돌일떄마다 상승시켜줌  
					}
					board[r_x][r_y] = turn	;	//상대돌을 내 돌로 바꿈  
			
					r_x += direction [i][0]	;
					r_y += direction [i][1]	;
			
				} while (board[r_x][r_y] == opposite)	;	//상대돌이라면 주어진 조건을 계속 실행  
				//return;
			}
		}
		
		tot += dir[i]	;	//뒤집힐때마다 추가되도록 해서 총 몇개를 뒤집었는지 세기 위함  
	}
	
	printf(":: flip result ::\n")	;
	printf("W : %d, E : %d, N : %d, S : %d, NW : %d, NE : %d, SW : %d, SE : %d\n ", dir[0], dir[1], dir[2], dir[3], dir[4],dir[5], dir[6], dir[7])	;
	//각 방향별로 뒤집힌 돌이 갯수 세기 위함  
	
	printf("\n")	;
	
	//흰색 돌이 었을 경우에는 흰색이 몇개 뒤집었는지 표시  
	if (turn == WHITE){
	
	printf("WHITE has flipped %d othellos! \n", tot)	;
	}
	
	//검은색 돌이었을 경우 검은색이 몇개 뒤집었는지 표시  
	if (turn == BLACK ) {
		printf("BLACK has flipped %d othellos! \n", tot)	;
	}
}	



void check_result (){
	
	//흰색돌의 갯수가 더 많으면 흰색이 이김  
	if(num[WHITE] > num[BLACK])
	printf("White win \n")	;
	
	//검은색 돌의 갯수가 더 많으면 검은색이 이김  
	else if (num[BLACK] > num[WHITE])
	printf("Black win \n")	;
	
	//둘의 갯수가 같을 경우 비김  
	else
	printf("Wow tie!\n")	;
}


//turn이 돌아가도록 하는 함수  
void turn_pass (){
	
	int tmp = turn	;
	turn = opposite	;
	opposite = tmp	;
}


//게임 종료 조건을 말함  
int isGameEnd (){
	int x, y	;

	
	for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{
				if(board [x][y] == EMPTY)	//게임판이 비어있으면 게임이 계속 됨  
					{
						return 0	;
					}
					
			}
			}
			
			
	//게임판이 꽉차면 게임이 종료 됨 		
	return 1	; 
			
}


