#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Cards/Card.h"
#include <vector>
#include <deque>
#include <map>
#include <memory>

using std::vector;
using std::deque;

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    private: 

    int scanCards(const std::string fileName);
    int scanPlayersSize();
    void scanPlayers();
    void addToCardDeque(const std::string& input);

    void deckAddBarfight();
    void deckAddDragon  ();
    void deckAddGremlin ();
    void deckAddMana    ();
    void deckAddMerchant();
    void deckAddTreasure();
    void deckAddWell    ();
    void deckAddWitch   ();

    void addPlayer(const std::string& nameInput ,const std::string& jobInput);
    void addHealer(const std::string& name);
    void addNinja(const std::string& name);
    void addWarrior(const std::string& name);

    void printLeaderBoards () const;
    void printDequeLeaderboards(const deque<std::unique_ptr<Player>>& playerDeque, int& curRank) const;

    deque<std::unique_ptr<Card>> m_cardsDeck; //deck
    deque<std::unique_ptr<Player>> m_actingPlayers;
    deque<std::unique_ptr<Player>> m_losers;
    deque<std::unique_ptr<Player>> m_winners;


    std::unique_ptr<Card> m_curCard;

    int m_playerAmount;
    int m_roundNum;

    static const int MIN_PLAYERS = 2;
    static const int MAX_PLAYERS = 6;
    static const int MIN_CARDS = 5;
    static const int STARTING_ROUND = 1;

};

#endif /* MTMCHKIN_H_ */
