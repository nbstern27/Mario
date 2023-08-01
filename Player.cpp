#include "Player.h"

Player::Player() : 
    Entity(INIT_MARIO_X, INIT_MARIO_Y, INIT_MARIO_VX, INIT_MARIO_VY, INIT_MARIO_AX, INIT_MARIO_AY, INIT_MARIO_WIDTH, INIT_MARIO_HEIGHT),
    m_subx(0),
    m_suby(0),
    m_Mario_State(Mario_State::SHORT)
{}

Player::~Player() {

}

bool Player::move(const float& dt, bool isGroundBelow) {
    float ax(0);
    float ay(0);

    if (isGroundBelow) {
        ay = 0;
    } else {
        ay = GRAVITY_ACCELERATION;
    }

    setAcceleration(ax, ay);

    Direction dir = Input::getInstance().getDirection();

    if (dir == Direction::UP) {
        if (!isGroundBelow) {
            //!!!JUMP
        }
    } else if (dir == Direction::DOWN) {
        if (isGroundBelow) {
            //!!!CROUTCH
        }
    } else if (dir == Direction::RIGHT) {
        setVelocityX(MOVE_SPEED);
    } else if (dir == DIRECTION::LEFT) {
        setVelocityX(-1 * MOVE_SPEED);
    } else {
        //!!!ERROR
    }

    updateVelocity(dt);
    updatePosition(dt);

    return (m_x != m_prevX) || (m_y != m_prevY)

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