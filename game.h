#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include"team.cpp"

class Game
{

public:
    Game(); 

    int playersPerTeam;
    int maxBalls;
    int totalPlayers;
    std::string players[11];

    bool isFirstInnings,isSecondInnings;
    team teamA,teamB;
    team *battingTeam, *bowlingTeam;
    Player *batsman, *bowler;
    bool tA;
    int rA,rB;
   
    void welcome();
    void showAllPlayers();
    int takeIntegerInput();
    void selectPlayers();
    bool validateSelectedPlayer(int);
    void showTeamPlayers();
    void toss();
    void tossChoice(team);
    void startFirstInnings();
    void initializePlayers();
    void playInnings();
    void bat();
    bool validateInningsScore();
    void showGameScorecard();
    void startSecondInnings();
    void matchSummary();
};


