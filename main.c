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

int	check_put_othello ( int putStone [] , int board [N][N]) {
	
		if (board [putStone[0]][putStone[1]] != 0 ) //�̹� ���� ���� ��  
		{
			printf ("invalid input ! (already occupied)\n" )	;
			return 0	;
		}
		
		else if (putStone [0] >= N || putStone [1] >=N) // ���� ���� ũ�⸦ �Ѿ�� �� 
		{
			printf("invalid input ! (should be less than %d)\n", N)	;
			return 0	;
		}
		//else if �� ������ �� 
		
		return 1	;
}

//�� ���� ������ ���� §  �Լ� 
void flip_try_white (  int putStone[] , int board [N][N])
	{
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		int	x	;
		int y	;
		
		//���� �� ������ �õ� 
		if (board[putStone[0]+1][putStone[1]] == 2) // ���� �� ���� � ���̶�� 
		{
			while ( board[putStone[0]+1+n][putStone[1]] !=2) //����� ���������� ���� 
			{
				n++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(x=0 ; x< n; x++)
				board [ putStone[0]+1+x][putStone[1]] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�Ʒ��� �� ������ �õ� 
			if (board[putStone[0]-1][putStone[1]] == 2) // ���� �� �Ʒ��� � ���̶�� 
		{
			while ( board[putStone[0]-1-s][putStone[1]] !=2) //����� ���������� ���� 
			{
				s++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(x=0 ; x< s; x++)
				board [ putStone[0]-1-x][putStone[1]] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//����(����) �� ������ �õ� 
			if (board[putStone[0]][putStone[1]-1] == 2) // ���� �� ������  � ���̶�� 
		{
			while ( board[putStone[0]][putStone[1]-1-w] !=2) //����� ���������� ���� 
			{
				w++ ;										//�������� �ٲ�  ���� ���� ���� ���� 
			}
			for(x=0 ; x< w; x++)
				board [ putStone[0]][putStone[1]-1-w] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//����(������) �� ������ �õ� 
			if (board[putStone[0]][putStone[1]+1] == 2) // ���� �� ��������  � ���̶�� 
		{
			while ( board[putStone[0]][putStone[1]+1+e] !=2) //����� ���������� ���� 
			{
				e++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(x=0 ; x< e; x++)
				board [ putStone[0]][putStone[1]+1+e] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�ϵ���(���� ����) �� ������ �õ� 
			if (board[putStone[0]-1][putStone[1]+1] == 2) // ���� �� ���� ������  � ���̶�� 
		{
			while ( board[putStone[0]-1-ne][putStone[1]+1+ne] !=2) //����� ���������� ���� 
			{
				ne++ ;												//�ϼ������� �ٲ� ���� ���� ����  ���� 
			}
			for(x=0 ; x< ne; x++)
				board [ putStone[0]-1-ne][putStone[1]+1+ne] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//������(���� �Ʒ���) �� ������ �õ� 
			if (board[putStone[0]+1][putStone[1]+1] == 2) // ���� �� ���� �Ʒ�����  � ���̶�� 
		{
			while ( board[putStone[0]+1+se][putStone[1]+1+se] !=2) //����� ���������� ���� 
			{
				se++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(x=0 ; x< se; x++)
				board [ putStone[0]+1+se][putStone[1]+1+se] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//������(�� �Ʒ���) �� ������ �õ� 
			if (board[putStone[0]+1][putStone[1]-1] == 2) // ���� �� �� �Ʒ�����  � ���̶�� 
		{
			while ( board[putStone[0]+1+sw][putStone[1]-1-sw] !=2) //����� ���������� ���� 
			{
				sw++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(x=0 ; x< sw; x++)
				board [ putStone[0]+1+sw][putStone[1]-1-sw] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�ϼ���(�� ����) �� ������ �õ� 
			if (board[putStone[0]-1][putStone[1]-1] == 2) // ���� �� �� ������  � ���̶�� 
		{
			while ( board[putStone[0]-1-nw][putStone[1]-1-nw] !=2) //����� ���������� ���� 
			{
				nw++ ;												//�ϼ������� �ٲ� ���� ���� ���� ���� 
			}
			for(x=0 ; x< nw; x++)
				board [ putStone[0]-1-nw][putStone[1]-1-nw] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //�� ��� ���� ���������� ���� ���� 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // �� ��ġ���� ������ ���� ���� ��Ÿ�� 
		printf ("White has flipped %d othellos!", y )	;
		
		
 } 
 
 //� ���� ������ ���� § �Լ� 
 void flip_try_black (  int putStone[] , int board [N][N])
	{
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		int	x	;
		int y	;
		
		//���� �� ������ �õ� 
		if (board[putStone[0]+1][putStone[1]] == 1) // ���� �� ���� �� ���̶�� 
		{
			while ( board[putStone[0]+1+n][putStone[1]] !=1) //���� ���������� ���� 
			{
				n++ ;
			}
			for(x=0 ; x< n; x++)
				board [ putStone[0]+1+x][putStone[1]] = 2	; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//�Ʒ��� �� ������ �õ� 
			if (board[putStone[0]-1][putStone[1]] == 1) // ���� �� �Ʒ��� �� ���̶�� 
		{
			while ( board[putStone[0]-1-s][putStone[1]] !=1) //���� ���������� ���� 
			{
				s++ ;
			}
			for(x=0 ; x< s; x++)
				board [ putStone[0]-1-x][putStone[1]] = 2	;//�� �� �� ��� ����� �ٲٱ� 
		}
		
		//����(����) �� ������ �õ� 
			if (board[putStone[0]][putStone[1]-1] == 1) // ���� �� ������  �� ���̶�� 
		{
			while ( board[putStone[0]][putStone[1]-1-w] !=1) //���� ���������� ����  
			{
				w++ ;
			}
			for(x=0 ; x< w; x++)
				board [ putStone[0]][putStone[1]-1-w] = 2	; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//����(������) �� ������ �õ� 
			if (board[putStone[0]][putStone[1]+1] == 1) // ���� �� ��������  ���̶�� 
		{
			while ( board[putStone[0]][putStone[1]+1+e] !=1)//���� ���������� ����  
			{
				e++ ;
			}
			for(x=0 ; x< e; x++)
				board [ putStone[0]][putStone[1]+1+e] = 2	; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//�ϵ���(���� ����) �� ������ �õ� 
			if (board[putStone[0]-1][putStone[1]+1] == 1) // ���� �� ���� ������ �� ���̶�� 
		{
			while ( board[putStone[0]-1-ne][putStone[1]+1+ne] !=1) ///���� ���������� ���� 
			{
				ne++ ;
			}
			for(x=0 ; x< ne; x++)
				board [ putStone[0]-1-ne][putStone[1]+1+ne] = 2; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//������(���� �Ʒ���) �� ������ �õ� 
			if (board[putStone[0]+1][putStone[1]+1] == 1) // ���� �� ���� �Ʒ�����  �� ���̶�� 
		{
			while ( board[putStone[0]+1+se][putStone[1]+1+se] !=1) //���� ���������� ����  
			{
				se++ ;
			}
			for(x=0 ; x< se; x++)
				board [ putStone[0]+1+se][putStone[1]+1+se] = 2	; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//������(�� �Ʒ���) �� ������ �õ� 
			if (board[putStone[0]+1][putStone[1]-1] == 1) // ���� �� �� �Ʒ�����  �� ���̶�� 
		{
			while ( board[putStone[0]+1+sw][putStone[1]-1-sw] !=1) //���� ���������� ����  
			{
				sw++ ;
			}
			for(x=0 ; x< sw; x++)
				board [ putStone[0]+1+sw][putStone[1]-1-sw] = 2	; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//�ϼ���(�� ����) �� ������ �õ� 
			if (board[putStone[0]-1][putStone[1]-1] == 1) // ���� �� �� ������ �� ���̶�� 
		{
			while ( board[putStone[0]-1-nw][putStone[1]-1-nw] !=1) //���� ���������� ����  
			{
				nw++ ;
			}
			for(x=0 ; x< nw; x++)
				board [ putStone[0]-1-nw][putStone[1]-1-nw] = 2	; //�� �� �� ��� ����� �ٲٱ� 
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
	//�ʱ�ȭ 
	init_othello ()	;
	
	print_othello ()	;
	

	
	
	

	

}


