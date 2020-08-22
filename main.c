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


	//스크린 셋팅 //빈스크린
	screen = setscreen();
	printscreen(screen);

	//넥스트 셋팅  새 블록 넥스트에 전달
	waiting_rotation_ = newblock(&Rnum);
	NextBlock(screen, waiting_rotation_);


	while (1) {
		
		rotation_ = waiting_rotation_; //넥스트에 있던 함수 넘기기

		//블록 출발지점 셋팅
		blocks[0].x = (MX0 + MX) / 2;
		blocks[0].y = MY0 + 1;

		// 출발 할 블록 좌표 계산 후 해당 블록 리턴, 좌표 입력
		blck = rotation_(Rnum, blck);
		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB;
	

		//넥스트 셋팅  새 블록 넥스트에 전달
		waiting_rotation_ = newblock(&Rnum);
		NextBlock(screen, waiting_rotation_);

		printscreen(screen); //셋팅된 스크린

		
		while (1) //>>시간 인터럽트로 할 방법 -->> 스피드 조절
		{  
			blockState = downBlock(screen, blck, rotation_, Rnum);

			if (blockState != 1)
				break;

			for (int level = 0; level < 3; level++)
			{
				if (kbhit()) //>>인터럽트 함수로 구현, 키와 연결
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