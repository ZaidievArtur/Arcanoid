
#ifndef ARCANOID_SHAPECIRCLE_H
#define ARCANOID_SHAPECIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    sf::CircleShape shape;

    float x() override { return shape.getPosition().x; }

    float y() override { return shape.getPosition().y; }

    float left() override { return x() - shape.getRadius(); }

    float right() override { return x() + shape.getRadius(); }

    float top() override { return y() - shape.getRadius(); }

    float bottom() override { return y() + shape.getRadius(); }

};

#endif //ARCANOID_SHAPECIRCLE_H
