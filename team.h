#ifndef TEAM_H
#define TEAM_H

#include "player.h"

class Team
{
private:
    std::string teamName;
    std::vector<Player> squad;

public:
    Team(const std::string& teamName, const std::vector<Player>& squad = {});

    std::vector<Player> signPlayers(const std::vector<Player>& squad);

    friend std::ostream& operator<<(std::ostream& os, const Team& team);

    // Bonus points:

    // Returns lineup as string: defense-midfield-striker
    std::string lineup() const;

    // Release players by position; returns released players
    std::vector<Player> releasePlayers(const std::vector<Position>&);

    // Transfer Market
    
    // Buys a player from another team; returns true if successful
    bool buyPlayer(Player& player, Team& fromTeam);

    // Sells a player to another team; returns true if successful
    bool sellPlayer(Player& player, Team& toTeam);

    std::string startingLineup() const;
};

#endif // TEAM_H
