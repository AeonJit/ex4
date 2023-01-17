//
// Created by Amit and Tal on 16/01/2023.
//

#include "Healer.h"

 const std::string Healer::JOB_STRING = "Healer";

Healer::Healer(const std::string name) : Player(name){};

void Healer::heal(int amount)
{
	if (amount <= 0)
	{
		return;
	}
	else
	{
		m_HP = m_HP + MULTIPLY_FACTOR*amount;
		m_HP = (m_HP > m_maxHP ? m_maxHP : m_HP);	//if above max lower to max
	}
}


std::string Healer::getJob() const 
{
    return JOB_STRING;
}

void Healer::manaEncounter(){
	this->heal(MANA_HEAL_AMOUNT);
	printManaMessage(true);
}
