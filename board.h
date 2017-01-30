#include "resultType.h"

class Board { 
    private:
        char board[10];
        resultType result;

    public:
        Board();
        void drawBoard();
        resultType checkWin();
        char getField(int fieldNumber);
        bool setField(int fieldNumber, char mark);
};