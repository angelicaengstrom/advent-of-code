//
// Created by angel on 2025-12-04.
//

#include "Lobby.h"

#include <fstream>
#include <iostream>

static constexpr int LABELS = 12;
LLONG Lobby::_sumOutputJoltages = 0;

bool Lobby::exec(std::string &outError) {
    std::ifstream input("03-input");

    if (!input) {
        outError = "Error opening file";
        return false;
    }

    std::string bank;
    while (std::getline(input, bank)) {
        _sumOutputJoltages += getLargestJoltage(bank);
    }

    return true;
}

LLONG Lobby::getAnswer() {
    return _sumOutputJoltages;
}

LLONG Lobby::getLargestJoltage(const std::string &bank) {
    std::string jolts;
    int l = 0;
    for (int i = 1; i <= LABELS; i++) {
        for (int j = l + 1; j < bank.length() - LABELS + i; j++) {
            if (bank[l] < bank[j]) {
                l = j;
            }
        }
        jolts += bank[l++];
    }
    return std::stoll(jolts);
}
