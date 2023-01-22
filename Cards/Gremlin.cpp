#include "Gremlin.h"


Gremlin::Gremlin(const std::string cardName) :  Battle(GREMLIN_FORCE, GREMLIN_LOOT, GREMLIN_DAMAGE, cardName){};
Gremlin::Gremlin() : Battle(GREMLIN_FORCE, GREMLIN_LOOT, GREMLIN_DAMAGE, "Gremlin")
{
}

