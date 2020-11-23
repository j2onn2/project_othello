#include "board.h"


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

