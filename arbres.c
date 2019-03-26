#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Algorithmes a faire:
    ancetre d'un noeud donné: ancetre(a,b): boolean
    ancetre commun (a,b,c):boolean
    noeuds internes+externes+globales
    H-equilibre
    AVL: rotations

Algorithmes qui ne fonctionnent pas:
    tester l'egalite

Algorithmes qui fonctionnent:
    creer
    inserer
    vider
    recherche de la valeur min de l'arbre
    recherche de la valeur max de l'arbre
    recherche d'une valeur de l'arbre
    Hauteur d'un arbre
    Parcours avec affichage
        Prefixe
        Postfixe
        Infixe
    

*/


/* Structure de l'arbre */
typedef struct Arbre Arbre;

struct Arbre {
    Arbre *FG, *FD;
    int element;
};

Arbre* creer() {
    Arbre* t=(Arbre*)malloc(sizeof(Arbre));
    t->FG = t->FD = NULL;
    return t;
}

/* Insertion d'une valeur dans un arbre, si la valeur est déjà présente,l'insertion sera ignoré */
/* Retourne un pointeur vers l'emplacement de l'insertion */

void insertion(int val, Arbre* t) {
    Arbre* newNode;
    newNode = (Arbre*)malloc(sizeof(Arbre));
    newNode->FG = newNode->FD = NULL;
    newNode->element = val;

    /* Arbre sans aucune valeur: val=racine */
    if (t->element==0) {
        t=newNode;
        return;
    }

    /* On construit l'arbre pour que les val inf a gauche et sup a droite */
    if (val < t->element && t->FG!=NULL) {
        insertion(val, t->FG);
    }
    else if (val < t->element && t->FG==NULL) {
        t->FG=newNode;
    }
    else if (val > t->element && t->FD!=NULL) {
        insertion(val, t->FD);
    }
    else if (val > t->element && t->FD==NULL) {
        t->FD=newNode;
    }
    else {
        /* valeur déjà présente ignorée */
        return;
    }
    return;
}

/* Vider un arbre */

Arbre* vider(Arbre* t) {
    if (t != NULL) {
        vider(t->FG);
        vider(t->FD);
        free(t);
    }

    return NULL;
}

/* Chercher la val min d'un arbre */

Arbre* Min(Arbre* t) {
    if (t == NULL) return NULL;
    
    /* Arbre AVL on cherche donc a gauche seulement */
    else if (t->FG == NULL) return t;
    
    /* La valeur min se trouve sur la derniere feuille la plus a gauche */
    else return Min(t->FG);
    
}

/* Chercher la val max d'un arbre */

Arbre* Max(Arbre* t) {
    if (t == NULL) return NULL;
    
    /* Arbre AVL on cherche donc a droite seulement */
    else if (t->FD == NULL) return t;
    
    /* La valeur min se trouve sur la derniere feuille la plus a droite */
    else return Max(t->FD);
    
}

/* Rechercher si une val est presente dans un arbre*/

Arbre* recherche(int val, Arbre* t) {
    if (t == NULL) return NULL;
    
    if (val < t->element) {
        return recherche(val, t->FG);
    }
    else if (val > t->element) {
        return recherche(val, t->FD);
    }
    else return t;
}

/* Hauteur d'un arbre */

int hauteur(Arbre* t) {
    if (t == NULL) return 0;

    else {
        /* Calcul de la hauteur des sous-arbres */
        int hauteurG = hauteur(t->FG);
        int hauteurD = hauteur(t->FD);

        if (hauteurG > hauteurD) return (hauteurG+1);
        else return (hauteurD+1);
    }
}

/* Affichage du parcours prefixe*/

void Prefixe(Arbre* t) {
    if (t != NULL) {
        printf("%d  ", t->element);
        Prefixe(t->FG);
        Prefixe(t->FD);
    }
}

/* Affichage du parcours postfixe*/

void Postfixe(Arbre* t) {
    if (t != NULL) {
        Postfixe(t->FG);
        Postfixe(t->FD);
        printf("%d  ",t->element);
    }
}

/* Affichage du parcours infixe*/

void Infixe(Arbre* t) {
    if (t != NULL) {
        Infixe(t->FG);
        printf("%d  ",t->element);
        Infixe(t->FD);
    }
}

/* Verification de l'egalite de 2 arbres */

