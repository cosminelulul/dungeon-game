#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    char ch;
    vector<smallint> runs;
    smallint bestTime = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "\nWelcome to the Dungeon Game.PRESS SPACE TO START\n";
    while (true) {
        if (kbhit()) {
            ch = tolower(_getch());
            if (ch == ' ') {
                Game g;
                smallint instance = g.Start();
                Sleep(1000);
                system("cls");
                SetConsoleTextAttribute(hConsole, 7);
                if (instance < bestTime || bestTime == 0) {
                    bestTime = instance;
                    cout << "\nCURRENTLY BEST RECORD TIME!\n";
                }
                runs.insert(runs.end(), instance);

                cout << "Press SPACE to Continue";
                ch = tolower(_getch());
            }
        }

    }



    return 0;
}
