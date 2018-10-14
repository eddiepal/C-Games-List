/*CODE RIGHTS**********
Edward Burke
20075129
Introduction to C++
Entertainment Systems
Waterford Institute of Technology
CODE RIGHTS***********/

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

vector<string> library;
vector<string>::const_iterator iter;
void listGames();
void addGame();
void deleteGame();

int main()
{
       enum Menu { listLibrary = 1, addToLibrary = 2, deleteFromLibrary = 3, exitApplication = 4 };

       cout << "Please select an option:"
            << "\n1: List all games"
            << "\n2: Add a game"
            << "\n3: Delete a game"
            << "\n4: Exit Application" << endl;

       int select;
       cin >> select;
       switch(select) {
              case listLibrary: {
                     listGames();
                     break;
              }
              case addToLibrary: {
                     addGame();
                     break;
              }
              case deleteFromLibrary: {
                     deleteGame();
                     break;
              }
              case exitApplication: {
                     return 0;
              }
       }
}

void listGames()
{
       cout << "\nGames in your library:\n";
       // List the games in alphabetical order
       sort(library.begin(), library.end());
       for(iter = library.begin(); iter != library.end(); ++iter) {
              cout << "\t\t\t" << *iter << endl;
       }
       cout << "\nYou have " << library.size() << " in your games library.\n\n";
       main();
}

void addGame()
{
       string game;
       cout << "\nPlease enter the name of the game you want to add: ";
       //line below is from https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       getline(cin, game);
       library.push_back(game);
       cout << "\nGame added successfully.\n\n";
       main();
}

void deleteGame()
{
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       string gameToDelete;
       cout << "\nPlease enter the name of the game to remove: ";
       getline(cin, gameToDelete);

       for(iter = library.begin(); iter != library.end(); ++iter) {
              cout << *iter << endl;
              if(*iter == gameToDelete) {
                     library.erase(iter);
                     cout << "\nGame successfully removed from list.\n\n";
                     main();
              } else {
                     cout << "\nGame not found\n\n.";
                     main();
              }
       }
}