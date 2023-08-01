#ifndef ENTITY_H
#define ENTITY_H

#include "Constants.h"
#include <vector>

class Entity {
private:
    float m_vx;
    float m_vy;
    float m_ax;
    float m_ay;

protected:
public:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    int m_prevX;
    int m_prevY;

    Entity(int x, int y, float vx, float vy, float ax, float ay, int width, int height);
    ~Entity();

    void move(const float dt, const bool isGroundBelow);
    void updatePosition(const float dt);
    void updateVelocity(const float dt);
    void setVelocity(const float vx = m_vx, const float vy = m_vy);
    void setAcceleration(const float ax = m_ax, const float ay = m_ay);

    std::vector<int> getBoundingBox() const;
    bool isCollidingWith(const Entity* other) const;

    bool operator==(const Entity& entity) const;
};

#endif // ENTITY_H