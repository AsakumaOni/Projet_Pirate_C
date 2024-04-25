#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h> //printf
#include <stdint.h>
#include <stdbool.h>
#include "map.h"


typedef struct {
    int x;
    int y;
} Coordinate;


typedef struct {
    int position_x;
    int position_y;
    int health_point;
} Player;

extern Player player;

void initialisation_Player(Player *player);


Coordinate get_pos(Player *player);


bool movement(char direction);

#endif 