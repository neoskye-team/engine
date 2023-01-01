#pragma once

#include "util/types.hpp"

struct Sprite {
    const u8* spriteData;
    u32 VBO, VAO, EBO;

    void load();
    void draw();
};
