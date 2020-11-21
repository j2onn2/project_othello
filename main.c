#include <stdio.h>
#include <stdlib.h>
#define N 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int board [N][N]	;

void	init_othello	( ) {
	
		int x , y	;
		
		//��� �� for������ �ʱ����� ǥ���� 
		for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{board [x][y]= 0 ;}	
			}
		
		// ù ���࿡ ���߾� 4ĭ�� ����� ������ �� 2���� �� 
		//print �Լ����� 1�� O 2�� X�� �� ���̹Ƿ� �ʱ������� �̷��� �������� 
		
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
		printf(" %d ", m)	;		//ù ���� 0~5 ǥ�� 
	}
	
	printf ("\n")	;
	printf ("   ")	;
	  
	for (m=0; m<N; m++)			//���м� ǥ�� 
	{
		printf("---")	;	 
	}
	
	printf("\n")	;
	
	for (k=0 ; k<N ; k++)		//������ 0~5���� ǥ�� 
	{
		printf("%d| ",k )	;	
		
		for(l=0 ; l<N ; l++)	//�� �ϳ� �� �����ִ� �� ǥ���ϱ� ���� for���� �ѹ� �� �� 
		{
			
			if (board[k][l] ==0)	//0�� ���� ��ĭ���� ���� 
			{ printf("  |")	;	}
			
			else if (board[k][l] ==1)	// O�� ���� 1�� ��Ÿ�� ���� 
			{ printf(" O|")	;
				o_status ++ ;	}		// white ���� ������ ������ �� ���� üũ 
			
			
			else if (board[k][l]== 2)	// X�� ���� 2�� ��Ÿ�� ���� 
			{ printf(" X|")	;
				x_status ++ ;	}		//black ���� ������ ������ �� ���� üũ 
			
		}
		printf("\n")	;
		for (m=0; m<N+1; m++)	//���м� ǥ�� 
		{
		printf("---")	;	 
		}
		
		printf("\n")	;
	}
		printf (" STATUS - WHITE : %d, BLACK : %d \n", o_status, x_status)	; // �� ������ ������ ������ �Ź� printf_othello�� ���� �� ���¸� ����� �� ���� 
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
		//else if �� ������ �� 
		
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
	//�ʱ�ȭ 
	init_othello ()	;
	
	print_othello ()	;
	

	
	
	

	

}


