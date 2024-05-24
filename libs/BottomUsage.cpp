#include "BottomUsage.h"

SingleUseBottom::SingleUseBottom() {
    shape.setSize(sf::Vector2f{winWidth, 10.f});
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(winWidth / 2.f, winHeight - 5.f);
    shape.setOrigin(winWidth / 2.f, 5.f);
}
