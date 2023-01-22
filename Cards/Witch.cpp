#include "Witch.h"



 Witch::Witch(const std::string cardName) :Battle(WITCH_FORCE, WITCH_LOOT, WITCH_DAMAGE ,cardName){};

Witch::Witch() : Battle(WITCH_FORCE, WITCH_LOOT, WITCH_DAMAGE, "Witch")
{
}

void Witch::encounterLoss(Player& player) const{
    player.damage(m_damage);
    player.weaken(WEAKEN_AMOUNT);
    printLossBattle(player.getName(),this->getName());
}


