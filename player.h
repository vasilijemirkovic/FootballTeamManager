#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

using namespace std;

enum class Position { Goalkeeper, Defense, Midfield, Striker };
const vector<string> positionNames{ "Goalkeeper", "Defense", "Midfield", "Striker" };


struct Stats {
    int goals = 0;
    int assists = 0;
    int yellowCards = 0;
    int redCards = 0;
};

class Player
{
private:
    string name;
    int transferFee;
    Position position;
    Stats stats;

public:
    Player(const string& name, const int& transferFee, const Position& position = Position::Goalkeeper);

    //getters
    const string& getName() const;
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

    friend ostream& operator<<(ostream& os, const Player& player);
};

#endif // PLAYER_H
