#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H
#include "Card.h"

class Battle : public Card{
    public:
    //Constructor
    Battle(int force, int loot, int damage); 

    //No def. constructor
    Battle() = delete; 
    //D'tor
    virtual ~Battle() = default;

    //Assign operator
    Battle& operator=(const Battle& sourceBattle) = delete; 
    //Copy constructor
    Battle(const Battle&) = delete;

//---------Methods----------------//

    void applyEncounter(Player& player) const override; //Overriding card's apply encounter.
    bool playerVictorious(Player& player) const;
    virtual void encounterLoss(Player& player) const; //Player is damaged/killed.
    void encounterWin(Player& player) const; //Gets loot



    protected:
    int m_force, m_loot, m_damage;

    virtual std::ostream& printCard(std::ostream& os) const override;
    
};

#endif //EX4_BATTLE_H