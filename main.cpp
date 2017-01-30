#include "gameController.h"
#include "resultType.h"
#include "player.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{   
    char* player1Name = NULL;
    char* player2Name = NULL;

    int c;  

    while ((c = getopt(argc, argv, "a:b:")) != -1)
    {
        switch (c)
        {
        case 'a':
            player1Name = optarg;
            break;
        case 'b':
            player2Name = optarg;
            break;
        default:
            break;
            //abort();
        }
    }

    Player players[2];
    players[0].playerNumber = player1;
    players[1].playerNumber = player2;


    if (player1Name != NULL)
        players[0].setName(player1Name);
    else
        player1Name=(char*)"Gracz 1";
        players[0].setName(player1Name);
    if (player2Name != NULL)
        players[1].setName(player2Name);
    else
        player2Name=(char*  )"Gracz 2";
        players[1].setName(player2Name);

    int currentPlayer = 0;
    GameController gameController = GameController(players, currentPlayer);

    int choice = 1;

    while (choice == 1)
    {
        cout << "Rewanz? (1- tak, 0- nie)" << endl;
        cin >> choice;
        if (choice == 1)
        {
            currentPlayer = (currentPlayer == 0) ? 1 : 0;
            gameController = GameController(players, currentPlayer);
        }
    }
    return 0;
}