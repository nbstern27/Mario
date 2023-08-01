#include "Entity.h"

Entity::Entity(int x, int y, float vx, float vy, float ax, float ay, int width, int height) : 
    m_x(x),
    m_y(y), 
    m_vx(vx),
    m_vy(vy),
    m_ax(ax),
    m_ay(ay),
    m_prevX(0),
    m_prevY(0),
    m_width(width),
    m_height(height)
{}

Entity::~Entity() {}

void Entity::move(const float dt, const bool isGroundBelow) {
    setAcceleration(0, GRAVITY_ACCELERATION);
    updateVelocity(dt);
    updatePosition(dt);
}

void Entity::updatePosition(const float dt) {s
    //Set previous position values
    m_prevX = m_x;
    m_prevY = m_y;

    //Distance traveled in time dt
    m_x = m_vx * dt;
    m_y = m_vy * dt;

    checkDespawn();
}

void Entity::updateVelocity(const float dt) {
    //Update velocity over time dt
    m_vx += m_ax * dt;
    m_vy += m_ay * dt;

    //Ensure we don't exceed max velocity
    m_vx = std::max(m_vx, TERMINAL_VELOCITY_X);
    m_vy = std::max(m_vy, TERMINAL_VELOCITY_Y);
}

void Entity::setVelocity(const float vx, const float vy) {
    m_vx = vx;
    m_vy = vy;
}

void Entity::setAcceleration(const float ax, const float ay) {
    m_ax = ax;
    m_ay = ay;
}

std::vector<int> Entity::getBoundingBox() const {
    return { _x - (_width / 2), _y - (_height / 2), _width, _height };
}

bool Entity::isCollidingWith(const Entity* other) const {
    const std::vector<int>& bbox1 = getBoundingBox();
    const std::vector<int>& bbox2 = other->getBoundingBox();

    bool xOverlap = bbox1[0] < bbox2[0] + bbox2[2] && bbox1[0] + bbox1[2] > bbox2[0];
    bool yOverlap = bbox1[1] < bbox2[1] + bbox2[3] && bbox1[1] + bbox1[3] > bbox2[1];

    return xOverlap && yOverlap;
}
bool Entity::operator==(const Entity& entity) const {
    return (this == &entity);
}