int egalite(Arbre* t1, Arbre*t2) {
    Arbre* tmp1=t1;
    Arbre* tmp2=t2;

    //Si les hauteurs sont différentes il est impossible qu'ils soient egaux

    if (hauteur(tmp1) != hauteur(tmp2)) return 0;
    if ((tmp1->element == tmp2->element) && (tmp1->FG == NULL && tmp1->FD == NULL && tmp2->FG == NULL && tmp2->FD == NULL)) return 1;
    else if (tmp1 != NULL && tmp2 != NULL) {
        int egaliteG= egalite(tmp1->FG, tmp2->FG);
        int egaliteD= egalite(tmp1->FD, tmp2->FD);
        if (egaliteG == 1 && egaliteD == 1) return 1;
        else return 0;
    }
}

/*  Fonctions utilisees pour l'affichage */

void padding ( char ch, int n ){
    int i;
    for (i=0;i<n;i++)
    putchar (ch);
}

void afficher (Arbre* t, int level){
    int i;
    if ( t == NULL ) {
        padding ( '\t', level );
        puts ( "~" );
    }
    else {
        afficher ( t->FD, level + 1 );
        padding ( '\t', level );
        printf ( "%d\n", t->element );
        afficher ( t->FG, level + 1 );
    }
}



int main() {
    /**** Initialisation des arbres ****/
    Arbre* t=creer();
    Arbre* t2=creer();
    Arbre* ma=creer();
    Arbre* mi=creer();

    /**** vider l'arbre ****/
    vider(t);

    /**** Insertion de certains valeurs ****/
    printf("\n----------------- Insertion -----------------\n");
    printf("\nApres l'insertion de la valeur 10..\n");
    insertion(10, t);
    insertion(10, t2);
    afficher(t,0);

    printf("\nApres l'insertion de la valeur 5..\n");
    insertion(5, t);
    insertion(5, t2);
    afficher(t,0);

    printf("\nApres l'insertion de la valeur 15..\n");
    insertion(15, t);
    insertion(15, t2);
    afficher(t,0);

    printf("\nApres l'insertion des valeur 9, 13..\n");
    insertion(9, t);
    insertion(13, t);
    insertion(9, t2);
    insertion(13, t2);
    afficher(t,0);

    printf("\nApres l'insertion des valeurs 2, 6, 12, 14, ..\n");
    insertion(2, t);
    insertion(6, t);
    insertion(12, t);
    insertion(14, t);
    insertion(2, t2);
    insertion(6, t2);
    insertion(12, t2);
    insertion(14, t2);
    afficher(t,0);


    /******************* Parcours **********************/
    printf("\n**************** parcours ****************\n\n");
    printf("Pre Fixe\n-------\n");
    Prefixe(t);
    printf("\n\nPost Fixe\n-------\n");
    Postfixe(t);
    printf("\n\nIn Fixe\n-------\n");
    Infixe(t);
    printf("\n");
    printf("\n******************************************\n");

    /******************* Recherche *******************/
    
    Arbre* cherche=recherche(50,t);
    printf("Recherche de la valeur 50 en cours...\n");
    if(cherche)
        printf("La valeur cherchee se trouve dans l'arbre\n");
    else
        printf("La valeur cherchee n'apparait pas dans l'arbre\n");

    Arbre* cherche2 = recherche(15,t);
    printf("Recherche de la valeur 15 en cours...\n");
    if(cherche2)
        printf("La valeur cherchee se trouve dans l'arbre\n");
    else
        printf("La valeur cherchee n'apparait pas dans l'arbre\n");

    vider(cherche);
    vider(cherche2);
    printf("\n******************************************\n");

    /******************* Recherche du maximum *******************/
    ma=Max(t);
    printf("\nRecherche du maximum en cours...\n");
    printf("Le Maximum vaut : %d\n",ma->element);
    printf("\n******************************************\n");
    vider(ma);

    /******************* Recherche du minimum *******************/
    mi=Min(t);
    printf("\nRecherche du minimum en cours...\n");
    printf("Le Minimum vaut : %d\n",mi->element);
    printf("\n******************************************\n");
    vider(mi);

    /******************* Hauteur de l'arbre *******************/
    printf("\nHauteur de l'arbre vaut : %d\n", hauteur(t)-1);
    printf("\n******************************************\n");

    /******************* Egalite *******************/

    printf("Test d'egalite: \n");
    afficher(t,0);
    afficher(t2,0);
    int i=egalite(t,t2);
    if(i)
        printf("Les deux arbres sont egaux\n");
    else
        printf("Les deux arbres ne sont pas égaux");

    vider(t);
    vider(t2);

    return 0;
}