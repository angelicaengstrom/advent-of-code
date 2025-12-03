//
// Created by angel on 2025-12-03.
//

#ifndef ADVENT_OF_CODE_SECRETENTRANCE_H
#define ADVENT_OF_CODE_SECRETENTRANCE_H

#include <string>
class SecretEntrance {
public:
    SecretEntrance() = default;
    static bool exec(std::string &outError);
    static int getAnswer();
private:
    enum class Direction {
        LEFT = 'L',
        RIGHT = 'R',
        INVALID = 999
    };

    static int turnLeft(int steps);
    static int turnRight(int steps);
    static int getSteps(const std::string &instruction);
    static Direction getDirection(const std::string &instruction);

    static int updatePassword();

    static int _password;
    static int _dial;
};


#endif //ADVENT_OF_CODE_SECRETENTRANCE_H