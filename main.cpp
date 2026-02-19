#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "player.h"
#include "team.h"

using namespace std;

int main() {

  Player stegen{"Stegen", 60, Position::Goalkeeper};
  Player cillessen{"Cillessen", 10};
  Player umtiti{"Umtiti", 60, Position::Defense};
  Player alba{"Alba", 60, Position::Defense};
  Player digne{"Digne", 15, Position::Defense};
  Player roberto{"Roberto", 55, Position::Defense};
  Player paulinho{"Paulinho", 40, Position::Midfield};
  Player gomes{"Gomes", 15, Position::Midfield};
  Player rakitic{"Rakitic", 50, Position::Midfield};
  Player coutinho{"Coutinho", 100, Position::Midfield};
  Player messi{"Messi", 180, Position::Striker};
  Player suarez{"Suarez", 70, Position::Striker};
  Player elhaddadi{"El Haddadi", 12, Position::Striker};

  cout << "PLAYERS\n";
  cout << messi << '\n';
  cerr << messi << '\n';
  cout << cillessen << '\n';
  
  messi.addGoal();
  messi.addGoal();
  messi.addAssist();
  messi.addYellowCard();

  cout << messi << '\n';

  try {
    Player s{"", 60};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 1\n";
  }

  try {
    Player s{"Mesis", 9};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 2\n";
  }

  try {
    Player s{"Mesis", 500};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 3\n";
  }

  try {
    Player s{"Mesis", 501};
    cout << s << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 4\n";
  }

  cout << (messi == messi)
       << (messi == alba)
       << (messi == Player{"Test", 180, Position::Striker});

  cout << (messi == Player{"Messi", 18})
       << (messi == Player{"Messis", 180, Position::Striker});


  cout << '\n';

  cout << "\nTEAMS\n";

  try {
    cout << Team{"Kapfenberg"} << '\n';
    cerr << Team{"Kapfenberg"} << '\n';
    cout << Team{"Simmering"} << '\n';
    cout << Team{"Brutal", {coutinho}} << '\n';
    cerr << Team{"Brutal", {coutinho}} << '\n';
    cerr << Team{"Sturm", {messi, cillessen}} << '\n';

    Team m{""};
    cout << m << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 5\n";
  }

  try {
    Team m{"Liga Nord", {messi, coutinho, cillessen, coutinho, elhaddadi}};
    cout << m << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 6\n";
  }

  Team barcelona{"Barcelona", {coutinho, cillessen, suarez}};
  const Team h{"Hoppala",
               barcelona.signPlayers({messi, cillessen, elhaddadi, coutinho, messi})};

  cout << h << '\n';
  cerr << h << '\n';

  barcelona.signPlayers({});
  cout << barcelona << '\n';



  
  cout << "\nBonus 10 points\n";
  try {
    cout << barcelona.lineup() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 7\n";
  }

  try {
    barcelona.signPlayers({umtiti, alba, digne, gomes, paulinho});
    cout << barcelona.lineup() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 8\n";
  }

  try {
    Team copy{barcelona};
    copy.signPlayers({});
    copy.signPlayers({roberto});
    cout << copy.lineup() << '\n';

    copy = barcelona;
    copy.signPlayers({stegen});
    cout << copy.lineup() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 9\n";
  }

  try {
    Team copy{barcelona};
    copy.signPlayers({rakitic, roberto});
    cout << copy.lineup() << '\n';
    cout << barcelona << '\n';
  }
  catch (runtime_error&) {
    cout << "Error 10\n";
  }


  cout << "\nBonus 15 points\n";
  vector<Player> result;

  barcelona.signPlayers({umtiti, alba, digne, gomes, paulinho, roberto, stegen});

  result = barcelona.releasePlayers({});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';

  result = barcelona.releasePlayers({Position::Goalkeeper});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';

  result = barcelona.releasePlayers({Position::Goalkeeper, Position::Striker});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';

  result = barcelona.releasePlayers({Position::Striker, Position::Defense});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';

  result = barcelona.releasePlayers({Position::Striker, Position::Defense, Position::Midfield});
  cout << barcelona << '\n';
  for (const auto& s : result)
    cout << s << " ";
  cout << '\n';
  

  return 0;
}
