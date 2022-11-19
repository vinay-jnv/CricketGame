#include"game.cpp"
using namespace std;

int main()
{
    cout<<"start your cricket game application"<<endl;

    Game game;
    game.welcome();

    cout<<"\nPress Enter to continue";
    getchar();

    game.showAllPlayers();

    cout<<"\nPress Enter to continue";
    getchar();

    game.selectPlayers();

    game.showAllPlayers();

    game.showTeamPlayers();

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout<<"\nPress Enter to toss";
    getchar();

    game.toss();

    game.startFirstInnings();

    game.startSecondInnings();

    game.matchSummary();
    return 0;
}