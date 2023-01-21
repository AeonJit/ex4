#ifndef EX4_GREMLIN_H
#define EX4_GREMLIN_H
#include "Battle.h"

class Gremlin : public Battle {
    public:
    Gremlin(const std::string cardName);
    Gremlin();
    ~Gremlin() = default;
    Gremlin(const Gremlin&) = default;
    Gremlin& operator=(const Gremlin& sourceGremlin) = default;


    private:

    static const int GREMLIN_FORCE = 5;
    static const int GREMLIN_LOOT = 2;
    static const int GREMLIN_DAMAGE = 10;
};
#endif