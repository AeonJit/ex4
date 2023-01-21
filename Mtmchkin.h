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
    void addToCardVector(const std::string& input);

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
    vector<std::unique_ptr<Card>> m_cardsDeck; //deck

    deque<std::unique_ptr<Player>> m_actingPlayers;
    deque<std::unique_ptr<Player>> m_losers;
    deque<std::unique_ptr<Player>> m_winners;


    std::unique_ptr<Card> m_curCard;

    int m_playerAmount;
    int m_cardsAmount;
    int m_roundNum;
    int m_indexCurrentCard;

    static const int MIN_PLAYERS = 2;
    static const int MAX_PLAYERS = 6;
    static const int MIN_CARDS = 5;
    static const int STARTING_ROUND = 1;
    static const int NO_ACTING_PLAYERS = 0;
    static const int EVERY_ONE_PLAY = 0;
    static const int FIRST_INDEX = 0;
};

#endif /* MTMCHKIN_H_ */
