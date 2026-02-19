#include "player.h"
#include <stdexcept>

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


bool Player::operator==(const Player& otherPlayer) const{
    return (name == otherPlayer.name);
}

ostream& operator<<(ostream& os, const Player& player)
{
    return os << "[" << player.name << ", "
              << player.transferFee << " Mio Euro, "
              << positionNames.at(static_cast<int>(player.position)) << "]";
}

// Bonus points:

Position Player::getPosition() const
{
    return this->position;
}
