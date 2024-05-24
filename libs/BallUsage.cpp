#include "BallUsage.h"

Ball::Ball(float mX, float mY) {
    shape.setPosition(mX, mY);
    shape.setRadius(ballRadius);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(ballRadius, ballRadius);
}

void Ball::update(float mFt) {
    if (isSticky && stickyPaddle) {
        shape.setPosition(stickyPaddle->x(), stickyPaddle->top() - ballRadius);
    } else {
        shape.move(velocity * mFt);

        if (left() < 0 or right() > winWidth) velocity.x *= -1;
        if (top() < 0) velocity.y *= -1;
    }
}

void Ball::release() {
    if (isSticky) {
        isSticky = false;
        stickyPaddle = nullptr;
        velocity = {ballVelocity, -ballVelocity};
    }
}

void Ball::randomizeDirection() {
    float angle = (rand() % 360) * 3.14159f / 180.f;
    velocity = {(ballVelocity * std::cos(angle)), (ballVelocity * std::sin(angle))};
}