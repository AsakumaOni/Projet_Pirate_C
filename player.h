#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h> //printf
#include <stdint.h>
#include <stdbool.h>
#include "map.h"
#include "utility.h"


typedef struct {
    coordinate pos;
    int health_point;
} Player;



void initialisation_Player(Player *player);


coordinate get_pos_player(Player *player);
void free_player(Player *player);
void Player_set_pos(Player *player, coordinate pos);
int Player_get_health(Player *player);
void Player_set_health(Player *player, int health);
#endif 