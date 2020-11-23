#include "board.h"


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

