
#include <iostream>
#include <string>
#include <iomanip>
#include "header.h"

int main()
{
    const int NUM_OF_PLAYERS = 4;

    Player players[NUM_OF_PLAYERS];

    int numOfPlayers;

    while(true)
    {
        cout << "How many players do you wish to add to this game: ";
        cin >> numOfPlayers;
		if (numOfPlayers != NULL)
			break;
    };
    while (numOfPlayers != 2 && numOfPlayers != 4);

    GameConfiguration(players, numOfPlayers);

    DisplayResults(players, numOfPlayers);

    //reduce members
    cout << "Deducting 1, 2, 3, 4 members from players 1, 2, 3 and 4 respectively";
    for (int i = 0; i < numOfPlayers; i++)
    {
        for (int j = 0; j < 2; j++){
            players[i].houses[j].members -= (i + 1);
        }
    }

        DisplayResults(players, numOfPlayers);
		system("pause");
    return 0;
}
