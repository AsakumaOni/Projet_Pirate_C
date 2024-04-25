#include <stdlib.h>
#include <stdio.h>
#include "grille.h"
#include "getch.h"
#include "player.h"
#include "map.h"
#include "treasure.h"

//#define COLONNE 5

//#define LIGNE 4

/**int main()
{
    char car ;
    int fin = 0;
    char **test_grille;
    int pos_joueur_x = 0;
    int pos_joueur_y = 0;
    Player player;
    



    //Allouer memoire pour le tableau
    test_grille = (char **)malloc(LIGNE * sizeof(char *));
    for (int i = 0; i < LIGNE; i++) {
        test_grille[i] = (char *)malloc(COLONNE * sizeof(char));
    }

    //Remplissage du tableau
    for(int i=0; i< LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            test_grille[i][j] = ' ';
        }
    }
    test_grille[pos_joueur_x][pos_joueur_y] = 'j';

    //Affichage du tableau
    grille_print(test_grille, COLONNE, LIGNE);

    while(!fin)
    {
        car = getch();
        test_grille[pos_joueur_x][pos_joueur_y] = ' ';
        switch(car)
        {
            case 'q':
                fin = 1;
                break;
            case 'i':
                pos_joueur_x--; 
                break;
            case 'k':
                pos_joueur_x++; 
                break;
            case 'j':
                pos_joueur_y--; 
                break;
            case 'l':
                pos_joueur_y++; 
                break;
        }
        test_grille[pos_joueur_x][pos_joueur_y] = 'j';
        system("clear");
        grille_print(test_grille, COLONNE, LIGNE);

    }

  
    //Liberation de la memoire pour le tableau
    for (int i = 0; i < LIGNE; i++) {
        free(test_grille[i]);
    }
    free(test_grille);

    // Initialisation du joueur
    initialisation(&player);

    // Exemple d'utilisation :
    char movement_input;
    while (true) {
        printf("Entrez la direction (Z, Q, S, D) ou 'a' pour quitter : ");
        scanf(" %c", &movement_input);
        
        if (movement_input == 'a') {
            break; // Quitter si la touche 'q' est pressée
        }

        movement(&player, movement_input); // Déplacer le joueur dans la direction spécifiée

        // Afficher la position actuelle du joueur
        Coordinate pos = get_pos(&player);
        printf("Position actuelle du joueur : (%d, %d)\n", pos.x, pos.y);
    }

    return 0;

}**/
Player player;
Treasure treasure;
int main(){
    initialisation_Player(&player);
    initialisation_Map();
    start_game();
    return 0;
}

void start_game() {
    char direction;
    while (1) {
        print();
        scanf(" %c", &direction); // Lire la direction du joueur
        if (!movement(direction)) {
            printf("Mouvement invalide ou joueur mort. La partie est terminée.\n");
            break;
        }
        if (player.position_x == treasure.position_x && player.position_y == treasure.position_y) {
            printf("Félicitations, vous avez trouvé le trésor !\n");
            break;
        }
    }
    map_liberation();
}

