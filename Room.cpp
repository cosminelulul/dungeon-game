#include "Room.h";

void Room::SetDoors(smallint side) {
    if (doors[side] == 1) return;
    doors[side] = 1;

    if (side % 2 == 1) {
        for (smallint x = 0; x <= 1; x++)
            for (smallint y = 0; y <= 1; y++)
                level[(rows / 2) - 1 + y][((side == 3) * (columns - 1 - x)) + (side == 1) * x] = door;
    } else {
        for (smallint x = 0; x <= 1; x++)
            level[(side - 2) * 4 + (side == 4)][columns / 2 + x] = door;
    }
}


void gotoxy(smallint x, smallint y) {
    COORD coord = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Room::ShowRoom() const{

    //gotoxy(0,0);
    system("cls");
    for (smallint i = 0;i<rows;i++){
        cout << "                                     ";
        for (smallint j = 0;j<columns;j++)
            cout << level[i][j];
        cout << endl;
    }
    cout << endl;

}


Room::Room() {
    for (smallint i = 0; i < rows; i++)
        for (smallint j = 0; j < columns; j++)
            level[i][j] = ((i + 1) == 1 || (i + 1) == rows || (j <= 1) || (j >= columns - 2)) ? wall : space;
}


void Room::ModifyPlayerPosition(smallint xval,smallint yval,bool state){
    (state == 1)?
        level[xval][yval] = sprite:
    level[xval][yval] = space;
    ShowRoom();
}

char Room::GetTile(smallint x, smallint y) const {
    return level[x][y];
}
