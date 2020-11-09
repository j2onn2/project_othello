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
	
	int i, 	j, k, l	, m;
	

	printf("   ")	;
	for (i=0; i<N; i++)
	{
		printf(" %d ", i)	;		//ù ���� 0~5 ǥ�� 
	}
	
	printf ("\n")	;
	printf ("   ")	;
	  
	for (j=0; j<N; j++)			//���м� ǥ�� 
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
			{ printf(" O|")	;	}
			
			else if (board[k][l]== 2)	// X�� ���� 2�� ��Ÿ�� ���� 
			{ printf(" X|")	;	}
			
		}
		printf("\n")	;
		for (m=0; m<N+1; m++)	//���м� ǥ�� 
		{
		printf("---")	;	 
		}
		
		printf("\n")	;
	}
}


void main () {
	//�ʱ�ȭ 
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


