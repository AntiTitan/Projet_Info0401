#include <stdio.h>
#include <stdlib.h>

int main(){
	int taille, i, j;
	int *Tab;

	printf("Saisir la taille de la suite de nombre : ");
	scanf("%d", &taille);	// L'utilisateur saisit la taille du tableau

	Tab = (int*)malloc(sizeof(int) * taille);	// Allocation dynamique du tableau

	for (i = 0 ; i < taille ; i++){
		printf("Saisir une valeur : ");
		scanf("%d", &Tab[i]);	// L'utilisateur saisit les valeurs du tableau
	}

	for (i = 0, j = taille - 1 ; i < j ; i++, j--){		
	/* La variable i parcourt la suite du début jusqu'à la fin
	La variable j parcourt la suite de la fin jusqu'au début
	Pour que la suite soit un palindrome, Tab[i] == Tab[j] */

		if (Tab[i] != Tab[j]){
			printf("La suite n'est pas un palindrome\n");

			free(Tab);
			Tab = NULL;

			return 0;

			// Si la suite de nombres n'est pas un palindrome, un message est affiché et le programme s'arrête
		}
	}

	// Si le programme ne s'est pas arrêté, cela signifie que la suite est un palindrome

	printf("La suite est un palindrome\n");

	free(Tab);
	Tab = NULL;

	return 0;	
}