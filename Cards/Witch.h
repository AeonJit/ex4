#ifndef EX4_WITCH_H
#define EX4_WITCH_H
#include "Battle.h"

class Witch : public Battle {
    public:

    Witch(const std::string cardName);
    Witch();
    ~Witch() = default;
    Witch(const Witch&) = default;
    Witch& operator=(const Witch& sourceWitch) = default;



    void encounterLoss(Player& player) const override;

    private:
    static const int WEAKEN_AMOUNT = 1;
    static const int WITCH_FORCE = 11;
    static const int WITCH_LOOT = 2;
    static const int WITCH_DAMAGE = 10;
};

#endif //EX4_WITCH_H