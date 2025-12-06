//
// Created by angel on 2025-12-03.
//

#include "GiftShop.h"
#include <fstream>
#include <iostream>
#include <sstream>

LLONG GiftShop::_sumofInvalidIDs = 0;
std::map<LLONG, bool> GiftShop::_invalidIDs = std::map<LLONG, bool>();

bool GiftShop::exec(std::string &outError) {
    std::ifstream input("02-input");

    if (!input) {
        outError = "Error opening file";
        return false;
    }

    std::string range;
    while (std::getline(input, range, ',')) {
        std::stringstream stream(range);
        getInvalidIDs(getRange(stream, outError));
        if (!outError.empty()) {
            return false;
        }
    }

    _sumofInvalidIDs = sumInvalidIDs(_invalidIDs);

    return true;
}

LLONG GiftShop::getAnswer() {
    return _sumofInvalidIDs;
}

GiftShop::range GiftShop::getRange(std::stringstream &range, std::string &outError) {
    std::string upper, lower;
    if (!std::getline(range, lower, '-') || !std::getline(range, upper)) {
        outError = "Invalid range";
        return {};
    }

    return GiftShop::range{ std::stoll(lower), std::stoll(upper)};
}

std::map<LLONG, bool> GiftShop::getInvalidIDs(const range &range) {
    for (int i = 2; i < std::to_string(range.end).size() + 1; i++) {
        LLONG id = getNextID(range.start, i);
        while (IDInUpperRange(id, range.end)) {
            _invalidIDs.insert({ id, true });
            id = getNextID(id + 1, i);
        }
    }

    return _invalidIDs;
}

bool GiftShop::IDInUpperRange(const LLONG id, const LLONG end) {
    return id <= end;
}

LLONG GiftShop::getNextID(const LLONG id, int repeated) {
    std::string next = std::to_string(id);
    int remainder = next.size() % repeated;
    if (remainder != 0) {
        next = std::string(next.size() + remainder, '0');
        next[0] = '1';
    }

    std::string subID = next.substr(0, next.size() / repeated);
    do {
        next = "";
        for (int i = 0; i < repeated; i++) {
            next += subID;
        }
        subID = std::to_string(std::stoll(subID) + 1);
    } while (id > std::stoll(next));

    return std::stoll(next);
}

LLONG GiftShop::sumInvalidIDs(const std::map<LLONG, bool> &invalidIDs) {
    LLONG sum = 0;
    for (const auto &invalidID : invalidIDs) {
        if (invalidID.second) {
            sum += invalidID.first;
        }
    }
    return sum;
}
