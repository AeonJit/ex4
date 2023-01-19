#include "Well.h"

const std::string Well::CARD_NAME = "Well";


void Well::applyEncounter(Player& player) const{
    player.wellEncounter();
}

std::string Well::getName() const{
    return Well::CARD_NAME;
}