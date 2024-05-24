#ifndef ARCANOID_BOTTOMUSAGE_H
#define ARCANOID_BOTTOMUSAGE_H

#include "ShapeRectangle.h"

class SingleUseBottom : public Rectangle {
public:
    bool active = true;

    SingleUseBottom();
};


#endif //ARCANOID_BOTTOMUSAGE_H
