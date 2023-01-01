#pragma once

#include "GLFW/glfw3.h"


struct WindowSubsystem {
    GLFWwindow* win;

    int initWindow();
    bool shouldClose();
};
