#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"


class Barfight : public Card
{
public:
    Barfight(const std::string cardName);
    Barfight();
    ~Barfight() override  = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight& other) = default;

    void applyEncounter(Player& player) const;
private:
    static const int BARFIGHT_DAMAGE = 10;
};

#endif //HW4_BARFIGHT_H