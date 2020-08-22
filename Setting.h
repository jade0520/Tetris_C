#ifndef __SETTING_H__
#define __SETTING_H__

//Mainbox ��ǥ
#define MX0 1
#define MY0 1
#define Ml 30
#define Mw 18
#define MX (Mw+MX0)
#define MY (Ml+MY0)

//Nextbox ��ǥ
#define NX0 (MX+2) //main�� next�� ���ݸ� �Է�
#define NY0 3 

//Scorebox ��ǥ
#define SX0 NX0
#define SY0 (NY0 + 4 + 2) // NY0 + 4 + (����) 

#define screenwidth 35
#define screenlength 35

#define blankB 3
#define movinB 2
#define savedB 1 
#define edgeB  0

#define sleept 500


typedef struct POINT {
	int x;
	int y;
}point;

typedef point * block; //��ǥ��Ʈ�� ����Ű�� ������ 



int** setscreen(void);
void printscreen(int **screenptr);
void  monvincursor(void);
void startscreen(int startcoin);
#endif 
