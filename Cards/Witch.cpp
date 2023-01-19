#include "Witch.h"

const std::string Witch::CARD_NAME = "Witch";

std::string Witch::getName() const{
    return Witch::CARD_NAME;
}

Witch::Witch() : Battle(WITCH_FORCE, WITCH_LOOT, WITCH_DAMAGE)
{
}

void Witch::encounterLoss(Player& player) const{
    player.damage(m_damage);
    player.weaken(WEAKEN_AMOUNT);
    printLossBattle(player.getName(),this->getName());
}


