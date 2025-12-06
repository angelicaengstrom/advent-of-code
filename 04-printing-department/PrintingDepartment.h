//
// Created by angel on 2025-12-05.
//

#ifndef ADVENT_OF_CODE_PRINTINGDEPARTMENT_H
#define ADVENT_OF_CODE_PRINTINGDEPARTMENT_H

#include <string>
#include <vector>

class PrintingDepartment {
public:

    PrintingDepartment() = default;
    static bool exec(std::string &outError);
    static int getAnswer();



private:
    enum class ITEM {
        ROLL = '@',
        NOTHING = '.',
        REMOVED = 'x',
        INVALID = 999
    };
    struct position {
        ITEM item;
        int adjacent;
        int shelf;
        int pos;
    };
    static void setUpPositions(int currentShelfID, const std::string & shelf);
    static void updatePositions();
    static int getRolls();
    static void printRolls();
    static std::vector<std::vector<position>> _positions;
};


#endif //ADVENT_OF_CODE_PRINTINGDEPARTMENT_H