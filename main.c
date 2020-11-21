#include <stdio.h>
#include <stdlib.h>
#define N 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int board [N][N]	;

void	init_othello	( ) {
	
		int x , y	;
		
		//행과 열 for문으로 초기조건 표현함 
		for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{board [x][y]= 0 ;}	
			}
		
		// 첫 실행에 정중앙 4칸에 흰색과 검정색 알 2개씩 놈 
		//print 함수에서 1을 O 2를 X로 쓸 것이므로 초기조건을 이렇게 지정해줌 
		
		board [N/2-1][N/2-1] = 1	;
		board [N/2-1][N/2] = 2	;
		board [N/2][N/2-1] = 2	;
		board [N/2][N/2] = 1	;
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
			
			if (board[k][l] ==0)	//0일 때는 빈칸으로 놔둠 
			{ printf("  |")	;	}
			
			else if (board[k][l] ==1)	// O일 때는 1로 나타낼 것임 
			{ printf(" O|")	;
				o_status ++ ;	}		// white 돌을 변수로 지정해 돌 갯수 체크 
			
			
			else if (board[k][l]== 2)	// X일 때는 2로 나타낼 것임 
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

int	check_put_othello ( int putStone [] , int board [N][N]) {
	
		if (board [putStone[0]][putStone[1]] != 0 ) //이미 돌이 있을 때  
		{
			printf ("invalid input ! (already occupied)\n" )	;
			return 0	;
		}
		
		else if (putStone [0] >= N || putStone [1] >=N) // 게임 판의 크기를 넘어갔을 때 
		{
			printf("invalid input ! (should be less than %d)\n", N)	;
			return 0	;
		}
		//else if 못 뒤집을 때 
		
		return 1	;
}

