#include <iostream>
#include "01-secret-entrance/SecretEntrance.h"

int main() {

    std::string outError;
    if (!SecretEntrance::exec(outError)) {
        std::cerr << outError << std::endl;
        return -1;
    }

    std::cout << "SecretEntrance::getAnswer(): " << SecretEntrance::getAnswer() << std::endl;
    return 0;
}