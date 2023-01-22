#include "Mana.h"
#include "../Players/Healer.h"

Mana::Mana(const std::string cardName) : Card(cardName){};
Mana::Mana() : Card("Mana"){};

void Mana::applyEncounter(Player& player) const{
    if ((dynamic_cast<Healer*> (&player))){
        player.heal(MANA_HEAL);
    }
    printManaMessage((dynamic_cast<Healer*> (&player)));
   
}


