#include "Mana.h"

const std::string Mana::CARD_NAME = "Mana";

std::string Mana::getName() const{
    return Mana::CARD_NAME;
}

void Mana::applyEncounter(Player& player) const{
    player.manaEncounter();
}