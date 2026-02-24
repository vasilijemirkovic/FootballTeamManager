#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "player.h"
#include "team.h"
#include "match.h"
#include "league.h"
#include "season.h"

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
  Player ramos{"Ramos", 60, Position::Defense};
  Player modric{"Modric", 50, Position::Midfield};

  Player drogba{"Drogba", 80, Position::Striker};
  Player terry{"Terry", 60, Position::Defense};
  Player lampard{"Lampard", 90, Position::Midfield};
  Player anelka{"Anelka", 40, Position::Striker};
  Player carvalho{"Carvalho", 30, Position::Defense};
  Player essien{"Essien", 60, Position::Midfield};
  Player cech{"Cech", 20};
  Player cole{"Cole", 70, Position::Midfield};

  Player podolski{"Podolski", 75, Position::Striker};
  Player lahm{"Lahm", 50, Position::Defense};
  Player ribery{"Ribery", 85, Position::Midfield};
  Player mueller{"Müller", 100, Position::Striker};
  Player schweinsteiger{"Schweinsteiger", 65, Position::Defense};
  Player neuer{"Neuer", 30};
  Player bommel{"Bommel", 90, Position::Midfield};


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

  Team psg{"PSG", {coutinho, cillessen, suarez}};
  Team realMadrid{"Real Madrid", {messi, ramos, modric}};

  std::cout << "Before transfer:\n" << psg << '\n' << realMadrid << '\n';

  // Transfer Messi from Real Madrid to PSG
  if (psg.buyPlayer(messi, realMadrid))
      std::cout << "Transfer successful!\n";
  else
      std::cout << "Transfer failed!\n";

  std::cout << "After transfer:\n" << psg << '\n' << realMadrid << '\n';

  Match elClasico(barcelona, realMadrid);

  elClasico.play();

  cout << elClasico.getScore() << endl;


  cout << psg.startingLineup() << endl;

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

  Team chelsea{"Chelsea", {}};
  Team bayern{"Bayern", {}};
  barcelona.signPlayers({umtiti, alba, digne, gomes, paulinho, roberto, stegen});
  chelsea.signPlayers({cech, terry, carvalho, cole, lampard, anelka, drogba, essien});
  bayern.signPlayers({neuer, lahm, bommel, schweinsteiger, mueller, roberto, podolski, ribery});

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


  vector<Team*> teams = { &barcelona, &realMadrid, &bayern, &chelsea };
  
  League UCL(teams);
  
  //First round
  Match m1(barcelona, realMadrid);
  Match m2(chelsea, bayern);

  m1.play();
  m2.play();
  UCL.recordMatch(barcelona, realMadrid, m1.getHomeGoals(), m1.getAwayGoals());
  UCL.recordMatch(chelsea, bayern, m2.getHomeGoals(), m2.getAwayGoals());
  
  UCL.sortTable();
  
  UCL.printTable();


  //Second round
  Match m3(realMadrid, chelsea);
  Match m4(bayern, barcelona);
  m3.play();
  m4.play();

  UCL.recordMatch(realMadrid, chelsea, m3.getHomeGoals(), m3.getAwayGoals());
  UCL.recordMatch(bayern, barcelona, m4.getHomeGoals(), m4.getAwayGoals());
  
  UCL.sortTable();
  
  UCL.printTable();

  //Third round
  Match m5(realMadrid, bayern);
  Match m6(barcelona, chelsea);
  m5.play();
  m6.play();

  UCL.recordMatch(realMadrid, bayern, m5.getHomeGoals(), m5.getAwayGoals());
  UCL.recordMatch(barcelona, chelsea, m6.getHomeGoals(), m6.getAwayGoals());
  
  UCL.sortTable();
  
  UCL.printTable();

  //Fourth round
  Match m7(realMadrid, barcelona);
  Match m8(bayern, chelsea);
  m7.play();
  m8.play();

  UCL.recordMatch(realMadrid, bayern, m7.getHomeGoals(), m7.getAwayGoals());
  UCL.recordMatch(barcelona, chelsea, m8.getHomeGoals(), m8.getAwayGoals());
  
  UCL.sortTable();
  
  UCL.printTable();

  //Fifth round
  Match m9(chelsea, realMadrid);
  Match m10(barcelona, bayern);
  m9.play();
  m10.play();

  UCL.recordMatch(chelsea, realMadrid, m9.getHomeGoals(), m9.getAwayGoals());
  UCL.recordMatch(barcelona, bayern, m10.getHomeGoals(), m10.getAwayGoals());
  
  UCL.sortTable();
  
  UCL.printTable();

  //Sixth round
  Match m11(bayern, realMadrid);
  Match m12(chelsea, barcelona);
  m11.play();
  m12.play();

  UCL.recordMatch(bayern, realMadrid, m11.getHomeGoals(), m11.getAwayGoals());
  UCL.recordMatch(chelsea, barcelona, m12.getHomeGoals(), m12.getAwayGoals());
  
  UCL.sortTable();
  
  UCL.printTable();


  cout << endl;

  cout << "CHAMPION OF THE UCL League is: " << UCL.getTable()[0].team->getName() << endl;
  
  Season season(teams);

  season.playSeason();
  season.printTable();



  return 0;
}
