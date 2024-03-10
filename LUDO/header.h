#ifndef _HEADER_H_
#define _HEADER_H_

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


enum Color
{
    RED,
    GREEN,
    YELLOW,
    BLUE,
    NOCOLOR
};

struct House {
    Color color; //Red
    int members; //4
    bool status;//false

    House(Color c = Color::RED, int m = 4, bool s = false){
        color = c;
        members = m;
        status = s;
    }
};

struct Player {
    string name;
    House houses[2]; //House_1, House_2
};

void GameConfiguration(Player players[], int numOfPlayers);

void DisplayResults(Player players[], int numOfPlayers);

#endif /* _HEADER_H_ */
