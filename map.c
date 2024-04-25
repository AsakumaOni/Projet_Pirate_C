#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "player.h"
#include "map.h"
#include "treasure.h"


char **game_map; // Tableau de caractères pour stocker la carte du jeu
#define COLONNE 10
#define LIGNE 10
//Player player ;
char car ;
int fin = 0;
//Treasure treasure;



void initialisation_Map() {
    initialisation_treasure(&treasure); // Initialisation du trésor
    // Initialisation du joueur
     //Allouer memoire pour le tableau
     printf("1la position du tresor est : %d, %d\n", treasure.position_x, treasure.position_y);
    
    game_map = (char **)malloc(LIGNE * sizeof(char *));
    for (int i = 0; i < LIGNE; i++) {
        game_map[i] = (char *)malloc(COLONNE * sizeof(char));
    }

     for(int i=0; i< LIGNE; i++)
    {
        //printf("2la position du tresor est : %d, %d\n", treasure.position_x, treasure.position_y);
    
        for(int j=0; j<COLONNE; j++)
        {
            //printf("3la position du tresor est : %d, %d\n", treasure.position_x, treasure.position_y);
    
            if (i == player.position_x && j == player.position_y) {
                game_map[i][j] = 'P'; // P pour le joueur
            } else if (i == treasure.position_x && j == treasure.position_y) {
                game_map[i][j] = 'T'; // . pour le trésor
            } else {
                game_map[i][j] = ' '; // # pour une case vide
            }
        }
    }

}

void print() {
    // Affichez la carte et le joueur, mais ne déplacez pas le joueur
    for (int i = 0; i < LIGNE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            printf("%c", game_map[i][j]);
        }
        printf("\n");
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

