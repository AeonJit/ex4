#include "Mtmchkin.h"
#include <fstream>
#include "Exception.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Cards/Barfight.h"
#include "Cards/Battle.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"

#include <regex>



Mtmchkin::Mtmchkin(const std::string &fileName){
    printStartGameMessage(); //Welcome to the world of mtmchkin!
    //Scans the file and puts the stuff into m_cardsDeck
    int m_cardsAmount;
    vector<std::unique_ptr<Card>> m_cardsDeck;
    //Scans amount of players and puts into m_playerAmount
    deque<std::unique_ptr<Player>> m_actingPlayers;
    deque<std::unique_ptr<Player>> m_losers;
    deque<std::unique_ptr<Player>> m_winners;
    deque<std::unique_ptr<Player>> m_leaderboards;

    int m_playerAmount;
    int m_roundNum;
}

void Mtmchkin::scanPlayersSize(){
    printEnterTeamSizeMessage();
    //Scan mispar
    std::string input;
    bool scanSucceed = false;
    int numInput;
    while (!scanSucceed){
        std::getline(std::cin, input);
        try
        {
            numInput = std::stoi(input);
        }
        catch(const std::exception& e)
        {
            printInvalidTeamSize();
            continue;
        }
        if(numInput > MAX_PLAYERS || numInput < MIN_PLAYERS){
            printInvalidTeamSize();
            continue;
        }
        scanSucceed = true;
    }
    m_playerAmount = numInput;
}

void Mtmchkin::scanPlayers(){
    int playersInitialized = 0;
    std::regex inputPattern("^\\s*([a-zA-Z]{1,15})(\\s*)([a-zA-Z]+)\\s*$");
    //split to invalid name and invalid class

    //a group of 1-15 english letter characters (not case sensitive)
    //a group of zero or more spaces
    // a group of one or more english letter characters (not case sensitive)
    //Note we don't care about trailing spaces or leading spaces (after 2nd word or before 1st)
    std::regex jobPattern("^(Ninja|Warrior|Healer)$");


    while (playersInitialized < m_playerAmount)
    {   

        printInsertPlayerMessage();
        std::string input;
        std::getline(std::cin, input);
        std::smatch match;

        if (std::regex_match(input, match, inputPattern)) {
            std::string nameInput = match[1];
            std::string jobInput = match[3];
            if(!std::regex_match(jobInput, jobPattern)){
                printInvalidClass();
                continue;
            }
            else{
                jobInput Player(nameInput);
                //TODO: Construct player object of relevant class and add to actingPlayers deque
            }
        }
        
        else{//invalid input
            printInvalidName();
            continue;
        }
        

        
        
        playersInitialized++;
    }
    

}