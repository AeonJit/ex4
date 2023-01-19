#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"


class Barfight : public Card
{
public:
    static const std::string CARD_NAME;
    std::string getName() const;
    Barfight() = default;
    ~Barfight() = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight& other) = default;

    void applyEncounter(Player& player) const;

};

#endif //HW4_BARFIGHT_H