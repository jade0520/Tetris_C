#ifndef __PRINT_BLOCK_H__
#define __PRINT_BLOCK_H__
#include "Setting.h"


//�̵��Լ�
void NextBlock(int** screen, point* (*rotation_)(int, point*));
point* (*newblock(int* Rnum))(int**, int, point*); /// Rnum�� �ʱ�ȭ ��Ű�� ����� ���Ͽ� �Լ��� �����ϴ� �Լ� + NEXT ����

//rotation_
point * rotation_O(int RNUM, point * blck);

point * rotation_T(int RNUM, point * blck);

point * rotation_Z(int RNUM, point * blck);

point * rotation_I(int RNUM, point * blck);

point * rotation_L(int RNUM, point * blck);

#endif // !__PRINT_BLOCK_H__



