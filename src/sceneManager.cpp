#include "../headers/sceneManager.h"
#include "../headers/constants.h"
#include "../headers/graphics.h"

int SceneManager::scene = 0;
bool SceneManager::renderBackground = true;
bool SceneManager::renderForeground = true;
bool SceneManager::renderCanvas = true;

std::vector<std::vector<Color>>
    SceneManager::background(CANVASX, std::vector<Color>(CANVASY, GRAY));

void SceneManager::changeScene(int scene) {
  SceneManager::scene = scene;
  renderBackground = true;
}

// Preps the background and foreground
void SceneManager::drawScene() {
  if (renderForeground) {
    ogstream::clearForeground();
    // renderForeground = false;
    renderForeground = true;
  }
  if (renderBackground) {
    ogstream::clearBackground();
    // renderBackground = false;
    renderBackground = true;
  }
  if (renderCanvas) {
    ogstream::clearCanvas();
    // renderCanvas = false;
    renderCanvas = true;
  }
  ogstream::changeTarget(0);
  switch (scene) {
  case 0: {
    ogstream::draw2DArrayHex2(SceneManager::background);
    break;
  }
  case 1: {
    ogstream::draw2DArraySqr(SceneManager::background);
    break;
  }
  case 2: {
    ogstream::draw2DArrayHex3(SceneManager::background);
    break;
  }
  case 3: {
    // ogstream::fillHex3(0,0);
    ogstream::draw3Radial(10, 10);
    break;
  }
  case 4: {
    ogstream::fillHex3(0,0);
    // ogstream::draw3Radial(10, 10);
    break;
  }
  default: {
    break;
  }
  }
}
