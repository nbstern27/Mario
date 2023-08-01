#ifndef CONSTANTS_H
#define CONSTANTS_H

static const uint8_t SUBPIXELS_PER_PIXEL(16);
static const uint8_t PIXELS_PER_BLOCK(8);
static const uint8_t LEVEL_WIDTH(128);
static const uint8_t LEVEL_HEIGHT(128);
static const uint8_t LEVEL_BOTTOM_LEFT_X(0);
static const uint8_t LEVEL_BOTTOM_LEFT_Y(0);
static const uint8_t SCALING_FACTOR(3);

static const uint32_t SCREEN_WIDTH(224 * SCALING_FACTOR);
static const uint32_t SCREEN_HEIGH(288 * SCALING_FACTOR);

static const float LOGIC_RATE(480.0f); // Rate at which logic updates
static const float FRAME_RATE(240.0f); // Frame rate

static const uint32_t INIT_MARIO_X(4);
static const uint32_t INIT_MARIO_Y(4);
static const uint32_t INIT_MARIO_SUBX(0);
static const uint32_t INIT_MARIO_SUBY(0);
        
static const float INIT_MARIO_VX(0);
static const float INIT_MARIO_VY(0);
static const float INIT_MARIO_AX(0);
static const float INIT_MARIO_AY(0);
static const float INIT_MARIO_WIDTH(1);
static const float INIT_MARIO_HEIGHT(1);

static const float SCROLL_SCREEN_MARIO_X(0); 
static const float TERMINAL_VELOCITY_X(0);
static const float TERMINAL_VELOCITY_Y(0);
static const float MOVE_SPEED(0);
static const float GRAVITY_ACCELERATION(0);

static const uint8_t INPUT_POLLING_RATE_MS(50);

static const uint8_t MAX_QUADTREE_LEVEL(8);
static const uint8_t MAX_NUM_ENTITIES_PER_QUADTREE_NODE(4);

namespace TileMap {
    static const std::array<std::array<int, LEVEL_WIDTH>, LEVEL_HEIGHT> LEVEL1_1 = {

    };
}

#endif // CONSTANTS_H