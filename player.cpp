#include "player.h"
#include <stdexcept>

using namespace std;

Player::Player(const string& name, const int& transferFee, const Position& position)
    : name{ name }, transferFee{ transferFee }, position{ position }
{
    if (name.empty()){
        throw runtime_error("Player name is missing!");
    }

    if (transferFee < 10 || transferFee > 500){
        throw runtime_error("Transfer fee must be between 10 and 500 Mio Euros!");
    }
}

const string& Player::getName() const {
    return this->name;
}

int Player::getTransferFee() const {
    return this->transferFee;
}

Position Player::getPosition() const {
    return this->position;
}

const Stats& Player::getStats() const {
    return this->stats;
}

void Player::addGoal(){
    stats.goals++;
}

void Player::addAssist(){
    stats.assists++;
}

void Player::addYellowCard(){
    stats.yellowCards++;
}

void Player::addRedCard(){
    stats.redCards++;
}

int Player::getRating() const {
    return stats.goals * 4 + stats.assists * 3 - stats.yellowCards - stats.redCards * 3;
}

bool Player::operator==(const Player &otherPlayer) const {
    return (name == otherPlayer.name);
}

ostream& operator<<(ostream& os, const Player& player)
{
    return os << "[" << player.name << ", "
              << player.transferFee << " Mio Euro, "
              << positionNames.at(static_cast<int>(player.position))
              << ", Rating: " << player.getRating() << "]";
}

string positionToString(Position p){
    return positionNames.at(static_cast<int>(p));
}

