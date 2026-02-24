#ifndef MATCH_H
#define MATCH_H

#include "team.h"
#include <string>

using namespace std;

class Match{

private:

    Team& home;
    Team& away;

    int homeGoals = 0;
    int awayGoals = 0;

    bool played = false;

    void simulateGoals(Team& scoringTeam, int goalCount);


public:

    Match(Team& home, Team& away);

    void play();

    string getScore() const;

    const int& getHomeGoals() const;
    const int& getAwayGoals() const;

};

#endif //MATCH_H