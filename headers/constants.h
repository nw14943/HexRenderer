#pragma once
// #include "raylib.h"
enum Direction { Up, Down, Left, Right };
const double UPDATES_PER_SECOND = 60;
const char GAMENAME[] = "Hexagon Renderer";
// const int SCREENWIDTH = 1920;
// const int SCREENHEIGHT = 1080;
const int SCREENWIDTH = 1000;
const int SCREENHEIGHT = 1000;
const double RADIUS = 50.0;
const int offsetLeft = 50;
const int offsetRight = 50;
const int offsetTop = 50;
const int offsetBottom = 50;
const int CANVASWIDTH = SCREENWIDTH - offsetLeft - offsetRight;
const int CANVASHEIGHT = SCREENHEIGHT - offsetTop - offsetBottom;
const int CANVASX = (int)(CANVASWIDTH / (RADIUS * 1.732));
const int CANVASY = (int)(CANVASHEIGHT / (RADIUS * 1.5));
