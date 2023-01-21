//
// Created by Amit and Tal on 16/01/2023.
//
#ifndef EX4_Healer_H
#define EX4_Healer_H

#include "Player.h"

class Healer : public Player {
   public:
   /*
    * C'tor of Ninja class.
   */
  Healer(const std::string name);

   Healer() = delete;



    /*
    * Copy C'tor of Ninja class. base class ~ is virtual.
   */
   Healer(const Healer & ninja) = default;

   /*
   * Assigment Operator of Ninja class.
   *take data from an existing object to another existing object.
   */
   Healer & operator = (const Healer & ninja ) = default;
   
    /*
    * D'tor of Ninja class. base class ~ is virtual.
   */
     ~Healer() override = default;

    /*
     *adding hp to the Healer but twice then regular. .
    */
  void heal(int amount) override;


/*
 *Getting the class of the player.
 */
std::string getJob() const override;

static const std::string JOB_STRING;

};


#endif //EX4_Ninja_H