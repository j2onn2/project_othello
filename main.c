#include <stdio.h>
#include <stdlib.h>

#define N 6 
#define BLACK 1
#define WHITE 0
#define	EMPTY 2



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int board [N][N]	;
int turn	;
int opposite	;
int end = 0	;

int num[2]	;	//num[0]�� �� ��, num [1]�� ������ �� 

//8���� ���� E,W,N,S,NE,NW,SE,SW ���� 
int direction [8][2] =  { {0, -1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1 }, {1,-1}, {1,1}}	;


void	init_othello	( ) {
	
		int x , y	;
		
		//��� �� for������ �ʱ����� ǥ���� 
		for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{board [x][y]= EMPTY;}	
			}
		
		// ù ���࿡ ���߾� 4ĭ�� ����� ������ �� 2���� �� 
		//print �Լ����� 1�� O 2�� X�� �� ���̹Ƿ� �ʱ������� �̷��� �������� 
		
		board [N/2-1][N/2-1] = WHITE	;
		board [N/2-1][N/2] = BLACK	;
		board [N/2][N/2-1] = BLACK	;
		board [N/2][N/2] = WHITE	;
		num[WHITE] = 2	;
		num[BLACK] = 2	;
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
			
			if (board[k][l] ==EMPTY)	//0�� ���� ��ĭ���� ���� 
			{ printf("  |")	;	}
			
			else if (board[k][l] ==WHITE)	// O�� ���� 1�� ��Ÿ�� ���� 
			{ printf(" O|")	;
				o_status ++ ;	}		// white ���� ������ ������ �� ���� üũ 
			
			
			else if (board[k][l]== BLACK)	// X�� ���� 2�� ��Ÿ�� ���� 
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


/*int print_put_othello (int turn) {
	
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
*/




//return ���� 1�̸� �ش� ĭ�� ���� ���� �� ����  
int	check_put_othello ( int x, int y) {
	
	
		int i	;
		
		//��ĭ�� ��쿡  
		if(board [x][y] == EMPTY){
			
			//ó�� �����ߴ� direction[8][2]�� �̿��Ͽ� ��� �����϶��� for���� ���� ǥ��  
			for (i=0; i<8; i++){
				int d_x = x+direction[i][0]	;
				int d_y = y+direction[i][1]	;
				
				if( d_x >=0 && d_y >= 0 && board [d_x][d_y] == opposite){
					do{
						d_x += direction [i][0]	;
						d_y += direction [i][1]	;
					} while (board[d_x][d_y] == opposite)	;
					
					if(board[d_x][d_y] == turn)
						return	1	;
				}
			}
			
			return 0	;
		}
		
		else if(x>=N || y>= N)
		{
			printf("(should be less than %d)\n", N)	;
			return 0	;
		}
		else
		return 0	;
	}
		
		
int exist_space (){
	int i ,j	;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			if(board [i][j] == EMPTY && check_put_othello(i,j)==1)
			return 1	;
		}
	}
	return 0	;
}

void put_mine (int x, int y){
	int dir[8] = {0,}	;
	int tot = 0	;
	int i 	;
	
	for(i=0; i<8; i++){
		int d_x = x+direction [i][0]	;
		int d_y = y+direction [i][1]	;
		int r_x = x	;
		int r_y = y	;
		
		if(d_x >= 0&&d_y >= 0 &&(board[d_x][d_y] == opposite)) {
			
			do {
				d_x += direction[i][0]	;
				d_y += direction[i][1]	;
			}	while (board[d_x][d_y]== opposite)	;
			
			if (board [d_x][d_y] == turn) {
				do{
					if(board[r_x][r_y] == EMPTY)
					num[turn]++	;
					else if (board [r_x][r_y] == opposite){
						num[turn] ++	;
						num[opposite] -- 	;
						dir [i] ++	;
					}
			board[r_x][r_y] = turn	;
			
			r_x += direction [i][0]	;
			r_y += direction [i][1]	;
			
				} while (board[r_x][r_y] == opposite)	;
				//return;
			}
		}
		
		tot += dir[i]	;
	}
	
	/*for(i=0;i<8;i++){
		printf("%d", dir[i])	;
		tot += dir[i]	;
	}*/
	
	printf(":: flip result ::\n")	;
	printf("W : %d, E : %d, N : %d, S : %d, NW : %d, NE : %d, SW : %d, SE : %d\n ", dir[0], dir[1], dir[2], dir[3], dir[4],dir[5], dir[6], dir[7])	;
	
	printf("\n")	;
	if (turn == WHITE){
	
	printf("WHITE has flipped %d othellos! \n", tot)	;
	}
	
	if (turn == BLACK ) {
		printf("BLACK has flipped %d othellos! \n", tot)	;
	}
}	

void check_result (){
	
	if(num[WHITE] > num[BLACK])
	printf("White win \n")	;
	
	else
	printf("Black win \n")	;
}


void turn_pass (){
	
	int tmp = turn	;
	turn = opposite	;
	opposite = tmp	;
}


