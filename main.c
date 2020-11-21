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


int print_put_othello (int turn) {
	
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


int	check_put_othello ( int x, int y) {
	
		int board[x][y]	;
		

		
		if (board [x][y] != 0 ) //�̹� ���� ���� ��  
		{
			printf ("invalid input ! (already occupied)\n" )	;
			return 0	;
		}
		
		else if (x >= N || y >=N) // ���� ���� ũ�⸦ �Ѿ�� �� 
		{
			printf("invalid input ! (should be less than %d)\n", N)	;
			return 0	;
		}
		//else if �� ������ �� 
		else
		{
		return 1	;
		}
}


/*int cannot_flip (int putStone[], int board [N][N], int turn)
	{
		if (board[putStone[0]])	
	} */

//�� ���� ������ ���� §  �Լ� 
void flip_try_white (  int x, int y)
	{
		int board[x][y]	;
		int i	;
	
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		
	
		
		
		
		//���� �� ������ �õ� 
		if (board[x+1][y] == 2) // ���� �� ���� � ���̶�� 
		{
			while ( board[x+1+n][y] !=2) //����� ���������� ���� 
			{
				n++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< n; i++)
				board [ x+1+i][y] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�Ʒ��� �� ������ �õ� 
			if (board[x-1][y] == 2) // ���� �� �Ʒ��� � ���̶�� 
		{
			while ( board[x-1-s][y] !=2) //����� ���������� ���� 
			{
				s++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< s; i++)
				board [ x-1-i][y] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//����(����) �� ������ �õ� 
			if (board[x][y-1] == 2) // ���� �� ������  � ���̶�� 
		{
			while ( board[x][y-1-w] !=2) //����� ���������� ���� 
			{
				w++ ;										//�������� �ٲ�  ���� ���� ���� ���� 
			}
			for(i=0 ; i< w; i++)
				board [ x][y-1-i] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//����(������) �� ������ �õ� 
			if (board[x][y+1] == 2) // ���� �� ��������  � ���̶�� 
		{
			while ( board[x][y+1+e] !=2) //����� ���������� ���� 
			{
				e++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< e; i++)
				board [ x][y+1+i] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�ϵ���(���� ����) �� ������ �õ� 
			if (board[x-1][y+1] == 2) // ���� �� ���� ������  � ���̶�� 
		{
			while ( board[x-1-ne][y+1+ne] !=2) //����� ���������� ���� 
			{
				ne++ ;												//�ϼ������� �ٲ� ���� ���� ����  ���� 
			}
			for(i=0 ; i< ne; i++)
				board [x-1-i][y+1+i] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//������(���� �Ʒ���) �� ������ �õ� 
			if (board[x+1][y+1] == 2) // ���� �� ���� �Ʒ�����  � ���̶�� 
		{
			while ( board[x+1+se][y+1+se] !=2) //����� ���������� ���� 
			{
				se++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< se; i++)
				board [ x+1+i][y+1+i] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//������(�� �Ʒ���) �� ������ �õ� 
			if (board[x+1][y-1] == 2) // ���� �� �� �Ʒ�����  � ���̶�� 
		{
			while ( board[x+1+sw][y-1-sw] !=2) //����� ���������� ���� 
			{
				sw++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< sw; i++)
				board [ x+1+i][y-1-i] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�ϼ���(�� ����) �� ������ �õ� 
			if (board[x-1][y-1] == 2) // ���� �� �� ������  � ���̶�� 
		{
			while ( board[x-1-nw][y-1-nw] !=2) //����� ���������� ���� 
			{
				nw++ ;												//�ϼ������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< nw; i++)
				board [ x-1-i][y-1-i] = 1	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //�� ��� ���� ���������� ���� ���� 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // �� ��ġ���� ������ ���� ���� ��Ÿ�� 
		printf ("White has flipped %d othellos!", y )	;
		
		
 } 
 
//����� ������ ���� §  �Լ� 
void flip_try_black (  int x, int y)
	{
		int board[x][y]	;
		int i	;
	
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		
		//���� �� ������ �õ� 
		if (board[x+1][y] == 2) // ���� �� ���� �� ���̶�� 
		{
			while ( board[x+1+n][y] !=2) //���� ���������� ���� 
			{
				n++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< n; i++)
				board [ x+1+i][y] = 1	; //�� �� �� ��� ����� �ٲٱ� 
		}
		
		//�Ʒ��� �� ������ �õ� 
			if (board[x-1][y] == 2) // ���� �� �ư� �� ���̶�� 
		{
			while ( board[x-1-s][y] !=2) //���� ���������� ���� 
			{
				s++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< s; i++)
				board [ x-1-i][y] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		//����(����) �� ������ �õ� 
			if (board[x][y-1] == 2) // ���� �� ������ �� ���̶�� 
		{
			while ( board[x][y-1-w] !=2) //���� ���������� ���� 
			{
				w++ ;										//�������� �ٲ�  ���� ���� ���� ���� 
			}
			for(i=0 ; i< w; i++)
				board [ x][y-1-i] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		//����(������) �� ������ �õ� 
			if (board[x][y+1] == 2) // ���� �� �������� �� ���̶��
		{
			while ( board[x][y+1+e] !=2) //���� ���������� ���� 
			{
				e++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< e; i++)
				board [ x][y+1+i] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		//�ϵ���(���� ����) �� ������ �õ� 
			if (board[x-1][y+1] == 2) // ���� �� ���� ������ �� ���̶�� 
		{
			while ( board[x-1-ne][y+1+ne] !=2) //���� ���������� ���� 
			{
				ne++ ;												//�ϼ������� �ٲ� ���� ���� ����  ���� 
			}
			for(i=0 ; i< ne; i++)
				board [x-1-i][y+1+i] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		//������(���� �Ʒ���) �� ������ �õ� 
			if (board[x+1][y+1] == 2) // ���� �� ���� �Ʒ����� �� ���̶�� 
		{
			while ( board[x+1+se][y+1+se] !=2) //���� ���������� ���� 
			{
				se++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< se; i++)
				board [ x+1+i][y+1+i] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		//������(�� �Ʒ���) �� ������ �õ� 
			if (board[x+1][y-1] == 2) // ���� �� �� �Ʒ����� �� ���̶�� 
		{
			while ( board[x+1+sw][y-1-sw] !=2) //���� ���������� ���� 
			{
				sw++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< sw; i++)
				board [ x+1+i][y-1-i] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		//�ϼ���(�� ����) �� ������ �õ� 
			if (board[x-1][y-1] == 2) // ���� �� �� ������ �� ���̶�� 
		{
			while ( board[x-1-nw][y-1-nw] !=2) //���� ���������� ���� 
			{
				nw++ ;												//�ϼ������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< nw; i++)
				board [ x-1-i][y-1-i] = 1	; //�� �� ��� ����� �ٲٱ� 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //�� ��� ���� ���������� ���� ���� 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // �� ��ġ���� ������ ���� ���� ��Ÿ�� 
		printf ("White has flipped %d othellos!", y )	;
		
		
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
	
	int turn =0	; // turn�� ¦���� white Ȧ���� black���� �����ϰ� �۵��ϵ��� �� 
	int x,y;
	//�ʱ�ȭ 
	init_othello ()	;
	
	print_othello ()	;
	

	
	if( (turn % 2)==0 )
	{
		printf("put a new white othello : ")	;
		scanf("%d %d", &x ,&y)	;
		
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
	

	

	
	
	

	




