//
// Created by angel on 2025-12-06.
//

#include "TrashCompactor.h"

#include <sstream>
#include <fstream>
#include <iostream>

LLONG TrashCompactor::_grandTotal = 0;
static constexpr bool CEPHALOPOD_MATH = true;

bool TrashCompactor::exec(std::string &outError) {
    std::ifstream input("06-input");

    if (!input) {
        outError = "Error opening file";
        return false;
    }

    std::string numbers;
    std::vector<std::stringstream> problems;
    while (std::getline(input, numbers)) {
            problems.push_back(std::stringstream(numbers));
    }

    if (CEPHALOPOD_MATH)
        return realCephalopodMath(problems, outError);

    return falseCephalopodMath(problems, outError);
}

LLONG TrashCompactor::getAnswer() {
    return _grandTotal;
}

bool TrashCompactor::falseCephalopodMath(std::vector<std::stringstream> &problems, std::string &outError) {
    char operationChar;
    while (problems.back() >> operationChar) {
        const auto operation = static_cast<OPERATION>(operationChar);
        LLONG output = 0;
        if (problems.front() >> output) {
            LLONG number = 0;
            for (int i = 1; i < problems.size() - 1; ++i) {
                if (problems[i] >> number) {
                    if (operation == OPERATION::ADDITION) {
                        output += number;
                    } else if (operation == OPERATION::MULTIPLICATION) {
                        output *= number;
                    } else {
                        outError = "Error parsing operation";
                        return false;
                    }
                } else {
                    outError = "Error parsing number";
                    return false;
                }
            }
        } else {
            outError = "Error parsing number";
            return false;
        }

        _grandTotal += output;
    }
    return true;
}

bool TrashCompactor::realCephalopodMath(std::vector<std::stringstream> &problems, std::string &outError) {
    char operationChar;
    while (problems.back() >> operationChar) {
        const auto operation = static_cast<OPERATION>(operationChar);
        LLONG output = getNumber(problems);
        LLONG number = 0;
        while ((number = getNumber(problems)) > 0) {
            if (operation == OPERATION::ADDITION) {
                output += number;
            } else if (operation == OPERATION::MULTIPLICATION) {
                output *= number;
            }
        }
        _grandTotal += output;
    }
    return true;
}

LLONG TrashCompactor::getNumber(std::vector<std::stringstream> &problems) {
    std::string number = "0";
    char digit;
    for (int i = 0; i < problems.size() - 1; ++i) {
        if (problems[i] >> std::noskipws >> digit) {
            if (isdigit(digit)) {
                number += digit;
            }
        }
    }
    return std::stoll(number);
}
