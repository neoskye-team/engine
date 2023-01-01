#pragma once

#include <GLFW/glfw3.h>

#include "gfx/Sprite.hpp"
#include "gfx/WindowSubsystem.hpp"
#include "gfx/SpriteBatch.hpp"
#include "util/types.hpp"


struct GraphicsSubsystem {
    GLFWwindow* win;
    
    u32 shaderProgram;

    u8 init(WindowSubsystem* window);

    void prepareFrame();
    void finishFrame(SpriteBatch* sb);
    
    Sprite loadSprite(const char* name);

    SpriteBatch spriteBatch();
};
