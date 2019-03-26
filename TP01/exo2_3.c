#include <stdio.h>
#include <stdlib.h>

void afficher(int *tab, int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main() {
    int *v1;
    int i, j=0, imax, max=0, tmp=0, nb;

    // Initialisation du tableau

    do {
        printf("Entrez la taille du tableau: ");
        scanf("%d", &nb);
    } while (nb<0);

    v1=malloc(nb*sizeof(int));

    for (i=0; i<nb; i++) {
        printf("Entrez la valeur de v1[%d]: ", i);
        scanf("%d", &v1[i]);
    }

    afficher(v1,nb);

    // Recherche du max de chiffres positifs à la suite

    for (i=0; i<nb; i++) {
        if (v1[i]>=0) {
            tmp++;
            j=i;
        }
        else if (v1[i]<=0 && tmp>max) {
            max=tmp;
            imax=j;
            tmp=0;
        }
    }

    printf("La suite de positifs la plus longue se trouve de v1[%d] a v1[%d] \n", imax-max+1, imax);

    for (i=imax-max+1; i<imax; i++)
        printf("%d ", v1[i]);
    printf("\n");

    return 0;
}
