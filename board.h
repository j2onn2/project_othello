#include <stdio.h>
#define N 6


#define BLACK 1
#define WHITE 0
#define	EMPTY 2



//������ �� �Լ�  
void print_othello (void)	;

//������ �ʱ�ȭ �Լ�  
void init_othello (void)	;

//��ġ�� ��ǥ �Է��� �������� üũ�ϴ� �Լ�  
int check_put_othello (int x, int y)	;


//��ġ�� �� �ִ� ������ �ִ��� üũ�ϴ� �Լ�  
int exist_space (void)	;

//�Է¹��� ��ǥ�� ���� ������ �Լ�  
void put_mine (int x, int y)	;

//���� ������ �� turn�� �ٲ��ִ� �Լ�  
void turn_pass (void)	;

//����� ����ϴ� �Լ�  
void check_result (void) ;

//���� ���������� ������ �Լ�  
int isGameEnd (void)	;
