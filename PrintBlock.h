#ifndef __PRINT_BLOCK_H__
#define __PRINT_BLOCK_H__
#include "Setting.h"


//이동함수
void NextBlock(int** screen, point* (*rotation_)(int, point*));
point* (*newblock(int* Rnum))(int**, int, point*); /// Rnum을 초기화 시키고 블록을 정하여 함수를 리턴하는 함수 + NEXT 연결

//rotation_
point * rotation_O(int RNUM, point * blck);

point * rotation_T(int RNUM, point * blck);

point * rotation_Z(int RNUM, point * blck);

point * rotation_I(int RNUM, point * blck);

point * rotation_L(int RNUM, point * blck);

#endif // !__PRINT_BLOCK_H__



