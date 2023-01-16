#include "Dragon.h"

const std::string Dragon::CARD_NAME = "DRAGON";

Dragon::Dragon() : Battle(DRAGON_FORCE, DRAGON_LOOT, DRAGON_DAMAGE)
{
}


std::ostream& Battle::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, m_force, m_damage, m_loot,true);
    printEndOfCardDetails(os);
    return os;
}