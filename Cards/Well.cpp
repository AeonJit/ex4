#include "Well.h"
#include "../Players/Ninja.h"


Well::Well(const std::string cardName) : Card(cardName){};
Well::Well() : Card("Well"){};

void Well::applyEncounter(Player& player) const{
    if ((dynamic_cast<Ninja*> (&player))){
        player.damage(WELL_DAMAGE);
    }
    printWellMessage((dynamic_cast<Ninja*> (&player)));
    
}


