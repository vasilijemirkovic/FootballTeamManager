#include "team.h"

#include <stdexcept>
#include <algorithm>

using namespace std;


Team::Team(const string& teamName, const vector<Player>& squad)
    : teamName{ teamName }, squad{ squad }
{
    if (teamName.empty())
        throw runtime_error("Team name is missing!");

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
    vector<Player> alreadySigned;

    for (const auto& player : players)
    {
        auto it = find(squad.begin(), squad.end(), player);
        
        if (it != squad.end()){
            alreadySigned.push_back(player);
        } else {
            squad.push_back(player);
        }
    }
    return alreadySigned;
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


string Team::lineup() const
{
    int defense = 0, midfield = 0, striker = 0;

    for (const auto& player : squad)
    {
        switch (player.getPosition())
        {
            case Position::Defense:  ++defense;  break;
            case Position::Midfield: ++midfield; break;
            case Position::Striker:  ++striker;  break;
            default: break;
        }
    }

    if (defense + midfield + striker != 10)
        throw runtime_error("Invalid lineup: total outfield players must be 10!");

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

bool Team::buyPlayer(Player& player, Team& fromTeam){

    auto fromTeamIt = find(fromTeam.squad.begin(), fromTeam.squad.end(), player);

    auto thisTeamIt = find(squad.begin(), squad.end(), player);

    if(thisTeamIt != squad.end() || fromTeamIt == fromTeam.squad.end()){
        return false;
    }

    squad.push_back(player);
    fromTeam.squad.erase(fromTeamIt);
    
    return true;
}

bool Team::sellPlayer(Player& player, Team& toTeam){

    auto toTeamIt = find(toTeam.squad.begin(), toTeam.squad.end(), player);

    auto thisTeamIt = find(squad.begin(), squad.end(), player);

    if(thisTeamIt == squad.end() || toTeamIt != toTeam.squad.end()){
        return false;
    }

    toTeam.squad.push_back(player);
    squad.erase(thisTeamIt);

    return true;

}
