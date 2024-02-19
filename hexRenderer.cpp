#include "constants.h"
#include "graphics.h"
#include "raylib.h"
#include "sceneManager.h"
#include <cmath>
#include <cstddef>

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------

  bool pause = false;
  bool debug = false;
  double time_last_update = 0.0;
  ogstream gout(CANVASWIDTH, CANVASHEIGHT);
  SceneManager scene;

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

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

    // Draw
    //----------------------------------------------------------------------------------

    SceneManager::drawScene();

    gout.changeTarget(0);

    double radius = 50.0;
    int canvasX = ceil(CANVASWIDTH/radius);
    int canvasY = ceil(CANVASHEIGHT/radius);
    Color colors[canvasX][canvasY];
    for (int x = 0; (double)x * (1.5 * radius) < CANVASWIDTH + radius; x++) {
      for (int y = 0; (double)y * (0.866 * radius * 2.0) < CANVASHEIGHT + radius; y++) {
          Color color = colors[x][y];
          // if(color != ){
          // }
        if ((int)((double)x * (1.5 * radius)) % 10) {
          gout.drawHexagon((double)x * (1.5 * radius), (double)y * (0.866 * radius * 2.0),
                           radius, color);
        } else {
          gout.drawHexagon((double)x * (1.5 * radius),
                           (double)y * (0.866 * radius * 2.0) + (0.866 * radius),
                           radius, color);
        }
      }
    }

    if (debug) {
      gout.changeTarget(2);
      gout.drawFPS();
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
