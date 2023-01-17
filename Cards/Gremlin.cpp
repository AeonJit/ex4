#include "Gremlin.h"

const std::string Gremlin::CARD_NAME = "Gremlin";

std::string Gremlin::getName() const{
    return Gremlin::CARD_NAME;
}

Gremlin::Gremlin() : Battle(GREMLIN_FORCE, GREMLIN_LOOT, GREMLIN_DAMAGE)
{
}

