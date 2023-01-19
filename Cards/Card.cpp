#include "Card.h"



std::ostream& operator<<(std::ostream& os, const Card& card){
    printCardDetails(os,card.getName());
    return os;
}
