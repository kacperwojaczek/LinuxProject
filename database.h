#include <map>
#include <string>
#include <iterator>

class Database
{
    private:
        std::map<std::string, int> files;
    public:
        Database(char* firstPlayer, char* secondPlayer);
        bool openFile(char* player);
        bool updateScore(char* player);
        ~Database();
};