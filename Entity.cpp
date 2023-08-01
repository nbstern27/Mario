#include "Entity.h"

Entity::Entity(int x, int y, int subx, int suby, float vx, float vy, float ax, float ay, int width, int height) : 
    m_x(x),
    m_y(y), 
    m_subx(subx),
    m_suby(suby),
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