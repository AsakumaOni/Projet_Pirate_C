#ifndef TREASURE_H
#define TREASURE_H
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "player.h"
#include "map.h"




typedef struct {
    int position_x;
    int position_y;
} Treasure;

extern Treasure treasure;

void initialisation_treasure();

Coordinate get_pos_treasure(Treasure *treasure);

#endif