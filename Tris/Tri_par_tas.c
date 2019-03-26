#include <stdio.h>

int main() {
    int tas[10], nb, i, j, cpt, root, temp;

    printf("\nSaisir le nombre d'elements :");
    scanf("%d", &nb);
    printf("\nSaisir les valeurs: \n");
    for (i=0; i<nb; i++) {
        printf("tas[%d]: ", i);
        scanf("%d", &tas[i]);
    }
    
    for (i=1; i<nb; i++) {
        cpt=i;
        do {
            root=(cpt-1)/2;
            if (tas[root] < tas[cpt]) {  /* formation du tableau */ 
                temp=tas[root];
                tas[root]=tas[cpt];
                tas[cpt]=temp;
            }
            cpt=root;
        } while (cpt!=0);
    }

    printf("Tableau de depart: ");
    for (i = 0; i < nb; i++)
        printf("%d\t  ", tas[i]);
    for (j=nb-1; j>=0; j--) {
        temp=tas[0];
        tas[0]=tas[j];  /* Echange entre le max et la feuille la plus à droite */
        tas[j]=temp;
        root=0;
        do {
            cpt=2*root+1;    /*le noeud gauche du root */
            if ((tas[cpt]<tas[cpt+1]) && (cpt<(j-1)))
                cpt++;
            if (tas[root]<tas[cpt] && cpt<j) {   /* reformation du tableau */
                temp=tas[root];
                tas[root]=tas[cpt];
                tas[cpt]=temp;
            }
            root=cpt;
        } while (cpt<j);
    }
    printf("\nTableau trie : ");
    for (i=0; i<nb; i++)
       printf("\t %d", tas[i]);
    printf("\n");
    return 0;
}
