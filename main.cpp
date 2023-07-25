#include "GameDriver.h"

using namespace sf;

//mingw32-make

const float TIME_PER_LOGIC_ADVANCE = 1.0f / LOGIC_RATE;
const float TIME_PER_FRAME_ADVANCE = 1.0f / FRAME_RATE;

Clock clock;
float deltaTime;
float elapsedTimeLogic(0);
float elapsedTimeGraphics(0);

void gameLoop(RenderWindow& window, std::unique_ptr<Game>& game, bool& running) {
    deltaTime = clock.restart().asSeconds();
    elapsedTimeLogic += deltaTime;
    elapsedTimeGraphics += deltaTime;
    
    if (elapsedTimeLogic >= TIME_PER_LOGIC_ADVANCE) {
        game->updatePhysics(elapsedTimeLogic);
        elapsedTimeLogic = 0;
    }
    if (elapsedTimeGraphics >= TIME_PER_FRAME_ADVANCE) {
        window.clear();
        game->updateGraphics();
        window.display();
        elapsedTimeGraphics = 0;
    }

    // Event handling
    Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                running = false;
        }
    }
}

void endGame() {
    window.close()
}

int main() {
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mario");
    std::unique_ptr<Game> game = std::make_unique<Game>(window);
    bool running(true);
    std::thread inputThread(Input::getInstance().handleInputThread, std::ref(running));

    while (running) {
        gameLoop(window, game, running);
    }

    inputThread.join();
    endGame();
}