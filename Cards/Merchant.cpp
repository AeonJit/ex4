#include "Merchant.h"

//checking if the player gave right input ("0" / "1" / "2").
 bool validInput(std::string str)
 {  
    int choice;
    try{
        choice = std::stoi(str);
    }
    catch(const std::exception& e)
    {
        printInvalidInput();
        return false;
    }

    if(choice == Merchant::LEAVE_STORE || choice == Merchant::BUY_HP_POT ||
    choice == Merchant::BUY_FORCE_UPGRADE)
    {
        return true;
    }
    printInvalidInput();
    return false;
 }


//according to the player choose the cost of the boost change.
  const int Merchant::getCost(int type) 
 {
    if(type == Merchant::BUY_HP_POT)
    {
        return Merchant::HEALTH_POTION_PRICE;
    }
    if(type == Merchant::BUY_FORCE_UPGRADE)
    {
        return Merchant::FORCE_UPGRADE_PRICE;
    }
    return Merchant::PLAYER_DIDNT_BUY;
 }


 bool enoughCoins(const int choice , const Player& player)
 {
    const int playerCoins = player.getCoins();
    if(choice == Merchant::BUY_HP_POT)
    {
        if(playerCoins >= Merchant::getCost(choice))
        {
            return true;
        }
        return false;
    }
    if(choice == Merchant::BUY_FORCE_UPGRADE)
    {
        if(playerCoins >= Merchant::getCost(choice))
        {
            return true;
        }
        return false;
    }
    return true;
 }

//adding to player HP/FORCE and pay.
 void Merchant::playerGain(Player& player , const int choice) const
 {
    player.pay(getCost(choice));
    if(choice == BUY_HP_POT)
    {
        player.heal(HEALTH_GAIN);
    }
    else if (choice == BUY_FORCE_UPGRADE)
    {
        player.buff(FORCE_GAIN);
    }
    else 
    {
        //Player didnt buy nothing.
    }

 }



//the card action.
void Merchant::applyEncounter(Player& player) const{
    //starting messege.
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());

    //the buffer.
    std::string input ;

    //getting the input to check validity.
    do
    {
        std::getline(std::cin , input);
    }while(!validInput(input));
    //from here we can assume stoi will not throw
        const int choice = std::stoi(input);
        if(enoughCoins(choice,player))
        {
            //if the input is valid and the player has enough coins,print summmery.
            //dealing with the situation of not buying .it will print "player has paid 0 coins".
            playerGain(player,choice);
            printMerchantSummary(std::cout ,player.getName(),choice,getCost(choice));
        }
        else{
            printMerchantInsufficientCoins(std::cout);
            printMerchantSummary(std::cout ,player.getName(),LEAVE_STORE,LEAVE_STORE);
            //next player turn.
        }

}