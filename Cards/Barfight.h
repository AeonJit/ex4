#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"


class Barfight : public Card
{
public:
    static const std::string NAME;
    Barfight() = default;
    ~Barfight() = default;
    Barfight(const Barfight&) = default;
    Barfight& operator=(const Barfight& other) = default;

    void applyEncounter(Player& player) const;

private:

    std::string getName() const;
};

#endif //HW4_BARFIGHT_H