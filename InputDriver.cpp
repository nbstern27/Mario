#include "InputDriver.h"

Input& Input::getInstance() {
    static Input instance; // This ensures it's created only once
    return instance;
}

Input::~Input() {

}

void Input::searchForInput() {

}

Direction Input::getDirection() {

}

Button Input::getButton() {

}