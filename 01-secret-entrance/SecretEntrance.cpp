//
// Created by angel on 2025-12-03.
//

#include "SecretEntrance.h"

#include <fstream>

int SecretEntrance::_dial = 50;
int SecretEntrance::_password = 0;

bool SecretEntrance::exec(std::string &outError) {
    std::ifstream input("input");

    if (!input) {
        outError = "Error opening file";
        return false;
    }

    std::string instruction;
    while (std::getline(input, instruction)) {
        switch (getDirection(instruction)) {
            case Direction::LEFT:
                _dial = turnLeft(getSteps(instruction));
                break;
            case Direction::RIGHT:
                _dial = turnRight(getSteps(instruction));
                break;
            default:
                outError = "Invalid direction";
                return false;
        }
        updatePassword();
    }

    return true;
}

int SecretEntrance::getAnswer() {
    return _password;
}

int SecretEntrance::turnLeft(const int steps) {
    return (_dial - steps + 100) % 100;
}

int SecretEntrance::turnRight(const int steps) {
    return (_dial + steps) % 100;
}

int SecretEntrance::getSteps(const std::string &instruction) {
    return stoi(instruction.substr(1, instruction.size() - 1));
}

SecretEntrance::Direction SecretEntrance::getDirection(const std::string &instruction) {
    return static_cast<Direction>(instruction[0]);
}

int SecretEntrance::updatePassword() {
    if (_dial == 0) {
        _password++;
    }
    return _password;
}

