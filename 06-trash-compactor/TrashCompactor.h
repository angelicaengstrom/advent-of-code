//
// Created by angel on 2025-12-06.
//

#ifndef ADVENT_OF_CODE_TRASHCOMPACTOR_H
#define ADVENT_OF_CODE_TRASHCOMPACTOR_H

#include <string>
#include <vector>

using LLONG = long long;

class TrashCompactor {
public:
    TrashCompactor() = default;
    static bool exec(std::string &outError);
    static LLONG getAnswer();
private:
    enum class OPERATION {
        ADDITION = '+',
        MULTIPLICATION = '*',
        INVALID = 999
    };
    static bool falseCephalopodMath(std::vector<std::stringstream> &problems, std::string &outError);
    static bool realCephalopodMath(std::vector<std::stringstream> &problems, std::string &outError);
    static LLONG getNumber(std::vector<std::stringstream> &problems);
    static LLONG _grandTotal;
};


#endif //ADVENT_OF_CODE_TRASHCOMPACTOR_H