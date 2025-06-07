#include "Room.h"

class Player{

    smallint health = 100;
    smallint lives = 5;
    smallint poz_value[2]={(rows/2-1),(columns/2-1)};
    double walkspeed_modifier = 1; // how fast you can move
    //char inv[3]={};

public:

    Player();
    void ModifyHealth();
    void ModifyLives();
    void GameOver();
    int Walk(Room& r);
    void ModifyPosition(nsmallint=0);

    void ModPlayerPoz(Room&,nsmallint=0);
    void MoveToDoor(Room&, smallint=0);

    smallint getPozX() const;
    smallint getPozY() const;


};
