//
// Created by Amit and Tal on 16/01/2023.
//

#include "Ninja.h"

 const std::string Ninja::JOB_STRING = "Ninja";

Ninja::Ninja(const std::string name) : Player(name){};

void Ninja::addCoins(int amount) 
{

     if (amount < 0)
	{
		amount = 0;
	}
    //Ninja special power.
	m_coins += amount*MULTIPLY_FACTOR;
}

std::string Ninja::getJob() const 
{
    return JOB_STRING;
}

