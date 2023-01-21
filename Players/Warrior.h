//
// Created by Amit and Tal on 16/01/2023.
//
#ifndef EX4_Warrior_H
#define EX4_Warrior_H

#include "Player.h"

class Warrior : public Player {
    public:

    /*
    * C'tor of Warrior class.
   */
  Warrior(const std::string name);

   /*
    * Copy C'tor of Warrior class. base class ~ is virtual.
   */
   Warrior(const Warrior & warrior) = default;

    /*
   * Assigment Operator of Warrior class.
   *take data from an existing object to another existing object.
   */
  Warrior &operator=(const Warrior & warrior ) = default;
   
    /*
    * D'tor of Warrior class. base class ~ is virtual.
   */
     ~Warrior() override = default;

    /*
     *Get the attack strength of the warrior. 
     but diffrently from the other kind of players his force = 2*force. 
    */
   int getAttackStrength()  const override;

   


   /*
    *Printing Warrior player details. outside function that must get to the private fields of the class.
   */
 friend void printPlayerDetails(std::ostream &os, const std::string &name, const std::string &job, int level, int force, int HP, int coins);

/*
 *Getting the class of the player.
 */
std::string getJob() const override ;

  static const std::string JOB_STRING;

};









#endif //EX4_Warrior_H