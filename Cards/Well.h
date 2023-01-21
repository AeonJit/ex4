#ifndef HW4_WELL_H
#define HW4_WELL_H

#include "Card.h"


class Well : public Card
{
public:
    Well(const std::string cardName);
    Well();
    ~Well() = default;
    Well(const Well&) = default;
    Well& operator=(const Well& other) = default;

    void applyEncounter(Player& player) const;
    

private:

static const int WELL_DAMAGE = 10;
};

#endif //HW4_well_H