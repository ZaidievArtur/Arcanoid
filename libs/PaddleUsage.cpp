#include "PaddleUsage.h"

Paddle::Paddle(float mX, float mY) {
    shape.setPosition(mX, mY);
    shape.setSize(sf::Vector2f{paddleWidth, paddleHeight});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
}

void Paddle::update(float mFt) {
    shape.move(velocity * mFt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && left() > 0) velocity.x = -paddleVelocity;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && right() < winWidth) velocity.x = paddleVelocity;
    else velocity.x = 0;
}