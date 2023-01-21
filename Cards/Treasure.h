#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H

#include "Card.h"


class Treasure : public Card
{
public:
    Treasure(const std::string cardName);
    Treasure() ;
    ~Treasure() = default;
    Treasure(const Treasure&) = default;
    Treasure& operator=(const Treasure& other) = default;
    void applyEncounter(Player& player) const;

private:

    static const int TREASURE_AMOUNT = 10;
};

#endif //HW4_TREASURE_H