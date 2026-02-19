#ifndef TEAM_H
#define TEAM_H

#include "player.h"

class Team
{
private:
    string teamName;
    vector<Player> squad;

public:
    Team(const string& teamName, const vector<Player>& squad = vector<Player>());
    vector<Player> signPlayers(const vector<Player>&);
    friend ostream& operator<<(ostream&, const Team&);

    // Bonus points:
    string lineup() const;

    vector<Player> releasePlayers(const vector<Position>&);
};

#endif // TEAM_H
