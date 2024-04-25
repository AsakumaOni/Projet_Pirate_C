#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include "player.h"
#include "map.h"




// Fonction pour initialiser le joueur
void initialisation_Player(Player *player) {
    player->position_x = 0; // Position initiale en x
    player->position_y = 0; // Position initiale en y
    player->health_point = 100; // Points de vie initiaux
}

// Fonction pour obtenir la position actuelle du joueur
Coordinate get_pos(Player *player) {
    Coordinate pos;
    pos.x = player->position_x;
    pos.y = player->position_y;
    return pos;
}

// Fonction pour déplacer le joueur dans une direction donnée
bool movement(char direction) {
    // Sauvegarde des anciennes coordonnées
    int old_x = player.position_x;
    int old_y = player.position_y;

    // Mettre à jour la position en fonction de la touche pressée
    switch(direction) {
        case 'z': // Mouvement vers le haut
            player.position_x--;
            break;
        case 's': // Mouvement vers le bas
            player.position_x++;
            break;
        case 'q': // Mouvement vers la gauche
            player.position_y--;
            break;
        case 'd': // Mouvement vers la droite
            player.position_y++;
            break;
        default:
            return false; // Touche invalide
    }

    // Vérifier si le joueur est sur un piège
    //if (map.traps[player.position_x][player.position_y]) {
      //  player.health_point--; // Décrémenter les points de vie
        //if (player.health_point <= 0) {
          //  printf("Vous avez perdu tous vos points de vie. La partie est terminée.\n");
            //return false;
        //}
    //}

    return true; // Mouvement réussi
}