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
	
	int i, 	j, k, l	, m;
	

	printf("   ")	;
	for (i=0; i<N; i++)
	{
		printf(" %d ", i)	;		//첫 줄의 0~5 표현 
	}
	
	printf ("\n")	;
	printf ("   ")	;
	  
	for (j=0; j<N; j++)			//구분선 표현 
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
			{ printf(" O|")	;	}
			
			else if (board[k][l]== 2)	// X일 때는 2로 나타낼 것임 
			{ printf(" X|")	;	}
			
		}
		printf("\n")	;
		for (m=0; m<N+1; m++)	//구분선 표현 
		{
		printf("---")	;	 
		}
		
		printf("\n")	;
	}
}


void main () {
	//초기화 
	init_othello ()	;
	
	print_othello ()	;
	
	
	
/*	int num1=0	;
	int num2 = 0	;
	

	
	
	
	
	while (isGameEnd()==0)
	{
		
	}

	{
		printf("0 1 2 3 4 5\n")	;
		printf("-------------\n")	;
		for (k=0 ; k<6 ;k++)
		{
			printf("%d |\n", k)	;
		
			for (i=0; i<6 ; i++)
		{
			printf("%d |", board[k][i]);
		}
	}
		printf("\n")	;
	}
	
	printf("\n  STATUS - WHITE: 2, BLACK :2")	;
	printf("\n")	;
	printf("\n put a new white othello : ")	;
	scanf("%d %d", &num1, &num2)	;
	board [num1][num2]= 'O'	; 
	

	}*/

}


