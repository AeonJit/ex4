#include "Treasure.h"

const std::string Treasure::CARD_NAME = "Treasure";

std::string Treasure::getName() const{
    return Treasure::CARD_NAME;
}

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(TREASURE_AMOUNT);
    printTreasureMessage();
}