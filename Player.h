#ifndef PLAYER_H
#define PLAYER_H

#include "Constants.h"
#include <cstdint>

enum class Mario_State {
    SHORT,
    TALL,
    STAR
};

class Player {
private:
    uint32_t m_subx;
    uint32_t m_suby;

    float m_vx;
    float m_vy;
    float m_ax;
    float m_ay;

protected:
public:
    Mario_State m_Mario_State;
    uint32_t m_x;
    uint32_t m_y;
    uint32_t m_prevX;
    uint32_t m_prevY;

    Player();
    ~Player();

    void updatePosition(const float dt);
    void updateVelocity(const float dt);
    void setVelocityX(const float vx);
    void setAcceleration(const float ax, const float ay);
};

#endif // PLAYER_H