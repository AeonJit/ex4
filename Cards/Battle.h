#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
#include "Card.h"

class Battle : public Card{
    public:
    //Constructor
    Battle(int force, int loot, int damage ,const std::string cardName = "Battle"); 

    //No def. constructor
    Battle() ; 
    //D'tor
    virtual ~Battle() = default;

    //Assign operator
    Battle& operator=(const Battle& sourceBattle) = delete; 
    //Copy constructor
    Battle(const Battle&) = delete;

//---------Methods----------------//

    void applyEncounter(Player& player) const override; 
    bool playerVictorious(Player& player) const;
    virtual void encounterLoss(Player& player) const; //Player is damaged/killed.
    void encounterWin(Player& player) const; //Gets loot



    protected:
    int m_force, m_loot, m_damage;

    std::ostream& printCard(std::ostream& os) const override;
};

#endif //EX4_BATTLE_H