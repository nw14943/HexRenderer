#include "graphics.h"
#include "constants.h"
#include "raylib.h"
#include <cstdlib>
#include <vector>

RenderTexture2D ogstream::canvas = RenderTexture2D();
RenderTexture2D ogstream::background = RenderTexture2D();
RenderTexture2D ogstream::foreground = RenderTexture2D();
int ogstream::currentTarget = 0;
int ogstream::canvasWidth = 0;
int ogstream::canvasHeight = 0;

void ogstream::startTarget() {
  switch (currentTarget) {
  case 1:
    BeginTextureMode(background);
    break;
  case 2:
    BeginTextureMode(foreground);
    break;
  default:
    BeginTextureMode(canvas);
  }
}

ogstream::ogstream(int width, int height) {
  canvasWidth = width;
  canvasHeight = height;
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREENWIDTH, SCREENHEIGHT, GAMENAME);
  this->canvas = LoadRenderTexture(canvasWidth, canvasHeight);
  this->background = LoadRenderTexture(canvasWidth, canvasHeight);
  this->foreground = LoadRenderTexture(canvasWidth, canvasHeight);
  clearCanvas();
  clearForeground();
  clearBackground();
}
ogstream::~ogstream() {
  UnloadRenderTexture(canvas);
  UnloadRenderTexture(background);
  UnloadRenderTexture(foreground);
  CloseWindow();
}
void ogstream::clearCanvas() {
  BeginTextureMode(canvas);
  ClearBackground(BLANK);
  EndTextureMode();
}
void ogstream::clearBackground() {
  BeginTextureMode(background);
  ClearBackground(BLACK);
  EndTextureMode();
}
void ogstream::clearForeground() {
  BeginTextureMode(foreground);
  ClearBackground(BLANK);
  EndTextureMode();
}
bool ogstream::shouldClose() { return WindowShouldClose(); }
int ogstream::getFPS() { return GetFPS(); }
float ogstream::getFrameTime() { return GetFrameTime(); }
Vector2 ogstream::getMousePosition() {
  Vector2 rawMousePos = GetMousePosition();
  float x = (rawMousePos.x / (double)GetScreenWidth()) * canvasWidth;
  float y = (rawMousePos.y / (double)GetScreenHeight()) * canvasHeight;
  Vector2 adjMousePos = Vector2{x, y};
  return adjMousePos;
}
void ogstream::draw() {
  BeginDrawing();
  // Draw Textures Here
  double screenwidth = GetScreenWidth();
  double screenheight = GetScreenHeight();
  DrawTexturePro(background.texture,
                 (Rectangle){0, 0, (float)canvasWidth, (float)-canvasHeight},
                 (Rectangle){0, 0, (float)screenwidth, (float)screenheight},
                 (Vector2){0, 0}, 0.0, WHITE);
  DrawTexturePro(canvas.texture,
                 (Rectangle){0, 0, (float)canvasWidth, (float)-canvasHeight},
                 (Rectangle){0, 0, (float)screenwidth, (float)screenheight},
                 (Vector2){0, 0}, 0.0, WHITE);
  DrawTexturePro(foreground.texture,
                 (Rectangle){0, 0, (float)canvasWidth, (float)-canvasHeight},
                 (Rectangle){0, 0, (float)screenwidth, (float)screenheight},
                 (Vector2){0, 0}, 0.0, WHITE);
  EndDrawing();
}
void ogstream::drawText(const char *text, int x, int y, double size,
                        Color color) {
  drawText(text, (Vector2){(float)x, (float)y}, size, color);
}
void ogstream::drawText(const char *text, Vector2 position, double size,
                        Color color) {
  ogstream::startTarget();
  DrawTextEx(GetFontDefault(), text, position, size, 1.0, color);
  EndTextureMode();
}
void ogstream::drawCircle(double x, double y, double radius, Color color) {
  ogstream::startTarget();
  DrawCircle(x, y, radius, color);
  EndTextureMode();
}
void ogstream::drawRectangle(double x, double y, double height, double width,
                             Color color) {
  ogstream::startTarget();
  DrawRectangle(x, y, height, width, color);
  EndTextureMode();
}
void ogstream::drawSquareAdj(int x, int y, Color color) {
  ogstream::startTarget();
  DrawRectangle(x * RADIUS * 1.5, y * RADIUS * 1.5, RADIUS * 1.5, RADIUS * 1.5,
                color);
  EndTextureMode();
}
void ogstream::drawHexagon(double x, double y, double radius, Color color) {
  ogstream::startTarget();
  // DrawCircle(x, y, radius, GRAY);
  // DrawCircleLines((int)x, (int)y, radius, RED);
  DrawPoly(Vector2{(float)x, (float)y}, 6, radius, 90.0, color);
  DrawPolyLines(Vector2{(float)x, (float)y}, 6, radius, 90.0, GREEN);
  EndTextureMode();
}
void ogstream::drawHexagonAdj(int x, int y, Color color) {
  ogstream::startTarget();
  double xScale = RADIUS * 1.732 * x + ((y % 2) ? RADIUS * 0.866 : 0.0);
  double yScale = RADIUS * 1.5 * y;
  DrawPoly(Vector2{(float)xScale, (float)yScale}, 6, RADIUS, 00.0, color);
  // DrawPolyLines(Vector2{(float)xScale, (float)yScale}, 6, RADIUS, 90.0,
  // GREEN);
  EndTextureMode();
}
void ogstream::draw2DArrayHex2(std::vector<std::vector<Color>> pic, int offsetX,
                               int offsetY) {
  Color color{0, 0, 255, 255};
  for (int x = offsetX; x < pic.size(); x++) {
    for (int y = offsetY; y < pic[x].size(); y++) {
      drawHexagonAdj(x, y, pic[x][y]);
    }
  }
}
void ogstream::draw2DArrayHex3(std::vector<std::vector<Color>> pic) {
  Color color{0, 0, 0, 255};
  int xOffset = 2;
  int yOffset = 3;
  // for (int x = xOffset; x < pic.size()/2; x++) {
  for (int x = 0; x < pic.size() / 2; x++) {
    for (int y = 0; y < pic[x].size() / 2; y++) {
      drawHexagonAdj((x + (y / 2)) % (pic.size() / 2) + xOffset, y + yOffset,
                     pic[x][y]);
    }
  }
}
void ogstream::fillHex3(int offsetX, int offsetY) {
  Color color{0, 0, 0, 255};
  int xOffset = 2;
  int yOffset = 3;
  for (int x = 0; x < CANVASX / 2; x++) {
    for (int y = 0; y < CANVASY / 2; y++) {
      color.r += 3;
      color.g += 4;
      color.b += 5;
      // drawHexagonAdj((x+(y/2))%(CANVASY/2)+xOffset, y+yOffset, GRAY);
      drawHexagonAdj((x + (y / 2)) % (CANVASY / 2) + xOffset, y + yOffset,
                     color);
    }
  }
}
void ogstream::draw2DArraySqr(std::vector<std::vector<Color>> pic, int offsetX,
                              int offsetY) {
  Color color{0, 0, 255, 255};
  for (int x = offsetX; x < pic.size(); x++) {
    for (int y = offsetY; y < pic[x].size(); y++) {
      drawSquareAdj(x, y, pic[x][y]);
    }
  }
}
void ogstream::draw3Radial(int x, int y, Color color) {
  // if (x <= 0 || y <= 0 || x >= CANVASX || y >= CANVASY)
  //   return;
  //
  // drawHexagonAdj(x, y, color);
  //
  // bool addX = abs(x + 1) > x;
  // bool subX = abs(x - 1) < x;
  // // bool addY = abs(y + 1) > y;
  // // bool subY = abs(y - 1) < y;
  // // bool addX = false;
  // // bool subX = false;
  // bool addY = false;
  // bool subY = false;
  //
  // if (y % 2 == 0) {
  //   if (addX) {
  //     draw3Radial(x + 1, y, color);
  //     if (addY)
  //       draw3Radial(x + 1, y + 1, color);
  //     if (subY)
  //       draw3Radial(x + 1, y - 1, color);
  //     return;
  //   }
  //   if (subX)
  //     draw3Radial(x - 1, y, color);
  //   if (subY)
  //     draw3Radial(y - 1, y, color);
  //   if (addY)
  //     draw3Radial(y + 1, y, color);
  // } else {
  //   if (subX) {
  //     draw3Radial(x - 1, y, color);
  //     if (addY)
  //       draw3Radial(x - 1, y + 1, color);
  //     if (subY)
  //       draw3Radial(x - 1, y - 1, color);
  //     return;
  //   }
  //   if (addX)
  //     draw3Radial(x + 1, y, color);
  //   if (subY)
  //     draw3Radial(y - 1, y, color);
  //   if (addY)
  //     draw3Radial(y + 1, y, color);
  // }
}
int ogstream::getWidth() { return canvasWidth; }
int ogstream::getHeight() { return canvasHeight; }
void ogstream::drawFPS() {
  BeginTextureMode(foreground);
  ogstream::startTarget();
  DrawFPS(10, 10);
  EndTextureMode();
}
void ogstream::changeTarget(int target) { currentTarget = target; }
