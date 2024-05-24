#ifndef ARCANOID_SHAPERECTANGLE_H
#define ARCANOID_SHAPERECTANGLE_H
const int winWidth = 800, winHeight = 600;

#include "Shape.h"

class Rectangle : public Shape {
public:
    sf::RectangleShape shape;

    float x() override { return shape.getPosition().x; }

    float y() override { return shape.getPosition().y; }

    float left() override { return x() - shape.getSize().x / 2.f; }

    float right() override { return x() + shape.getSize().x / 2.f; }

    float top() override { return y() - shape.getSize().y / 2.f; }

    float bottom() override { return y() + shape.getSize().y / 2.f; }


};

#endif //ARCANOID_SHAPERECTANGLE_H
