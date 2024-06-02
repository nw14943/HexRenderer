#pragma once

#include "graphics.h"

class SceneManager {
    private:
        static int scene;
    public:
        static bool renderBackground;
        static bool renderForeground;
        static bool renderCanvas;
        static std::vector<std::vector<Color>> background;
        SceneManager() {}
        static void changeScene(int scene);
        static void drawScene();
};
