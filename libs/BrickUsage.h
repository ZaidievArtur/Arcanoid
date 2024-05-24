#ifndef ARCANOID_BRICKUSAGE_H
#define ARCANOID_BRICKUSAGE_H

const float blockWidth = 60.f, blockHeight = 20.f;

#include "ShapeRectangle.h"

class Brick : public Rectangle {
public:
    bool destroyed = false;
    bool indestructible = false;
    bool speedUp = false;
    int hp = rand() % 4 + 1;

    Brick(float mX, float mY);
};

#endif //ARCANOID_BRICKUSAGE_H
