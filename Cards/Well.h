#ifndef HW4_WELL_H
#define HW4_WELL_H

#include "Card.h"


class Well : public Card
{
public:
    static const std::string NAME;
    Well() = default;
    ~Well() = default;
    Well(const Well&) = default;
    Well& operator=(const Well& other) = default;

    void applyEncounter(Player& player) const;

private:

    std::string getName() const;
};

#endif //HW4_well_H