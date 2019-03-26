#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bleu 1 // indice i
#define blanc 2 // indice j
#define rouge 3 // indice k

void afficher(int *tab, int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main() {
	int k, n, tmp, i, j;
	int *tab;

	do {
        printf("Entrez la taille du tableau (max 100):");
        scanf("%d", &n);
    } while (n<0 || n>100);

    tab=malloc(n*sizeof(int));
    printf("Remplir le tableau avec les entiers correspondant a la couleur voulue: \n   1=bleu \n   2=blanc \n   3=rouge \n");

    for (i=0; i<n; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
	printf("\n");

    printf("\nVoici le contenu du tableau avant tri :\n");
    afficher(tab, n);
	printf("\n");

	k=n-1;
    j=-1;
    i=-1;

    while (j!=k) {
        if (tab[j+1]==bleu) {
            tmp=tab[j+1];
            tab[j+1]=tab[i+1];
            tab[i+1]=tmp;
            i++;
            j++;
        }
        else if (tab[j+1]==rouge) {
            tmp=tab[k];
            tab[k]=tab[j+1];
            tab[j+1]=tmp;
            k--;
        }
        else
            j++;
    }

	printf("\nVoici le contenu du tableau apres tri :\n");
    afficher(tab, n);

    free(tab);

	return 0;
}