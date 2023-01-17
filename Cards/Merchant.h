#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H

#include "Card.h"


class Merchant : public Card
{
public:
    static const std::string NAME;
    Merchant() = default;
    ~Merchant() = default;
    Merchant(const Merchant&) = default;
    Merchant& operator=(const Merchant& other) = default;

    void applyEncounter(Player& player) const;

private:

    std::string getName() const;
    static const int HEALTH_POTION_PRICE = 5;
    static const int FORCE_UPGRADE_PRICE = 10;

};

#endif //HW4_MERCHANT_H