#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

#include "Player.h"
#include "Enemy.h"
#include "Block.h"
#include "InputDriver.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

enum class Game_State {
    CUTSCENE,
    PLAY,
    GAMEOVER
};

class Game {
    private:
        sf::RenderWindow& m_window;
        Player* m_player;
        Game_State m_Game_State;
        uint8_t m_numLives;

    protected:
    public:
        Game(sf::RenderWindow& window);
        ~Game();
        void updatePhysics();
        void updateGraphics();

        void movePlayer();
        void moveEntities();
        void checkCollisions();

        void drawBackground();
        void drawBlocks();
        void drawEntities();
};

#endif // GAMEDRIVER_H