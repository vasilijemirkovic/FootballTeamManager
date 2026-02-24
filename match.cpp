#include "match.h"
#include <random>
#include <stdexcept>
#include <vector>

using namespace std;

Match::Match(Team& home, Team& away) : home { home }, away { away } {}


void Match::play(){

    if(played){
        throw runtime_error("Match already played!");
    }

    
    random_device rd;
    mt19937 gen(rd());
    
    // realistic football score range
    uniform_int_distribution<> goalsDist(0, 5);

    homeGoals = goalsDist(gen);
    awayGoals = goalsDist(gen);

    simulateGoals(home, homeGoals);
    simulateGoals(away, awayGoals);

    played = true;

}

void Match::simulateGoals(Team& scoringTeam, int goalCount)
{
    if (goalCount == 0) return;

    auto& players = scoringTeam.getSquad();

    if (players.empty()) return;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> playerDist(0, players.size() - 1);

    for (int i = 0; i < goalCount; i++)
    {
        int scorerIndex = playerDist(gen);
        players[scorerIndex].addGoal();

        if (players.size() > 1)
        {
            int assistIndex;
            do {
                assistIndex = playerDist(gen);
            } while (assistIndex == scorerIndex);

            players[assistIndex].addAssist();
        }
    }
}

string Match::getScore() const
{
    if (!played)
        throw runtime_error("Match not played yet!");

    return home.getName() + " "
         + to_string(homeGoals) + " : "
         + to_string(awayGoals) + " "
         + away.getName();    
}

const int &Match::getHomeGoals() const {
    return homeGoals;
}

const int &Match::getAwayGoals() const {
    return awayGoals;
}
