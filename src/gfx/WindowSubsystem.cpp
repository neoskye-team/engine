#include <GLFW/glfw3.h>

#include "gfx/WindowSubsystem.hpp"
#include "util/types.hpp"

void errorCallback(int error, const char* description) {
    std::cout << "GLFW Error " << error << ": " << description << std::endl;
}

int WindowSubsystem::initWindow() {
    if (glfwInit() == GLFW_FALSE) { 
        std::cout << "Failed to initialize glfw3!" << std::endl;
        return -1;
    }

    glfwSetErrorCallback(errorCallback);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->win = glfwCreateWindow(1280, 720, "Neoskye Game", nullptr, nullptr);
    if (this->win == nullptr) {
        glfwTerminate();
        std::cout << "Failed to initialize a GLFW window!" << std::endl;
    }
    
    glfwMakeContextCurrent(this->win);

    return 0;
}

bool WindowSubsystem::shouldClose() {
    return glfwWindowShouldClose(this->win);
}
