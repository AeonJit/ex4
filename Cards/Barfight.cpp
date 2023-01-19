#include "Barfight.h"

void Barfight::applyEncounter(Player& player) const{
    player.barfightEncounter();
}

const std::string Barfight::CARD_NAME = "Barfight";

std::string Barfight::getName() const{
    return Barfight::CARD_NAME;
}