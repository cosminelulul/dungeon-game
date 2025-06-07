#include "defined.h"
#pragma once

class Room{

    bool isChoosen = false;
    short unsigned int doors[5]={}; // 0 null,1 left, 2 top, 3 right, 4 bottom
    char level[rows][columns]={};

    public:

        void SetDoors(smallint); // arbitrary parameter
        void ShowRoom() const; // testing function
        void ModifyPlayerPosition(smallint=0,smallint=0,bool=1);
        char GetTile(smallint, smallint) const;

        Room();



};
