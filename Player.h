#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <cstdint>

enum class Player_State {
    GROUNDED,
    AIRBORNE,
    DIVING
};

class Player : public Entity {
private:
    int m_subx;
    int m_suby;
protected:
public:
    Player_State m_Player_State;

    Player();
    ~Player();

    bool move(const float dt) override;                                 // Player moves with user input
    void updatePosition(const float dt) overide;                        // Player moves with subpixel precision
};

#endif // PLAYER_H