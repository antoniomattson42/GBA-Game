#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#include "gba.h"
#include "images/duck.h"
#include "scene.h"
#include "actions.h"

/* TODO: */
// Include any header files for title screen or exit
// screen images generated by nin10kit. Example for the provided garbage
// image:
// #include "images/garbage.h"

/* TODO: */
// Add any additional states you need for your app. You are not requried to use
// these specific provided states.
enum gba_state {
  START,
  PLAY,
  WIN,
  LOSE,
};


int main(void) {
  /* TODO: */
  // Manipulate REG_DISPCNT here to set Mode 3. //
  REG_DISPCNT = MODE3 | BG2_ENABLE;
  // Save current and previous state of button input.
  u32 previousButtons = BUTTONS;
  u32 currentButtons = BUTTONS;

  // Load initial application state
  enum gba_state state = START;


  while (1) {
    currentButtons = BUTTONS; // Load the current state of the buttons
    int status;
    waitForVBlank();
    if (status == 1) {
          state = WIN;
        }
        if (status == 2) {
          state = LOSE;
        }

    switch (state) {
      case START:
      if (KEY_DOWN(BUTTON_A, currentButtons) == 0) 
      {
        makeSceneStart();
      } else {
        status = makeSceneGame();
        state = PLAY;
      }
        break;
      case PLAY:

        break;
      case WIN:
        makeSceneWin();
        
        break;
      case LOSE:
        makeSceneLoss();

        // state = ?
        break;
    }

    previousButtons = currentButtons; // Store the current state of the buttons
  }

  UNUSED(previousButtons); // You can remove this once previousButtons is used

  return 0;
}