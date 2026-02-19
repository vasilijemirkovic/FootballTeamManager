#include "player.h"
#include "team.h"
#include <stdexcept>
#include <algorithm>

Team::Team(const string& teamName, const vector<Player>& squad)
    : teamName{ teamName }, squad{ squad }
{
    if (teamName.empty())
        throw runtime_error("Team name missed!");

    // check for duplicate players
    for (size_t i = 0; i < squad.size(); i++)
    {
        for (size_t j = i + 1; j < squad.size(); j++)
        {
            if (squad.at(i) == squad.at(j))
                throw runtime_error("There are duplicated players!");
        }
    }
}

vector<Player> Team::signPlayers(const vector<Player>& players)
{
    vector<Player> removed;
    bool found = true;

    for (size_t i = 0; i < players.size(); i++)
    {
        found = false;

        for (size_t j = 0; j < squad.size(); j++)
        {
            if (players.at(i) == squad.at(j))
            {
                removed.push_back(players.at(i));
                found = true;
                break;
            }
        }

        if (!found)
        {
            squad.push_back(players.at(i));
        }
    }
    return removed;
}

ostream& operator<<(ostream& os, const Team& team)
{
    // [Name, {List of players}]
    os << "[" << team.teamName << ", {";

    for (size_t i = 0; i < team.squad.size(); i++)
    {
        os << team.squad.at(i);
        if (i != team.squad.size() - 1)
            os << ", ";
    }

    return os << "}]";
}


#include <stdexcept>
#include <string>

string Team::lineup() const
{
    int defense = 0;
    int midfield = 0;
    int striker = 0;

    for (const auto& player : squad)
    {
        if (player.getPosition() == Position::Defense) defense++;
        if (player.getPosition() == Position::Midfield) midfield++;
        if (player.getPosition() == Position::Striker) striker++;
    }

    if (defense + midfield + striker != 10)
        throw runtime_error("Error!");

    return to_string(defense) + "-" +
           to_string(midfield) + "-" +
           to_string(striker);
}



vector<Player> Team::releasePlayers(const vector<Position>& positions)
{
    vector<Player> removed;

    auto shouldRemove = [&](const Player& player){
        return find(positions.begin(), positions.end(),
                    player.getPosition()) != positions.end();
    };


    copy_if(squad.begin(), squad.end(), back_inserter(removed), shouldRemove);


    squad.erase(remove_if(squad.begin(), squad.end(), shouldRemove), squad.end());

    return removed;
}
