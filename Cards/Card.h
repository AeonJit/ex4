//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Card_H
#define EX4_Card_H

#include "../Players/Player.h"
#include "../utilities.h"
#include <string>


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

    virtual std::ostream& printCard(std::ostream& os) const = 0;

   protected:

    virtual std::string getName() const = 0; 


};


#endif //EX4_Card_H