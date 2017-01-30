#include "board.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Board::Board()
{
    board[0] = 'o';
    board[1] = '1';
    board[2] = '2';
    board[3] = '3';
    board[4] = '4';
    board[5] = '5';
    board[6] = '6';
    board[7] = '7';
    board[8] = '8';
    board[9] = '9';
    /*  for (int i = 0; i<10; i++)
    {
        this->board[i] = i;
    }*/
    result = inProgress;
}

void Board::drawBoard()
{
    system("clear");
    cout << "\n\n\tKolko i krzyzyk\n\n";

    //cout << "Gracz 1 (X)  -  Gracz 2 (O)" << endl << endl;
    cout << endl
         << endl;

    cout << "     |     |     " << endl;
    cout << "  " << this->board[1] << "  |  " << this->board[2] << "  |  " << this->board[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << this->board[4] << "  |  " << this->board[5] << "  |  " << this->board[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << this->board[7] << "  |  " << this->board[8] << "  |  " << this->board[9] << endl;

    cout << "     |     |     " << endl
         << endl;
}

resultType Board::checkWin()
{
    if (this->board[1] == this->board[2] && this->board[2] == this->board[3])

        return result = win;
    else if (this->board[4] == this->board[5] && this->board[5] == this->board[6])

        return result = win;
    else if (this->board[7] == this->board[8] && this->board[8] == this->board[9])

        return result = win;
    else if (this->board[1] == this->board[4] && this->board[4] == this->board[7])

        return result = win;
    else if (this->board[2] == this->board[5] && this->board[5] == this->board[8])

        return result = win;
    else if (this->board[3] == this->board[6] && this->board[6] == this->board[9])

        return result = win;
    else if (this->board[1] == this->board[5] && this->board[5] == this->board[9])

        return result = win;
    else if (this->board[3] == this->board[5] && this->board[5] == this->board[7])

        return result = win;
    else if (this->board[1] != '1' && this->board[2] != '2' && this->board[3] != '3' && this->board[4] != '4' && this->board[5] != '5' && this->board[6] != '6' && this->board[7] != '7' && this->board[8] != '8' && this->board[9] != '9')

        return result = draw;
    else
        return result = inProgress;
}

char Board::getField(int fieldNumber)
{
    if (fieldNumber < 10 && fieldNumber > 0)
    {
        return board[fieldNumber];
    }
    else
        return 0;
}

bool Board::setField(int fieldNumber, char mark)
{
    if (fieldNumber < 10 && fieldNumber > 0 && board[fieldNumber] != 'X' && board[fieldNumber] != 'O')
    {
        board[fieldNumber] = mark;
        return true;
    }
    else
        return false;
}