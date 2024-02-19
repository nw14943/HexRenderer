#pragma once

#include "graphics.h"

class SceneManager {
    private:
        static int scene;
    public:
        SceneManager() {}
        static void changeScene(int scene);
        static void drawScene();
};
