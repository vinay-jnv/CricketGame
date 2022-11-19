#include "game.h"
using namespace std;
#include <iostream>

Game::Game()
{
    playersPerTeam = 4;
    maxBalls = 6;
    totalPlayers = 11;

    players[0] = "Virat";
    players[1] = "Rohit";
    players[2] = "Dhawan";
    players[3] = "Rishabh";
    players[4] = "Karthik";
    players[5] = "KLRahul";
    players[6] = "Jadeja";
    players[7] = "Hardik";
    players[8] = "Bumrah";
    players[9] = "BKumar";
    players[10] = "Ishant";

    isFirstInnings = false;
    isSecondInnings = false;
    tA = false;

    teamA.name = "Team-A";
    teamB.name = "Team-B";
}

void Game::welcome()
{
    cout << "---------------------------------------" << endl;
    cout << "|============CRIC-IN==================|" << endl;
    cout << "|                                     |" << endl;
    cout << "|   Welcome to Virtual Cricket Game   |" << endl;
    cout << "---------------------------------------" << endl;

    cout << endl
         << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|==================Instructons=====================|" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "|                                                  |" << endl;
    cout << "| 1.  Create 2 teams (Team-A and Team-B with 4     |" << endl;
    cout << "|     plyers each) from a given pool of 11 players.|" << endl;
    cout << "| 2.  Lead the toss and decide the choice of play. |" << endl;
    cout << "| 3.  Each innings will be of 6 balls.             |" << endl;
    cout << "----------------------------------------------------" << endl;
}

void Game::showAllPlayers()
{

    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "|==========Pool of Players==============|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;

    for (int i = 0; i < totalPlayers; i++)
    {
        cout << "\t\t[" << i << "]" << players[i] << endl;
    }
}

int Game ::takeIntegerInput()
{
    int n;

    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again with valid input: ";
    }

    return n;
}

void Game ::selectPlayers()
{
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "|==========Create Team-A and Team-B =========|" << endl;
    cout << "----------------------------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++)
    {
    teamASelection:
        cout << endl
             << "Select player " << i + 1 << "of Team-A - ";

        int playerIndexTeamA = takeIntegerInput();

        if (playerIndexTeamA < 0 || playerIndexTeamA > 10)
        {
            cout << endl
                 << "Please select from the given players" << endl;
            goto teamASelection;
        }
        else if (!validateSelectedPlayer(playerIndexTeamA))
        {
            cout << endl
                 << "Player has been already selected. Pleasse select other player" << endl;
            goto teamASelection;
        }
        else
        {
            Player teamAPlayer;
            teamAPlayer.id = playerIndexTeamA;
            teamAPlayer.name = players[playerIndexTeamA];
            teamA.player.push_back(teamAPlayer);
        }

    teamBSelection:
        cout << endl
             << "Select player" << i + 1 << "of Team-B - ";

        int playerIndexTeamB = takeIntegerInput();
        if (playerIndexTeamA < 0 || playerIndexTeamA > 10)
        {
            cout << endl
                 << "Please select from the given players" << endl;
            goto teamASelection;
        }
        else if (!validateSelectedPlayer(playerIndexTeamB))
        {
            cout << endl
                 << "Player has been already selected. Pleasse select other player" << endl;
            goto teamBSelection;
        }
        else
        {
            Player teamBPlayer;
            teamBPlayer.id = playerIndexTeamB;
            teamBPlayer.name = players[playerIndexTeamB];
            teamB.player.push_back(teamBPlayer);
        }
    }
}

bool Game::validateSelectedPlayer(int index)
{
    int n;
    vector<Player> players;

    players = teamA.player;
    n = players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].id == index)
        {
            return false;
        }
    }

    players = teamB.player;
    n = players.size();
    for (int i = 0; i < n; i++)
    {
        if (players[i].id == index)
        {
            return false;
        }
    }
    return true;
}

void Game::showTeamPlayers()
{
    vector<Player> teamAPlayers = teamA.player;
    vector<Player> teamBPlayers = teamB.player;

    cout << endl
         << endl;
    cout << "---------------------------\t\t--------------------------" << endl;
    cout << "|==========Team-A=========|\t\t|==========Team-B=========|" << endl;
    cout << "---------------------------\t\t---------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++)
    {
        cout << "|\t"
             << "[" << i << "]" << teamAPlayers[i].name << "\t|"
             << "\t\t"
             << "|\t"
             << "[" << i << "]" << teamBPlayers[i].name << "\t|"<<endl;
    }
    cout << "-------------------------\t\t--------------------------" << endl;
}

