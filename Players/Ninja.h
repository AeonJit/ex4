//
// Created by Amit and Tal on 16/01/2023.
//
#ifndef EX4_Ninja_H
#define EX4_Ninja_H

#include "Player.h"

class Ninja : public Player {
   public:
   /*
    * C'tor of Ninja class.
   */
  Ninja(const std::string name);

  Ninja() = delete;



    /*
    * Copy C'tor of Ninja class. base class ~ is virtual.
   */
  Ninja(const Ninja & ninja) = default;

   /*
   * Assigment Operator of Ninja class.
   *take data from an existing object to another existing object.
   */
   
   Ninja & operator = (const Ninja & ninja ) = default;
   
    /*
    * D'tor of Ninja class. base class ~ is virtual.
   */
    ~Ninja() override = default;

    /*
     *Adding coins to Ninja player is diffrenet from other player. he gets 2 times coins then usuall.
     so we implenting is own function .
    */
  void addCoins(int amount) override;

  

/*
 *Getting the class of the player.
 */
std::string getJob() const override ;

static const std::string JOB_STRING ;


};


#endif //EX4_Ninja_H