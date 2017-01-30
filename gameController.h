#include "board.h"
#include "resultType.h"
#include "player.h"
#include "database.h"

class GameController
{
    private:
        Board board;
        int currentPlayer;
        Player* players;
        Database database;

    public:
        GameController(Player players[] , int currentPlayer);
        void playTurn();
};