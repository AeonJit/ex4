#include "Battle.h"

Battle::Battle(int force, int loot, int damage) : m_force(force), m_loot(loot), m_damage(damage){}


bool Battle::playerVictorious(Player& player) const{
    return (player.getAttackStrength() >= m_force);
}

void Battle::applyEncounter(Player& player) const{
    if((*this).playerVictorious(player)){
        (*this).encounterWin(player);
    }
    else{
        (*this).encounterLoss(player);
    }
    
}

void Battle::encounterWin(Player& player) const{
    player.addCoins(m_loot);
    player.levelUp();
    printWinBattle(player.getName(),(*this).getName());
}

void Battle::encounterLoss(Player& player) const{
    player.damage(m_damage);
    printLossBattle(player.getName(),(*this).getName());
}

std::ostream& Battle::printCard(std::ostream& os) const{
    printCardDetails(os, getName());
    printMonsterDetails(os, m_force, m_damage, m_loot,false);
    printEndOfCardDetails(os);
    return os;
}