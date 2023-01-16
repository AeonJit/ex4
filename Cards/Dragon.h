#ifndef EX4_BATTLE_H
#include "Battle.h"
#define EX4_BATTLE_H
#endif
#define MAX_HP 100

class Dragon : public Battle {
    public:

    static const std::string CARD_NAME;
    Dragon();
    ~Dragon() = default;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon& sourceDragon) = default;


    std::ostream& printCard(std::ostream& os) const override;

    private:

    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_DAMAGE = MAX_HP; //Will always kill defeated players, as required.
};