//흰 돌을 뒤집기 위해 짠  함수 
void flip_try_white (  int putStone[] , int board [N][N])
	{
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		int	x	;
		int y	;
		
		//위쪽 돌 뒤집기 시도 
		if (board[putStone[0]+1][putStone[1]] == 2) // 놓은 돌 위가 까만 돌이라면 
		{
			while ( board[putStone[0]+1+n][putStone[1]] !=2) //까만돌이 끝날때까지 세기 
			{
				n++ ;										//북쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(x=0 ; x< n; x++)
				board [ putStone[0]+1+x][putStone[1]] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//아래쪽 돌 뒤집기 시도 
			if (board[putStone[0]-1][putStone[1]] == 2) // 놓은 돌 아래가 까만 돌이라면 
		{
			while ( board[putStone[0]-1-s][putStone[1]] !=2) //까만돌이 끝날때까지 세기 
			{
				s++ ;										//남쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(x=0 ; x< s; x++)
				board [ putStone[0]-1-x][putStone[1]] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//서쪽(왼쪽) 돌 뒤집기 시도 
			if (board[putStone[0]][putStone[1]-1] == 2) // 놓은 돌 왼쪽이  까만 돌이라면 
		{
			while ( board[putStone[0]][putStone[1]-1-w] !=2) //까만돌이 끝날때까지 세기 
			{
				w++ ;										//서쪽으로 바꿀  돌의 갯수 세기 위함 
			}
			for(x=0 ; x< w; x++)
				board [ putStone[0]][putStone[1]-1-w] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//동쪽(오른쪽) 돌 뒤집기 시도 
			if (board[putStone[0]][putStone[1]+1] == 2) // 놓은 돌 오른쪽이  까만 돌이라면 
		{
			while ( board[putStone[0]][putStone[1]+1+e] !=2) //까만돌이 끝날때까지 세기 
			{
				e++ ;										//동쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(x=0 ; x< e; x++)
				board [ putStone[0]][putStone[1]+1+e] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//북동쪽(오른 위쪽) 돌 뒤집기 시도 
			if (board[putStone[0]-1][putStone[1]+1] == 2) // 놓은 돌 오른 위쪽이  까만 돌이라면 
		{
			while ( board[putStone[0]-1-ne][putStone[1]+1+ne] !=2) //까만돌이 끝날때까지 세기 
			{
				ne++ ;												//북서쪽으로 바꿀 돌의 갯수 세기  위함 
			}
			for(x=0 ; x< ne; x++)
				board [ putStone[0]-1-ne][putStone[1]+1+ne] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//남동쪽(오른 아래쪽) 돌 뒤집기 시도 
			if (board[putStone[0]+1][putStone[1]+1] == 2) // 놓은 돌 오른 아래쪽이  까만 돌이라면 
		{
			while ( board[putStone[0]+1+se][putStone[1]+1+se] !=2) //까만돌이 끝날때까지 세기 
			{
				se++ ;												//남동쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(x=0 ; x< se; x++)
				board [ putStone[0]+1+se][putStone[1]+1+se] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//남서쪽(왼 아래쪽) 돌 뒤집기 시도 
			if (board[putStone[0]+1][putStone[1]-1] == 2) // 놓은 돌 왼 아래쪽이  까만 돌이라면 
		{
			while ( board[putStone[0]+1+sw][putStone[1]-1-sw] !=2) //까만돌이 끝날때까지 세기 
			{
				sw++ ;												//남서쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(x=0 ; x< sw; x++)
				board [ putStone[0]+1+sw][putStone[1]-1-sw] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		//북서쪽(왼 위쪽) 돌 뒤집기 시도 
			if (board[putStone[0]-1][putStone[1]-1] == 2) // 놓은 돌 왼 위쪽이  까만 돌이라면 
		{
			while ( board[putStone[0]-1-nw][putStone[1]-1-nw] !=2) //까만돌이 끝날때까지 세기 
			{
				nw++ ;												//북서쪽으로 바꿀 돌의 갯수 세기 위함 
			}
			for(x=0 ; x< nw; x++)
				board [ putStone[0]-1-nw][putStone[1]-1-nw] = 1	; //센 까만돌 모두 흰돌로 바꾸기 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //총 몇개의 돌을 뒤집었는지 세기 위해 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // 각 위치별로 뒤집은 돌의 갯수 나타냄 
		printf ("White has flipped %d othellos!", y )	;
		
		
 } 
 
 //까만 돌을 뒤집기 위해 짠 함수 
 void flip_try_black (  int putStone[] , int board [N][N])
	{
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		int	x	;
		int y	;
		
		//위쪽 돌 뒤집기 시도 
		if (board[putStone[0]+1][putStone[1]] == 1) // 놓은 돌 위가 흰 돌이라면 
		{
			while ( board[putStone[0]+1+n][putStone[1]] !=1) //흰돌이 끝날때까지 세기 
			{
				n++ ;
			}
			for(x=0 ; x< n; x++)
				board [ putStone[0]+1+x][putStone[1]] = 2	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//아래쪽 돌 뒤집기 시도 
			if (board[putStone[0]-1][putStone[1]] == 1) // 놓은 돌 아래가 흰 돌이라면 
		{
			while ( board[putStone[0]-1-s][putStone[1]] !=1) //흰돌이 끝날때까지 세기 
			{
				s++ ;
			}
			for(x=0 ; x< s; x++)
				board [ putStone[0]-1-x][putStone[1]] = 2	;//센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//서쪽(왼쪽) 돌 뒤집기 시도 
			if (board[putStone[0]][putStone[1]-1] == 1) // 놓은 돌 왼쪽이  흰 돌이라면 
		{
			while ( board[putStone[0]][putStone[1]-1-w] !=1) //흰돌이 끝날때까지 세기  
			{
				w++ ;
			}
			for(x=0 ; x< w; x++)
				board [ putStone[0]][putStone[1]-1-w] = 2	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//동쪽(오른쪽) 돌 뒤집기 시도 
			if (board[putStone[0]][putStone[1]+1] == 1) // 놓은 돌 오른쪽이  흰돌이라면 
		{
			while ( board[putStone[0]][putStone[1]+1+e] !=1)//흰돌이 끝날때까지 세기  
			{
				e++ ;
			}
			for(x=0 ; x< e; x++)
				board [ putStone[0]][putStone[1]+1+e] = 2	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//북동쪽(오른 위쪽) 돌 뒤집기 시도 
			if (board[putStone[0]-1][putStone[1]+1] == 1) // 놓은 돌 오른 위쪽이 흰 돌이라면 
		{
			while ( board[putStone[0]-1-ne][putStone[1]+1+ne] !=1) ///흰돌이 끝날때까지 세기 
			{
				ne++ ;
			}
			for(x=0 ; x< ne; x++)
				board [ putStone[0]-1-ne][putStone[1]+1+ne] = 2; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//남동쪽(오른 아래쪽) 돌 뒤집기 시도 
			if (board[putStone[0]+1][putStone[1]+1] == 1) // 놓은 돌 오른 아래쪽이  흰 돌이라면 
		{
			while ( board[putStone[0]+1+se][putStone[1]+1+se] !=1) //흰돌이 끝날때까지 세기  
			{
				se++ ;
			}
			for(x=0 ; x< se; x++)
				board [ putStone[0]+1+se][putStone[1]+1+se] = 2	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//남서쪽(왼 아래쪽) 돌 뒤집기 시도 
			if (board[putStone[0]+1][putStone[1]-1] == 1) // 놓은 돌 왼 아래쪽이  흰 돌이라면 
		{
			while ( board[putStone[0]+1+sw][putStone[1]-1-sw] !=1) //흰돌이 끝날때까지 세기  
			{
				sw++ ;
			}
			for(x=0 ; x< sw; x++)
				board [ putStone[0]+1+sw][putStone[1]-1-sw] = 2	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		//북서쪽(왼 위쪽) 돌 뒤집기 시도 
			if (board[putStone[0]-1][putStone[1]-1] == 1) // 놓은 돌 왼 위쪽이 흰 돌이라면 
		{
			while ( board[putStone[0]-1-nw][putStone[1]-1-nw] !=1) //흰돌이 끝날때까지 세기  
			{
				nw++ ;
			}
			for(x=0 ; x< nw; x++)
				board [ putStone[0]-1-nw][putStone[1]-1-nw] = 2	; //센 흰 돌 모두 까만돌로 바꾸기 
		}
		
		y = w+e+n+s+nw+ne+sw+se	;
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	;
		printf ("Black has flipped %d othellos!", y )	;
		
		
 } 


int where_othello (int turn ) {
	
	int x ,y 	;

	
	if ( turn == 0)
	printf ("put a new white othello : ")	;
	scanf (" %d %d", &x, &y)	;
	
	if (turn == 1)
	printf ( "put a new black othello : ")	;
	scanf (" %d %d", &x, &y)	;
	
	return board[x][y]	;
	
}


void main () {
	//초기화 
	init_othello ()	;
	
	print_othello ()	;
	

	
	
	

	

}


