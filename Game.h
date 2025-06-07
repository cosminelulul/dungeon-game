#pragma once
#include "Room.h"
#include "Player.h"
#include "defined.h"

class Game {

    Room dungeon[dungeon_size][dungeon_size];
    Player player;

    smallint playerRow, playerCol;
    smallint goalRow, goalCol;

    void GenerateDungeon();
    void UpdateScreenColour();
    void PlacePlayerAndGoal();


public:
    Game();
    smallint Start();
};

