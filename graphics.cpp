#include "graphics.h"
#include "constants.h"
#include "raylib.h"

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
    float x = (rawMousePos.x/GetScreenWidth())*canvasWidth;
    float y = (rawMousePos.y/GetScreenHeight())*canvasHeight;
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
void ogstream::drawHexagon(double x, double y, double radius, Color color) {
  ogstream::startTarget();
  // DrawCircle(x, y, radius, GRAY);
  DrawPoly(Vector2{(float)x, (float)y}, 6, radius, 90.0, color);
  DrawPolyLines(Vector2{(float)x, (float)y}, 6, radius, 90.0, GREEN);
  // DrawCircleLines((int)x, (int)y, radius, RED);
  EndTextureMode();
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
