#include "../Mtmchkin.h"



 #define MAX_ROUNDS 100 


int main() {
Mtmchkin game("../deck.txt");
while(!game.isGameOver() /*&& game.getNumberOfRounds() < MAX_ROUNDS*/)
{
    game.playRound();
}
game.printLeaderBoard();


    return 0;
}
