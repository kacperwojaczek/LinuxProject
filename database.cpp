#include "database.h"
#include <unistd.h>
#include <fcntl.h>

using namespace std;

Database::Database(char *firstPlayer, char *secondPlayer)
{
    openFile(firstPlayer);
    openFile(secondPlayer);
}

Database::~Database()
{
    for (map<std::string, int>::iterator  i = files.begin(); i != files.end(); ++i)
    {
        close(i->second);
    }
}

bool Database::openFile(char *player)
{
    int result = open(player, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (result > -1)
    {
        files[player] = result;
        return true;
    }
    else
        return false;
}

bool Database::updateScore(char *player)
{
    char score;
    int result = read(files[player], &score, 1);

    if ( result < 0)
        return false;
    else if (result == 0)
    {
        score = '1';
        write(files[player], &score, 1);
        return true;
    } 
    else
    {
        unlink(player);
        openFile(player);
        score++;
        write(files[player], &score, 1);
        return true;
    }
}