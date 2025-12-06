#include <iostream>

#include "01-secret-entrance/SecretEntrance.h"
#include "02-gift-shop/GiftShop.h"
#include "03-lobby/Lobby.h"
#include "04-printing-department/PrintingDepartment.h"
#include "05-cafeteria/Cafeteria.h"
#include "06-trash-compactor/TrashCompactor.h"

int main() {

    std::string outError;
    if (!SecretEntrance::exec(outError)) {
        std::cerr << "SecretEntrance: " << outError << std::endl;
        return -1;
    }

    std::cout << "SecretEntrance::getAnswer(): " << SecretEntrance::getAnswer() << std::endl;

    if (!GiftShop::exec(outError)) {
        std::cerr << "GiftShop:" << outError << std::endl;
        return -1;
    }
    std::cout << "GiftShop::getAnswer(): " << GiftShop::getAnswer() << std::endl;

    if (!Lobby::exec(outError)) {
        std::cerr << "Lobby:" << outError << std::endl;
        return -1;
    }
    std::cout << "Lobby::getAnswer(): " << Lobby::getAnswer() << std::endl;

    if (!PrintingDepartment::exec(outError)) {
        std::cerr << "PrintingDepartment:" << outError << std::endl;
        return -1;
    }
    std::cout << "PrintingDepartment::getAnswer(): " << PrintingDepartment::getAnswer() << std::endl;

    if (!Cafeteria::exec(outError)) {
        std::cerr << "Cafeteria:" << outError << std::endl;
        return -1;
    }
    std::cout << "Cafeteria::getAnswer(): " << Cafeteria::getAnswer() << std::endl;

    if (!TrashCompactor::exec(outError)) {
        std::cerr << "TrashCompactor:" << outError << std::endl;
        return -1;
    }
    std::cout << "TrashCompactor::getAnswer(): " << TrashCompactor::getAnswer() << std::endl;
    return 0;
}