void Game::toss()
{
    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "|=================Let's Toss ===================|" << endl;
    cout << "-------------------------------------------------" << endl
         << endl;

    cout << "Tossing the coin ..." << endl
         << endl;

    srand(time(NULL));
    int randomValue = rand() % 2;

    switch (randomValue)
    {
    case 0:
        cout << "Team-A won the toss" << endl
             << endl;
        tossChoice(teamA);
        break;

    case 1:
        cout << "Team-B won the toss" << endl
             << endl;
        tossChoice(teamB);
        break;
    }
}

void Game::tossChoice(team tossWinnerTeam)
{
    cout << "Enter 1 to bat or 2 to bowl first." << endl
         << "1. Bat" << endl
         << "2. Bowl" << endl;

    int tossInput = takeIntegerInput();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (tossInput)
    {
    case 1:
        cout << endl
             << tossWinnerTeam.name << "won the toss and elected to bat first" << endl
             << endl;

        if (tossWinnerTeam.name.compare("Team-A") == 0)
        {
            tA = true;
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
        else
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }

        break;
    case 2:
        cout << endl
             << tossWinnerTeam.name << "won the toss and choose to bowl first" << endl
             << endl;

        if (tossWinnerTeam.name.compare("Team-A") == 0)
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }
        else
        {
            tA = true;
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
        break;

    default:
        cout << endl
             << "Invalid input. Please try again:" << endl
             << endl;
        tossChoice(tossWinnerTeam);
        break;
    }
}

void Game::startFirstInnings()
{
    cout << "\t\t ||| FIRST INNINGS STARTS |||" << endl
         << endl;
    isFirstInnings = true;

    initializePlayers();
    playInnings();
}

void Game::initializePlayers()
{
    if (isSecondInnings == true)
    {
        if (tA == true)
        {
            battingTeam = &teamB;
            bowlingTeam = &teamA;
        }
        else
        {
            battingTeam = &teamA;
            bowlingTeam = &teamB;
        }
    }
    batsman = &battingTeam->player[0];
    bowler = &bowlingTeam->player[0];

    cout << battingTeam->name << "-" << batsman->name << "is batting" << endl;
    cout << bowlingTeam->name << "-" << bowler->name << "is bowling" << endl
         << endl;
}

void Game::playInnings()
{
    for (int i = 0; i < maxBalls; i++)
    {
        cout << "Press Enter to bowl...";
        getchar();
        cout << "Bowling..." << endl;
        bat();

        if (validateInningsScore())
        {
            break;
        }
    }
}

void Game::bat()
{
    srand(time(NULL));
    int runScored = rand() % 7;

    batsman->runScored = batsman->runScored + runScored;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runScored;

    if (runScored != 0)
    {
        cout << endl
             << bowler->name << " to " << batsman->name << " " << runScored << " run!" << endl
             << endl;
        showGameScorecard();

        if (isSecondInnings == true)
        {
            rA = battingTeam->totalRunsScored;
        }
        else
        {
            rB = battingTeam->totalRunsScored;
        }
    }
    else
    {
        cout << endl
             << bowler->name << "to" << batsman->name << "OUT!" << endl
             << endl;

        battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
        bowler->wicketsTaken = bowler->wicketsTaken + 1;

        showGameScorecard();

        int nextPlayerIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->player[nextPlayerIndex];

        if (isSecondInnings == true)
        {
            rA = battingTeam->totalRunsScored;
        }
        else
        {
            rB = battingTeam->totalRunsScored;
        }
    }
}

bool Game::validateInningsScore()
{

    if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
    {
        if (isSecondInnings == false)
        {
            cout << "\t\t  ||| FIRST INNINGS ENDS  ||| " << endl
                 << endl;

            cout << battingTeam->name << " " << battingTeam->totalRunsScored << "_" << battingTeam->wicketsLost << "(" << bowlingTeam->totalBallsBowled << ")" << endl;

            cout << bowlingTeam->name << "needs" << battingTeam->totalRunsScored + 1 << "runs to win the match" << endl
                 << endl;
            return false;
        }
        else
        {
            if (rA == rB)
            {
                cout << "TEAMS HAVE EQUAL SCORE" << endl;
                cout << "\t\t  |||  MATCH ENDS  ||| " << endl
                     << endl;
            }
            else if (rA > rB)
            {
                cout << "TEAMS-A WIN THE MATCH" << endl;
                cout << "\t\t  |||  MATCH ENDS  ||| " << endl
                     << endl;
            }
            else
            {
                cout << "TEAMS-B WIN THE MATCH" << endl;
                cout << "\t\t  |||  MATCH ENDS  ||| " << endl
                     << endl;
            }
            return false;
        }
    }
    // else
    // {
    //     if (isSecondInnings == true)
    //     {
    //         if (rA == rB)
    //         {
    //             cout << "TEAMS HAVE EQUAL SCORE" << endl;
    //             cout << "\t\t  |||  MATCH ENDS  ||| " << endl
    //                  << endl;
    //         }
    //         else if (rA > rB)
    //         {
    //             cout << "TEAMS-A WIN THE MATCH" << endl;
    //             cout << "\t\t  |||  MATCH ENDS  ||| " << endl
    //                  << endl;
    //         }
    //         else
    //         {
    //             cout << "TEAMS-B WIN THE MATCH" << endl;
    //             cout << "\t\t  |||  MATCH ENDS  ||| " << endl
    //                  << endl;
    //         }
    //         return false;
    //     }
    // }
    // }
    return false;
}

