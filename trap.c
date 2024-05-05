#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "player.h"
#include <time.h>
#include "treasure.h"
#include "trap.h"

void initialisation_trap(Trap *trap) {
   srand(time(NULL));
   
  do {
        trap->pos.x = rand() % 10; // Génère une position aléatoire pour x
        trap->pos.y = rand() % 10; // Génère une position aléatoire pour y
    } while (trap->pos.x == treasure.pos.x && trap->pos.y == treasure.pos.y);
    // Continue à générer une nouvelle position pour le piège jusqu'à ce qu'elle soit différente de celle du trésor
    
}

coordinate get_pos_trap(Trap *trap) {
    coordinate pos;
    pos.x = trap->pos.x;
    pos.y = trap->pos.y;
    return pos;
}

void free_trap(Trap *trap) {
    free(trap);
    trap = NULL;
}