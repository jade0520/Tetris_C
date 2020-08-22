#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Setting.h"


int** setscreen(void) {
	int **screen;
	//TEST
	int y = MY0 + 5;

	// screen �迭 ����
	screen = (int**)malloc(sizeof(int**)*screenlength);

	for (int y = 0; y < screenlength; y++)
	{
		screen[y] = (int*)malloc(sizeof(int*)*screenwidth);
		for (int x = 0; x < screenwidth; x++)
		{
			screen[y][x] = blankB;
		}
	}

	//main �׸���
	for (int x = MX0; x < MX; x++) //top,bottom of main
	{
		screen[MY0][x] = edgeB;
		screen[MY - 1][x] = edgeB;
	}
	for (int y = MY0; y < MY - 1; y++) // inside of main	
	{
		screen[y][MX0] = edgeB;
		screen[y][MX - 1] = edgeB;
	}

	//next �׸���

	screen[NY0][NX0] = edgeB;
	screen[NY0][NX0+1] = 'N';
	screen[NY0][NX0+2] = 'E';
	screen[NY0][NX0+3] = 'X';
	screen[NY0][NX0+4] = 'T';

	 

	//score �׸���
	screen[SY0][SX0] = edgeB;
	screen[SY0][SX0 + 1] = 'S';
	screen[SY0][SX0 + 2] = 'C';
	screen[SY0][SX0 + 3] = 'O';
	screen[SY0][SX0 + 4] = 'R';
	screen[SY0][SX0 + 5] = 'E';
	screen[SY0][SX0 + 6] = blankB;
	screen[SY0][SX0 + 7] = 0;

	 




	return screen;
}
void printscreen(int **screen) {
	
    monvincursor();

	// main ȭ�� Ƣ����� �� ������ 
	 
	for (int x = MX0; x < MX; x++) //top,bottom of main
	{
		screen[MY0][x] = edgeB;
		screen[MY0 - 1][x] = blankB;
	}


	//���
	for (int y = 0; y < screenlength; y++)
	{
			for (int x = 0; x < screenwidth; x++)
			{
				if (y == SY0 && x == SX0 + 7) //������ ==����
					printf("%d", screen[y][x]);
				else {//������
					switch (screen[y][x])
					{
					case blankB: printf("  ");
						break;
					case movinB: printf("��");
						break;
					case savedB: printf("��");
						break;
					case edgeB: printf("��");
						break;
					default: printf("%c", screen[y][x]);
						break;
					}
				}
				}
		printf("\n");
	}


}

void monvincursor(void) {
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void startscreen(int startcoin) {

	while (startcoin != 1) {
		printf("��Ʈ������ �����Ϸ��� 1�� ���缼�� >>");
		scanf("%d", &startcoin);
		monvincursor();
	}
	printf("                                          ");
	monvincursor();

	printf("\n\n\n\n\n\n\n\n ");
	printf("                 ");
	printf("Get\n");
	Sleep(1000);

	printf("                 ");
	printf("Ready\n");
	Sleep(1000);

	printf("                 ");
	printf("Start!! \n");
	Sleep(1000);
}
