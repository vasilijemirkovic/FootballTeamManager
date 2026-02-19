#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

using namespace std;

enum class Position { Goalkeeper, Defense, Midfield, Striker };
const vector<string> positionNames{ "Goalkeeper", "Defense", "Midfield", "Striker" };

class Player
{
private:
    string name;
    int transferFee;
    Position position;

public:
    Player(const string& name, const int& transferFee, const Position& position = Position::Goalkeeper);

    const std::string& getName() const;
    int getTransferFee() const;

    bool operator==(const Player& otherPlayer) const;

    friend ostream& operator<<(ostream& os, const Player& player);

    // Bonus points:
    Position getPosition() const;
};

#endif // PLAYER_H
