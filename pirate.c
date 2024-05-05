#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include "pirate.h"
#include "map.h"
#include "utility.h"


void initialisation_Pirate(Pirate *pirate) {
    srand(time(NULL));
    pirate->pos.x = rand() % 10;
    pirate->pos.y = rand() % 10;
}

void move_pirate(Pirate *pirate, Player *player, char **game_map) {
    if (pirate == NULL || player == NULL || game_map == NULL) {
        printf("Erreur : pirate, player ou game_map non initialisé.\n");
        return;
    }

    // Si le pirate voit le joueur (même ligne ou colonne)
    if (pirate->pos.x == player->pos.x || pirate->pos.y == player->pos.y) {
        // Déplace le pirate vers le joueur
        if (pirate->pos.x < player->pos.x) {
            pirate->pos.x++;
        } else if (pirate->pos.x > player->pos.x) {
            pirate->pos.x--;
        } else if (pirate->pos.y < player->pos.y) {
            pirate->pos.y++;
        } else if (pirate->pos.y > player->pos.y) {
            pirate->pos.y--;
        }
    } else {
        // Déplace le pirate aléatoirement
        pirate->pos.x = rand() % 10;
        pirate->pos.y = rand() % 10;
    }

    // Si le pirate est sur la même case que le joueur
    if (pirate->pos.x == player->pos.x && pirate->pos.y == player->pos.y) {
        // Le joueur perd un point de vie
        player->health_point--;
        // Le pirate est déplacé sur une case aléatoire du jeu
        pirate->pos.x = rand() % 10;
        pirate->pos.y = rand() % 10;
    }
}
coordinate get_pos_pirate(Pirate *pirate) {
    coordinate pos;
    pos.x = pirate->pos.x;
    pos.y = pirate->pos.y;
    return pos;
}

void free_pirate(Pirate *pirate) {
    free(pirate);
    pirate = NULL;
}