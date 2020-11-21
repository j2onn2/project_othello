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

int	check_put_othello (char color [], int putStone [] , int board [N][N]) {
	
		if (board [putStone[1]][putStone[0]] != 0 )
		{
			printf ("invalid input ! (already occupied)\n" )	;
			return 0	;
		}
		
		else if (putStone [1] >= N || putStone [0] >=N)
		{
			printf("invalid input ! (should be less than %d)\n", N)	;
			return 0	;
		}
		//else if 못 뒤집을 때 
		
		return 1	;
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


