//
// Created by angel on 2025-12-05.
//

#include "PrintingDepartment.h"

#include <fstream>
#include <iostream>

std::vector<std::vector<PrintingDepartment::position>> PrintingDepartment::_positions = std::vector<std::vector<position>>();

bool PrintingDepartment::exec(std::string &outError) {
    _positions.clear();
    _positions.push_back(std::vector<position>());
    std::ifstream input("04-input");

    if (!input) {
        outError = "Error opening file";
        return false;
    }

    std::string shelf;
    int i = 0;
    while (std::getline(input, shelf)) {
        setUpPositions(i++, shelf);
    }
    _positions.pop_back();

    //printRolls();

    return true;
}

int PrintingDepartment::getAnswer() {
    int tot_rolls = 0;
    int rolls;
    while ((rolls = getRolls()) > 0) {
        tot_rolls += rolls;
    }
    return tot_rolls;
}

void PrintingDepartment::setUpPositions(const int currentShelfID, const std::string & shelf) {
    _positions.push_back(std::vector<position>());
    for (int i = 0; i < shelf.size(); i++) {
        position currentPosition {static_cast<ITEM>(shelf[i]), 0};
        if (currentPosition.item == ITEM::ROLL) {
            if (currentShelfID != 0)
            {
                _positions[currentShelfID - 1][i].adjacent++;
                if (i + 1 < shelf.size()) {
                    _positions[currentShelfID - 1][i + 1].adjacent++;
                }
                if (i - 1 >= 0) {
                    _positions[currentShelfID - 1][i - 1].adjacent++;
                }
            }
            if (i - 1 >= 0) {
                _positions[currentShelfID][i - 1].adjacent++;
            }
        }
        if (currentShelfID != 0)
        {
            if (_positions[currentShelfID - 1][i].item == ITEM::ROLL) {
                currentPosition.adjacent++;
            }
            if (i + 1 < shelf.size() && _positions[currentShelfID - 1][i + 1].item == ITEM::ROLL) {
                currentPosition.adjacent++;
            }
            if (i - 1 >= 0 && _positions[currentShelfID - 1][i - 1].item == ITEM::ROLL) {
                currentPosition.adjacent++;
            }
        }
        if (i - 1 >= 0 && _positions[currentShelfID][i - 1].item == ITEM::ROLL) {
            currentPosition.adjacent++;
        }
        _positions[currentShelfID].push_back(currentPosition);
    }
}

void PrintingDepartment::updatePositions() {
    for (int i = 0; i < _positions.size(); i++) {
        for (int j = 0; j < _positions[i].size(); j++) {
            if (_positions[i][j].item == ITEM::REMOVED) {
                if (i - 1 >= 0) {
                    if (j - 1 >= 0) {
                        _positions[i - 1][j - 1].adjacent--;
                    }
                    _positions[i - 1][j].adjacent--;
                    if (j + 1 < _positions[i].size()) {
                        _positions[i - 1][j + 1].adjacent--;
                    }
                }
                if (i + 1 < _positions.size()) {
                    if (j - 1 >= 0) {
                        _positions[i + 1][j - 1].adjacent--;
                    }
                    _positions[i + 1][j].adjacent--;
                    if (j + 1 < _positions[i].size()) {
                        _positions[i + 1][j + 1].adjacent--;
                    }
                }
                if (j - 1 >= 0) {
                    _positions[i][j - 1].adjacent--;
                }
                if (j + 1 < _positions[i].size()) {
                    _positions[i][j + 1].adjacent--;
                }
            }
        }
    }
}

int PrintingDepartment::getRolls() {
    int rolls = 0;
    for (int i = 0; i < _positions.size(); i++) {
        for (int j = 0; j < _positions[i].size(); j++) {
            if (_positions[i][j].item == ITEM::ROLL && _positions[i][j].adjacent < 4) {
                rolls++;
                _positions[i][j].item = ITEM::REMOVED;
            } else if (_positions[i][j].item == ITEM::REMOVED) {
                _positions[i][j].item = ITEM::NOTHING;
            }
        }
    }
    updatePositions();
    return rolls;
}

void PrintingDepartment::printRolls() {
    for (const auto &shelf : _positions) {
        for (const auto &position : shelf) {
            std::cout << static_cast<char>(position.item) << " ";
        }
        std::cout << std::endl;
    }

    for (const auto &shelf : _positions) {
        for (const auto &position : shelf) {
            std::cout << position.adjacent << " ";
        }
        std::cout << std::endl;
    }
}
