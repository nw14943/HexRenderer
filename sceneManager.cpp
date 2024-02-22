#include "sceneManager.h"
#include "constants.h"
#include "graphics.h"

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
    renderForeground = false;
  }
  if (renderBackground) {
    ogstream::clearBackground();
    renderBackground = false;
  }
  if (renderCanvas) {
    ogstream::clearCanvas();
    renderCanvas = false;
  }
  ogstream::changeTarget(1);
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
  default: {
    break;
  }
  }
}
