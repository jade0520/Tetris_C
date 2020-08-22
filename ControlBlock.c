#include <stdio.h>
#include "Setting.h"
#include "PrintBlock.h"
#include "Tell.h"
#include "ControlBlock.h"


void dropBlock(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum)
{
	int howdeepY = 0;
	int howY = MY; // movin ��ϰ� ���� ����� �Ÿ� �� ���� ª�� �Ÿ�

				   //���� �� ���� //
	for (int i = 0; i < 4; i++)
		screen[blck[i].y][blck[i].x] = blankB;

	//�� ��ǥ ���� //
	// ����� �̷�� y��ǥ�� ���� �����Ͽ� savedB�� edgeB�� ���� �� ������ ���� ���� ���� ������� �� ���� ŭ ������
	for (int i = 0; i < 4; i++)
	{
		while (1)//ù�� ° saved�� edge�� ���� �� ����
		{
			if (screen[blck[i].y + howdeepY + 1][blck[i].x] == savedB || screen[blck[i].y + howdeepY + 1][blck[i].x] == edgeB) //���� �ش� ���� �� �� �Ʒ��� ���� ���̳� �����ڸ����
				break;
			howdeepY++;
		}
		if (howY > howdeepY) //���� ���� ���� �� ������
			howY = howdeepY; // ���� ������ �ٲ۴�.

		howdeepY = 0; //����
	}


	for (int i = 0; i < 4; i++) //��� ����� �� ���� ª�� �Ÿ���ŭ ������.
	{
		for (int k = 0; k < howY; k++)
			blck[i].y++;
	}


	//���ο� �� ��ǥ �Է�///
	blck = rotation_(Rnum, blck); //���� ����Ʈ �������� �� ��ġ ��Ƽ� ��ǥ ����
	for (int i = 0; i < 4; i++)
		screen[blck[i].y][blck[i].x] = movinB; //�� ��� �Է�
	printscreen(screen); //���
}

//������ ������ 2����
int downBlock(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) { //���� ������ ���� �� ��ġ ���� �ٴڿ� ������  0 ����ϰ� �ؾ���
																						 // blck �� ���� �� ��ġ�� ���� ����Ʈ ������ 

	if (tellBlockStop(screen, blck, rotation_, Rnum) == 1)  //����� ���� ��Ҵ��� Ȯ�� ������� 1 õ�忡�� ������� 2 ����
		return 0;
	else if (tellBlockStop(screen, blck, rotation_, Rnum) == 2)
		return 2;

	else {
		for (int i = 0; i < 4; i++)//���� �� �����
			screen[blck[i].y][blck[i].x] = blankB;

		blck[0].y++; //��ĭ ������
		blck = rotation_(Rnum, blck); //���� ����Ʈ �������� �� ��ġ ��Ƽ� ��ǥ ����
		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //�� ��� �Է�

		printscreen(screen); //�갡 �ְ� ���� Ű �Է� �� ��ȭ�ϴ� ���� �ӵ��� �޶�����!!1!!!!!!!

		return 1;
	}
}

void moveright(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) {//for tellKey 
	point testblock[4];
	// ������ �˻��̹Ƿ� X+1�˻�
	
	for (int i = 0; i < 4; i++)
	{
		testblock[i].x = blck[i].x + 1;
		testblock[i].y = blck[i].y;
	}
 
	if (!tellBlockEdge(screen, testblock))// �̵��� ������ ������ ������
	{
		for (int i = 0; i < 4; i++)//���� �� �����
			screen[blck[i].y][blck[i].x] = blankB;

		blck[0].x++; //��ĭ ����������
	 
		blck = rotation_(Rnum, blck); //���� ����Ʈ �������� �� ��ġ ��Ƽ� ��ǥ ����

		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //��ǥ �Է�
	}
	 

};

void moveleft(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) {//for tellKey
	point testblock[4];
	// ������ �˻��̹Ƿ� X-1�˻�
	for (int i = 0; i < 4; i++)
	{
		testblock[i].x = blck[i].x - 1;
		testblock[i].y = blck[i].y;
	}

	if (!tellBlockEdge(screen, testblock))// �̵��� ������ ������ ������
	{
		for (int i = 0; i < 4; i++)//���� �� �����
			screen[blck[i].y][blck[i].x] = blankB;

		blck[0].x--; //��ĭ ��������
		blck = rotation_(Rnum, blck); //���� ����Ʈ �������� �� ��ġ ��Ƽ� ��ǥ ����
		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //��ǥ �Է�
	}

}
