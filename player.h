#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

enum class Position { Goalkeeper, Defense, Midfield, Striker };
const std::vector<std::string> positionNames{ "Goalkeeper", "Defense", "Midfield", "Striker" };


struct Stats {
    int goals = 0;
    int assists = 0;
    int yellowCards = 0;
    int redCards = 0;
};

class Player
{
private:
    std::string name;
    int transferFee;
    Position position;
    Stats stats;

public:
    Player(const std::string& name, const int& transferFee, const Position& position = Position::Goalkeeper);

    //getters
    const std::string& getName() const;
    int getTransferFee() const;
    Position getPosition() const;
    const Stats& getStats() const;

    // update stats
    void addGoal();
    void addAssist();
    void addYellowCard();
    void addRedCard();

    int getRating() const;
    
    bool operator==(const Player& otherPlayer) const;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

};

std::string positionToString(Position p);

#endif // PLAYER_H
