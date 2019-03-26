#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pile {
    int val;
    struct Pile *prec;
} PILE;

PILE* creer() {
    PILE* p=malloc(sizeof(PILE));
    return p;
}

int estVide(PILE *p) {
    if (p==NULL) return 1;
    return 0;
}

PILE* initialiser(PILE *p) {
    int val, i;
    creer(p);
    printf("Saisir la valeur 0:");
    scanf("%d", &val);
    p->val=val;
    p->prec=NULL;
    return p;
}

void empiler(PILE *p, int e) {
    PILE *newElement=malloc(sizeof(*newElement));
    if (newElement!=NULL) {
        newElement->val=e;
        newElement->prec=p;
        p=newElement;
    }
}

PILE* saisir(PILE *p) {
    int val;
    while (1) {
        printf("Saisir une valeur, si la valeur est negative la saisie est stoppee:\n");
        scanf("%d",&val);
        if (val<0) exit(0);
        empiler(p,val);
    }
    return p;
}

int depiler(PILE *p) {
    PILE* tmp;
    int retour=-1;
    if (p!=NULL) {
        tmp=p->prec;
        retour=p->val;
        free(p);
        p=tmp;
    }

    return retour;
}

int sommet(PILE* p) {
    int retour=-1;
    if (p!=NULL)
        retour=p->val;
    return retour;
}

PILE* vider(PILE* p) {
    while (p!=NULL) {
        depiler(p);
    }
    
    return p;
}

void afficher(PILE* p) {
    if (p==NULL) {
        printf("La pile est vide !! ");
        return;
    }
    PILE *p2;
    *p2=*p;
    printf("Contenu de la pile en commencant par le sommet:\n");

    while (p2->prec!=NULL) {
        printf("%d \n", p2->val);
        p2=p2->prec;
    }
    printf("\n");
}

// Egalite

//recherche et suppression d'une occurence
void supprimer(PILE *p, int x) {
    PILE *p2;
    creer(p2);
    while (p!=NULL) {
        empiler(p2, depiler(p));
    }
    while (p2!=NULL) {
        if (sommet(p2)!=x)
            empiler(p,sommet(p2));
        depiler(p2);
    }
}

// Trier
// PILE* trier(PILE *p) {
//     PILE *p2, *p3;
//     int min;
//     creer(*p2);
//     creer(*p3);
    
// }


int main() {
    PILE* p;
    p=creer();
    p=initialiser(p);
    afficher(p);
    p=saisir(p);
    afficher(p);
    empiler(p, 7);
    afficher(p);
    depiler(p);
    afficher(p);

    return 0;
}