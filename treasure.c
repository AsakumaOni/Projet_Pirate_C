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
    treasure->pos.x = rand() % 10;
    treasure->pos.y = rand() % 10;
}

coordinate get_pos_treasure(Treasure *treasure) {
    coordinate pos;
    pos.x = treasure->pos.x;
    pos.y = treasure->pos.y;
    return pos;
}

