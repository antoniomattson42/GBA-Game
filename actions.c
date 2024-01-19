#include "actions.h"
#include "gba.h"
#include "images/chef.h"
#include "images/bread.h"
#include "images/duck.h"



void createChef(int row, int col) {
    drawImageDMA(row, col, CHEF_WIDTH, CHEF_HEIGHT, chef);
}


struct breads createBreads(void) {
    int row = randint(0, HEIGHT -BREAD_HEIGHT);
    int col = randint(0, WIDTH - BREAD_WIDTH);
    drawImageDMA(row, col, BREAD_WIDTH, BREAD_HEIGHT, bread);
    struct breads loaf;
    loaf.row = row;
    loaf.col = col;
    return loaf;
}

void makeDuck(int row, int column) {
    drawImageDMA(row, column, DUCK_WIDTH, DUCK_HEIGHT, duck);
}

void makeChef(int row, int column) {
    drawImageDMA(row, column, CHEF_WIDTH, CHEF_HEIGHT, chef);
}

struct duck createDuck(void) {
    drawImageDMA(HEIGHT/2, WIDTH/2, DUCK_WIDTH, DUCK_HEIGHT, duck);
    struct duck temp;
    temp.col = WIDTH/2;
    temp.row = HEIGHT/2;
    return temp;
}

struct breads makeBread(int row, int column) {
    drawImageDMA(row, column, BREAD_WIDTH, BREAD_HEIGHT, bread);
    struct breads loaf;
    loaf.row = row;
    loaf.col = column;
    return loaf;
}