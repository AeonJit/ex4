
#include "Mtmchkin.h"
#include "Exception.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Players/Healer.h"
#include "Cards/Barfight.h"
#include "Cards/Battle.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"

#include <fstream>
#include <regex>
#include <memory>



Mtmchkin::Mtmchkin(const std::string &fileName) : m_roundNum(STARTING_ROUND), 
m_indexCurrentCard(FIRST_INDEX)
 {
    printStartGameMessage(); //Welcome to the world of mtmchkin!

    //Scans amount of players and puts into m_playerAmount
     m_playerAmount = scanPlayersSize();
     scanPlayers();
    //Scans the file and puts the stuff into m_cardsDeck
     m_cardsAmount = scanCards(fileName);
   
}

//getting size of players and check (2-6).
int Mtmchkin::scanPlayersSize(){
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
   return numInput;
}


void Mtmchkin::scanPlayers(){
    int playersInitialized = 0;

        //a group of 1-15 english letter characters (not case sensitive)
    //a group of zero or more spaces
    // a group of one or more english letter characters (not case sensitive)
    //Note we don't care about trailing spaces or leading spaces (after 2nd word or before 1st)
    std::regex inputPattern("^\\s*([a-zA-Z]{1,15})(\\s*)(\\w+)\\s*$");
    //******split to invalid name and invalid class******\\


    std::regex jobPattern("^(Ninja|Warrior|Healer)$");


    while (playersInitialized < m_playerAmount)
    {   
        printInsertPlayerMessage();
        std::string input;
        std::getline(std::cin, input);
        std::smatch match;

        if (std::regex_match(input, match, inputPattern))
         {
            std::string nameInput = match[1];
            std::string jobInput = match[3];
            if(!std::regex_match(jobInput, jobPattern)){
                printInvalidClass();
                continue;
            }
            addPlayer(nameInput,jobInput);
        }
        
        else{//invalid name
            printInvalidName();
            continue;
        }
        
        playersInitialized++;
    }
}

void Mtmchkin::addPlayer(const std::string& nameInput ,const std::string& jobInput)
{   //We can assume jobInput is valid
    if(jobInput.compare(Ninja::JOB_STRING))
    {
        addNinja(nameInput);
    }
    else if(jobInput.compare(Warrior::JOB_STRING))
    {
        addWarrior(nameInput);
    }
    else{ //thus we can assume only option left is healer
        addHealer(nameInput);
    }
    
}
void Mtmchkin::addNinja(const std::string& name)
{
   std::unique_ptr<Player> ninja(new Ninja(name));
   m_actingPlayers.push_back(std::move(ninja));

}
void Mtmchkin::addHealer(const std::string& name)
{   
    std::unique_ptr<Player> healer(new Healer(name));
    m_actingPlayers.push_back(std::move(healer)); 
    
}
void Mtmchkin::addWarrior(const std::string& name)
{
    std::unique_ptr<Player> warrior(new Warrior(name));
    m_actingPlayers.push_back(std::move(warrior)); 
    
}

int Mtmchkin::scanCards(const std::string fileName)
{
   //open file
   std::ifstream file(fileName);
   if(!file) //Invalid location for file
   {
    throw DeckFileNotFound();
   } 
   
   if(file.peek() == std::ifstream::traits_type::eof()){ //Ensuring file isn't empty
    throw DeckFileInvalidSize();
   }
   
   std::string getCard;
   int lineCounter = 0;
   int cardCounter = 0;
   std::regex CardPattern("^(Mana|Gremlin|Dragon|Merchant|Treasure|Well|Witch|Barfight|)$");
   //TODO: how to deal with fucking spaces in the middle start or end fo deck file??


   //reading the file until EOF line by line and add to cards vector(of unique_ptr<Card>)
   // according to the input.
   while(!file.eof())
   {
    std::getline(file,getCard);
    //counter lines to know in which line there is an error to throw.
    lineCounter++;
    if(std::regex_match(getCard,CardPattern)) //If one of card names
    {   
        cardCounter++;
        addToCardVector(getCard);
    }
    else
    {
        DeckFileFormatError formatError(lineCounter);
        throw formatError;
    }
   }
   //checkin min size of cards deck.
   if(m_cardsAmount < MIN_CARDS)
   {
     throw DeckFileInvalidSize();
   }
   return cardCounter;
}


