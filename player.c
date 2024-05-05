#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include "player.h"
#include "map.h"
#include "utility.h"




// Fonction pour initialiser le joueur
void initialisation_Player(Player *player) {
    
    player->pos.x = 0; // Position initiale en x
    player->pos.y = 0; // Position initiale en y
    player->health_point = 100; // Points de vie initiaux
    
}

// Fonction pour obtenir la position actuelle du joueur
coordinate get_pos_player(Player *player) {
    
    return player->pos;
}


void free_player(Player *player) {
    free(player);
    player = NULL;
}

void Player_set_pos(Player *player, coordinate pos) {
    player->pos = pos;
}

int Player_get_health(Player *player) {
    return player->health_point;
}

void Player_set_health(Player *player, int health) {
    player->health_point = health;
}