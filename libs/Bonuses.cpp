#include "Bonuses.h"

Bonus::Bonus(float mX, float mY, Type mType) : type(mType) {
    shape.setPosition(mX, mY);
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(10.f, 10.f);
}

void Bonus::update(float mFt) {
    shape.move(velocity * mFt);
    if (shape.getPosition().y > winHeight) active = false;
}

void Bonus::apply(Paddle &paddle, Ball &ball, bool &singleUseBottomActive) {
    float newPaddleWidth = paddleWidth;
    switch (type) {
        case Type::ResizePaddle:
            newPaddleWidth *= 1.25f;
            paddle.shape.setSize(sf::Vector2f{newPaddleWidth, paddleHeight});
            paddle.shape.setOrigin(newPaddleWidth / 2.f, paddleHeight / 2.f);
            break;
        case Type::SpeedUpBall:
            ball.velocity *= 1.25f;
            break;
        case Type::StickyBall:
            ball.isSticky = true;
            break;
        case Type::SingleUseBottom:
            singleUseBottomActive = true;
            break;
        case Type::RandomizeBallDirection:
            ball.randomizeDirection();
            break;
    }
    active = false;
}