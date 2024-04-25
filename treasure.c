#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "player.h"
#include <time.h>
#include "treasure.h"

//int position_x = 0;
//int position_y = 0;




void initialisation_treasure(Treasure *treasure) {
   srand(time(NULL));
    treasure->position_x = rand() % 10;
    treasure->position_y = rand() % 10;
}

Coordinate get_pos_treasure(Treasure *treasure) {
    Coordinate pos;
    pos.x = treasure->position_x;
    pos.y = treasure->position_y;
    return pos;
}

