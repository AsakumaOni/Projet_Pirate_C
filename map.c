#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "player.h"
#include "map.h"
#include "treasure.h"
#include "trap.h"


char **game_map; // Tableau de caractères pour stocker la carte du jeu
#define COLONNE 10
#define LIGNE 10
char car ;
int fin = 0;
Trap trap;




void initialisation_Map(Player *player) {
    initialisation_treasure(&treasure); 
    
    initialisation_trap(&trap);
    
    printf("1la position du tresor est : %d, %d\n", treasure.pos.x, treasure.pos.y);
    printf("1la position du trap est : %d, %d\n", trap.pos.x, trap.pos.y);
    game_map = (char **)malloc(LIGNE * sizeof(char *));
    if (game_map == NULL) {
        printf("Erreur d'allocation de mémoire pour game_map.\n");
        return;
    }
    // Assurez-vous que player, treasure et trap sont initialisés
    if (player == NULL || &treasure == NULL || &trap == NULL) {
        printf("Erreur : player, treasure ou trap non initialisé.\n");
        return;
    }

// Assurez-vous que pos.x et pos.y sont dans les limites de game_map
    if (player->pos.x < 0 || player->pos.x >= LIGNE || player->pos.y < 0 || player->pos.y >= COLONNE ||
        treasure.pos.x < 0 || treasure.pos.x >= LIGNE || treasure.pos.y < 0 || treasure.pos.y >= COLONNE ||
        trap.pos.x < 0 || trap.pos.x >= LIGNE || trap.pos.y < 0 || trap.pos.y >= COLONNE) {
        printf("Erreur : pos.x ou pos.y hors des limites de game_map.\n");
        return;
    }

    for (int i = 0; i < LIGNE; i++) {
        game_map[i] = (char *)malloc(COLONNE * sizeof(char));
        if (game_map[i] == NULL) {
            printf("Erreur d'allocation de mémoire pour game_map[%d].\n", i);
            return;
        }
    }
     for(int i=0; i< LIGNE; i++)
    {
        //printf("2la position du tresor est : %d, %d\n", treasure.pos.x, treasure.pos.y););
    
        for(int j=0; j<COLONNE; j++)
        {
            //printf("3la position du tresor est : %d, %d\n", treasure.pos.x, treasure.pos.y););
    
            if (i == player->pos.x && j == player->pos.y) {
                game_map[i][j] = 'P'; // P pour le joueur
            } else if (i == treasure.pos.x && j == treasure.pos.y) {
                game_map[i][j] = 'T'; // . pour le trésor

            } else if (i == trap.pos.x && j == trap.pos.y) {
                game_map[i][j] = 'X'; // X pour le piège
            } else {
                game_map[i][j] = ' '; // # pour une case vide
            }
        }
    }

}

void print (Player *player){
    grille_print(game_map, COLONNE, LIGNE);
    
    while(!fin)
    {
        car = getch(); 
        game_map[player->pos.x][player->pos.y] = ' ';
        int new_x = player->pos.x;
        int new_y = player->pos.y;
        switch(car)
        {
            case 'a':
                fin = 1;
                break;
            case 'z':
                new_x--; 
                break;
            case 's':
                new_x++; 
                break;
            case 'q':
                new_y--; 
                break;
            case 'd':
                new_y++; 
                break;
        }
        // Vérifie si les nouvelles coordonnées sont à l'intérieur de la grille
        if (new_x >= 0 && new_x < LIGNE && new_y >= 0 && new_y < COLONNE) {
            // Met à jour les coordonnées du joueur
            player->pos.x = new_x;
            player->pos.y = new_y;
        }
        if (player->pos.x == treasure.pos.x && player->pos.y == treasure.pos.y) {
            printf("Félicitations, vous avez trouvé le trésor !\n");
            printf("vos point de vie sont : %d\n", player->health_point);
            free_trap(&trap);
            break;
        }
        printf("vos point de vie sont : %d\n", player->health_point);
        if (player->health_point <= 0) {
            printf("Vous avez perdu !\n");
            free_trap(&trap);
            break;
        }
        if (player->pos.x == trap.pos.x && player->pos.y == trap.pos.y) {
            printf("Vous avez marché sur un piège !\n");
            player->health_point -= 10;
        }
     
        game_map[player->pos.x][player->pos.y] = 'j';
        game_map[treasure.pos.x][treasure.pos.y] = 'T';
        system("clear");
        grille_print(game_map, COLONNE, LIGNE);

    }
}


char get_case(int x, int y){
    return game_map[x][y];
}

void set_case(int x, int y, char c){
    game_map[x][y] = c;
}
// Libération de la mémoire allouée pour le tableau
void map_liberation(){
    for (int i = 0; i < LIGNE; i++) {
        free(game_map[i]);
    }
    free(game_map);
}

