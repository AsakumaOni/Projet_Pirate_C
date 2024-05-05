#include <stdlib.h>
#include <stdio.h>
#include "grille.h"
#include "getch.h"
#include "player.h"
#include "map.h"
#include "treasure.h"


Player *player;
Treasure treasure;
int main(){
    
    player = malloc(sizeof(Player));
    if (player == NULL) {
        printf("Erreur d'allocation de mémoire pour le joueur.\n");
        return 1;
    }
    
    initialisation_Player(player);
    printf("la vie du joueur est : %d\n", player->health_point);
    initialisation_Map(player);
    print(player);
    
    map_liberation();
    free_player(player);
    return 0;
    
}

