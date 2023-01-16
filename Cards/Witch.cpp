#include "Witch.h"

const std::string Witch::CARD_NAME = "WITCH";

Witch::Witch() : Battle(WITCH_FORCE, WITCH_LOOT, WITCH_DAMAGE)
{
}

void encounterLoss(Player& player) const{
    player.damage(m_damage);
    player.weaken(WEAKEN_AMOUNT);
    printLossBattle(player.getName(),(*this).getName());
}
