#include "GameDriver.h"

Game::Game(sf::RenderWindow& window):
    m_window(window),
    m_quadtree(QUADTREE_LEFT_X, QUADTREE_BOTTOM_Y, QUADTREE_WIDTH, QUADTREE_HEIGHT),
    m_entities(),
    m_player(std::make_unique<Player>()),
    m_Game_State(Game_State::CUTSCENE),
    m_numLives(5)
{
    m_entities.push_back(m_player);
    m_quadtree.insert(m_player);
}

Game::~Game() {

}

void Game::updatePhysics(const float& dt) {
    moveAllEntities(dt);
    checkCollisions();
    tryMoveScreen();
}
        
void Game::updateGraphics() {
    drawBackground();
    drawPlayer();
    drawEntities();
}

void Game::checkCollisions() {
    m_quadtree.resolveCollisions();
    m_isGroundBelowPlayer = true;
}

void Game::moveAllEntities(const float& dt) {
    int newX;
    int newY;
    for (auto& e : m_entities) {
        // If the entity wants to move, we store its new position and remove from the quadtree using previous position.
        // We then update the position and insert into the quadtree to be checked for collisions later
        if (e->move(dt)) {
            newX = e->m_x;
            newY = e->m_y;

            e->m_x = e->m_prevX;
            e->m_y = e->m_prevY;
            m_quadtree.remove(e);

            e->m_x = newX;
            e->m_y = newY;
            m_quadtree.insert(e);
        }
    }
}

void Game::tryMoveScreen() {
    if (m_player->m_x < SCROLL_SCREEN_MARIO_X) {
        return;
    }
}

void Game::drawBackground() {

}

void Game::drawPlayer() {
    //!!!DEBUG CURRENTLY 
    sf::RectangleShape rectangle(sf::Vector2f(5.0f, 5.0f)); // Width: 5, Height: 5
    rectangle.setFillColor(sf::Color::Green); // Set the fill color to green
    rectangle.setPosition(m_player->m_x, m_player->m_y); // Set the position (x, y) to (m_x, m_y)
    m_window.draw(rectangle);
}

void Game::drawEntities() {

}