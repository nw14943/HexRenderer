#pragma once

#include "raylib.h"
#include <vector>
#include <functional>

class ogstream {
private:
  // The canvas is used for objects that move &/or collide (uses hexagons)
  static RenderTexture2D canvas; // target other
  // The background is used for static background textures (and paralax?)
  static RenderTexture2D background; // target 1
  // Foreground is used primarily for particles/effects
  static RenderTexture2D foreground; // target 2
  static Shader shader;
  static int currentTarget;
  static int currentShader;
  static int canvasWidth;
  static int canvasHeight;
  static int displayWidth;
  static int displayHeight;
  static float scale;
  // static void startTarget();
  static int windowBox;

public:
  ogstream(int width, int height);
  ~ogstream();
  static void clearCanvas();
  static void clearBackground();
  static void clearForeground();
  static bool shouldClose();
  static int getFPS();
  static float getFrameTime();
  static Vector2 getMousePosition();
  static Vector2 getMouseCanvasPosition();
  static void draw();
  static void drawText(const char *text, Vector2 position, double size,
                       Color color);
  static void drawText(const char *text, int x, int y, double size,
                       Color color);
  static void drawCircle(double x, double y, double radius, Color color);
  static void drawHexagon(double x, double y, double radius, Color color);
  static void drawHexagonAdj(int x, int y, Color color);
  static void drawSquareAdj(int x, int y, Color color);
  static void drawRectangle(double x, double y, double height, double width,
                            Color color);
  static void draw2DArrayHex2(std::vector<std::vector<Color>> pic,
                              int offsetX = 0, int offsetY = 0);
  static void draw2DArrayHex3(std::vector<std::vector<Color>> pic);
  static void fillHex3(int x, int y);
  static void draw3Radial(int x, int y, Color color = Color{255, 0, 0, 255});
  static void draw2DArraySqr(std::vector<std::vector<Color>> pic,
                             int offsetX = 0, int offsetY = 0);
  static void changeTarget(int target);
  static void changeShader(int target);
  static int getWidth();
  static int getHeight();
  static float getZoom();
  static float getScale();
  static void changeScale(bool positive);
  static void drawFPS();
  static void useShader(std::function<void()> func);
  static void useShader(int target, std::function<void()> func);
  static void useTexture(std::function<void()> func);
  static void useTexture(int target, std::function<void()> func);
};
