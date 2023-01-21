#include "Card.h"


Card::Card(const std::string cardName) : m_cardName(cardName){};

std::string Card::getName() const{
    return m_cardName;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    printCardDetails(os,card.getName());
    return os;
}


std::ostream& Card::printCard(std::ostream& os) const{
    printCardDetails(os,this->getName());
    printEndOfCardDetails(os);
    return os;
}