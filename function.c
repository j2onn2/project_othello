#include "board.h"

int board[N][N]	;
int turn	;
int opposite	;


int num[2]	;	//num[0]�� ��, num [1]�� ������ 

//8���� ���� E,W,N,S,NE,NW,SE,SW ���� 
int direction [8][2] =  { {0, -1}, {0,1}, {-1,0}, {1,0}, {-1,-1}, {-1,1 }, {1,-1}, {1,1}}	;


//�ʱ�ȭ �Լ�  
void	init_othello	( ) {
	
		int x , y	;
		
		//��� �� for������ �ʱ����� ǥ���� 
		for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{board [x][y]= EMPTY;}	
			}
		
		// ù ���࿡ ���߾� 4ĭ�� ����� ������ �� 2���� �� 
		//print �Լ����� 0�� O 1�� X�� �� ���̹Ƿ� �ʱ������� �̷��� �������� 
		
		board [N/2-1][N/2-1] = WHITE	;
		board [N/2-1][N/2] = BLACK	;
		board [N/2][N/2-1] = BLACK	;
		board [N/2][N/2] = WHITE	;
		num[WHITE] = 2	;
		num[BLACK] = 2	;
	}


//���� ���� �� �ִ��� Ȯ���ϴ� �Լ� 	
int	check_put_othello ( int x, int y) {
	
	
		int i	;
		
		//��ĭ�� ��쿡  
		if(board [x][y] == EMPTY){
			
			//ó�� �����ߴ� direction[8][2]�� �̿��Ͽ� ��� �����϶��� for���� ���� ǥ��  
			for (i=0; i<8; i++){
				int d_x = x+direction[i][0]	;
				int d_y = y+direction[i][1]	;
			//�ֺ��� ���� �ִ��� Ȯ���ϱ� ���� ���ο� ������ ���� 	
				
				//0���� ���� ���� �� ��뵹�� �ֺ��� ���� ��� ��ȯ�� 1����   
				if( d_x >=0 && d_y >= 0&& board [d_x][d_y] == opposite){
					do{
						d_x += direction [i][0]	;
						d_y += direction [i][1]	;
					} while (board[d_x][d_y] == opposite)	; //�ݴ뵹�� ���Ë����� ��  
					
					if(board[d_x][d_y] == turn)
						return	1	;		 
				}
				
			}
			
		
			return 0	;
		}
		
		else if(x>=N || y>= N)	//�Ǻ��� ū ���� �Է��ϸ� ���� �� ��  
		{
			printf("(should be less than %d)\n", N)	;
			return 0	;
		}
		else if (board[x][y]!= EMPTY)	//�̹� ���� �ִ� ��� ���� �� ��  
		{
			printf("already occupied!\n")	;
		}
		return 0	;
	}
	
// ��ȯ���� 1�� ��� ���� �� ���� 
int exist_space (){
	int i ,j	;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			
			if(board [i][j] == EMPTY && check_put_othello(i,j)==1)	//���� ����ְ� ���� ���� �� �ִ� �����̸� ��ȯ�� 1�� ��  
			return 1	;
		}
	}
	return 0	; // �׷��� ���� ��� ��ȯ�� 0 �� �־� �� ���� ��  
}


//�� ���� ���� �Լ�  
void put_mine (int x, int y){
	
	int dir[8] = {0,}	;
	int tot = 0	;	//�� ������ ���� ������ ���� ���� ����  
	int i 	;
	
	for(i=0; i<8; i++){
		int d_x = x+direction [i][0]	;
		int d_y = y+direction [i][1]	;
		int r_x = x	;
		int r_y = y	;
		
		if(d_x >= 0&&d_y >= 0 &&(board[d_x][d_y] == opposite)) { //������ ��뵹�� ���� ��� 
			
			do {
				d_x += direction[i][0]	;
				d_y += direction[i][1]	;
			}	while (board[d_x][d_y]== opposite)	;	//�ݴ뵹�̶�� ��� ��  
			
			if (board [d_x][d_y] == turn) {
				do{
					if (board [r_x][r_y] == opposite){
						dir [i] ++	;			//������ ��뵹�� ������ ���� ���� dir[i]�� ��뵹�ϋ����� ��½�����  
					}
					board[r_x][r_y] = turn	;	//��뵹�� �� ���� �ٲ�  
			
					r_x += direction [i][0]	;
					r_y += direction [i][1]	;
			
				} while (board[r_x][r_y] == opposite)	;	//��뵹�̶�� �־��� ������ ��� ����  
				//return;
			}
		}
		
		tot += dir[i]	;	//������������ �߰��ǵ��� �ؼ� �� ��� ���������� ���� ����  
	}
	
	printf(":: flip result ::\n")	;
	printf("W : %d, E : %d, N : %d, S : %d, NW : %d, NE : %d, SW : %d, SE : %d\n ", dir[0], dir[1], dir[2], dir[3], dir[4],dir[5], dir[6], dir[7])	;
	//�� ���⺰�� ������ ���� ���� ���� ����  
	
	printf("\n")	;
	
	//��� ���� ���� ��쿡�� ����� � ���������� ǥ��  
	if (turn == WHITE){
	
	printf("WHITE has flipped %d othellos! \n", tot)	;
	}
	
	//������ ���̾��� ��� �������� � ���������� ǥ��  
	if (turn == BLACK ) {
		printf("BLACK has flipped %d othellos! \n", tot)	;
	}
}	



void check_result (){
	
	//������� ������ �� ������ ����� �̱�  
	if(num[WHITE] > num[BLACK])
	printf("White win \n")	;
	
	//������ ���� ������ �� ������ �������� �̱�  
	else if (num[BLACK] > num[WHITE])
	printf("Black win \n")	;
	
	//���� ������ ���� ��� ���  
	else
	printf("Wow tie!\n")	;
}


//turn�� ���ư����� �ϴ� �Լ�  
void turn_pass (){
	
	int tmp = turn	;
	turn = opposite	;
	opposite = tmp	;
}


//���� ���� ������ ����  
int isGameEnd (){
	int x, y	;

	
	for(x=0; x<N; x++)
			{
				for (y=0; y<N; y++)
				{
				if(board [x][y] == EMPTY)	//�������� ��������� ������ ��� ��  
					{
						return 0	;
					}
					
			}
			}
			
			
	//�������� ������ ������ ���� �� 		
	return 1	; 
			
}


