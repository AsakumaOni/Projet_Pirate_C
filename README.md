# Projet_Pirate_C
Ce projet de language C avancer de S8 avait pour but de dévellopé un Jeu de pirate ou le but est de trouver le trésor en évitant les pièger et les pirates.

Ici le jeu est fonctionnelle hors mis le camouflage du trésor et du piège qui une fois patch fesait apparaitre un bug disfonctinnant le jeu 

Vous trouverez plusieur méthode comme Pirate.c pour la gestion des pirates, player.c pour la gestion du jouer, map.c pour la gestion de la carte et des mouvement du joueur, trap.c et treasure.c pour les pièges et le trésors et un utility.h pour la structure coordonnee.

ici le jeu est fonctionnel avec le player pouvant se déplacer dans un map de 10X10 avec de présent le pirate et le piège qui viendront faire diminuer les point de vie du joueur.

La majeur partie des test on etait effectuer avec valgrind pour trouver d'evantuelle fuite de mémoire


les difficultés :

la cammouflage de piège et trésors qui une implémenter engendrer un bug du jeu, le choix a était fait de les laisser visible pour fournir un jeu fonctionnel. 

A se jour, sur les fuite de mémoire tropuver il une seule qui n'a pas peu être patch, les tentavie se sont réseulté par un échec finisant par un bug du jeu. 


Enjoy 
