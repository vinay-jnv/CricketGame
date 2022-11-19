#include <vector>
#include "player.cpp"

class team
{
public:
    team();

    std::string name;
    int totalRunsScored;
    int wicketsLost;
    int totalBallsBowled;
    std::vector<Player> player;
};