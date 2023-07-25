#include "Player.h"

Player::Player():
    m_Mario_State(Mario_State::SHORT),
    m_x(INIT_MARIO_X),
    m_y(INIT_MARIO_Y),
    m_subx(INIT_MARIO_SUBX),
    m_suby(INIT_MARIO_SUBY),
    m_vx(INIT_MARIO_VX),
    m_vy(INIT_MARIO_VY),
    m_ax(INIT_MARIO_AX),
    m_ay(INIT_MARIO_AY)
{}

Player::~Player() {

}

void Player::updatePosition(const float dt) {
    //Set previous position values
    m_prevX = m_x;
    m_prevY = m_y;

    //Distance traveled in time dt
    float dx = m_vx * dt;
    float dy = m_vy * dt;

    //Get new subpixel values
    m_subx += std::floor(SUBPIXELS_PER_PIXEL * dx);
    m_suby += std::floor(SUBPIXELS_PER_PIXEL * dy);

    //Get new pixels from subpixel
    m_x += m_subx / SUBPIXELS_PER_PIXEL;
    m_y += m_suby / SUBPIXELS_PER_PIXEL;

    //Get the remaider subpixels
    m_subx %= SUBPIXELS_PER_PIXEL;
    m_suby %= SUBPIXELS_PER_PIXEL;
}

void Player::updateVelocity(const float dt) {
    //Update velocity over time dt
    m_vx += m_ax * dt;
    m_vy += m_ay * dt;

    //Ensure we don't exceed max velocity
    m_vx = std::max(m_vx, TERMINAL_VELOCITY_X)
    m_vy = std::max(m_vy, TERMINAL_VELOCITY_Y)

}

void Player::setVelocityX(const float vx) {
    m_vx = vx;
}

void Player::setAcceleration(const float ax, const float ay) {
    m_ax = ax;
    m_ay = ay;
}