#ifndef __TELL_H__
#define __TELL_H__
#include "Setting.h"


int tellLinkedLine(int **pscreen, int Y, int X); //for tellClear
int downraw(int ** pscreen, int Y, int X); //for tellClear
int tellClear(int ** pscreen); //한줄 검사기
int tellKey(int ** screen, point * blck, point* (*rotation_)(int, point*), int * Rnum) ; //키 입력 검사기
int tellBlockStop(int ** screen, point * blck, point* (*rotation_)(int, point*), int Rnum); //for down block
int tellBlockEdge(int ** screen, point* blck); //for moveleft,right

#endif
