#ifndef PLAYER_H
#define PLAYER_H

#include <cstdint>

enum class Mario_State {
    SHORT,
    TALL,
    STAR
};

class Player {
    private:
        Mario_State m_Mario_State;
        uint32_t m_x;
        uint32_t m_y;
        uint32_t m_subx;
        uint32_t m_suby;

    protected:
    public:
        Player();
        ~Player();
};

#endif // INPUT_H