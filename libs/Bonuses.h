
#ifndef ARCANOID_BONUSES_H
#define ARCANOID_BONUSES_H

#include "ShapeCircle.h"
#include "PaddleUsage.h"
#include "BallUsage.h"

class Bonus : public Circle {
public:
    enum class Type {
        ResizePaddle,
        SpeedUpBall,
        StickyBall,
        SingleUseBottom,
        RandomizeBallDirection,
    };

    sf::Vector2f velocity{0.f, 0.3f};
    Type type;
    bool active = true;

    Bonus(float mX, float mY, Type mType);

    void update(float mFt);

    void apply(Paddle &paddle, Ball &ball, bool &singleUseBottomActive);
};

#endif //ARCANOID_BONUSES_H
