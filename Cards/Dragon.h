#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H
#include "Battle.h"


class Dragon : public Battle {
    public:
    Dragon(const std::string cardName);
    Dragon();
    ~Dragon() = default;
    Dragon(const Dragon&) = default;
    Dragon& operator=(const Dragon& sourceDragon) = default;

    //std::ostream& printCard(std::ostream& os) const override;

    private:

    static const int DRAGON_FORCE = 25;
    static const int DRAGON_LOOT = 1000;
    static const int DRAGON_DAMAGE = Player::INITIAL_MAX_HP; //Will always kill defeated players, as required.
};

#endif //EX4_DRAGON_H