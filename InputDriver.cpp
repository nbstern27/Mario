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

bool Input::pressingUp() {
    return Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::UP) || Joystick::isButtonPressed(0,0);
}

bool Input::pressingDown() {
    return Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down) || Joystick::isButtonPressed(0, 1)
}

bool Input::pressingLeft() {
    return Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::left) || Joystick::isButtonPressed(0, 2)
}

bool Input::pressingRight() {
    return Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right) || Joystick::isButtonPressed(0, 3)
}

void Input::searchForInput() {
    m_Direction = Direction::NONE;
    m_Button = Button::NONE;

    if (Keyboard::isKeyPressed(Keyboard::O)) {
        m_Button = Button::A;
    }

    if (Keyboard::isKeyPressed(Keyboard::P)) {
        m_Button = Button::B;
    }

    // Precedence on most recent input if there are two held inputs
    if (pressingUp() && (!pressingDown() || (m_Direction != Direction::UP && m_Direction != Direction::UP_LEFT && m_Direction != Direction::UP_RIGHT))) {
        if (pressingLeft() && (!pressingRight() || (m_Direction != Direction::UP_LEFT))) {
            m_Direction = Direction::UP_LEFT;
        } else if (pressingRight() && (!pressingLeft() || (m_Direction != Direction::UP_RIGHT))) {
            m_Direction = Direction::UP_RIGHT;
        } else {
            m_Direction = Direction::UP;
        }
    } else if (pressingDown() && (!pressingUp() || (m_Direction != Direction::DOWN && m_Direction != Direction::DOWN_LEFT && m_Direction != Direction::DOWN_RIGHT))) {
        if (pressingLeft() && (!pressingRight() || (m_Direction != Direction::DOWN_LEFT))) {
            m_Direction = Direction::DOWN_LEFT;
        } else if (pressingRight() && (!pressingLeft() || (m_Direction != Direction::DOWN_RIGHT))) {
            m_Direction = Direction::DOWN_RIGHT;
        } else {
            m_Direction = Direction::DOWN;
        }
    } else if (pressingLeft() && (!pressingRight() || m_Direction != Direction::LEFT)) {
        m_Direction = Direction::LEFT;
    } else if (pressingRight() && (!pressingLeft() || m_Direction != Direction::RIGHT)) {
        m_Direction = Direction::RIGHT;
    } else {
        m_Direction = Direction::NONE;
    }
}

Direction Input::getDirection() {
    return m_Direction;
}

Button Input::getButton() {
    return m_Button;
}