#ifndef ARCANOID_PADDLEUSAGE_H
#define ARCANOID_PADDLEUSAGE_H


#include "ShapeRectangle.h"

const float paddleWidth = 120.f, paddleHeight = 20.f, paddleVelocity = 0.6f;

class Paddle : public Rectangle {
public:

    sf::Vector2f velocity;

    Paddle(float mX, float mY);

    void update(float mFt);
};


#endif //ARCANOID_PADDLEUSAGE_H
