#ifndef EX4_BATTLE_H
#include "Battle.h"
#define EX4_BATTLE_H
#endif

class Gremlin : public Battle {
    public:

    static const std::string CARD_NAME;
    Gremlin();
    ~Gremlin() = default;
    Gremlin(const Gremlin&) = default;
    Gremlin& operator=(const Gremlin& sourceGremlin) = default;


    private:

    static const int GREMLIN_FORCE = 5;
    static const int GREMLIN_LOOT = 2;
    static const int GREMLIN_DAMAGE = 10;
};