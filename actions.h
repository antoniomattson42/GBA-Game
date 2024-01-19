#ifndef ACTIONS_H
#define ACTIONS_H

#include "gba.h"


struct breads {
    int row;
	int col;
};

struct chefs {
    int row;
    int col;
    int rd;
    int cd;
};

struct duck {
    int row;
    int col;
};



void createChef(int row, int col);

struct breads createBreads(void);

void makeDuck(int row, int column);

struct breads makeBread(int row, int column);

void makeChef(int row, int column);

struct duck createDuck(void);


#endif