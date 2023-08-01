#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

class Entity {
private:
    int m_x;
    int m_y;
    int m_subx;
    int m_suby;

    float m_vx;
    float m_vy;
    float m_ax;
    float m_ay;

    int m_prevX;
    int m_prevY;

    int m_width;
    int m_height;

protected:
public:
    Entity(int x, int y, int subx, int suby, float vx, float vy, float ax, float ay, int width, int height);
    ~Entity();

    std::vector<int> getBoundingBox() const;
    bool isCollidingWith(const Entity* other) const;

    bool operator==(const Entity& entity) const;
};

#endif // ENTITY_H