void Game::showGameScorecard()
{
    cout << "----------------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << "_"
         << battingTeam->wicketsLost << "(" << bowlingTeam->totalBallsBowled << ") |" << batsman->name
         << " " << batsman->runScored << "(" << batsman->ballsPlayed << ") \t" << bowler->name << " "
         << bowler->ballsBowled << "_" << bowler->runsGiven << "_" << bowler->wicketsTaken << "\t" << endl;

    cout << "-------------------------------------------------------------------------------" << endl
         << endl;
}

void Game::startSecondInnings()
{
    cout << "\t\t ||| SECOND INNINGS STARTS |||" << endl
         << endl;
    isSecondInnings = true;

    initializePlayers();
    playInnings();
}

void Game::matchSummary()
{
     vector<Player> teamAPlayers = teamA.player;
    vector<Player> teamBPlayers = teamB.player;

    cout << endl
         << endl;
    cout <<" TEAM-A "<<battingTeam->totalRunsScored<<"-"<<battingTeam->wicketsLost<<"("<<battingTeam->totalBallsBowled<<")"<<endl;
    cout<<"================================================="<<endl;
    cout<<"|PLAYER        BATTING                 BOWLING  |"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamAPlayers[0].name<<"\t"<<teamAPlayers[0].runScored<<"("<<teamAPlayers[0].ballsPlayed<<")"<<"\t\t\t"<<teamAPlayers[0].ballsBowled<<"-"<<teamAPlayers[0].runsGiven<<"-"<<teamAPlayers[0].wicketsTaken<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamAPlayers[1].name<<"\t"<<teamAPlayers[1].runScored<<"("<<teamAPlayers[1].ballsPlayed<<")"<<"\t\t\t"<<teamAPlayers[1].ballsBowled<<"-"<<teamAPlayers[1].runsGiven<<"-"<<teamAPlayers[1].wicketsTaken<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamAPlayers[2].name<<"\t"<<teamAPlayers[2].runScored<<"("<<teamAPlayers[2].ballsPlayed<<")"<<"\t\t\t"<<teamAPlayers[2].ballsBowled<<"-"<<teamAPlayers[2].runsGiven<<"-"<<teamAPlayers[2].wicketsTaken<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamAPlayers[3].name<<"\t"<<teamAPlayers[3].runScored<<"("<<teamAPlayers[3].ballsPlayed<<")"<<"\t\t\t"<<teamAPlayers[3].ballsBowled<<"-"<<teamAPlayers[3].runsGiven<<"-"<<teamAPlayers[3].wicketsTaken<<"\t|"<<endl;
    cout<<"================================================="<<endl;

    cout << endl
         << endl;
    cout <<" TEAM-B "<<bowlingTeam->totalRunsScored<<"-"<<bowlingTeam->wicketsLost<<"("<<bowlingTeam->totalBallsBowled<<")"<<endl;
    cout<<"================================================="<<endl;
    cout<<"|PLAYER        BATTING                 BOWLING  |"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamBPlayers[0].name<<"\t"<<teamBPlayers[0].runScored<<"("<<teamBPlayers[0].ballsPlayed<<")"<<"\t\t\t"<<teamBPlayers[0].ballsBowled<<"-"<<teamBPlayers[0].runsGiven<<"-"<<teamBPlayers[0].wicketsTaken<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamBPlayers[1].name<<"\t"<<teamBPlayers[1].runScored<<"("<<teamBPlayers[1].ballsPlayed<<")"<<"\t\t\t"<<teamBPlayers[1].ballsBowled<<"-"<<teamBPlayers[1].runsGiven<<"-"<<teamBPlayers[1].wicketsTaken<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamBPlayers[2].name<<"\t"<<teamBPlayers[2].runScored<<"("<<teamBPlayers[2].ballsPlayed<<")"<<"\t\t\t"<<teamBPlayers[2].ballsBowled<<"-"<<teamBPlayers[2].runsGiven<<"-"<<teamBPlayers[2].wicketsTaken<<"\t|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|"<<"[0]"<<teamBPlayers[3].name<<"\t"<<teamBPlayers[3].runScored<<"("<<teamBPlayers[3].ballsPlayed<<")"<<"\t\t\t"<<teamBPlayers[3].ballsBowled<<"-"<<teamBPlayers[3].runsGiven<<"-"<<teamBPlayers[3].wicketsTaken<<"\t|"<<endl;
    cout<<"================================================="<<endl;
}