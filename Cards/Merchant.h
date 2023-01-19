//
// Created by Amit and Tal on 16/01/2023.
//
#ifndef EX4_Merchant_H
#define EX4_Merchantsa_H

#include "Card.h"


//is derived from card
class Merchant : public Card
{
public:

    enum Choice {LEAVE_STORE, BUY_HP_POT  ,BUY_FORCE_UPGRADE};
    
    static const std::string NAME;

    //constructor , copy constructor , = , destructor .
    Merchant() = default;
    ~Merchant() = default;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant& other) = default;
   
    //aplly card action.
    void applyEncounter(Player& player) const;
    
    void playerGain(Player& player , const int choice) const;

    static const int getCost(int type) ;

private:

    //costs for every player Choice.
    static const int HEALTH_POTION_PRICE = 5;
    static const int FORCE_UPGRADE_PRICE = 10;
    static const int PLAYER_DIDNT_BUY = 0;

    //Gains
    static const int HEALTH_GAIN = 1;
    static const int FORCE_GAIN = 1;

};

//checking valid input and player coins.
 bool validInput(std::string str);
 bool enoughCoins(const int choice , const Player& player);


#endif //HW4_MERCHANT_H