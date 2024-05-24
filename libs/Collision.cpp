#include "Collision.h"

void testCollision(Paddle &mPaddle, Ball &mBall) {
    if (!isIntersecting(mPaddle, mBall)) return;
    if (!mBall.isSticky) {
        mBall.velocity.y = -ballVelocity;
    } else {
        mBall.stickyPaddle = &mPaddle;
    }
}

void testCollision(Brick &mBrick, Ball &mBall) {
    if (!isIntersecting(mBrick, mBall)) return;
    if (!mBrick.indestructible) {
        mBrick.hp -= 1;
        if (mBrick.hp <= 0) {
            mBrick.destroyed = true;
        }
    }

    if (mBrick.speedUp) {
        mBall.velocity.x *= 1.5f;
        mBall.velocity.y *= 1.5f;
    }
    float overLapLeft = mBall.right() - mBrick.left();
    float overLapRight = mBrick.right() - mBall.left();
    float overLapTop = mBall.bottom() - mBrick.top();
    float overLapBottom = mBrick.bottom() - mBall.top();

    bool ballFromLeft(std::abs(overLapLeft) < std::abs(overLapRight));
    bool ballFromTop(std::abs(overLapTop) < std::abs(overLapBottom));

    float minOverLapX = ballFromLeft ? overLapLeft : overLapRight;
    float minOverLapY = ballFromTop ? overLapTop : overLapBottom;

    if (std::abs(minOverLapX) < std::abs(minOverLapY)) mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    else mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

void testCollision(SingleUseBottom &singleUseBottom, Ball &ball) {
    if (!isIntersecting(singleUseBottom, ball)) return;

    ball.velocity.y = -ballVelocity;
    singleUseBottom.active = false;
}
