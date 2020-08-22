#include "Setting.h"
#include "PrintBlock.h"
#include "ControlBlock.h" //for tellkey ���� ������ ������
#include <stdio.h>
//�Ϸ�



int tellBlockStop(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum) { //��� ������ �˻�, ��� ȸ���ϰ� �˻�,��� ������ �� �˻� ���� ���߸� 1����

	int x, y;

	for (int i = 0; i < 4; i++)
	{
		x = blck[i].x;
		y = blck[i].y; //�� �� �ϳ� ��ǥ�� �ް� 
		if (y > MY0) {
			if (screen[y + 1][x] == savedB || screen[y + 1][x] == edgeB) //���� �ش� ���� �� �� �Ʒ��� ���� ���̳� �����ڸ����
			{
				for (int i = 0; i < 4; i++)
					screen[blck[i].y][blck[i].x] = savedB; // �� �����ü�� ���´�.
				
				//���� ��� ���
				printscreen(screen);
				
				//����� õ��� ������ 2����
				if (blck[0].y == MY0 || blck[1].y == MY0 || blck[2].y == MY0 || blck[3].y == MY0 ) //����� 0��° ��ġ�� ���� ���� �ִ� ��ǥ 
				return 2;
					


				return 1;
			}
		}

	}

	

	return 0;
}

int downraw(int ** pscreen, int Y, int X) { //������ Y���� ����
	if (Y - 1 == MY0)
	{
		pscreen[Y][X] = blankB; //���� ���� �ִ� ���� 0�� �޴´�
		return 1; //�˻��ϴ� ���� ����⿡ ������ ��
	}
	else
	{
		pscreen[Y][X] = pscreen[Y - 1][X]; //���� ���� �Ʒ��� ������.
		downraw(pscreen, Y - 1, X); //���� �� �˻�
		return 1;
	}


}

int tellLinkedLine(int **pscreen, int Y, int X) { //ȣ���� ���� �˻��� Y��, X�� ���� ���� MX0
	if (pscreen[Y][X + 1] == savedB) 
	{
		tellLinkedLine(pscreen, Y, X + 1);//��ĭ�� ��ĭ�� �˻�
		 //��ĭ���� ��ü ���� 1�̶�� ��ȣ�� ���� return 1
	}
	else if (X + 1 == MX -1) //��ĭ�� 1�� �ƴѵ�, MX��
		return 1; // ���� ��� �̾��� �ִ�.
	else
		return 0;
}

int tellClear(int ** pscreen) //��ü �˻�
{
	int score = 0; 
	for (int y = MY0+1; y < MY; y++)
	{
		if (tellLinkedLine(pscreen, y, MX0)) { //k��° ���� �ϼ��Ǿ��ٸ� 
			for (int x = MX0 + 1; x < MX - 1; x++)
			{
				downraw(pscreen, y, x); //k��° ���� i���� ���� �׵��� �ϳ��� ������.
			}
			score += 100; //�ϼ� �� �� �� 100���� �߰�
		}
	}
	return score;
}

int tellBlockEdge(int ** screen, point* blck) {// ���� ������ saved�� ������ return 1
	int x, y;

	for (int i = 0; i < 4; i++)
	{
		x = blck[i].x;
		y = blck[i].y; //�� �� �ϳ� ��ǥ�� �ް� 

		if (screen[y][x] == savedB || screen[y][x] == edgeB) //���� �ش� ��ǥ�� ���� ������ ���� ���̶�� return 1
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
		case 75: moveleft(screen, blck, rotation_, *Rnum);//�� �����̵� �Լ��� ����
			break;
		case 77: moveright(screen, blck, rotation_, *Rnum);//�� �����̵� �Լ��� ����
			break;
		case 80:dropBlock(screen, blck, rotation_, *Rnum); //���̿� ���� ������ �����ϴ� �ɷ� �ٲٱ�
		default:
			break;
		}
	}
	else if (key == 32)
	{
		for (int i = 0; i < 4; i++)//���� �� �����
			screen[blck[i].y][blck[i].x] = blankB;

		(*Rnum)++;

		blck = rotation_(*Rnum, blck); //��� �ٲٴ� �Լ��� ���� blck ����

		if (blck[1].x == MX0) //���� ����� �˻� 
		{
			for (int i = 0; i < 4; i++)
				blck[i].x++; //������ ����������
		}
		else if (blck[1].x == MX0 - 1)//���θ����˻��
		{
			for (int i = 0; i < 4; i++)
				blck[i].x += 2; //������ ����������
		}
		if (blck[2].x == MX - 2) //������ ����� �˻�
		{
			for (int i = 0; i < 4; i++)
				blck[i].x--; //������ ��������
		}

		for (int i = 0; i < 4; i++)
			screen[blck[i].y][blck[i].x] = movinB; //�� ��� �Է�

												   //printscreen(screen); //���

	}
}



#pragma once