void flip_try_white (  int x, int y)
	{
		
		int i	;
	
		int n=0, s=0, e=0, w=0, nw=0, ne=0, sw=0, se=0	;
		
	
		
		
		board [x][y] == WHITE	;
		//���� �� ������ �õ� 
		if (board[x+1][y] == BLACK) // ���� �� ���� � ���̶�� 
		{
			while ( board[x+1+n][y] !=BLACK) //����� ���������� ���� 
			{
				n++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< n; i++)
				board [ x+1+i][y] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�Ʒ��� �� ������ �õ� 
			if (board[x-1][y] == BLACK) // ���� �� �Ʒ��� � ���̶�� 
		{
			while ( board[x-1-s][y] !=BLACK) //����� ���������� ���� 
			{
				s++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< s; i++)
				board [ x-1-i][y] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//����(����) �� ������ �õ� 
			if (board[x][y-1] == BLACK) // ���� �� ������  � ���̶�� 
		{
			while ( board[x][y-1-w] !=BLACK) //����� ���������� ���� 
			{
				w++ ;										//�������� �ٲ�  ���� ���� ���� ���� 
			}
			for(i=0 ; i< w; i++)
				board [ x][y-1-i] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//����(������) �� ������ �õ� 
			if (board[x][y+1] == BLACK) // ���� �� ��������  � ���̶�� 
		{
			while ( board[x][y+1+e] !=BLACK) //����� ���������� ���� 
			{
				e++ ;										//�������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< e; i++)
				board [ x][y+1+i] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�ϵ���(���� ����) �� ������ �õ� 
			if (board[x-1][y+1] == BLACK) // ���� �� ���� ������  � ���̶�� 
		{
			while ( board[x-1-ne][y+1+ne] !=BLACK) //����� ���������� ���� 
			{
				ne++ ;												//�ϼ������� �ٲ� ���� ���� ����  ���� 
			}
			for(i=0 ; i< ne; i++)
				board [x-1-i][y+1+i] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//������(���� �Ʒ���) �� ������ �õ� 
			if (board[x+1][y+1] == BLACK) // ���� �� ���� �Ʒ�����  � ���̶�� 
		{
			while ( board[x+1+se][y+1+se] !=BLACK) //����� ���������� ���� 
			{
				se++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< se; i++)
				board [ x+1+i][y+1+i] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//������(�� �Ʒ���) �� ������ �õ� 
			if (board[x+1][y-1] == BLACK) // ���� �� �� �Ʒ�����  � ���̶�� 
		{
			while ( board[x+1+sw][y-1-sw] !=BLACK) //����� ���������� ���� 
			{
				sw++ ;												//���������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< sw; i++)
				board [ x+1+i][y-1-i] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		//�ϼ���(�� ����) �� ������ �õ� 
			if (board[x-1][y-1] == BLACK) // ���� �� �� ������  � ���̶�� 
		{
			while ( board[x-1-nw][y-1-nw] !=BLACK) //����� ���������� ���� 
			{
				nw++ ;												//�ϼ������� �ٲ� ���� ���� ���� ���� 
			}
			for(i=0 ; i< nw; i++)
				board [ x-1-i][y-1-i] = WHITE	; //�� ��� ��� �򵹷� �ٲٱ� 
		}
		
		y = w+e+n+s+nw+ne+sw+se	; //�� ��� ���� ���������� ���� ���� 
		
		printf (":: flip result :: \n")	;
		printf (" W : %d E : %d N : %d S : %d NW : %d NE : %d SW : %d SE : %d \n", w, e, n, s, nw, ne, sw, se)	; // �� ��ġ���� ������ ���� ���� ��Ÿ�� 
		printf ("White has flipped %d othellos! \n", y )	;
		
		
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
 
 
int isGameEnd (){
	int x, y	;

	
	for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{
				if(board [x][y] == EMPTY)	
					{
						return 1	;
					}
					
			}
			}
			
			
			
	return 0	; 
			
}



void main () {
	
	int x, y	;
	turn = WHITE	;
	opposite = BLACK	;
	
	//�ʱ�ȭ 
	init_othello ()	;
	
	while (isGameEnd()==1){
	
		print_othello ()	;
	
		if(exist_space() == 0){
			turn_pass ()	;
			end ++	;
		//	break	;
			}
		
		else if (exist_space() == 1)	{
		
	
	
	
	if( turn == WHITE )
	{
		printf("put a new white othello : ")	;
		scanf("%d %d", &x ,&y)	;	}
	else if (turn == BLACK)
	{
		printf("put a new black othello : ")	;
		scanf("%d %d", &x ,&y)	; 
	} 
	
	
	if(check_put_othello (x,y)==1) {
	/*	flip_try_white(x,y)	;
			turn_pass ()	;
		} */
		
	put_mine (x,y)	;
		turn_pass ()	;
	}
	else if (check_put_othello (x,y)== 0){
		printf("invalid input! \n")	;
		continue	;
	}
 
}
}
	
		printf(" the number is %d\n", isGameEnd ())	;
		printf("the exist space %d\n", exist_space())	;
	check_result ()	;
}

/*
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
	*/

	

	
	
	

	




