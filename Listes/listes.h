#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// fonction extraite

// structure
typedef struct cellule;
struct cellule{
    int val; //tete
    struct cellule *suiv; //queue
};

typedef cellule* liste;

//afficher une liste chainée
void afficherListe(liste );

//ajout d'un element au debut de la liste
liste ajouterDebut(liste , int );

//ajout d'un element en fin de liste
liste ajouterFin(liste , int );

//saisir une liste chainee
liste saisir(int );

#endif