#pragma once
// #include <iostream>
#include "constants.h"
#include "graphics.h"
#include "raylib.h"

class Sprite {
public:
  Sprite() {}
  virtual void draw(ogstream &gout, Vector3 position) = 0;
};

class SpriteSquare : public Sprite {
private:
  double height;
  double width;
  Color color;

public:
  SpriteSquare() : height(1.0), width(1.0), color(LIGHTGRAY) {}
  SpriteSquare(double height, double width, Color color)
      : height(height), width(width), color(color) {}
  void draw(ogstream &gout, Vector3 position) {
    gout.drawRectangle(position.x, position.y, height, width, color);
  }
};

class SpriteCircle : public Sprite {
private:
  double radius;
  Color color;

public:
  SpriteCircle() : radius(1.0), color(LIGHTGRAY) {}
  SpriteCircle(double radius, Color color) : radius(radius), color(color) {}
  void draw(ogstream &gout, Vector3 position) {
    gout.drawCircle(position.x, position.y, radius, color);
  }
};

class SpriteHex : public Sprite {
private:
  double radius;
  Color color;

public:
  SpriteHex() : radius(1.0), color(LIGHTGRAY) {}
  SpriteHex(double radius, Color color) : radius(radius), color(color) {}
  void draw(ogstream &gout, Vector3 position) {
    gout.drawHexagon(position.x, position.y, radius, color);
  }
};
