#pragma once

#include "raylib.h"

class ogstream {
private:
// The canvas is used for objects that move &/or collide (uses hexagons)
  static RenderTexture2D canvas; // target other
// The background is used for static background textures (and paralax?)
  static RenderTexture2D background; // target 1
// Foreground is used primarily for particles/effects
  static RenderTexture2D foreground; // target 2
  static int currentTarget;
  static int canvasWidth;
  static int canvasHeight;
  static void startTarget();
  static int windowBox;

public:
  ogstream(int width, int height);
  ~ogstream();
  static void clearCanvas(); //uses hexagons
  static void clearBackground();
  static void clearForeground();
  static bool shouldClose();
  static int getFPS();
  static float getFrameTime();
  static Vector2 getMousePosition();
  static void draw();
  static void drawText(const char *text, Vector2 position, double size,
                       Color color);
  static void drawText(const char *text, int x, int y, double size,
                       Color color);
  static void drawCircle(double x, double y, double radius, Color color);
  static void drawHexagon(double x, double y, double radius, Color color);
  static void drawRectangle(double x, double y, double height, double width,
                            Color color);
  static void changeTarget(int target);
  static int getWidth();
  static int getHeight();
  static void drawFPS();
};
