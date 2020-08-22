#include <stdlib.h>
#include <time.h>
#include "PrintBlock.h"
#include "Setting.h"

point * rotation_Z(int RNUM, point * blck) { //Rnum과 메인 포인트를 기준으로 좌표를 찍은 후 좌표 세트 주소 리턴

	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;

	if (RNUM) //Rnum이 0일 때는 처음 시작 case로 가야함.
	{
		Rnum %= 2;
	}

	switch (Rnum)
	{
	case 0: //Z

		blck[1].x = mpx-1;  //제일 왼쪽에 있는 블럭
		blck[1].y = mpy;

		blck[2].x = mpx +1;  // 제일 오른쪽에있는 블럭
		blck[2].y = mpy + 1;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;

		return blck;
	case 1: //세로

		blck[1].x = mpx;
		blck[1].y = mpy+1;

		blck[2].x = mpx+1;
		blck[2].y = mpy;

		blck[3].x = mpx + 1;
		blck[3].y = mpy -1;
		return blck;

	default:
		break;
	}
}

point * rotation_I(int RNUM, point * blck) { //Rnum과 메인 포인트를 기준으로 좌표를 찍은 후 좌표 세트 주소 리턴


	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;

	if (RNUM) //Rnum이 0일 때는 처음 시작 case로 가야함.
	{
		Rnum %= 2;
	}

	switch (Rnum)
	{
	case 0: //ㅡ

		blck[1].x = mpx - 2;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx - 1;
		blck[3].y = mpy;

		return blck;

	case 1: //I

		blck[1].x = mpx;
		blck[1].y = mpy-2;

		blck[2].x = mpx;
		blck[2].y = mpy-1;

		blck[3].x = mpx;
		blck[3].y = mpy +1;

		return blck;
	

	default:
		break;
	}
}

point * rotation_O(int Rnum, point * blck) { //Rnum과 메인 포인트를 기준으로 좌표를 찍은 후 좌표 세트 주소 리턴

	int mpx = blck[0].x; 
	int mpy = blck[0].y;

	blck[1].x = mpx - 1;
	blck[1].y = mpy - 1;

	blck[2].x = mpx;
	blck[2].y = mpy - 1;

	blck[3].x = mpx - 1;
	blck[3].y = mpy;

	return blck;
}

point * rotation_T(int RNUM, point * blck) { //Rnum과 메인 포인트를 기준으로 좌표를 찍은 후 좌표 세트 주소 리턴
	
	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;

	if (RNUM) //Rnum이 0일 때는 처음 시작 case로 가야함.
	{
		Rnum %= 4;
	}

	switch (Rnum)
	{
	case 0: //초기 모양 ㅗ

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx;
		blck[3].y = mpy - 1;
 		return blck;
	case 1: //초기 모양 ㅏ

		blck[1].x = mpx;
		blck[1].y = mpy + 1;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx;
		blck[3].y = mpy - 1;
		return blck;

	case 2: //초기 모양 ㅜ

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;
		return blck;

	case 3: //초기 모양 ㅓ

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx;
		blck[2].y = mpy + 1;

		blck[3].x = mpx;
		blck[3].y = mpy - 1;
		return blck;

	default:
		break;
	}
}

point * rotation_L(int RNUM, point * blck) { //Rnum과 메인 포인트를 기준으로 좌표를 찍은 후 좌표 세트 주소 리턴


	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;


	if (RNUM) //Rnum이 0일 때는 처음 시작 case로 가야함.
	{
		Rnum %= 4;
	}

	switch (Rnum)
	{
	case 0: //초기 모양 ㅗ

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy - 1;

		blck[3].x = mpx + 1;
		blck[3].y = mpy;
		return blck;

	case 1: //초기 모양 L

		blck[1].x = mpx;
		blck[1].y = mpy -1;

		blck[2].x = mpx+1;
		blck[2].y = mpy +1;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;
		return blck;

	case 2: //ㅜ

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;
		
		blck[3].x = mpx - 1;
		blck[3].y = mpy+1;

		return blck;

	case 3: //7

		blck[1].x = mpx - 1;
		blck[1].y = mpy - 1;

		blck[2].x = mpx;
		blck[2].y = mpy - 1;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;
		return blck;

	default:
		break;
	}
}



point* (*newblock(int* Rnum))(int, point*) { // Rnum을 초기화 시키고 블록을 정하여 함수를 리턴하는 함수 + NEXT 연결
				 
	srand((unsigned)time(NULL));
	int type = rand() % 5;
	 

	//첫 블록 회전 번호 리셋
	*Rnum = 0;

	// 블록번호에 맞는 함수 연결 
	switch (type)
	{
	case 0:
		return rotation_T;
	case 1:
		return rotation_O;
	case 2:
		return rotation_L;
	case 3:
		return rotation_I;
	case 4:
		return rotation_Z;
		
	default:
		break;
	}
}


void NextBlock(int** screen, point* (*rotation_)(int, point*)) {

	point Nblck[4];

	//중심좌표 설정 //블록 마다 다르게 해야 할 것 같다
	Nblck[0].x = NX0; //일단 기준선 보다 더 왼쪽으로 치우치게 설정
	Nblck[0].y = NY0 + 3;

	//모양잡기
	rotation_(0, Nblck);

	if (Nblck[1].x != NX0 + 2) //첫 점의 가장 왼쪽 좌표가 NY0+2이 아니면 //더 왼쪽에 있다면
	{
		while ((Nblck[1].x != NX0 + 2)) { //가장 왼쪽 좌표가 NY0+2이 될 때까지
			for (int i = 0; i < 4; i++)
				Nblck[i].x++; // 모든 좌표를 오른쪽으로
		}
	}

	//박스비우기
	for (int x = NX0 + 2; x < NX0 + 6; x++) //NX0 + 2에서 시작하여 + 가로 최대 4 = NX0+6
		for (int y = NY0 + 2; y < NY0 + 5; y++) //  //NY0 + 2 에서 시작하여 + 세로 3칸 = NX0+5
			screen[y][x] = blankB;

	//블록 입력
	for (int i = 0; i < 4; i++) //top,bottom of next
		screen[Nblck[i].y][Nblck[i].x] = movinB;


}