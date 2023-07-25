#include "GameDriver.h"

Game::Game(sf::RenderWindow* window):
    m_window(window),
    m_player(new Player()),
    m_Game_State(Game_State::CUTSCENE),
    m_numLives(5)
{}

Game::~Game() {

}

void Game::updatePhysics() {
    movePlayer();
    moveEntities();
    checkCollisions();
}
        
void Game::updateGraphics() {
    drawBackground();
    drawBlocks();
    drawEntities();
}

void Game::movePlayer() {
    Direction dir = Input::getInstance().getDirection();

    int8_t dx(0);
    int8_t dy(0);
    if (dir == Direction::UP) {
        dy = 1;
    } else if (dir == Direction::DOWN) {
        dy = -1;
    } else if (dir == Direction::RIGHT) {
        dx = 1;
    } else {
        dx = -1;
    }


}

void Game::moveEntities() {

}

void Game::checkCollisions() {

}

void Game::drawBackground() {

}

void Game::drawBlocks() {

}

void Game::drawEntities() {

}