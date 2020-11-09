#include <stdio.h>
#include <stdlib.h>
#define N 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int board [N][N]	;

void	init_othello	( ) {
	
		int x , y	;
		
		for(x=0; x<N; x++){
		for (y=0; y<N; y++)
		{
			board [x][y]= 0 ;
		}
		}
		// 첫 실행에 정중앙 4칸에 흰색과 검정색 알 2개씩 놈 
		board [N/2-1][N/2-1] = 'O'	;
		board [N/2-1][N/2] = 'X'	;
		board [N/2][N/2-1] = 'X'	;
		board [N/2][N/2] = 'O'	;
}

void	print_othello () {
	
	int i, 	j, k	;
	for (i=0; i<N; i++)
	{
		printf(" %d ", i)	;	
	}
	
	printf ("\n")	;
	
	for (j=0; j<N; j++)
	{
		printf("---")	;	
	}
	
	printf("\n")	;
	
	for (k=0 ; k<N ; k++)
	{
		if 
		printf("%d | %c | \n", k, )	;
		
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


