#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {
    const uint8_t SUBPIXELS_PER_PIXEL(16);
    const uint8_t PIXELS_PER_BLOCK(8);
    const uint8_t SCALING_FACTOR(3);

    const uint32_t SCREEN_WIDTH(224 * SCALING_FACTOR);
    const uint32_t SCREEN_HEIGH(288 * SCALING_FACTOR);

    const float LOGIC_RATE(480.0f); // Rate at which logic updates
    const float FRAME_RATE(240.0f); // Frame rate

    const uint32_t INIT_MARIO_X(0);
    const uint32_t INIT_MARIO_Y(0);
    const uint32_t INIT_MARIO_SUBX(0);
    const uint32_t INIT_MARIO_SUBY(0);
        
    const float INIT_MARIO_VX(0);
    const float INIT_MARIO_VY(0);
    const float INIT_MARIO_AX(0);
    const float INIT_MARIO_AY(0);

    const float TERMINAL_VELOCITY_X(0);
    const float TERMINAL_VELOCITY_Y(0);
    const float MOVE_SPEED(0);
    const float GRAVITY_ACCELERATION(0);

    const uint8_t POLLING_RATE_MS(50);

}

#endif // CONSTANTS_H