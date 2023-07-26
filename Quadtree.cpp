#include "Quadtree.h"

void Quadtree::destroy(QuadtreeNode* node) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        destroy(node->_children[i]);
        delete node->_children[i];
        node->_children[i] = nullptr;
    }

    node->_entities.clear();
}

void Quadtree::insertHelper(QuadtreeNode* node, Entity* entity) {
    if (node == nullptr) {
        return;
    }

    if (node->_entities.size() < 4 || node->_level >= MAX_QUADTREE_LEVEL) {
        // If the node has space or reached the maximum level, add the entity here
        node->_entities.push_back(entity);
        return;
    }

    // Otherwise, split the node and redistribute entities to children
    if (node->_children[0] == nullptr) {
        splitNode(node);
    }

    // Redistribute entities to the appropriate child nodes
    for (Entity* e : node->_entities) {
        Quadrant quadrant = getQuadrant(node, e);
        insertHelper(node->_children[quadrant], e);
    }

    node->entities.clear(); // Clear the entities from the current node
}

bool Quadtree::removeHelper(QuadtreeNode* node, Entity* entity) {
    if (node == nullptr) {
        return false;
    }

    // Find and remove the entity from the current node
    auto it = std::find(node->_entities.begin(), node->_entities.end(), entity);
    if (it != node->_entities.end()) {
        node->_entities.erase(it);
        return true;
    }

    // If the node has children, try to remove from them
    if (node->_children[0] != nullptr) {
        Quadrant quadrant = getQuadrant(node, entity);
        return removeHelper(node->_children[quadrant], entity);
    }

    return false; // Element not found in the quadtree
}

void Quadtree::splitNode(QuadtreeNode* node) {
    int subWidth = node->_x + (_width >> 1);
    int subHeight = node->_y + (_height >> 1);

    node->children[NORTH_WEST] = new QuadtreeNode(node->_level + 1, node->_x, node->_y);
    node->children[NORTH_EAST] = new QuadtreeNode(node->_level + 1, subWidth, node->_y);
    node->children[SOUTH_WEST] = new QuadtreeNode(node->_level + 1, node->_x, subHeight);
    node->children[SOUTH_EAST] = new QuadtreeNode(node->_level + 1, subWidth, subHeight);
}

Quadrant Quadtree::getQuadrant(QuadtreeNode* node, Entity* entity) {
    int subWidth = node->_x + (_width >> 1);
    int subHeight = node->_y + (_height >> 1);

    if (entity->_x >= subWidth) {
        if (entity->_y >= subHeight) {
            return SOUTH_EAST;
        } else {
            return NORTH_EAST;
        }
    } else {
        if (entity->_y >= subHeight) {
            return SOUTH_WEST;
        } else {
            return NORTH_WEST;
        }
    }
}