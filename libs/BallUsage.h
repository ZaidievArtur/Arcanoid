#ifndef ARCANOID_BALLUSAGE_H
#define ARCANOID_BALLUSAGE_H

#include "ShapeCircle.h"
#include "PaddleUsage.h"
#include <cmath>


const float ballRadius = 10.f, ballVelocity = 0.6f;

class Ball : public Circle {
public:
    sf::Vector2f velocity = {-ballVelocity, -ballVelocity};
    bool isSticky = false;
    Paddle *stickyPaddle = nullptr;

    Ball(float mX, float mY);

    void update(float mFt);

    void release();

    void randomizeDirection();
};

#endif //ARCANOID_BALLUSAGE_H
