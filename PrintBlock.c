#include <stdlib.h>
#include <time.h>
#include "PrintBlock.h"
#include "Setting.h"

point * rotation_Z(int RNUM, point * blck) { //Rnum�� ���� ����Ʈ�� �������� ��ǥ�� ���� �� ��ǥ ��Ʈ �ּ� ����

	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;

	if (RNUM) //Rnum�� 0�� ���� ó�� ���� case�� ������.
	{
		Rnum %= 2;
	}

	switch (Rnum)
	{
	case 0: //Z

		blck[1].x = mpx-1;  //���� ���ʿ� �ִ� ��
		blck[1].y = mpy;

		blck[2].x = mpx +1;  // ���� �����ʿ��ִ� ��
		blck[2].y = mpy + 1;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;

		return blck;
	case 1: //����

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

point * rotation_I(int RNUM, point * blck) { //Rnum�� ���� ����Ʈ�� �������� ��ǥ�� ���� �� ��ǥ ��Ʈ �ּ� ����


	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;

	if (RNUM) //Rnum�� 0�� ���� ó�� ���� case�� ������.
	{
		Rnum %= 2;
	}

	switch (Rnum)
	{
	case 0: //��

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

point * rotation_O(int Rnum, point * blck) { //Rnum�� ���� ����Ʈ�� �������� ��ǥ�� ���� �� ��ǥ ��Ʈ �ּ� ����

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

point * rotation_T(int RNUM, point * blck) { //Rnum�� ���� ����Ʈ�� �������� ��ǥ�� ���� �� ��ǥ ��Ʈ �ּ� ����
	
	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;

	if (RNUM) //Rnum�� 0�� ���� ó�� ���� case�� ������.
	{
		Rnum %= 4;
	}

	switch (Rnum)
	{
	case 0: //�ʱ� ��� ��

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx;
		blck[3].y = mpy - 1;
 		return blck;
	case 1: //�ʱ� ��� ��

		blck[1].x = mpx;
		blck[1].y = mpy + 1;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx;
		blck[3].y = mpy - 1;
		return blck;

	case 2: //�ʱ� ��� ��

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;
		return blck;

	case 3: //�ʱ� ��� ��

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

point * rotation_L(int RNUM, point * blck) { //Rnum�� ���� ����Ʈ�� �������� ��ǥ�� ���� �� ��ǥ ��Ʈ �ּ� ����


	int Rnum = RNUM;

	int mpx = blck[0].x;
	int mpy = blck[0].y;


	if (RNUM) //Rnum�� 0�� ���� ó�� ���� case�� ������.
	{
		Rnum %= 4;
	}

	switch (Rnum)
	{
	case 0: //�ʱ� ��� ��

		blck[1].x = mpx - 1;
		blck[1].y = mpy;

		blck[2].x = mpx + 1;
		blck[2].y = mpy - 1;

		blck[3].x = mpx + 1;
		blck[3].y = mpy;
		return blck;

	case 1: //�ʱ� ��� L

		blck[1].x = mpx;
		blck[1].y = mpy -1;

		blck[2].x = mpx+1;
		blck[2].y = mpy +1;

		blck[3].x = mpx;
		blck[3].y = mpy + 1;
		return blck;

	case 2: //��

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



point* (*newblock(int* Rnum))(int, point*) { // Rnum�� �ʱ�ȭ ��Ű�� ����� ���Ͽ� �Լ��� �����ϴ� �Լ� + NEXT ����
				 
	srand((unsigned)time(NULL));
	int type = rand() % 5;
	 

	//ù ��� ȸ�� ��ȣ ����
	*Rnum = 0;

	// ��Ϲ�ȣ�� �´� �Լ� ���� 
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

	//�߽���ǥ ���� //��� ���� �ٸ��� �ؾ� �� �� ����
	Nblck[0].x = NX0; //�ϴ� ���ؼ� ���� �� �������� ġ��ġ�� ����
	Nblck[0].y = NY0 + 3;

	//������
	rotation_(0, Nblck);

	if (Nblck[1].x != NX0 + 2) //ù ���� ���� ���� ��ǥ�� NY0+2�� �ƴϸ� //�� ���ʿ� �ִٸ�
	{
		while ((Nblck[1].x != NX0 + 2)) { //���� ���� ��ǥ�� NY0+2�� �� ������
			for (int i = 0; i < 4; i++)
				Nblck[i].x++; // ��� ��ǥ�� ����������
		}
	}

	//�ڽ�����
	for (int x = NX0 + 2; x < NX0 + 6; x++) //NX0 + 2���� �����Ͽ� + ���� �ִ� 4 = NX0+6
		for (int y = NY0 + 2; y < NY0 + 5; y++) //  //NY0 + 2 ���� �����Ͽ� + ���� 3ĭ = NX0+5
			screen[y][x] = blankB;

	//��� �Է�
	for (int i = 0; i < 4; i++) //top,bottom of next
		screen[Nblck[i].y][Nblck[i].x] = movinB;


}