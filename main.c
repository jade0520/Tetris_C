#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Setting.h"
#include "PrintBlock.h"
#include "Tell.h"
#include "ControlBlock.h"


void Score(int ** screen, int score)
{
	screen[SY0][SX0 + 7] = score;
}
 
int main(void) {

	int startcoin=0;
	int blockState = 0;
	int key;
	int Rnum;
	int score =0;
	point blocks[4];
	point* blck = blocks;
	int** screen;
	point * (*rotation_)(int, point*) = NULL;
	point * (*waiting_rotation_)(int, point*) = NULL;
	
	
	startscreen(startcoin);


	//��ũ�� ���� //��ũ��
	screen = setscreen();
	printscreen(screen);

	//�ؽ�Ʈ ����  �� ��� �ؽ�Ʈ�� ����
	waiting_rotation_ = newblock(&Rnum);
	NextBlock(screen, waiting_rotation_);


	while (1) {
		
		rotation_ = waiting_rotation_; //�ؽ�Ʈ�� �ִ� �Լ� �ѱ��

		//��� ������� ����
		blocks[0].x = (MX0 + MX) / 2;
		blocks[0].y = MY0 + 1;

		// ��� �� ��� ��ǥ ��� �� �ش� ��� ����, ��ǥ �Է�
		blck = rotation_(Rnum, blck);
		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB;
	

		//�ؽ�Ʈ ����  �� ��� �ؽ�Ʈ�� ����
		waiting_rotation_ = newblock(&Rnum);
		NextBlock(screen, waiting_rotation_);

		printscreen(screen); //���õ� ��ũ��

		
		while (1) //>>�ð� ���ͷ�Ʈ�� �� ��� -->> ���ǵ� ����
		{  
			blockState = downBlock(screen, blck, rotation_, Rnum);

			if (blockState != 1)
				break;

			for (int level = 0; level < 3; level++)
			{
				if (kbhit()) //>>���ͷ�Ʈ �Լ��� ����, Ű�� ����
				{
					tellKey(screen, blck, rotation_, &Rnum);
				}
				printscreen(screen);
				Sleep(50);

			}
		}

		if (blockState == 0) {
			score += tellClear(screen);
			Score(screen, score);
		}
		else break;

	}

	printf("\n The Game END");


		
	while (1);

	
	return 0;
}