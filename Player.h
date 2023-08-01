#ifndef PLAYER_H
#define PLAYER_H

#include "Constants.h"
#include "Entity.h"
#include <cstdint>

enum class Mario_State {
    SHORT,
    TALL,
    STAR
};

class Player : public Entity {
private:
protected:
public:
    Mario_State m_Mario_State;

    Player();
    ~Player();

    bool move(const float dt) override;
    void updatePosition(const float dt);
    void updateVelocity(const float dt);
    void setVelocityX(const float vx);
    void setAcceleration(const float ax, const float ay);
};

#endif // PLAYER_H