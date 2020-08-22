#include "Setting.h"
#include "PrintBlock.h"
#include "ControlBlock.h" //for tellkey 가장 밑으로 내리기
#include <stdio.h>
//완료



int tellBlockStop(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) { //블록 내리고 검사, 블록 회전하고 검사,블록 시작할 때 검사 블럭이 멈추면 1리턴

	int x, y;

	for (int i = 0; i < 4; i++)
	{
		x = blck[i].x;
		y = blck[i].y; //블럭 중 하나 좌표를 받고 
		if (y > MY0) {
			if (screen[y + 1][x] == savedB || screen[y + 1][x] == edgeB) //만약 해당 블럭의 한 점 아래가 굳은 블럭이나 가장자리라면
			{
				for (int i = 0; i < 4; i++)
					screen[blck[i].y][blck[i].x] = savedB; // 그 블록전체가 굳는다.
				
				//굳은 블록 출력
				printscreen(screen);
				
				//블록이 천장과 닿으면 2리턴
				if (blck[0].y == MY0 || blck[1].y == MY0 || blck[2].y == MY0 || blck[3].y == MY0 ) //블록의 0번째 위치는 가장 높이 있는 좌표 
				return 2;
					


				return 1;
			}
		}

	}

	

	return 0;
}

int downraw(int ** pscreen, int Y, int X) { //없어진 Y부터 시작
	if (Y - 1 == MY0)
	{
		pscreen[Y][X] = blankB; //가장 위에 있던 행은 0을 받는다
		return 1; //검사하는 열의 꼭대기에 닿으면 끝
	}
	else
	{
		pscreen[Y][X] = pscreen[Y - 1][X]; //위의 값을 아래로 내린다.
		downraw(pscreen, Y - 1, X); //다음 값 검사
		return 1;
	}


}

int tellLinkedLine(int **pscreen, int Y, int X) { //호출할 때는 검사할 Y열, X는 시작 전열 MX0
	if (pscreen[Y][X + 1] == savedB) 
	{
		tellLinkedLine(pscreen, Y, X + 1);//옆칸의 옆칸도 검사
		 //전칸에서 전체 행이 1이라는 신호가 오면 return 1
	}
	else if (X + 1 == MX -1) //옆칸이 1이 아닌데, MX면
		return 1; // 행이 모두 이어져 있다.
	else
		return 0;
}

int tellClear(int ** pscreen) //전체 검사
{
	int score = 0; 
	for (int y = MY0+1; y < MY; y++)
	{
		if (tellLinkedLine(pscreen, y, MX0)) { //k번째 행이 완성되었다면 
			for (int x = MX0 + 1; x < MX - 1; x++)
			{
				downraw(pscreen, y, x); //k번째 행의 i부터 위의 항들을 하나씩 내린다.
			}
			score += 100; //완성 된 줄 당 100점씩 추가
		}
	}
	return score;
}

int tellBlockEdge(int ** screen, point* blck) {// 블럭이 엣지나 saved에 닿으면 return 1
	int x, y;

	for (int i = 0; i < 4; i++)
	{
		x = blck[i].x;
		y = blck[i].y; //블럭 중 하나 좌표를 받고 

		if (screen[y][x] == savedB || screen[y][x] == edgeB) //만약 해당 좌표의 블럭이 엣지나 굳은 블럭이라면 return 1
			return 1;

	}
	return 0;
}

void tellKey(int ** screen, point * blck, point* (*rotation_)(int, point*), int * Rnum) {

	int key = getch();
	if (key == 224)
	{
		key = getch();
		switch (key) {
		case 75: moveleft(screen, blck, rotation_, *Rnum);//우 우측이동 함수로 연결
			break;
		case 77: moveright(screen, blck, rotation_, *Rnum);//좌 좌측이동 함수로 연결
			break;
		case 80:dropBlock(screen, blck, rotation_, *Rnum); //아이에 가장 밑으로 도착하는 걸로 바꾸기
		default:
			break;
		}
	}
	else if (key == 32)
	{
		for (int i = 0; i < 4; i++)//기존 블럭 지우기
			screen[blck[i].y][blck[i].x] = blankB;

		(*Rnum)++;

		blck = rotation_(*Rnum, blck); //모양 바꾸는 함수로 연결 blck 리턴

		if (blck[1].x == MX0) //왼쪽 닿는지 검사 
		{
			for (int i = 0; i < 4; i++)
				blck[i].x++; //닿으면 오른쪽으로
		}
		else if (blck[1].x == MX0 - 1)//가로막대기검사용
		{
			for (int i = 0; i < 4; i++)
				blck[i].x += 2; //닿으면 오른쪽으로
		}
		if (blck[2].x == MX - 2) //오른쪽 닿는지 검사
		{
			for (int i = 0; i < 4; i++)
				blck[i].x--; //닿으면 왼쪽으로
		}

		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //새 블록 입력

												   //printscreen(screen); //출력

	}
}



#pragma once
