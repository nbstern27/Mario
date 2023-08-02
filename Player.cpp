#include "Player.h"

Player::Player() : 
    Entity(INIT_MARIO_X, INIT_MARIO_Y, INIT_MARIO_VX, INIT_MARIO_VY, INIT_MARIO_AX, INIT_MARIO_AY, INIT_MARIO_WIDTH, INIT_MARIO_HEIGHT),
    m_subx(0),
    m_suby(0),
    m_Player_State(Player_State::GROUNDED)
{}

Player::~Player() {

}

bool Player::move(const float& dt) {
    auto direc = Input::getInstance().getDirection();
    auto button = Input::getInstance().getButton();

    if (m_Player_State == Player_State::GROUNDED) {
        switch (button) {
            case (Direction::UP) : {
                m_ax = 0;
                m_ay = JUMP_SPEED;
                break;
            }
            case (Direction::UP_LEFT) : {
                m_ax = -1*RUN_SPEED;
                m_ay = JUMP_SPEED;
                break;
            }
            case (Direction::UP_RIGHT) : {
                m_ax = RUN_SPEED;
                m_ay = JUMP_SPEED;
                break;
            }
            case (Direction::DOWN) : {
                m_ax = 0;
                m_ay = -1*JUMP_SPEED;
                break;
            }
            case (Direction::DOWN_LEFT) : {
                m_ax = -1*RUN_SPEED;
                m_ay = -1*JUMP_SPEED;
                break;
            }
            case (Direction::DOWN_RIGHT) : {
                m_ax = RUN_SPEED;
                m_ay = -1*JUMP_SPEED;
                break;
            }
            case (Direction::LEFT) : {
                m_ax = -1*RUN_SPEED;
                m_ay = 0;
                break;
            }
            case (Direction::RIGHT) : {
                m_ax = RUN_SPEED;
                m_ay = 0;
                break;
            }
            case (Direction::NONE) : {
                m_ax = 0;
                m_ay = 0;
                break;
            }
        }
    }

    
    updateVelocity(dt);
    updatePosition(dt);

    return (m_x != m_prevX) || (m_y != m_prevY);
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