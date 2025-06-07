#include "Player.h";

smallint Player::getPozX() const{
    return poz_value[0];
}

smallint Player::getPozY() const{
    return poz_value[1];
}

void Player::ModifyPosition(nsmallint modif){
    poz_value[0]+=(modif%2);
    poz_value[1]+=!(modif%2)*(modif/2);
}

Player::Player(){
    ModifyPosition(0);
}

void Player::ModPlayerPoz(Room& r,nsmallint val){
    smallint newX = poz_value[0] + (val % 2);
    smallint newY = poz_value[1] + (!(val % 2)) * (val / 2);

    if (r.GetTile(newX, newY) != wall) {
        r.ModifyPlayerPosition(getPozX(), getPozY(), 0);
        ModifyPosition(val);
        r.ModifyPlayerPosition(getPozX(), getPozY(), 1);
    }
}

int Player::Walk(Room& r) {
    char ch;
    r.ModifyPlayerPosition(getPozX(), getPozY(), 1);

    while (true) {
        Sleep(250 / walkspeed_modifier);
        if (kbhit()) {
            ch = tolower(_getch());
            nsmallint val = 0;
            switch (ch) {
                case 'w': val = -1; break;
                case 'a': val = -2; break;
                case 's': val = 1; break;
                case 'd': val = 2; break;
                default: continue;
            }

            smallint newX = poz_value[0] + (val % 2);
            smallint newY = poz_value[1] + (!(val % 2)) * (val / 2);
            char tile = r.GetTile(newX, newY);

            if (tile == door) {
                //  door did we hit?
                if (newY <= 1) return 1;          // Left
                else if (newX <= 1) return 2;     // Top
                else if (newY >= columns - 2) return 3; // Right
                else if (newX >= rows - 2) return 4;    // Bottom
                return 0;
            }

            if (tile != wall) {
                r.ModifyPlayerPosition(getPozX(), getPozY(), 0);
                ModifyPosition(val);
                r.ModifyPlayerPosition(getPozX(), getPozY(), 1);
            }
        }
    }
}

void Player::MoveToDoor(Room& r, smallint fromDoor) {
    poz_value[0] = rows / 2 - 1;
    poz_value[1] = columns / 2 - 1;
    r.ModifyPlayerPosition(getPozX(), getPozY(), 1);
}

