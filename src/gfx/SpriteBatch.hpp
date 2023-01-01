#pragma once

#include "util/types.hpp"
#include "gfx/Sprite.hpp"

struct SpriteBatch {
    std::vector<Sprite*> drawData;
    i32 winx, winy;

    void submit(Sprite* sprite, i32 x, i32 y);

    std::vector<Sprite*> getDrawData();
};
