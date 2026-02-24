#ifndef SEASON_H
#define SEASON_H

#include <vector>
#include <map>
#include <string>
#include "team.h"
#include "match.h"

class Season {
private:
    std::vector<Team*> teams;
    std::map<std::string, int> points;

public:
    Season(const std::vector<Team*>& teams);

    void playSeason();
    void printTable() const;
};

#endif //SEASON_H