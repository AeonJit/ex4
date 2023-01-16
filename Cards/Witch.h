#ifndef EX4_BATTLE_H
#include "Battle.h"
#define EX4_BATTLE_H
#endif

class Witch : public Battle {
    public:

    static const std::string CARD_NAME;
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