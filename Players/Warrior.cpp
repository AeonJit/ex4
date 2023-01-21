//
// Created by Amit and Tal on 16/01/2023.
//

#include "Warrior.h"
#include "../utilities.h"


const std::string Warrior::JOB_STRING = "Warrior";

  Warrior::Warrior(const std::string name) : Player(name) {};

   int Warrior::getAttackStrength() const 
   {
    return(m_force*MULTIPLY_FACTOR + m_level);
   }


   std::string Warrior::getJob() const 
{
    return JOB_STRING;
}