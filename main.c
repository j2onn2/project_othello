#include "board.h"

#define N 6


#define BLACK 1
#define WHITE 0
#define	EMPTY 2

int turn	;
int opposite	;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 


void main () {
	
	int x, y	;
	turn = WHITE	;
	opposite = BLACK	;
	
	//�ʱ�ȭ�ϴ� �Լ�  
	init_othello ()	;
	
	
	while (isGameEnd()==0){
	
		//��ġ�� ������ ĭ�� �ִ��� Ȯ���ϴ� �Լ�  
		if(exist_space() == 0){
			
			//��ġ�� �Ұ����ϸ� turn pass  
			turn_pass ()	;
			printf("Can't put stone. Automatically turn pass\n")	;
			
			//�� player�� ��ġ�� �Ұ��� �ϸ� �ݺ��� ��������  
			break	;
			}
		
		//��ġ�� �����ϸ� ������ ����  
		else if (exist_space() == 1)	{
		
		//������ �� ���  
		print_othello ()	;
		
		//���� ����� ���ʶ��  
		if( turn == WHITE )
		{
			printf("put a new white othello : ")	;	//��� ���� ��ġ ��ǥ�� �Է¹���  
			scanf("%d %d", &x ,&y)	;
		}
		
		//���� �������� ���ʶ��  
		else if (turn == BLACK)
		{
			printf("put a new black othello : ")	; //������ ���� ��ġ ��ǥ�� �Է� ����  
			scanf("%d %d", &x ,&y)	; 
		} 
	
	
		//��ġ�� ��ǥ �Է��� �������� üũ  
		if(check_put_othello (x,y)==1) 	//�����ϴٸ� ���� ������ turn�� �ѱ�  
		{
			put_mine (x,y)	;
			turn_pass ()	;
		}
		else if (check_put_othello (x,y)== 0)	//�������� �ʴٸ� �������� �Է����� �������� �ٽ� ��  
		{
			printf("invalid input! \n")	;
			continue	;
		}
 
		}
		}
	print_othello ()	;	//������ ������ �� ������ ���� ������  
	
	check_result ()	;	//���� ����� ��Ÿ��  
}


	

	
	
	

	




