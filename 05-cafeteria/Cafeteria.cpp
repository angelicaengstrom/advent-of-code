//
// Created by angel on 2025-12-05.
//

#include "Cafeteria.h"

#include <fstream>
#include <iostream>
#include <sstream>

std::map<LLONG, LLONG> Cafeteria::_ranges = std::map<LLONG, LLONG>();
LLONG Cafeteria::_availableIngredients = 0;
static constexpr bool GET_ALL_VALID_IDS = true;

bool Cafeteria::exec(std::string &outError) {
    std::ifstream input("05-input");

    if (!input) {
        outError = "Error opening file";
        return false;
    }

    std::string range, lower, upper;
    while (std::getline(input, range)) {
        std::stringstream stream(range);
        if (std::getline(stream, lower, '-') && std::getline(stream, upper)) {
            if (!addRange(std::stoll(lower), std::stoll(upper))) {
                outError = "Error adding range " + lower + "-" + upper;
                return false;
            }
        } else {
            break;
        }
    }
    if (GET_ALL_VALID_IDS)
    {
        std::map<LLONG, LLONG>::iterator it;
        for (it = _ranges.begin(); it != _ranges.end(); it++) {
            _availableIngredients += (it->second + 1) - it->first;
        }
    }
    else {
        std::string ID;
        while (std::getline(input, ID)) {
            if (IDInRange(std::stoll(ID))) {
                _availableIngredients++;
            }
        }
    }
    return true;
}

LLONG Cafeteria::getAnswer() {
    return _availableIngredients;
}

bool Cafeteria::addRange(LLONG l, LLONG r) {
    if (l > r) return false;

    const auto it = _ranges.lower_bound(l);

    if (it != _ranges.begin()) {
        const auto prev = std::prev(it); // l1 < l
        if (prev->second >= l) { // r1 >= l
            l = prev->first;
            if (prev->second > r) { //r1 <= r
                r = prev->second;
            }
            _ranges.erase(prev);
        } // r1 < l
    }

    if (it != _ranges.end()) { // l2 > l
        if (it->first <= r) { // l2 <= r
            if (it->second > r) {
                r = it->second;
            }
            _ranges.erase(it);
        }
    }

    _ranges[l] = r;
    return true;
}

bool Cafeteria::IDInRange(LLONG x) {
    auto it = _ranges.upper_bound(x);
    if (it == _ranges.begin()) {
        return false;
    }
    --it;
    if (x <= it->second) {
        return true;
    }
    return false;
}

void Cafeteria::printRanges() {
    for (const auto &it : _ranges) {
        std::cout << it.first << "-" << it.second << std::endl;
    }
}
