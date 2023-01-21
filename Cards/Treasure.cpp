#include "Treasure.h"

Treasure::Treasure(const std::string cardName) : Card(cardName){};
Treasure::Treasure() :Card("Treasure"){};

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(TREASURE_AMOUNT);
    printTreasureMessage();
}