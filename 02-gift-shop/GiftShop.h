//
// Created by angel on 2025-12-03.
//

#ifndef ADVENT_OF_CODE_GIFTSHOP_H
#define ADVENT_OF_CODE_GIFTSHOP_H
#include <map>
#include <string>
#include <vector>

using LLONG = long long;

class GiftShop {
public:
    GiftShop() = default;
    static bool exec(std::string &outError);
    static LLONG getAnswer();
private:
    struct range {
        LLONG start;
        LLONG end;
    };

    static range getRange(std::stringstream &range, std::string &outError);
    static std::map<LLONG, bool> getInvalidIDs(const range &range);
    static bool IDInUpperRange(LLONG id, LLONG end);
    static LLONG getNextID(LLONG id, int repeated);
    static LLONG sumInvalidIDs(const std::map<LLONG, bool> &invalidIDs);
    static LLONG _sumofInvalidIDs;
    static std::map<LLONG, bool> _invalidIDs;
};


#endif //ADVENT_OF_CODE_GIFTSHOP_H