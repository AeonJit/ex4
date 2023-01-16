//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Card_H
#define EX4_Card_H

#include "Player.h"
#include "../utilities.h"

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.

enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card
*/


class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card() = default; //Abstract class

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;




    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;



    friend std::ostream& operator<<(std::ostream& os, const Card& card);


   protected:
    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    void printCard() const;
    virtual std::string getName() const = 0; 


};


#endif //EX4_Card_H