#ifndef TREASURE_H
#define TREASURE_H
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "utility.h"
//#include "player.h"
//#include "map.h"



typedef struct {
    coordinate pos;
} Treasure;

extern Treasure treasure;

void initialisation_treasure();

coordinate get_pos_treasure(Treasure *treasure);

#endif