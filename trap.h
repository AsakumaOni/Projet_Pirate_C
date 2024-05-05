#ifndef TRAP_H
#define TRAP_H
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "utility.h"
//#include "player.h"
//#include "map.h"



typedef struct {
    coordinate pos;
} Trap;



void initialisation_trap();

coordinate get_pos_trap(Trap *trap);

void free_trap(Trap *trap);
#endif