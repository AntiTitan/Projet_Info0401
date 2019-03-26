#include <stdio.h>
main() {
    /* Déclarations */

    int A[50][50]; /* matrice donnée   */
    int B[50][50]; /* matrice donnée   */
    int C[50][50]; /* matrice résultat */
    int n;         /* dimension des matrices */
    int i, j, k;   /* indices courants */

    /* Saisie des données */

    printf("*** Initialisation des matrices ***\n");

    printf("Dimension des matrices (max 50) : ");
    scanf("%d", &n );

    printf("*** Matrice A ***\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            printf("Elément A[%d][%d] : ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("*** Matrice B ***\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            printf("Elément B[%d][%d] : ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    /* Affichage des matrices */

    printf("Matrice A donnée :\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%7d", A[i][j]);
        printf("\n");
    }

    printf("Matrice B donnée :\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%7d", B[i][j]);
        printf("\n");
    }
    
    /* Affectation du résultat de la multiplication à C */

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            C[i][j]=0;
            for (k=0; k<n; k++)
                C[i][j] += A[i][k]*B[k][j];
        }
    }

    /* Affichage du résultat */

    printf("Matrice résultat C :\n");
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++)
            printf("%7d", C[i][j]);
        printf("\n");
    }
    
    return 0;
}