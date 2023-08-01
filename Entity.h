#ifndef ENTITY_H
#define ENTITY_H

#include <vector>

class Entity {
private:
    int _x;
    int _y;
    int _width;
    int _height;

    int _prevX;
    int _prevY;

protected:
public:
    Entity(int x, int y, int width, int height);
    ~Entity();

    std::vector<int> getBoundingBox() const;
    bool isCollidingWith(const Entity* other) const;

    bool operator==(const Entity& entity) const;
};

#endif // ENTITY_H