#ifndef MAP_H
#define MAP_H

#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include <stdbool.h> // bool
#include <stdlib.h> // malloc
#include "grille.h"
#include "getch.h"
#include "player.h"
#include "treasure.h"


// Fonction pour initialiser le jeu
void initialisation_Map();

// Fonction pour afficher la carte du jeu
void print();

// Fonction pour obtenir le caractère à une position donnée sur la carte du jeu
char get_case(int x, int y);

// Fonction pour définir le caractère à une position donnée sur la carte du jeu
void set_case(int x, int y, char c);
// Libération de la mémoire allouée pour le tableau
void map_liberation();

#endif 