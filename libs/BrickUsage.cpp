#include "BrickUsage.h"

Brick::Brick(float mX, float mY) {
    shape.setPosition(mX, mY);
    shape.setSize(sf::Vector2f{blockWidth, blockHeight});
    shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
}
