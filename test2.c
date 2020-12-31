#include <stdlib.h>
#include <string.h>
//#include <conio.h>

int main()
{
	char j1[5];
	char j2[5];
	int tentatives = 20;
	int trouve = 0;
	int jokerUtilise = 0;
	int joker, index;
	int chiffresBienPlaces, chiffresMalPlaces, i;

	int niveau;
	printf("Niveau 1 (debutant) : Tous les chiffres du code sont distincts");
	printf("\nNiveau 2 (expert) : Les chiffres peuvent se repeter");
	printf("\ntaper 1 ou 2 pour choisir : ");
	scanf("%d", &niveau);


	printf("Joueur 1 : proposer un code : ");
	scanf("%s", j1);
	system("cls");

	while(tentatives < 20 && trouve == 0)
	{
		printf("\n========== Niveau %d ==========\n", niveau);

		if (jokerUtilise == 0 && tentatives < 10 && tentatives > 3) {
			printf("\nVoulez-vous utiliser le JOKER oui = 1/non = 0: ");
			scanf("%d", &joker);
			if (joker == 1) {
				jokerUtilise = 1;
				tentatives-=3;
				printf("taper le chiffre a afficher : 0-4");
				scanf("%d", &index);
				printf("%c", j1[index]);
			}
		}


		printf("\n\nJoueur 2 : proposer un code : ");
		scanf("%s", j2);
		chiffresBienPlaces = chiffresMalPlaces = 0;
		if (strcmp(j1, j2) == 0) {
			trouve = 1;
		}
		else {
			for (i = 0; j1[i] != '\0'; i++)
			{
				if (j1[i] == j2[i]) {
					chiffresBienPlaces++;
				}
				else {
					chiffresMalPlaces++;
				}
			}
			printf("\nChiffres Bien Places : %d", chiffresBienPlaces);
			printf("\nChiffres Mal Places : %d", chiffresMalPlaces);
		}
		tentatives--;
		system("cls");
	}

	printf("\nLe code est : %s", j1);



	return 0;
	getch();
}
