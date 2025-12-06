//
// Created by angel on 2025-12-05.
//

#ifndef ADVENT_OF_CODE_CAFETERIA_H
#define ADVENT_OF_CODE_CAFETERIA_H

#include <string>
#include <map>

using LLONG = long long;

class Cafeteria {
public:
    Cafeteria() = default;
    static bool exec(std::string &outError);
    static LLONG getAnswer();
private:
    static bool addRange(LLONG l, LLONG r);
    static bool IDInRange(LLONG x);
    static void printRanges();
    static std::map<LLONG, LLONG> _ranges;
    static LLONG _availableIngredients;
};


#endif //ADVENT_OF_CODE_CAFETERIA_H