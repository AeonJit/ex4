#ifndef HW4_MANA_H
#define HW4_MANA_H

#include "Card.h"


class Mana : public Card
{
public:
    static const std::string CARD_NAME;
    std::string getName() const;
    Mana() = default;
    ~Mana() = default;
    Mana(const Mana&) = default;
    Mana& operator=(const Mana& other) = default;

    void applyEncounter(Player& player) const;
};

#endif //HW4_mana_H