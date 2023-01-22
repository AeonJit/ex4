#include "Dragon.h"


Dragon::Dragon(const std::string cardName) : Battle(DRAGON_FORCE, DRAGON_LOOT, DRAGON_DAMAGE,cardName){};

Dragon::Dragon() : Battle(DRAGON_FORCE, DRAGON_LOOT, DRAGON_DAMAGE, "Dragon")
{
}



/* hurani maybe? no.

std::ostream& Dragon::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, m_force, m_damage, m_loot,true);
    printEndOfCardDetails(os);
    return os;
}*/