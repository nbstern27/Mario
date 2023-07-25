#include "GameDriver.h"

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

void advanceFrame(Game* game) {
    game->updatePhysics();
    game->updateGraphics();
}

int main() {
    RenderWindow* window = new RenderWindow(VideoMode(SCREENWIDTH, SCREENHEIGHT), "Mario");
    Game* game = new Game(window);
    bool doNextFrame = true;
    if (doNextFrame) {
        advanceFrame(game);
    }

}