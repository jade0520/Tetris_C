#ifndef __CONTROL_BLOCK__
#define __CONTROL_BLOCK__

#include "Setting.h"

void dropBlock(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum);
int downBlock(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum);
void moveright(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum);
void moveleft(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum);



#endif __CONTROL_BLOCK__