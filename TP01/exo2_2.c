#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

// void Color(int couleurDuTexte,int couleurDeFond) {// fonction d'affichage de couleurs
//         HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
//         SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
// }

void afficher(int *tab, int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int maxi(int *tab, int size) {
    int i, max=0;
    for (i=0; i<size; i++) {
        if (tab[i]>tab[max]) {
            max=i;
        }
    }
    return max+1;
}

int main() {
    int *v1;
    int i, j, max, nb;
    int *v, *v2;

    // Initialisation du tableau trié

    do {
        printf("Entrez la taille du tableau: ");
        scanf("%d", &nb);
    } while (nb<0);

    v1=malloc(nb*sizeof(int));

    // Color(12,8);
    printf("Le tableau doit etre trié\n");
    // Color(15, 0);

    for (i=0; i<nb; i++) {
        printf("Entrez la valeur de v1[%d]: ", i);
        scanf("%d", &v1[i]);
    }

    afficher(v1,nb);

    //size=sizeof(v1)/sizeof(int);

    // Recherche du max pour creer le tableau resultat

    max=0;

    for (i=0; i<nb; i++) {
        if (v1[i]>v1[max]) {
            max=i;
        }
    }

    v=malloc(v1[max]*sizeof(int));
    v2=malloc(v1[max]*sizeof(int));

    for (i=0; i<v1[max]; i++) {
        v[i]=i+1;
        v2[i]=0;
    }

    j=1;

    for (i=0; i<nb; i++) {
        for (j=0; j<v1[max]+1; j++) {
            if (v1[i]==j) {
                v2[j-1]++;
            }
        }
    }

    afficher(v, v1[max]);
    afficher(v2, v1[max]);

    printf("Le candidats %d a recu le plus de voies \n", maxi(v2, v1[max]));

    return 0;
}

// 0 : Noir
// 1 : Bleu foncé
// 2 : Vert foncé
// 3 : Turquoise
// 4 : Rouge foncé
// 5 : Violet
// 6 : Vert caca d'oie
// 7 : Gris clair
// 8 : Gris foncé
// 9 : Bleu fluo
// 10 : Vert fluo
// 11 : Turquoise
// 12 : Rouge fluo
// 13 : Violet 2
// 14 : Jaune
// 15 : Blanc 