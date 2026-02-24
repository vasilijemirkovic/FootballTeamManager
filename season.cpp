#include "season.h"
#include <algorithm>

using namespace std;

Season::Season(const vector<Team*>& teams) : teams { teams } {
    for (auto t : teams) points[t->getName()] = 0;
}

void Season::playSeason() {
    for (size_t i = 0; i < teams.size(); i++) {
        for (size_t j = i + 1; j < teams.size(); j++) {

            Match match(*teams[i], *teams[j]);
            match.play();

            cout << match.getScore() << endl;

            int home = match.getHomeGoals();
            int away = match.getAwayGoals();

            if (home > away)
                points[teams[i]->getName()] += 3;
            else if (away > home)
                points[teams[j]->getName()] += 3;
            else {
                points[teams[i]->getName()] += 1;
                points[teams[j]->getName()] += 1;
            }
        }
    }
}

void Season::printTable() const {
    vector<pair<string, int>> table(points.begin(), points.end());

    sort(table.begin(), table.end(), [](auto& a, auto& b) { return a.second > b.second; });

    cout << "\n=== FINAL TABLE ===\n";
    for (const auto& entry : table) {
        cout << entry.first << " - " << entry.second << " pts\n";
    }
}