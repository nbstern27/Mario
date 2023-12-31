#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

#include "Constants.h"
#include "Quadtree.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Block.h"
#include "InputDriver.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include <memory>
#include <vector>

enum class Game_State {
    CUTSCENE,
    PLAY,
    GAMEOVER
};

class Game {
private:
    sf::RenderWindow& m_window;
    Quadtree m_quadtree;
    std::vector<Entity*> m_entities;
    std::unique_ptr<Player> m_player;
    Game_State m_Game_State;
    uint8_t m_numLives;
    bool m_isGroundBelowPlayer;

protected:
public:
    Game(sf::RenderWindow& window);
    ~Game();
    
    void updatePhysics(const float& dt);
    void updateGraphics();

    void moveAllEntities(const float& dt);
    void checkCollisions();
    void tryMoveScreen();

    void drawBackground();
    void drawPlayer();
    void drawEntities();
};

#endif // GAMEDRIVER_H