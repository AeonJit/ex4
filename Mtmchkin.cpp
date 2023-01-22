
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



Mtmchkin::Mtmchkin(const std::string &fileName)  
 {
     m_roundNum= STARTING_ROUND ;
    printStartGameMessage(); //Welcome to the world of mtmchkin!

    //Scans amount of players and puts into m_playerAmount
     m_playerAmount = scanPlayersSize();
     scanPlayers();
    //Scans the file and puts the stuff into m_cardsDeck
     scanCards(fileName);
   
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


    std::regex inputPattern("^\\s*([a-zA-Z]{1,15})(\\s*)(\\w+)\\s*$");
    //This pattern expects a name made of up to 15 english letters
    //it disregards spaces, and has no requirments for the 2nd word

    std::regex jobPattern("^(Ninja|Warrior|Healer)$");
    //This pattern expects one of the 3 valid classes in our game

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
                //If 2nd pattern didn't match it means the class was wrongly inputted and we retry
                printInvalidClass();
                continue;
            }
            addPlayer(nameInput,jobInput);
        }
        
        else{ //if no match it means the first pattern failed aka wrong name input
            printInvalidName();
            continue;
        }
        
        playersInitialized++;
    }
}

void Mtmchkin::addPlayer(const std::string& nameInput ,const std::string& jobInput)
{   //Here we can assume jobInput is valid
    if(jobInput == Ninja::JOB_STRING)
    {
        addNinja(nameInput);
    }
    else if(jobInput == Warrior::JOB_STRING)
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


   //reading the file until EOF line by line and add to cards deque(of unique_ptr<Card>)
   // according to the input.
   while(!file.eof())
   {
    std::getline(file,getCard);
    //counter lines to know in which line there is an error to throw.
    lineCounter++;
    if(std::regex_match(getCard,CardPattern)) //If one of card names
    {   
        cardCounter++;
        addToCardDeque(getCard);
    }
    else
    {
        throw DeckFileFormatError(lineCounter);
    }
   }
   //checkin min size of cards deck.
   if(cardCounter < MIN_CARDS)
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
void Mtmchkin::addToCardDeque(const std::string& input)
{
    //We can assume input has name one of cards
    try{   
        if(input == "Well")
        {
            deckAddWell();
        }
        else if(input == "Mana")
        {
        deckAddMana();
        }
        else if(input == "Witch")
        {
        deckAddWitch();
        }
        else if(input == "Dragon")
        {
            deckAddDragon();     
        }
        else if(input== "Barfight")
        {
            deckAddBarfight(); 
        }
        else if(input == "Merchant")
        {
            deckAddMerchant();     
        }
        else if(input == "Treasure")
        {
            deckAddTreasure();        
        }
        else if(input == "Gremlin")
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
    if(m_actingPlayers.size() == 0 && getNumberOfRounds() != STARTING_ROUND)
    {
        return true;
    }
    return false;
}

//The Game!
void Mtmchkin::playRound()
{   printRoundStartMessage(m_roundNum);
    int activePlayers = m_actingPlayers.size();
    
    while(activePlayers > 0)
    {
         std::unique_ptr<Player> currentPlayer = std::move(m_actingPlayers.front());
         std::unique_ptr<Card> currentCard = std::move(m_cardsDeck.front()); 
         m_cardsDeck.pop_front();
         m_actingPlayers.pop_front();

         printTurnStartMessage(currentPlayer->getName());


         currentCard->applyEncounter(*currentPlayer); //Exception
         //
         m_cardsDeck.push_back(std::move(currentCard));
         
         if(currentPlayer->isKnockedOut()){
            m_losers.push_front(std::move(currentPlayer));
         }
         else if( currentPlayer->getLevel() == Player::MAX_LEVEL){
            m_winners.push_back(std::move(currentPlayer));
         }
         else {
            m_actingPlayers.push_back(std::move(currentPlayer));
         }
         activePlayers--;

    }
    m_roundNum++;

    if(isGameOver())
    {
        printGameEndMessage();
    }
    
    
}



