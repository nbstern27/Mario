#ifndef QUADTREE_H
#define QUADTREE_H

#include "Entity.h"
#include <vector>

enum Quadrant {
    NORTH_WEST,
    NORTH_EAST,
    SOUTH_WEST,
    SOUTH_EAST
};

class QuadtreeNode {
private:
    std::vector<Entity*> _entities;
    QuadtreeNode* _children[4] = {nullptr};
    int _level;
    int _x;                 // Bottom-left corner x-value of quadtree
    int _y;                 // Bottom-left corner y-value of quadtree
    int _width;             // Width in the x-direction of quadtree
    int _height;            // Height in the y-direction of quadtree

    void splitNode();
    std::vector<Quadrant> getQuadrants(Entity* entity);
    bool isEntityOverlapping(Entity* entity, int x, int y, int width, int height);

    friend class Quadtree;

public:
    QuadtreeNode(int level, int x, int y, int width, int height);
    ~QuadtreeNode();
};

class Quadtree {
private:
    QuadtreeNode* _root;
    int _width;
    int _height;

    bool insertHelper(QuadtreeNode* node, Entity* entity);
    bool removeHelper(QuadtreeNode* node, Entity* entity);
    void resolveCollisionsHelper(QuadtreeNode* node);

public:
    Quadtree(int x, int y, int width, int height);
    ~Quadtree();

    bool insert(Entity* entity);
    bool remove(Entity* entity);

    void resolveCollisions();
};

#endif // QUADTREE_H