void Mtmchkin::deckAddBarfight(){
    std::unique_ptr<Card> card(new Barfight());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddDragon(){
    std::unique_ptr<Card> card(new Dragon());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddGremlin(){
    std::unique_ptr<Card> card(new Gremlin());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddMana(){
    std::unique_ptr<Card> card(new Mana());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddMerchant(){
    std::unique_ptr<Card> card(new Merchant());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddTreasure(){
    std::unique_ptr<Card> card(new Treasure());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddWell(){
    std::unique_ptr<Card> card(new Well());
    m_cardsDeck.push_back(std::move(card)); 
    
}

void Mtmchkin::deckAddWitch(){
    std::unique_ptr<Card> card(new Witch());
    m_cardsDeck.push_back(std::move(card)); 
    
}


//maping the input and adding to the vector the right type of unique_ptr<Card>.
void Mtmchkin::addToCardVector(const std::string& input)
{
    //We can assume input has name one of cards
try{   
    if(input.compare("Well"))
    {
        deckAddWell();
    }
    else if(input.compare("Mana"))
    {
       deckAddMana();
    }
     else if(input.compare("Witch"))
    {
       deckAddWitch();
    }
     else if(input.compare("Dragon"))
    {
        deckAddDragon();     
    }
     else if(input.compare("Barfight"))
    {
        deckAddBarfight(); 
    }
     else if(input.compare("Merchant"))
    {
        deckAddMerchant();     
    }
     else if(input.compare("Treasure"))
    {
        deckAddTreasure();        
    }
     else if(input.compare("Gremlin"))
    {
        deckAddGremlin();         
    }
    }

    catch(std::bad_alloc& e){
        //Game is killed.
        
    }
}


int Mtmchkin::getNumberOfRounds() const
{
    return m_roundNum;
}

void Mtmchkin::printDequeLeaderboards(const deque<std::unique_ptr<Player>>& playerDeque, int& curRank)const {
    for (int i = 0; i < playerDeque.size(); ++i)
    {
        printPlayerLeaderBoard(curRank,*playerDeque[i]);
        curRank++;
    }
}


void Mtmchkin::printLeaderBoard()const{
    printLeaderBoardStartMessage();
    int curRank = 1;
    printDequeLeaderboards(m_winners, curRank); //First winner will be printed first etc
    printDequeLeaderboards(m_actingPlayers, curRank);
    //Remember to add losers from the back
    printDequeLeaderboards(m_losers, curRank);
}

//if there is no acting players game over.
bool Mtmchkin::isGameOver() const
{   
    if(m_actingPlayers.size() == NO_ACTING_PLAYERS && getNumberOfRounds() != STARTING_ROUND)
    {
        return true;
    }
    return false;
}

//The Game!
void Mtmchkin::playRound()
{   printRoundStartMessage(m_roundNum);
    int activePlayers = m_actingPlayers.size();
    std::unique_ptr<Card> currentCard = std::move(m_cardsDeck[m_indexCurrentCard]);
    
    
    while(activePlayers != EVERY_ONE_PLAY)
    {
         std::unique_ptr<Player> currentPlayer = std::move(m_actingPlayers.front());
      
         m_actingPlayers.pop_front();

         printTurnStartMessage((*currentPlayer).getName());


         (*currentCard).applyEncounter(*currentPlayer);
         
         
         if(currentPlayer->isKnockedOut()){
            m_losers.push_front(std::move(currentPlayer));
         }
         else if( currentPlayer->getLevel() == Player::MAX_LEVEL){
            m_winners.push_back(std::move(currentPlayer));
         }
         else {
            m_actingPlayers.push_back(std::move(currentPlayer));
         }
         
         m_indexCurrentCard = (m_indexCurrentCard+1) % (m_cardsDeck.size());
         activePlayers--;

    }
    m_roundNum++;

    if(isGameOver())
        //Gameover
    {
        printGameEndMessage();
    }
    
    
}



