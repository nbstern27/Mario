#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <cstdint>

enum class Mario_State {
    SHORT,
    TALL,
    STAR
};

class Player : public Entity {
private:
    int m_subx;
    int m_suby;
protected:
public:
    Mario_State m_Mario_State;

    Player();
    ~Player();

    bool move(const float dt, const bool isGroundBelow) override;       // Mario moves with user input
    void updatePosition(const float dt) overide;                        // Mario moves with subpixel precision
};

#endif // PLAYER_H