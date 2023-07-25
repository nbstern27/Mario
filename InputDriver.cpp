#include "InputDriver.h"

using namespace sf;

Input& Input::getInstance() {
    static Input instance; // This ensures it's created only once
    return instance;
}

Input::~Input() {

}

void Input::handleInputThread(bool& running) {
    while (running) {
        searchForInput();
        std::this_thread::sleep_for(std::chrono::milliseconds(INPUT_POLLING_RATE_MS));
    }
}

void Input::searchForInput() {
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up) || Joystick::isButtonPressed(0, 0)) {
        m_Direction = Direction::UP;
    }

    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down) || Joystick::isButtonPressed(0, 1)) {
        m_Direction = Direction::DOWN;
    }

    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right) || Joystick::isButtonPressed(0, 3)) {
        m_Direction = Direction::RIGHT;
    }

    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::left) || Joystick::isButtonPressed(0, 2)) {
        m_Direction = Direction::LEFT;
    }
}

Direction Input::getDirection() {
    return m_Direction;
}

Button Input::getButton() {
    return m_Button;
}