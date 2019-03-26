#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct element_pile {
    int val;
    struct element_pile *prec;
} ELEMENT_PILE;

typedef struct Pile {
    ELEMENT_PILE *first;
} PILE;

PILE *ma_pile;

PILE* creer() {
    PILE *p=malloc(sizeof(PILE));
    p->first=NULL;
}

void empiler(PILE* p, int val) {
    ELEMENT_PILE* newElement=malloc(sizeof(ELEMENT_PILE));
    if (newElement!=NULL) {
        newElement->val=val;
        newElement->prec=p->first;
        p->first=newElement;
    }
}

int depiler (PILE* p) {
    int retour=-1;
    if (p->first!=NULL) {
        ELEMENT_PILE* tmp=p->first->prec;
        retour=p->first->val;
        free(p->first);
        p->first=tmp;
    }
    return retour;
}

int sommet(PILE* p) {
    int retour=-1;
    if (p->first!=NULL) {
        retour=p->first->val;
    }
    return retour;
}

void vider(PILE* p) {
    while(p->first!=NULL) {
        depiler(p);
    }
}

int chercher_val(PILE* p, int val) {
    ELEMENT_PILE* p_Element;
    if (p->first==NULL) return 0;  // Pile vide
    p_Element=p->first;
    while(p_Element!=NULL) {
        if (p_Element->val==val) return 1;
        p_Element-p_Element->prec;
    }
    return 0;
}

void afficher(PILE* p) {
    if (p->first==NULL) {
        printf("La pile est vide !!");
        return;
    }
    ELEMENT_PILE* p_Element;
    p_Element=p->first;
    printf("Contenu de la pile en commencant par le sommet:\n");
    while(p_Element!=NULL) {
        printf("%d\n",p_Element->val);
        p_Element=p_Element->prec;
    }
    printf("\n");
}

//recherche et suppression d'une occurence
void supprimer(PILE* p, int x) {
    PILE* p2;
    p2=creer();
    while (p->first!=NULL) {
        empiler(p2, depiler(p));
    }
    while (p2->first!=NULL) {
        if (sommet(p2)!=x)
            empiler(p,sommet(p2));
        depiler(p2);
    }
}

void saisir(PILE* p) {
    int val;
    while (1) {
        printf("Saisir une valeur, si la valeur est negative la saisie est stoppee:\n");
        scanf("%d",&val);
        if (val<0) return;
        empiler(p,val);
    }
}

PILE* fusion(PILE* p1, PILE* p2) {
    PILE* p3;
    p3=creer();
    while (p1->first!=NULL && p2->first!=NULL) {
        if (sommet(p1)>sommet(p2)) {
            empiler(p3,depiler(p1));
        }
        else if (sommet(p2)>=sommet(p1)) {
            empiler(p3,depiler(p2));
        }
    }
    return p3;
}

int main() {
    PILE* p1;
    PILE* p2;
    PILE* p3;
    p1=creer();
    p2=creer();
    p3=creer();
    printf("Saisie de p1\n");
    saisir(p1);
    printf("Saisie de p2\n");
    saisir(p2);
    printf("Affichage de p1\n");
    afficher(p1);
    printf("Affichage de p2\n");
    afficher(p2);
    supprimer(p1,5);
    printf("Affichage de p1\n");
    afficher(p1);
    p3=fusion(p1,p2);
    printf("Affichage de p3\n");
    afficher(p3);
}