//
// Created by angel on 2025-12-04.
//

#ifndef ADVENT_OF_CODE_LOBBY_H
#define ADVENT_OF_CODE_LOBBY_H

#include <string>

using LLONG = long long;

class Lobby {
public:
    Lobby() = default;
    static bool exec(std::string &outError);
    static LLONG getAnswer();
private:
    static LLONG getLargestJoltage(const std::string &bank);
    static LLONG _sumOutputJoltages;
};


#endif //ADVENT_OF_CODE_LOBBY_H