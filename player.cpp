#include "player.h"
#include <stdexcept>

Player::Player(const string& name, const int& transferAmount, const Position& position)
    : name{ name }, transferAmount{ transferAmount }, position{ position }
{
    if (name.empty() || transferAmount < 10 || transferAmount > 500)
        throw runtime_error("Error");
}

bool Player::operator==(const Player& p) const
{
    return (name == p.name);
}

ostream& operator<<(ostream& os, const Player& p)
{
    return os << "[" << p.name << ", "
              << p.transferAmount << " Mio Euro, "
              << positionNames.at(static_cast<int>(p.position)) << "]";
}

// Bonus points:

Position Player::getPosition() const
{
    return this->position;
}
