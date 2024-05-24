#ifndef ARCANOID_SHAPE_H
#define ARCANOID_SHAPE_H

#include <SFML/Graphics.hpp>


class Shape {
public:
    virtual float x() = 0;

    virtual float y() = 0;

    virtual float left() = 0;

    virtual float right() = 0;

    virtual float top() = 0;

    virtual float bottom() = 0;

};

#endif //ARCANOID_SHAPE_H
