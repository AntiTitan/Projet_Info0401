#include <stdio.h>
#include <stdlib.h>

void afficher(int *tab, int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main() {
    int *tab;
    int size, n, aux, i;

    do {
        printf("Entrez la taille du tableau (max 100):");
        scanf("%d", &n);
    } while (n<0 || n>100);

    tab=malloc(n*sizeof(int));
    size=n;

    for (i=0; i<n; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    while (size>1) {
        for (i=0; i<size-1; i++) {
            if (tab[i]>tab[i+1]) {
                aux=tab[i+1];
                tab[i+1]=tab[i];
                tab[i]=aux;
            }
        }
        size=size-1;
    }

    afficher(tab, n);

    free(tab);

    return 0;
}