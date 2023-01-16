#include "assert.h"
#include "Player.h"
#include <string>

//Player constructor. inizialized by inizializetion list.
Player::Player(const std::string name, int maxHP, int force, int level,
		int coins, int HP):
	m_name(name),
	m_maxHP(maxHP),
	m_force(force),
	m_level(STARTING_LEVEL),
	m_coins(STARTING_COINS),
	m_HP(maxHP)
	{};

//copy consstructor. inizialize new Player object and give him the same data as the argument.
Player::Player(const Player &player) = default;

//Destructor.
Player::~Player() = default;

//Assignment Operator. 
Player &Player::operator=(const Player &) = default;


void Player::levelUp()
{
	assert(m_level >= 0 && m_level <= MAX_LEVEL);

	if (m_level >= MAX_LEVEL)
	{
		return;
	}
	else
	{
		m_level++;
	}
}

std::string Player::getName() const {
	return m_name;
}

int Player::getLevel() const
{
	assert(m_level <= MAX_LEVEL);
	return m_level;
}

void Player::buff(int amount)
{
	if (amount <= 0)
	{
		return;
	}

	m_force += amount;
}

void Player::weaken(int amount)
{
	if (amount <= 0)
	{
		return;
	}

	m_force -= amount;
	if(m_force < 0)
	{
		m_force = 0;
	}
}

void Player::heal(int amount)
{
	if (amount <= 0)
	{
		return;
	}
	else
	{
		m_HP = m_HP + amount;
		m_HP = (m_HP > m_maxHP ? m_maxHP : m_HP);	//if above max lower to max
	}
}

void Player::damage(int amount)
{
	if (amount <= 0)
	{
		return;
	}
	else
	{
		m_HP -= amount;
		m_HP = (m_HP < 0 ? 0 : m_HP);	//if below 0 hp raise to 0
	}
}


bool Player::isKnockedOut() const
{
	if (!m_HP)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::addCoins(int amount)
{
	if (amount < 0)
	{
		amount = 0;
	}

	m_coins += amount;
}


bool Player::pay(int amount)
{
	if (amount <= 0)
	{
		return true;
	}

	if (m_coins >= amount)
	{
		m_coins -= amount;
		return true;
	}
	else
	{
		return false;
	}
}

int Player::getAttackStrength() const
{
	return (m_force + m_level);
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os, player.m_name, player.getJob() , player.m_level, player.m_force, player.m_HP, player.m_coins);
    return os;
}