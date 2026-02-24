#ifndef LEAGUE_H
#define LEAGUE_H

#include "team.h"

struct LeagueEntry {
    Team* team;

    int played = 0;
    int wins = 0;
    int draws = 0;
    int losses = 0;
    int goalsFor = 0;
    int goalsAgainst = 0;
    int points = 0;
};

class League {

private:
    std::vector<LeagueEntry> table;

public:
    League(const std::vector<Team*>& teams);

    void recordMatch(Team& home, Team& away, int homeGoals, int awayGoals);

    void sortTable();

    void printTable() const;

    std::vector<LeagueEntry> getTable();

};

#endif