#include <stdio.h>
#include <stdlib.h>

void afficher(int *tab, int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

void TriRapide(int* tab, int inf, int sup) {
	int G,D,i,j,P,k;

	G=inf;
	D=sup;
	i=G;
	j=sup-1;
	P=tab[sup];
	printf("Le pivot courant est: %d\n",P);
	while (i != j ) {
		while ((tab[i]<P) && (i != j)) {
			i++;
		}
		while ((tab[j]>P) && (i != j)) {
			j--;
		}
		k=tab[i];
		tab[i]=tab[j];
		tab[j]=k;
	}
	if(tab[i]>P) {
		k=tab[i];
		tab[i]=tab[sup];
		tab[sup]=k;
	}
	if(G<i) {
		printf("Appel recursif gauche, inf=%d, sup=%d\n",G,i-1);
		TriRapide(tab,G,i);
	}
	if(D>i+1) {
		printf("Appel recursif droite, inf=%d, sup=%d\n",i+1,D);
		TriRapide(tab,i+1,D);
	}
}

int main() {
	int n;
	int i;
	int *tab;

	do {
        printf("Entrez la taille du tableau (max 100):");
        scanf("%d", &n);
    } while (n<0 || n>100);

    tab=malloc(n*sizeof(int));

    for (i=0; i<n; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }
	printf("\n");

    printf("\nVoici le contenu du tableau avant tri :\n");
    afficher(tab, n);
	printf("\n");

	TriRapide(tab,0,n-1);

	printf("\nVoici le contenu du tableau apres tri :\n");
    afficher(tab, n);

	free(tab);

	return 0;
}