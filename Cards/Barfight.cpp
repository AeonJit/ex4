#include "Barfight.h"
#include "../Players/Warrior.h"


Barfight::Barfight(const std::string cardName) : Card(cardName){};

Barfight::Barfight():Card("Barfight"){};

void Barfight::applyEncounter(Player& player) const{
    if (!(dynamic_cast<Warrior*> (&player))){
        player.damage(BARFIGHT_DAMAGE);
    }
    printBarfightMessage((dynamic_cast<Warrior*> (&player)));
}



