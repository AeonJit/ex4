#ifndef HW4_MANA_H
#define HW4_MANA_H

#include "Card.h"


class Mana : public Card
{
public:
    Mana(const std::string cardName);
    Mana();
    ~Mana() = default;
    Mana(const Mana&) = default;
    Mana& operator=(const Mana& other) = default;

    void applyEncounter(Player& player) const;

private:
    static const int MANA_HEAL = 10;
};

#endif //HW4_mana_H