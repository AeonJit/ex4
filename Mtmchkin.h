#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include "Players/Player.h"
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

    void scanPlayersSize();
    void scanPlayers();
    vector<std::unique_ptr<Card>> m_cardsDeck;

    deque<std::unique_ptr<Player>> m_actingPlayers;
    deque<std::unique_ptr<Player>> m_losers;
    deque<std::unique_ptr<Player>> m_winners;
    deque<std::unique_ptr<Player>> m_leaderboards;

    int m_playerAmount;
    int m_cardsAmount;
    int m_roundNum;

    static const int MAX_NAME_LENGTH = 15;
    static const int MIN_PLAYERS = 2;
    static const int MAX_PLAYERS = 6;
    static const int MIN_CARDS = 5;
};



#endif /* MTMCHKIN_H_ */
