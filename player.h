#ifndef PLAYER
#define PLAYER

#include "resultType.h"

class Player
{
    private:
        char* name;
    public:
        Players playerNumber;
        char* getName();
        void setName(char* name);
};

#endif // !PLAYER