#include "../headers/constants.h"
#include "../headers/graphics.h"
#include "../headers/sceneManager.h"
#include "raylib.h"
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------

  bool pause = false;
  bool debug = false;
  bool select = true;
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
      if (x == 0 || y == 0)
        scene.background[x][y] = Color{0, 0, 0, 0};
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
    if (IsKeyPressed(KEY_LEFT_SHIFT))
      debug = !debug;
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
    if (IsKeyPressed(KEY_FOUR))
      scene.changeScene(4);
    if (IsKeyPressed(KEY_FIVE))
      scene.changeScene(5);

    if (IsKeyPressed(KEY_S))
      select = !select;
    if (IsKeyPressed(KEY_DOWN)) {
      // selectY += 1;
    }
    if (IsKeyPressed(KEY_UP)) {
      // selectY -= 1;
    }
    if (IsKeyPressed(KEY_RIGHT)) {
      // selectX += 1;
    }
    if (IsKeyPressed(KEY_LEFT)) {
      // selectX -= 1;
    }

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

    Vector2 pos = gout.getMouseCanvasPosition();
    selectY = gout.getZoom() * (pos.y + (RADIUS / 2.0)) / (RADIUS * 1.5);
    selectX = gout.getZoom() *
              (pos.x + ((selectY % 2) ? 0.0 : (RADIUS / 0.866))) /
              (RADIUS * 1.732);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      // Vector2 pos = gout.getMousePosition();
      Vector2 pos = gout.getMouseCanvasPosition();
      // Gout::GetCanvasMousePosition()
      int selectedY = (pos.y + (RADIUS / 2.0)) / (RADIUS * 1.5);
      int selectedX = (pos.x + ((selectedY % 2) ? 0.0 : (RADIUS / 0.866))) /
                      (RADIUS * 1.732);
      // Possible out of bounds error FIXME:
      SceneManager::background[selectedX][selectedY] = WHITE;
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
        // TODO: Panning changes canvas offset
        Vector2 delta = GetMouseDelta();
        gout.moveCanvas(delta.x, delta.y);
    }

    float mouseWheelMove = -GetMouseWheelMove();
    if (mouseWheelMove != 0.0f) {
      gout.changeScale(mouseWheelMove > 0);
    }

    // Draw
    //----------------------------------------------------------------------------------

    SceneManager::drawScene();

    gout.changeTarget(0);

    if (debug) {
      gout.changeTarget(2);
      gout.drawFPS();
      Vector2 pos = gout.getMouseCanvasPosition();
      gout.drawText(
          (std::to_string(pos.x) + " " + std::to_string(pos.y)).c_str(),
          Vector2{50.0, 100.0}, 50, WHITE);
      // char * xCoord;
      // char * yCoord;
      // xCoord = std::to_string(selectX);
      gout.drawText(
          (std::to_string(selectX) + ", " + std::to_string(selectY)).c_str(),
          Vector2{50.0, 50.0}, 50, WHITE);
      gout.drawText((std::to_string(mouseWheelMove)).c_str(),
                    Vector2{50.0, 150.0}, 50, WHITE);
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
