#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

//mingw32-make

const int PIXELSPERBLOCK = 8;
const int SCALINGFACTOR = 3;

const int SCREENWIDTH = 224 * SCALINGFACTOR;
const int SCREENHEIGHT = 288 * SCALINGFACTOR;

const int BLOCKSX = 28; // Original packman value
const int BLOCKSY = 36; // Original packman value
const int BLOCKWIDTH = PIXELSPERBLOCK * SCALINGFACTOR;
const int BLOCKHEIGHT = PIXELSPERBLOCK * SCALINGFACTOR;

const float LOGICRATE = 480.0f; // Rate at which logic updates
const float FPS = 240.0f; // Frame rate

const float TIMEPERLOGICUPDATE = 1.0f / LOGICRATE;
const float TIMEPERFRAME = 1.0f / FPS;

RenderWindow window(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Mario");

Clock clockCounter;
float deltaTime = 0;

int secondCount = 0; // Goes from 0 to FPS number

int main() {
    if (sf::Joystick::isConnected(0)) {
        std::cout << "Joystick is Connected!" << std::endl;
    }
    
    while (true) {
        if (playGame() == -1) {
            return 1;
        }
    }
}

int playGame() {    
    GameData * game = new GameData(SCREENWIDTH/BLOCKWIDTH, SCREENHEIGHT/BLOCKHEIGHT, BLOCKWIDTH, BLOCKHEIGHT);
    Player * player = new Player(STARTR, STARTC, game);

    while (window.isOpen()) {
        deltaTime = clockCounter.restart().asSeconds();
        int newRow, newCol;

        if ((Keyboard::isKeyPressed(Keyboard::W) || (Keyboard::isKeyPressed(Keyboard::Up))) || (Joystick::isButtonPressed(0, 0)) && ((player->px + 5) % 8 == 0)) {
            newCol = 8*(player->c);
            newRow = 8*(player->r - 1);

            newCol = ((8*game->getCols()+newCol)) % (game->getCols()*8) / 8;
            newRow = ((8*game->getRows()+newRow)) % (game->getRows()*8) / 8;
            if (!game->checkCollision(newRow, newCol, 4)) {
                player->direc[0] = 0;
                player->direc[1] = -1;
            }
        }
        if ((Keyboard::isKeyPressed(Keyboard::S) || (Keyboard::isKeyPressed(Keyboard::Down)) || (Joystick::isButtonPressed(0, 1))) && ((player->px + 5) % 8 == 0)) {
            newCol = 8*(player->c);
            newRow = 8*(player->r + 1);

            newCol = ((8*game->getCols()+newCol)) % (game->getCols()*8) / 8;
            newRow = ((8*game->getRows()+newRow)) % (game->getRows()*8) / 8;
            if (!game->checkCollision(newRow, newCol, 4)) {
                player->direc[0] = 0;
                player->direc[1] = 1;
            }
        }
        if ((Keyboard::isKeyPressed(Keyboard::D) || (Keyboard::isKeyPressed(Keyboard::Right)) || (Joystick::isButtonPressed(0, 3))) && ((player->py + 5) % 8 == 0)) {
            newCol = 8*(player->c + 1);
            newRow = 8*(player->r);

            newCol = ((8*game->getCols()+newCol)) % (game->getCols()*8) / 8;
            newRow = ((8*game->getRows()+newRow)) % (game->getRows()*8) / 8;
            if (!game->checkCollision(newRow, newCol, 4)) {
                player->direc[0] = 1;
                player->direc[1] = 0;
            }
        }
        if ((Keyboard::isKeyPressed(Keyboard::A) || (Keyboard::isKeyPressed(Keyboard::Left)) || (Joystick::isButtonPressed(0, 2))) && ((player->py + 5) % 8 == 0)) {
            newCol = 8*(player->c - 1);
            newRow = 8*(player->r);

            newCol = ((8*game->getCols()+newCol)) % (game->getCols()*8) / 8;
            newRow = ((8*game->getRows()+newRow)) % (game->getRows()*8) / 8;
            if (!game->checkCollision(newRow, newCol, 4)) {
                player->direc[0] = -1;
                player->direc[1] = 0;
            }
        }
        
        // Event handling
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    return -1;
            }
        }

        if (accumulatedTimeGraphics >= TIMEPERFRAME) {
            accumulatedTimeGraphics = 0;
            window.display();
        } 
    }

    return -1;
}
