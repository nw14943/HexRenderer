#pragma once

#include <raylib.h>

class canvas {
public:
  void draw(float x, float y, float scale);
private:
  RenderTexture2D canvas;
};
