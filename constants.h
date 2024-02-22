#pragma once
// #include "raylib.h"
enum Direction { Up, Down, Left, Right };
const double UPDATES_PER_SECOND = 60;
const char GAMENAME[] = "Hexagon Renderer";
const int CANVASWIDTH = 2400;
const int CANVASHEIGHT = 1600;
const int SCREENWIDTH = 480;
const int SCREENHEIGHT = 320;
const double RADIUS = 50.0;
const int CANVASX = (int)(CANVASWIDTH / (RADIUS * 1.732)) + 2;
const int CANVASY = (int)(CANVASHEIGHT / (RADIUS * 1.5)) + 2;
