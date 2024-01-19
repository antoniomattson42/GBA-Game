#include "scene.h"
#include "gba.h"
#include "actions.h"
#include "images/park.h"
#include "images/duck.h"
#include "images/chef.h"
#include "images/bread.h"
#include "images/win.h"
#include <stdio.h>
#include <stdlib.h>
int breadCount = 0;
int breadTotal = 5;
int breadCurrent = 0;
int start = 0;
int leave = 0;
struct breads loaf;
struct chefs list;
struct duck quack;

void makeSceneStart(void) {
    drawFullScreenImageDMA(park);
    char title[] = "PRESS A TO START";
    drawCenteredString((HEIGHT / 4) * 3, (WIDTH /2) -20 , 20, 20, title, BLACK);
    makeChef(HEIGHT - 25, 0);
    makeBread(HEIGHT - 25, (WIDTH - 25)/2 );
    makeDuck(HEIGHT - 25, WIDTH - 25);
}

int makeSceneGame(void) {
    while(leave == 0) {
        waitForVBlank();
        fillScreenDMA(GREEN);
        char counter[24];
        int needed = breadTotal - breadCount;
        int temp = snprintf(counter, 22, "Total Bread Needed: %d", needed);
        UNUSED(temp);
        if (breadCurrent == 0) {
            loaf = createBreads();
            breadCurrent = 1;
        } else {
                loaf = makeBread(loaf.row, loaf.col);
            }
        if (start == 0) {
            createChefs();
            quack = createDuck();
            start = 1;
        } else {
            moveChefs();
            moveDuck();
            drawString(HEIGHT - 10, 0, counter, BLACK);
            checkBread();
            leave = checkChefCollsion();
            if (breadCount == breadTotal) {
                leave = 1;
            }
        }
    }
    return leave;
}

void makeSceneLoss(void) {
    fillScreenDMA(WHITE);
    char title[] = "You suck!!";
    drawCenteredString((HEIGHT / 2), (WIDTH /2) -20 , 20, 20, title, BLACK);
}

void makeSceneWin(void) {
    drawFullScreenImageDMA(win);
    char title[] = "GOOD JOB";
    drawCenteredString((HEIGHT / 2), (WIDTH /2) -20 , 20, 20, title, BLACK);
}

void createChefs(void) {
    createChef(HEIGHT - CHEF_HEIGHT, WIDTH - CHEF_WIDTH);
    struct chefs ch2;
    ch2.cd = -1;
    ch2.col = WIDTH - CHEF_WIDTH;
    ch2.rd = 1;
    ch2.row = HEIGHT - CHEF_HEIGHT;
    list = ch2;
}

void moveChefs(void) {
        if (list.cd == 1) {
            if (list.col + 1 >= WIDTH - CHEF_WIDTH) {
                list.cd = -1;
                list.col = list.col - 1;
            } else {
                list.col = list.col + 1;
            }
        } else {
            if (list.col - 1 <= 0) {
                list.cd = 1;
                list.col = list.col + 1;
            } else {
                list.col = list.col - 1;
            }
        }
        makeChef(list.row, list.col);
    }

void moveDuck(void) {
    u32 currentButtons = BUTTONS; 
    if (KEY_DOWN(BUTTON_UP, currentButtons) == 0 ){
        quack.row = quack.row + 1;
    }
    if (KEY_DOWN(BUTTON_DOWN, currentButtons) == 0) {
        quack.row = quack.row - 1;
    }
    if (KEY_DOWN(BUTTON_LEFT, currentButtons) == 0) {
        quack.col = quack.col + 1;
    }
    if (KEY_DOWN(BUTTON_RIGHT, currentButtons) == 0) {
        quack.col = quack.col - 1;
    }
    makeDuck(quack.row, quack.col);
}

void checkBread(void) {
    if ((abs(loaf.row - quack.row) <= DUCK_HEIGHT)&&(abs(loaf.col - quack.col <= 25))) {
        breadCount++;
        breadCurrent = 0;
    }
}

int checkChefCollsion(void) {
        if ((abs(list.row - quack.row) <= DUCK_HEIGHT)&&(abs(list.col - quack.col <= 25))) {
            return 2;
    }
    return 0;

}

