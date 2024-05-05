#ifndef PIRATE_H
#define PIRATE_H
#include <stdio.h> //printf
#include <stdint.h>
#include <stdbool.h>
#include "map.h"
#include "utility.h"

typedef struct {
    coordinate pos;
    int health_point;
} Pirate;

void initialisation_Pirate(Pirate *pirate);
void move_pirate(Pirate *pirate, Player *player, char **game_map);
coordinate get_pos_pirate(Pirate *pirate);

void free_pirate(Pirate *pirate);

#endif