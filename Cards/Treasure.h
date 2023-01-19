#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H

#include "Card.h"


class Treasure : public Card
{
public:
    static const std::string CARD_NAME;
    Treasure() = default;
    ~Treasure() = default;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure& other) = default;
    std::string getName() const;
    void applyEncounter(Player& player) const;

private:

    static const int TREASURE_AMOUNT = 10;
};

#endif //HW4_TREASURE_H