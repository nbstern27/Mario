#include "GameDriver.h"

Game::Game(sf::RenderWindow& window):
    m_window(window),
    m_player(new Player()),
    m_Game_State(Game_State::CUTSCENE),
    m_numLives(5)
{}

Game::~Game() {

}

void Game::updatePhysics(const float& dt) {
    checkCollisions();
    movePlayer();
    moveEntities();
}
        
void Game::updateGraphics() {
    drawBackground();
    drawPlayer();
    drawEntities();
}

void Game::movePlayer(const float& dt) {
    float ax(0);
    float ay(0);

    if (m_isGroundBelowPlayer) {
        ay = 0;
    } else {
        ay = GRAVITY_ACCELERATION;
    }

    m_player->setAcceleration(ax, ay);

    Direction dir = Input::getInstance().getDirection();

    if (dir == Direction::UP) {
        if (!m_isGroundBelowPlayer) {
            //!!!JUMP
        }
    } else if (dir == Direction::DOWN) {
        if (m_isGroundBelowPlayer) {
            //!!!CROUTCH
        }
    } else if (dir == Direction::RIGHT) {
        m_player->setVelocityX(MOVE_SPEED);
    } else if (dir == DIRECTION::LEFT) {
        m_player->setVelocityX(-1 * MOVE_SPEED);
    } else {
        //!!!ERROR
    }

    m_player->updateVelocity(dt);
    m_player->updatePosition(dt);

}

void Game::moveEntities(const float& dt) {

}

void Game::checkCollisions() {
    //!!!QUADTREE??
    //!!!TRY BRUTE FORCE FIRST
    m_isGroundBelowPlayer = true;
}

void Game::drawBackground() {

}

void Game::drawPlayer() {
    //!!!DEBUG CURRENTLY 
    sf::RectangleShape rectangle(sf::Vector2f(5.0f, 5.0f)); // Width: 5, Height: 5
    rectangle.setFillColor(sf::Color::Green); // Set the fill color to green
    rectangle.setPosition(m_player->m_x, m_player->m_y); // Set the position (x, y) to (m_x, m_y)
}

void Game::drawEntities() {

}