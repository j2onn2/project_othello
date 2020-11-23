#include <stdio.h>
#include <stdlib.h>

#define N 6 
#define BLACK 1
#define WHITE 0
#define	EMPTY 2



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int board [N][N]	;
int turn	;
int opposite	;
int end = 0	;

int num[2]	;	//num[0]은 흰돌 수, num [1]은 검은돌 수 

//8개의 방향 E,W,N,S,NE,NW,SE,SW 순서 
int direction [8][2] =  { {0, -1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1 }, {1,-1}, {1,1}}	;


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




void	print_othello () {
	
	int k, l, m;
	int o_status =0	;
	int x_status =0	;
	

	printf("   ")	;
	for (m=0; m<N; m++)
	{
		printf(" %d ", m)	;		//첫 줄의 0~5 표현 
	}
	
	printf ("\n")	;
	printf ("   ")	;
	  
	for (m=0; m<N; m++)			//구분선 표현 
	{
		printf("---")	;	 
	}
	
	printf("\n")	;
	
	for (k=0 ; k<N ; k++)		//세로줄 0~5까지 표현 
	{
		printf("%d| ",k )	;	
		
		for(l=0 ; l<N ; l++)	//행 하나 당 나와있는 열 표현하기 위해 for문을 한번 더 씀 
		{
			
			if (board[k][l] ==EMPTY)	//0일 때는 빈칸으로 놔둠 
			{ printf("  |")	;	}
			
			else if (board[k][l] ==WHITE)	// O일 때는 1로 나타낼 것임 
			{ printf(" O|")	;
				o_status ++ ;	}		// white 돌을 변수로 지정해 돌 갯수 체크 
			
			
			else if (board[k][l]== BLACK)	// X일 때는 2로 나타낼 것임 
			{ printf(" X|")	;
				x_status ++ ;	}		//black 돌을 변수로 지정해 돌 갯수 체크 
			
		}
		printf("\n")	;
		for (m=0; m<N+1; m++)	//구분선 표현 
		{
		printf("---")	;	 
		}
		
		printf("\n")	;
	}
		printf (" STATUS - WHITE : %d, BLACK : %d \n", o_status, x_status)	; // 돌 갯수를 변수로 지정해 매번 printf_othello가 나올 때 상태를 출력할 수 있음 
}


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
int	check_put_othello ( int x, int y) {
	
	
		int i	;
		
		//빈칸일 경우에  
		if(board [x][y] == EMPTY){
			
			//처음 정의했던 direction[8][2]를 이용하여 모든 방향일때를 for문을 돌려 표현  
			for (i=0; i<8; i++){
				int d_x = x+direction[i][0]	;
				int d_y = y+direction[i][1]	;
				
				if( d_x >=0 && d_y >= 0 && board [d_x][d_y] == opposite){
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
	
	/*for(i=0;i<8;i++){
		printf("%d", dir[i])	;
		tot += dir[i]	;
	}*/
	
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


void flip_try_white (  int x, int y)
	{
		
		int i	;
	
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		
	
		
		
		board [x][y] == WHITE	;
		//위쪽 돌 뒤집기 시도 
		if (board[x+1][y] == BLACK) // 놓은 돌 위가 까만 돌이라면 
		{
			while ( board[x+1+n][y] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				n++ ;										//북쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< n; i++)
				board [ x+1+i][y] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//아래쪽 돌 뒤집기 시도 
			if (board[x-1][y] == BLACK) // 놓은 돌 아래가 까만 돌이라면 
		{
			while ( board[x-1-s][y] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				s++ ;										//남쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< s; i++)
				board [ x-1-i][y] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//서쪽(왼쪽) 돌 뒤집기 시도 
			if (board[x][y-1] == BLACK) // 놓은 돌 왼쪽이  까만 돌이라면 
		{
			while ( board[x][y-1-w] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				w++ ;										//서쪽으로 바꿀  돌의 갯수 세기 위함 
			}
			for(i=0 ; i< w; i++)
				board [ x][y-1-i] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//동쪽(오른쪽) 돌 뒤집기 시도 
			if (board[x][y+1] == BLACK) // 놓은 돌 오른쪽이  까만 돌이라면 
		{
			while ( board[x][y+1+e] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				e++ ;										//동쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< e; i++)
				board [ x][y+1+i] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//북동쪽(오른 위쪽) 돌 뒤집기 시도 
			if (board[x-1][y+1] == BLACK) // 놓은 돌 오른 위쪽이  까만 돌이라면 
		{
			while ( board[x-1-ne][y+1+ne] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				ne++ ;												//북서쪽으로 바꿀 돌의 갯수 세기  위함 
			}
			for(i=0 ; i< ne; i++)
				board [x-1-i][y+1+i] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//남동쪽(오른 아래쪽) 돌 뒤집기 시도 
			if (board[x+1][y+1] == BLACK) // 놓은 돌 오른 아래쪽이  까만 돌이라면 
		{
			while ( board[x+1+se][y+1+se] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				se++ ;												//남동쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< se; i++)
				board [ x+1+i][y+1+i] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//남서쪽(왼 아래쪽) 돌 뒤집기 시도 
			if (board[x+1][y-1] == BLACK) // 놓은 돌 왼 아래쪽이  까만 돌이라면 
		{
			while ( board[x+1+sw][y-1-sw] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				sw++ ;												//남서쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< sw; i++)
				board [ x+1+i][y-1-i] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//북서쪽(왼 위쪽) 돌 뒤집기 시도 
			if (board[x-1][y-1] == BLACK) // 놓은 돌 왼 위쪽이  까만 돌이라면 
		{
			while ( board[x-1-nw][y-1-nw] !=BLACK) //까만돌이 끝날때까지 세기 
			{
				nw++ ;												//북서쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< nw; i++)
				board [ x-1-i][y-1-i] = WHITE	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //총 몇개의 돌을 뒤집었는지 세기 위해 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // 각 위치별로 뒤집은 돌의 갯수 나타냄 
		printf ("White has flipped %d othellos! \n", y )	;
		
		
 } 
 
//까만돌을 뒤집기 위해 짠  함수 
void flip_try_black (  int x, int y)
	{
		int board[x][y]	;
		int i	;
	
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		
		//위쪽 돌 뒤집기 시도 
		if (board[x+1][y] == 2) // 놓은 돌 위가 흰 돌이라면 
		{
			while ( board[x+1+n][y] !=2) //흰돌이 끝날때까지 세기 
			{
				n++ ;										//북쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< n; i++)
				board [ x+1+i][y] = 1	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//아래쪽 돌 뒤집기 시도 
			if (board[x-1][y] == 2) // 놓은 돌 아가 흰 돌이라면 
		{
			while ( board[x-1-s][y] !=2) //흰돌이 끝날때까지 세기 
			{
				s++ ;										//남쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< s; i++)
				board [ x-1-i][y] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		//서쪽(왼쪽) 돌 뒤집기 시도 
			if (board[x][y-1] == 2) // 놓은 돌 왼쪽이 흰 돌이라면 
		{
			while ( board[x][y-1-w] !=2) //흰돌이 끝날때까지 세기 
			{
				w++ ;										//서쪽으로 바꿀  돌의 갯수 세기 위함 
			}
			for(i=0 ; i< w; i++)
				board [ x][y-1-i] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		//동쪽(오른쪽) 돌 뒤집기 시도 
			if (board[x][y+1] == 2) // 놓은 돌 오른쪽이 흰 돌이라면
		{
			while ( board[x][y+1+e] !=2) //흰돌이 끝날때까지 세기 
			{
				e++ ;										//동쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< e; i++)
				board [ x][y+1+i] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		//북동쪽(오른 위쪽) 돌 뒤집기 시도 
			if (board[x-1][y+1] == 2) // 놓은 돌 오른 위쪽이 흰 돌이라면 
		{
			while ( board[x-1-ne][y+1+ne] !=2) //흰돌이 끝날때까지 세기 
			{
				ne++ ;												//북서쪽으로 바꿀 돌의 갯수 세기  위함 
			}
			for(i=0 ; i< ne; i++)
				board [x-1-i][y+1+i] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		//남동쪽(오른 아래쪽) 돌 뒤집기 시도 
			if (board[x+1][y+1] == 2) // 놓은 돌 오른 아래쪽이 흰 돌이라면 
		{
			while ( board[x+1+se][y+1+se] !=2) //흰돌이 끝날때까지 세기 
			{
				se++ ;												//남동쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< se; i++)
				board [ x+1+i][y+1+i] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		//남서쪽(왼 아래쪽) 돌 뒤집기 시도 
			if (board[x+1][y-1] == 2) // 놓은 돌 왼 아래쪽이 흰 돌이라면 
		{
			while ( board[x+1+sw][y-1-sw] !=2) //흰돌이 끝날때까지 세기 
			{
				sw++ ;												//남서쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< sw; i++)
				board [ x+1+i][y-1-i] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		//북서쪽(왼 위쪽) 돌 뒤집기 시도 
			if (board[x-1][y-1] == 2) // 놓은 돌 왼 위쪽이 흰 돌이라면 
		{
			while ( board[x-1-nw][y-1-nw] !=2) //흰돌이 끝날때까지 세기 
			{
				nw++ ;												//북서쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(i=0 ; i< nw; i++)
				board [ x-1-i][y-1-i] = 1	; //센 흰돌 모두 까만돌로 바꾸기 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //총 몇개의 돌을 뒤집었는지 세기 위해 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // 각 위치별로 뒤집은 돌의 갯수 나타냄 
		printf ("White has flipped %d othellos!", y )	;
		
		
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
		//	break	;
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
	/*	flip_try_white(x,y)	;
			turn_pass ()	;
		} */
		
	put_mine (x,y)	;
		turn_pass ()	;
	}
	else if (check_put_othello (x,y)== 0){
		printf("invalid input! \n")	;
		continue	;
	}
 
}
}
	
		printf(" the number is %d\n", isGameEnd ())	;
		printf("the exist space %d\n", exist_space())	;
	check_result ()	;
}

/*
		while (check_put_othello (x, y)==1)
		{	
			printf("put a new white othello : \n")	;
			scanf("%d %d", &x, &y)	;
		}
		
		flip_try_white (x,y)	;
		turn++	;
	}
	else
	{
		printf("put a new back othello : \n")	;
		scanf("%d %d", &x, &y)	;
		
		while (check_put_othello (x, y)==1)
		{
			printf("put a new black othello : \n")	;
			scanf("%d %d", &x , &y)	;
		}
		
		flip_try_black (x, y)	;
		turn++	;
	}
}
	*/

	

	
	
	

	




