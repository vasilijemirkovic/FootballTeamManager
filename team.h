#ifndef TEAM_H
#define TEAM_H

#include "player.h"
#include <vector>
#include <string>
#include <ostream>

class Team
{
private:
    string teamName;
    vector<Player> squad;

public:
    Team(const string& teamName, const vector<Player>& squad = {});

    vector<Player> signPlayers(const vector<Player>& squad);

    friend ostream& operator<<(ostream& os, const Team& team);

    // Bonus points:

    // Returns lineup as string: defense-midfield-striker
    string lineup() const;

    // Release players by position; returns released players
    vector<Player> releasePlayers(const vector<Position>&);
};

#endif // TEAM_H
