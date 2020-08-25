#ifndef __GANESHA_H
#define __GANESHA_H

#include <ncurses.h>
#include <curses.h>
#include <stdio.h>

#define WINCOUNT 7			//Total windows count

void initCurses(WINDOW **wins, int i);							//program initializing function

void stairs(WINDOW **wins, int i);

void makhar(WINDOW **wins, int i);

void ganesha();

void swastikLeftRight(WINDOW **wins,int i);

void name1(WINDOW **wins, int i);

void name2(WINDOW **wins, int i);

void name3(WINDOW **wins, int i);

void swastik(int j, int k);

void lightLeft();

void lLeftRight(int i, int j, int l2, int l3, int l4);

void lightRight();

#endif