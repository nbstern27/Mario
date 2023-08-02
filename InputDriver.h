#ifndef INPUTDRIVER_H
#define INPUTDRIVER_H

#include <thread>

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT,
    DOWN_RIGHT,
    NONE
};

enum class Button {
    A,
    B,
    X,
    Y,
    NONE
};

class Input {
private:
    Direction m_Direction;
    Button m_Button;
    Input() = default;
    bool pressingUp();
    bool pressingDown();
    bool pressingLeft();
    bool pressingRight();
    
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