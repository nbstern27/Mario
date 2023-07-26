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
    int _x;
    int _y;

protected:
public:
    QuadtreeNode(int level, int x, int y): _level(level), _x(x), _y(y) {}
    ~QuadtreeNode() {
        for (int i = 0; i < 4; ++i) {
            delete _children[i];
        }
        _children = {nullptr};
        _entities.clear();
    }
};

class Quadtree {
private:
    QuadtreeNode* _root;
    int _width;
    int _height;

    void destroy(QuadtreeNode* node);

    void insertHelper(QuadtreeNode* node, Entity* entity);
    bool removeHelper(QuadtreeNode* node, Entity* entity);
    
    void splitNode(QuadtreeNode* node);
    Quadrant getQuadrant(QuadtreeNode* node, Entity* entity);
    

protected:
public:
    Quadtree(): 
        _root(new QuadtreeNode(0, QUADTREE_WEST_X, QUADTREE_SOUTH_Y)), 
        _width(QUADTREE_EAST_X), 
        _height(QUADTREE_NORTH_Y) 
    {}

    ~Quadtree() {
        destroy(_root);
        delete _root;
    }

    void insert(Entity* entity) {
        insertHelper(_root, entity);
    }

    bool remove(Entity* entity) {
        return removeHelper(_root, entity);
    }
};

#endif // QUADTREE_H