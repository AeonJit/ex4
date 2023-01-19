#ifndef HW4_WELL_H
#define HW4_WELL_H

#include "Card.h"


class Well : public Card
{
public:
    static const std::string CARD_NAME;
    std::string getName() const;

    Well() = default;
    ~Well() = default;
    Well(const Well&) = default;
    Well& operator=(const Well& other) = default;

    void applyEncounter(Player& player) const;
    

private:

};

#endif //HW4_well_H