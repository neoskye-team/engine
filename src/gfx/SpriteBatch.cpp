#include "gfx/SpriteBatch.hpp"

void SpriteBatch::submit(Sprite* sprite, i32 x, i32 y) {
    this->drawData.push_back(sprite);
}

std::vector<Sprite*> SpriteBatch::getDrawData() {
    return this->drawData;
}
