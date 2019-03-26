#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// fonction extraite

// structure
typedef struct cellule{
    int val; //tete
    struct cellule *suiv; //queue
}cellule;

typedef cellule* liste;

//creer une liste vide
liste creer() {
    liste L;
    L=(cellule*)malloc(sizeof(cellule));
    L->val=0;
    L->suiv=NULL;
    return L;
}

//voir si la liste est vide
int estVide(liste L) {
    if (L==NULL) return 1;
    else return 0;
}

//vider une liste
liste vider(liste L) {
    if (estVide(L)) return NULL;
    else{
        cellule* tmp;
        tmp=L->suiv;
        free(L);
        return vider(tmp);
    }
}

//afficher une liste chainée
void afficherListe(liste L) {
    cellule* tmp=L;
    while (tmp->suiv!=NULL) { // tant qu'on est pas a la fin de la liste
        printf("%d  ", tmp->val);
        tmp=tmp->suiv;
    }
    printf("%d  ", tmp->val);
    printf("\n");
}

//ajout d'un element au debut de la liste 
liste ajouterDebut(liste L, int val) {
    cellule* newElement=(cellule*)malloc(sizeof(cellule));
    newElement->val=val;
    newElement->suiv=L;
    return newElement;
}

//suppression d'un element au debut de la liste 
liste supDebut(liste L) {
    if (L!=NULL) {
        cellule* res=L->suiv;
        free(L);
        return res;
    }
    else return NULL;
}

//ajout d'un element en fin de liste
liste ajouterFin(liste L, int val) {
    cellule* newElement=(cellule*)malloc(sizeof(cellule));
    newElement->val=val;
    newElement->suiv=NULL;
    if (L==NULL) {   // liste vide
        return newElement;
    }
    else {
        cellule* tmp=L;
        while (tmp->suiv != NULL) {
            tmp=tmp->suiv;
        }
        tmp->suiv=newElement;
        return L;
    }
}

//suppression d'un element à la fin de la liste 
liste supFin(liste L) {
    if (L==NULL) return NULL;
    if (L->suiv==NULL) {
        free(L);
        return NULL;
    }

    cellule* tmp=L;
    cellule* ptmp=L;

    while (tmp->suiv!=NULL) {
        ptmp=tmp;
        tmp=tmp->suiv;
    }
    ptmp->suiv=NULL;
    free(tmp);
    return L;
}

//saisir une liste chainee
liste saisir(liste L,int size) {
    int i, v;

    printf("Entrez la valeur 0: ");
    scanf("%d", &v);
    L->val=v;

    for (i=1; i<size; i++) {  //demande des valeurs
        printf("Entrez la valeur %d: ", i);
        scanf("%d", &v);
        ajouterFin(L, v);
    }
    return L;
}

//compter le nombre d'elements d'une liste
int nbElement(liste L) {
    if (estVide(L)==1) return 0;
    return nbElement(L->suiv)+1;
}

//fusion de 2 listes triées
liste fusion(liste L1, liste L2) {
    liste tmp1=L1, tmp2=L2;

    if (tmp1==NULL) {return tmp2;}
    else if (tmp2==NULL) {return tmp1;}
    else if ((tmp1->val)<=(tmp2->val)) {
        tmp1->suiv=fusion(tmp1->suiv,tmp2);
        return tmp1;
    }
    else {
        tmp2->suiv=fusion(tmp1,tmp2->suiv);
        return tmp2;
    }
}

//egalite de 2 listes
int egalite(liste L1, liste L2) {
    while (L1!=NULL && L2!=NULL) {
        if (L1->val!=L2->val) return 0;
        L1=L1->suiv;
        L2=L2->suiv;
    }
    return (L1==NULL && L2==NULL);
}

//recherche d'un element dans une liste
int recherche(liste L, int val) {
    cellule* tmp=L;
    int i=1;

    while (tmp!=NULL) {
        if (tmp->val==val) {
            printf("L'indice de l'element recherche dans la liste est:");
            return i;
        }
        i++;
        tmp=tmp->suiv;
    }
    printf("L'element cherche n'est pas present dans la liste ");
    return 0;
}

//ajouter un element a une position precise
//supprimer un element
//union de 2 listes
//intersection de 2 listes
//trier une liste
//multiplication + addition de 2 polynomes
//listes binaires
//fction extraite

int main() {
    int e, trouve;
    liste L, M, N;
    L=creer();
    M=creer();
    printf("Saisie de L:\n");
    saisir(L, 5);

    printf("Saisie de M:\n");
    saisir(M, 5);

    printf("Affichage de L:\n");
    afficherListe(L);

    printf("Affichage de M:\n");
    afficherListe(M);

    L=ajouterDebut(L,1);
    ajouterFin(M,20);
    printf("Ajout de 1 au debut de L:\n");
    afficherListe(L);
    printf("Ajout de 20 a la fin de M:\n");
    afficherListe(M);

    N=fusion(L,M);
    printf("Affichage de N:\n");
    afficherListe(N);

    e=egalite(L,M);
    printf("\n0=NON, 1=OUI\negalite de L et M: %d\n", e);

    trouve=recherche(L, 1);
    if (trouve!=0) 
        printf("%d\n", trouve);
    
    return 0;
}