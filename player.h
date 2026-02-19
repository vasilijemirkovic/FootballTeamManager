#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

enum class Position { Goalkeeper, Defense, Midfield, Striker };
const vector<string> positionNames{ "Goalkeeper", "Defense", "Midfield", "Striker" };

class Player
{
private:
    string name;
    int transferAmount;
    Position position;

public:
    Player(const string& name, const int& transferAmount, const Position& position = Position::Goalkeeper);
    bool operator==(const Player&) const;
    friend ostream& operator<<(ostream&, const Player&);

    // Bonus points:
    Position getPosition() const;
};

#endif // PLAYER_H
