#include <stdio.h>
#include <stdlib.h>

void afficher(int *tab, int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}

int main() {
    int **M;
    int *v1, *v2, *l;
    int i, j, k, n, tmp;

    do {
        printf("Entrez la taille de la matrice caree (max 100):");
        scanf("%d", &n);
    } while (n<0 || n>100);

    v1=(int*)malloc(n*sizeof(int)); // d+
    v2=(int*)malloc(n*sizeof(int)); // d-
    l=(int*)malloc(n*sizeof(int));

    for (i=0; i<n; i++) {
        v1[i]=0;
        v2[i]=0;
    }

    M=(int**)malloc(n*sizeof(int*));

    for (i=0; i<n; i++) {
        M[i]=(int*)malloc(n*sizeof(int));
        for (j=0; j<n; j++) {
            printf("Saisissez M[%d][%d]", i, j);
            scanf("%d", &tmp);
            M[i][j]=tmp;
            if (tmp==1) {
                ++v1[i];
                ++v2[j];
            }
        }
    }

    printf("--------M--------\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf(" %d ", M[i][j]);
        }
	    printf("\n");
    }
    printf("\n");

    printf("d+ : ");
    for (i=0; i<n; i++) {
        printf(" %d ", v1[i]);
    }
    printf("\n");

    printf("d- : ");
    for (i=0; i<n; i++) {
        printf(" %d ", v2[i]);
    }
    printf("\n");

    for (i=0; i<n; i++) {
        j=0;
        while (v1[j]!=0) {
            j++;
        }
        l[i]=j+1;
        v1[j]=-1;
        for (k=0; k<n; k++) {
            if (M[j][k]==1) {
                --v1[k];
            }
        }
    }

	printf("\n");

    for (i=0; i<n; i++) {
        printf(" %d ", l[i]);
    }

    free(M);

    return 0;
}