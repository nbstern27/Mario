#include "Entity.h"

Entity::Entity(int x, int y, int width, int height)
    : _x(x), _y(y), _width(width), _height(height) {}

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