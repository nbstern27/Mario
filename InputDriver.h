#ifndef INPUTDRIVER_H
#define INPUTDRIVER_H

#include <thread>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum class Button {
    A,
    B,
    X,
    Y
};

class Input {
private:
    Direction m_Direction;
    Button m_Button;
    Input() = default;
protected:
public:
    static Input& getInstance();
    ~Input();
    void handleInputThread(bool& running);
    void searchForInput();
    Direction getDirection();
    Button getButton();
};

#endif // INPUTDRIVER_H