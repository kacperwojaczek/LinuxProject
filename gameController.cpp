#include "gameController.h"
#include <iostream>

using namespace std;

GameController::GameController(Player players[], int currentPlayer) : database(players[0].getName(), players[1].getName())
{
    this->players = players;
    this->currentPlayer = currentPlayer;
    playTurn();
}

void GameController::playTurn()
{
    while (inProgress == board.checkWin())
    {
        board.drawBoard();

        cout << players[currentPlayer].getName()<< " podaj liczbe: "<<endl;

        int choice;
        cin >> choice;

        if (choice < 10 && choice > 0 && (board.getField(choice) - '0') == choice)
        {
            board.setField(choice, (players[currentPlayer].playerNumber == player1) ? 'X' : 'O');
            currentPlayer = (players[currentPlayer].playerNumber == player1) ? 1 : 0;
        }
        else
        {
            cout << "Nieprawidlowy ruch, sprobuj ponownie " << players[currentPlayer].getName() << endl;
        }
    }

    if (board.checkWin() == win)
    {
        board.drawBoard();
        cout<<players[(currentPlayer == 0) ? 1 : 0].getName()<<" wygrywa!"<<endl;
        database.updateScore(players[(currentPlayer == 0) ? 1 : 0].getName());
    }
    else
        cout<<"Remis"<<endl;
}