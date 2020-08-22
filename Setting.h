#ifndef __SETTING_H__
#define __SETTING_H__

//Mainbox 좌표
#define MX0 1
#define MY0 1
#define Ml 30
#define Mw 18
#define MX (Mw+MX0)
#define MY (Ml+MY0)

//Nextbox 좌표
#define NX0 (MX+2) //main과 next의 간격만 입력
#define NY0 3 

//Scorebox 좌표
#define SX0 NX0
#define SY0 (NY0 + 4 + 2) // NY0 + 4 + (여백) 

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

typedef point * block; //좌표세트를 가리키는 포인터 



int** setscreen(void);
void printscreen(int **screenptr);
void  monvincursor(void);
void startscreen(int startcoin);
#endif 
