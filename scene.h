#ifndef SCENE_H
#define SCENE_H

#include "gba.h"


void makeSceneStart(void);

int makeSceneGame(void);

void makeSceneLoss(void);

void makeSceneWin(void);

void createChefs(void);
 
void moveDuck(void);

void moveChefs(void);

void checkBread(void);

int checkChefCollsion(void);


#endif