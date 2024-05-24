#include "GameFinal.h"

Game::Game() {
    srand(time(0));
    window.setFramerateLimit(60);
    for (int i = 0; i < countBlocksX; i++) {
        for (int j = 0; j < countBlocksY; j++) {
            bricks.emplace_back((i + 1) * (blockWidth + 3) + 22, (j + 2) * (blockHeight + 3));
        }
    }
    for (auto &brick: bricks) {
        if (rand() % 100 < 5) {
            brick.indestructible = true;
            brick.shape.setFillColor(sf::Color(128, 0, 0));
        } else if (rand() % 100 > 95) {
            brick.speedUp = true;
            brick.shape.setFillColor(sf::Color(255, 192, 203));
        }
    }
}

void Game::run() {
    running = true;
    while (running) {
        auto timePoint1(std::chrono::high_resolution_clock::now());
        window.clear(sf::Color::Black);

        inputPhase();
        updatePhase();
        drawPhase();

        auto timePoint2(std::chrono::high_resolution_clock::now());
        auto elapsedTime = timePoint2 - timePoint1;
        float frameTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(elapsedTime).count();

        lastFrameTime = frameTime;

        window.setTitle("\t     aYour lives : " + std::to_string(lives));
    }
}

void Game::inputPhase() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            ball.release();
        }
    }
}

void Game::updatePhase() {
    currentSlice += lastFrameTime;
    for (; currentSlice >= frameSlice; currentSlice -= frameSlice) {
        ball.update(frameStep);
        paddle.update(frameStep);

        testCollision(paddle, ball);
        if (singleUseBottomActive) {
            testCollision(singleUseBottom, ball);
            if (!singleUseBottom.active) {
                singleUseBottomActive = false;
            }
        }

        for (auto &brick: bricks) {
            testCollision(brick, ball);
            if (brick.destroyed) {

                if (rand() % 100 < 20) {
                    auto type = static_cast<Bonus::Type>(rand() % 5);
                    bonuses.emplace_back(brick.x(), brick.y(), type);
                }
            }
        }

        for (auto &brick: bricks) {
            if (!brick.speedUp && !brick.indestructible) {
                if (brick.hp == 4) brick.shape.setFillColor(sf::Color(255, 255, 255));
                if (brick.hp == 3) brick.shape.setFillColor(sf::Color(211, 211, 211));
                if (brick.hp == 2) brick.shape.setFillColor(sf::Color(169, 169, 169));
                if (brick.hp == 1) brick.shape.setFillColor(sf::Color(105, 105, 105));
            }
        }

        for (auto &bonus: bonuses) {
            bonus.update(frameStep);
            if (isIntersecting(paddle, bonus)) {
                bonus.apply(paddle, ball, singleUseBottomActive);
            }
        }


        bricks.erase(remove_if(begin(bricks), end(bricks), [](const Brick &mBrick) { return mBrick.destroyed; }),
                     end(bricks));
        bonuses.erase(remove_if(begin(bonuses), end(bonuses), [](const Bonus &mBonus) { return !mBonus.active; }),
                      end(bonuses));

        if (ball.bottom() > winHeight) {
            lives--;
            if (lives > 0) {
                ball.isSticky = true;
                ball.stickyPaddle = &paddle;
            } else {
                running = false;
            }
        }

    }
}

void Game::drawPhase() {
    window.draw(ball.shape);
    window.draw(paddle.shape);

    for (auto &brick: bricks) window.draw(brick.shape);
    for (auto &bonus: bonuses) window.draw(bonus.shape);
    if (singleUseBottomActive) window.draw(singleUseBottom.shape);

    window.display();
}