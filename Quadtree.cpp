#include "Quadtree.h"

QuadtreeNode::QuadtreeNode(int level, int x, int y, int width, int height)
    : _level(level), _x(x), _y(y), _width(width), _height(height) {}

QuadtreeNode::~QuadtreeNode() {
    for (int i = 0; i < 4; ++i) {
        delete _children[i];
        _children[i] = nullptr;
    }
    _entities.clear();
}

void QuadtreeNode::splitNode() {
    int subWidth = _width >> 1;
    int subHeight = _height >> 1;

    _children[NORTH_WEST] = new QuadtreeNode(_level + 1, _x, _y, subWidth, subHeight);
    _children[NORTH_EAST] = new QuadtreeNode(_level + 1, _x + subWidth, _y, subWidth, subHeight);
    _children[SOUTH_WEST] = new QuadtreeNode(_level + 1, _x, _y + subHeight, subWidth, subHeight);
    _children[SOUTH_EAST] = new QuadtreeNode(_level + 1, _x + subWidth, _y + subHeight, subWidth, subHeight);

    // Redistribute entities to the appropriate child nodes
    for (Entity* entity : _entities) {
        std::vector<Quadrant> quadrants = getQuadrants(entity);
        _children[quadrant]->insert(entity);
    }

    _entities->clear();
}

std::vector<Quadrant> QuadtreeNode::getQuadrants(Entity* entity) {
    std::vector<Quadrant> quadrants;
    for (int i = 0; i < 4; ++i) {
        if (isEntityOverlapping(entity, _children[i]->_x, _children[i]->_y, _children[i]->_width, _children[i]->_height)) {
            quadrants.push_back(static_cast<Quadrant>(i));
        }
    }
    return quadrants;
}

bool QuadtreeNode::isEntityOverlapping(Entity* entity, int x, int y, int width, int height) {
    auto bbox = entity->getBoundingBox();
    return !(bbox[0] + bbox[2] <= x || bbox[0] >= x + width || bbox[1] + bbox[3] <= y || bbox[1] >= y + height);
}

Quadtree::Quadtree(int x, int y, int width, int height)
    : _root(new QuadtreeNode(0, x, y, width, height)), _width(width), _height(height) {}

Quadtree::~Quadtree() {
    delete _root;
    _root = nullptr;
}

bool Quadtree::insert(Entity* entity) {
    return insertHelper(_root, entity);
}

bool Quadtree::insertHelper(QuadtreeNode* node, Entity* entity) {
    if (node == nullptr) {
        return;
    }

    // The entity's bounding box does not fit within this node
    if (!node->isEntityOverlapping(entity, node->_x, node->_y, node->_width, node->_height)) {
        return false;
    }

    // If the node has children, go to them to insert
    if (node->_children[0] != nullptr) {
        bool inserted = false;
        for (auto& child : node->_children) {
            inserted |= insertHelper(child, entity);
        }

        return inserted;
    }

    // If the node has space or reached the maximum level, add the entity here
    if (node->_entities.size() < MAX_NUM_ENTITIES_PER_QUADTREE_NODE || node->_level >= MAX_QUADTREE_LEVEL) {
        node->_entities.push_back(entity);
        return true;
    }

    // Too many entitites in node, time to split!
    node->splitNode();
    return true;
}

bool Quadtree::remove(Entity* entity) {
    return removeHelper(_root, entity);
}

bool Quadtree::removeHelper(QuadtreeNode* node, Entity* entity) {
    if (node == nullptr) {
        return;
    }

    // The entity's bounding box does not fit within this node
    if (!node->isEntityOverlapping(entity, node->_x, node->_y, node->_width, node->_height)) {
        return false;
    }

    // If the node has children, go to them to remove
    if (node->_children[0] != nullptr) {
        bool removed = false;
        bool childrenEmptyCount = 0;
        for (auto& child : node->_children) {
            removed |= removeHelper(child, entity);
            if (child->_entities.size() == 0) {
                childrenEmptyCount++;
            }
        }

        // All children are empty! Delete them.
        if (childrenEmptyCount >= 4) {
            for (auto& child : node->_children) {
                delete child;
                child = nullptr;
            }
        }

        return removed;
    }

    // Entity is in the node!
    auto it = std::find(node->_entities.begin(), node->_entities.end(), entity);
    if (it != node->_entities.end()) {
        node->_entities.erase(it);
        return true;
    }

    return false; // Element not found in the quadtree
}

void Quadtree::resolveCollisions() {
    resolveCollisionsHelper(_root);
}

void Quadtree::resolveCollisionsHelper(QuadtreeNode* node) {
    if (node == nullptr) {
        return;
    }

    // If the node has children, go to them to check for collisions
    if (node->_children[0] != nullptr) {
        for (auto& child : node->_children) {
            resolveCollisionsHelper(child);
        }
        
        return;
    }

    // No children: resolve conflicts in current node
    for (size_t i = 0; i < node->_entities.size(); ++i) {
        for (size_t j = i + 1; j < node->_entities.size(); ++j) {
            Entity* entity1 = node->_entities[i];
            Entity* entity2 = node->_entities[j];
            if (entity1->isCollidingWith(entity2)) {
                resolveCollision(entity1, entity2);
            }
        }
    }
}