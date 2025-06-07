#include "Game.h"

Game::Game() {
    GenerateDungeon();
    PlacePlayerAndGoal();
}

void Game::GenerateDungeon() {
    // Link doors based on actual adjacency
    for (smallint i = 0; i < dungeon_size; ++i) {
        for (smallint j = 0; j < dungeon_size; ++j) {
            Room& r = dungeon[i][j];

            if (i > 0) r.SetDoors(2); // Top
            if (i < dungeon_size - 1) r.SetDoors(4); // Bottom
            if (j > 0) r.SetDoors(1); // Left
            if (j < dungeon_size - 1) r.SetDoors(3); // Right
        }
    }
}

void Game::PlacePlayerAndGoal() {
    srand(time(NULL));
    do {
        playerRow = rand() % (dungeon_size - 2) + 1;
        playerCol = rand() % (dungeon_size - 2) + 1;
        goalRow = rand() % dungeon_size;
        goalCol = rand() % dungeon_size;
    } while (abs(goalRow - playerRow) + abs(goalCol - playerCol) < 8);

    player.MoveToDoor(dungeon[playerRow][playerCol], 0);
}


void Game::UpdateScreenColour() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    smallint diff = abs(goalRow - playerRow) + abs(goalCol - playerCol);
    if (diff == 0)
        SetConsoleTextAttribute(hConsole, 14);
    else if (diff < 3)
        SetConsoleTextAttribute(hConsole, 12);
    else if (diff < 6)
        SetConsoleTextAttribute(hConsole, 10);
    else
        SetConsoleTextAttribute(hConsole, 7);
}

smallint Game::Start() {
    auto start_time = high_resolution_clock::now();
    while (true) {
        UpdateScreenColour();

        smallint doorUsed = player.Walk(dungeon[playerRow][playerCol]);
        if (doorUsed == 0) continue;

        dungeon[playerRow][playerCol].ModifyPlayerPosition(player.getPozX(), player.getPozY(), 0);



        switch (doorUsed) {
            case 1: playerCol--; break;
            case 2: playerRow--; break;
            case 3: playerCol++; break;
            case 4: playerRow++; break;
        }

        int enterFrom = (doorUsed == 1) ? 3 :
                        (doorUsed == 2) ? 4 :
                        (doorUsed == 3) ? 1 : 2;

        player.MoveToDoor(dungeon[playerRow][playerCol], enterFrom);

        if (playerRow == goalRow && playerCol == goalCol) {

            auto end_time = high_resolution_clock::now();  // Stop the timer
            auto duration = duration_cast<seconds>(end_time - start_time).count();

            UpdateScreenColour();
            system("cls");
            Sleep(1000);

            cout << "\n YOU WIN IN ROOM (" << playerRow << "," << playerCol << ")! \n";
            cout << "\n Time taken: " << (duration / 60) << " minutes and " << (duration % 60) << " seconds.\n";

            return static_cast<smallint>(duration);
            //break;
        }
    }
}
