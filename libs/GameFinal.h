
#ifndef ARCANOID_GAMEFINAL_H
#define ARCANOID_GAMEFINAL_H

#include "Collision.h"
#include <vector>
#include <ctime>
#include <chrono>


const int countBlocksX = 11, countBlocksY = 4;
const float frameStep = 1.f, frameSlice = 1.f;


class Game {
public:

    float lastFrameTime = 0.f, currentSlice = 0.f;
    bool running = false;
    int lives = 3;

    sf::RenderWindow window{{winWidth, winHeight}, "Arkanoid - 14"};

    Ball ball{winWidth / 2.f, winHeight / 2.f};
    Paddle paddle{winWidth / 2.f, winHeight - 50.f};
    std::vector<Brick> bricks;
    std::vector<Bonus> bonuses;
    SingleUseBottom singleUseBottom;
    bool singleUseBottomActive = false;

    Game();

    void run();

    void inputPhase();

    void updatePhase();

    void drawPhase();
};

#endif //ARCANOID_GAMEFINAL_H
