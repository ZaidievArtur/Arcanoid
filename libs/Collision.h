
#ifndef ARCANOID_COLLISION_H
#define ARCANOID_COLLISION_H

#include "PaddleUsage.h"
#include "BallUsage.h"
#include "BrickUsage.h"
#include "BottomUsage.h"
#include "Bonuses.h"

template<class T1, class T2>
bool isIntersecting(T1 &mA, T2 &mB) {
    return mA.right() >= mB.left() && mA.left() <= mB.right() &&
           mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void testCollision(Paddle &mPaddle, Ball &mBall);

void testCollision(Brick &mBrick, Ball &mBall);

void testCollision(SingleUseBottom &singleUseBottom, Ball &ball);

#endif //ARCANOID_COLLISION_H
