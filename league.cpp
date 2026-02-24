#include "league.h"
#include <algorithm>
#include <iostream>

using namespace std;

League::League(const vector<Team*>& teams) {
    for (auto team : teams)
        table.push_back({ team });
}

void League::recordMatch(Team& home, Team& away, int homeGoals, int awayGoals) {
    auto findEntry = [&](Team& t) -> LeagueEntry& {
        for (auto& entry : table){
            if (entry.team == &t) return entry;
        }
            
        throw runtime_error("Team not found in league!");
    };

    auto& h = findEntry(home);
    auto& a = findEntry(away);

    h.played++;
    a.played++;

    h.goalsFor += homeGoals;
    h.goalsAgainst += awayGoals;

    a.goalsFor += awayGoals;
    a.goalsAgainst += homeGoals;

    if (homeGoals > awayGoals) {
        h.wins++;
        a.losses++;
        h.points += 3;
    }
    else if (awayGoals > homeGoals) {
        a.wins++;
        h.losses++;
        a.points += 3;
    }
    else {
        h.draws++;
        a.draws++;
        h.points += 1;
        a.points += 1;
    }
}

void League::sortTable() {
    sort(table.begin(), table.end(),
        [](const LeagueEntry& a, const LeagueEntry& b) {

            if (a.points != b.points){
                return a.points > b.points;
            }

            int diffA = a.goalsFor - a.goalsAgainst;
            int diffB = b.goalsFor - b.goalsAgainst;

            if (diffA != diffB)
                return diffA > diffB;

            return a.goalsFor > b.goalsFor;
        });
}

void League::printTable() const {
    cout << "\n===== LEAGUE TABLE =====\n";

    for (size_t i = 0; i < table.size(); ++i) {
        const auto& e = table[i];

        cout << i + 1 << ". "
             << e.team->getName()
             << " | P:" << e.played
             << " W:" << e.wins
             << " D:" << e.draws
             << " L:" << e.losses
             << " GF:" << e.goalsFor
             << " GA:" << e.goalsAgainst
             << " PTS:" << e.points
             << "\n";
    }
}

std::vector<LeagueEntry> League::getTable() {
    return table;
}
