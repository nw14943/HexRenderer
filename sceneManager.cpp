#include "sceneManager.h"
#include "graphics.h"

int SceneManager::scene = 0;

void SceneManager::changeScene(int scene) { SceneManager::scene = scene; }

// Preps the background and foreground
void SceneManager::drawScene() {
  ogstream::clearForeground();
  ogstream::clearCanvas();
  ogstream::changeTarget(2);
  switch (scene) {
  case 0: {
    // const char *text = "Press Enter to start";
    // double size = 20.0;
    // Vector2 text_size = MeasureTextEx(GetFontDefault(), text, size, 1.0);
    // Vector2 position = {(float)((ogstream::getWidth() - text_size.x) / 2.0),
    //                     (float)((ogstream::getHeight() - text_size.y) / 2.0)};
    // ogstream::drawText(text, position, size, LIGHTGRAY);
    break;
  }
  default: {
    break;
  }
  }
}
