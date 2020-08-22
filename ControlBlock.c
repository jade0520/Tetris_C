#include <stdio.h>
#include "Setting.h"
#include "PrintBlock.h"
#include "Tell.h"
#include "ControlBlock.h"


void dropBlock(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum)
{
	int howdeepY = 0;
	int howY = MY; // movin 블록과 굳은 블록의 거리 중 가장 짧은 거리

				   //기존 블럭 삭제 //
	for (int i = 0; i < 4; i++)
		screen[blck[i].y][blck[i].x] = blankB;

	//블럭 좌표 수정 //
	// 블록을 이루는 y좌표들 에서 시작하여 savedB나 edgeB을 만날 때 까지의 값이 가장 적은 블록으로 그 값만 큼 내린다
	for (int i = 0; i < 4; i++)
	{
		while (1)//첫번 째 saved나 edge를 만날 때 까지
		{
			if (screen[blck[i].y + howdeepY + 1][blck[i].x] == savedB || screen[blck[i].y + howdeepY + 1][blck[i].x] == edgeB) //만약 해당 블럭의 한 점 아래가 굳은 블럭이나 가장자리라면
				break;
			howdeepY++;
		}
		if (howY > howdeepY) //받은 높이 값이 더 작으면
			howY = howdeepY; // 받은 값으로 바꾼다.

		howdeepY = 0; //비우기
	}


	for (int i = 0; i < 4; i++) //모든 블록을 그 가장 짧은 거리만큼 내린다.
	{
		for (int k = 0; k < howY; k++)
			blck[i].y++;
	}


	//새로운 블럭 좌표 입력///
	blck = rotation_(Rnum, blck); //메인 포인트 기준으로 블럭 위치 잡아서 좌표 수정
	for (int i = 0; i < 4; i++)
		screen[blck[i].y][blck[i].x] = movinB; //새 블록 입력
	printscreen(screen); //출력
}

//게임이 끝나면 2리턴
int downBlock(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) { //메인 내리고 현재 블럭 위치 수정 바닥에 닿으면  0 출력하게 해야함
																						 // blck 는 현재 블럭 위치를 담은 포인트 포인터 

	if (tellBlockStop(screen, blck, rotation_, Rnum) == 1)  //블록이 땅에 닿았는지 확인 닿았으면 1 천장에도 닿았으면 2 리턴
		return 0;
	else if (tellBlockStop(screen, blck, rotation_, Rnum) == 2)
		return 2;

	else {
		for (int i = 0; i < 4; i++)//기존 블럭 지우기
			screen[blck[i].y][blck[i].x] = blankB;

		blck[0].y++; //한칸 내리기
		blck = rotation_(Rnum, blck); //메인 포인트 기준으로 블럭 위치 잡아서 좌표 수정
		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //새 블록 입력

		printscreen(screen); //얘가 있고 없고에 키 입력 후 변화하는 블럭의 속도가 달라진다!!1!!!!!!!

		return 1;
	}
}

void moveright(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) {//for tellKey 
	point testblock[4];
	// 오른쪽 검사이므로 X+1검사
	
	for (int i = 0; i < 4; i++)
	{
		testblock[i].x = blck[i].x + 1;
		testblock[i].y = blck[i].y;
	}
 
	if (!tellBlockEdge(screen, testblock))// 이동할 공간이 막히지 않으면
	{
		for (int i = 0; i < 4; i++)//기존 블럭 지우기
			screen[blck[i].y][blck[i].x] = blankB;

		blck[0].x++; //한칸 오른쪽으로
	 
		blck = rotation_(Rnum, blck); //메인 포인트 기준으로 블럭 위치 잡아서 좌표 수정

		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //좌표 입력
	}
	 

};

void moveleft(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) {//for tellKey
	point testblock[4];
	// 오른쪽 검사이므로 X-1검사
	for (int i = 0; i < 4; i++)
	{
		testblock[i].x = blck[i].x - 1;
		testblock[i].y = blck[i].y;
	}

	if (!tellBlockEdge(screen, testblock))// 이동할 공간이 막히지 않으면
	{
		for (int i = 0; i < 4; i++)//기존 블럭 지우기
			screen[blck[i].y][blck[i].x] = blankB;

		blck[0].x--; //한칸 왼쪽으로
		blck = rotation_(Rnum, blck); //메인 포인트 기준으로 블럭 위치 잡아서 좌표 수정
		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //좌표 입력
	}

}
