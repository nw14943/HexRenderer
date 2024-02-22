#include "constants.h"
#include "graphics.h"
#include "raylib.h"
#include "sceneManager.h"
#include <cmath>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------

  bool pause = false;
  bool debug = false;
  bool select = false;
  int selectX = 0;
  int selectY = 0;
  double time_last_update = 0.0;
  ogstream gout(CANVASWIDTH, CANVASHEIGHT);
  SceneManager scene;

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  Color color{0, 0, 255, 255};
  for (int x = 0; x < CANVASX; x++) {
    for (int y = 0; y < CANVASY; y++) {
      color.r = x * (int)(255 / CANVASX);
      color.g = y * (int)(255 / CANVASY);
      color.b = 0;
      scene.background[x][y] = color;
    }
  }
  std::cout << "Init done" << std::endl;
  // SceneManager::drawScene();

  // Main game loop
  while (!gout.shouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------
    if (IsKeyDown(KEY_LEFT_SHIFT))
      debug = true;
    else
      debug = false;
    if (IsKeyPressed(KEY_SPACE))
      // pause = !pause;
      debug = !debug;
    if (IsKeyPressed(KEY_ZERO))
      scene.changeScene(0);
    if (IsKeyPressed(KEY_ONE))
      scene.changeScene(1);
    if (IsKeyPressed(KEY_TWO))
      scene.changeScene(2);
    if (IsKeyPressed(KEY_THREE))
      scene.changeScene(3);

    if (IsKeyPressed(KEY_S))
      select = !select;
    if (IsKeyPressed(KEY_DOWN))
      selectY += 1;
    if (IsKeyPressed(KEY_UP))
      selectY -= 1;
    if (IsKeyPressed(KEY_RIGHT))
      selectX += 1;
    if (IsKeyPressed(KEY_LEFT))
      selectX -= 1;

    if (IsKeyPressed(KEY_W)) {
      selectY -= 1;
      selectX -= selectY % 2;
    }
    if (IsKeyPressed(KEY_E)) {
      selectX += selectY % 2;
      selectY -= 1;
    }
    if (IsKeyPressed(KEY_D)) {
      selectX += 1;
    }
    if (IsKeyPressed(KEY_X)) {
      selectY += 1;
      selectX -= selectY % 2;
    }
    if (IsKeyPressed(KEY_C)) {
      selectX += selectY % 2;
      selectY += 1;
    }
    if (IsKeyPressed(KEY_A)) {
      selectX -= 1;
    }
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 pos = gout.getMousePosition();
        selectY = (pos.y+(RADIUS/2.0))/(RADIUS * 1.5);
        selectX = (pos.x+((selectY%2)?0.0:(RADIUS/0.866)))/(RADIUS * 1.732);
    }

    // Draw
    //----------------------------------------------------------------------------------

    SceneManager::drawScene();

    gout.changeTarget(0);

    if (debug) {
      gout.changeTarget(2);
      gout.drawFPS();
      SceneManager::renderForeground = true;
    }
    if (select) {
      gout.changeTarget(0);
      gout.drawHexagonAdj(selectX, selectY, Color{255, 255, 255, 200});
      SceneManager::renderCanvas = true;
    }

    //----------------------------------------------------------------------------------
    // Draw the Screen
    //----------------------------------------------------------------------------------
    gout.draw();
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  // Should work out when gout falls out of scope
  //--------------------------------------------------------------------------------------

  return 0;
}
