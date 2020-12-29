#include <stdio.h>

int		*calcul_number(int a, int *tab)
{
	tab[0] =  a/10000;
	tab[1] = (a - (tab[0] * 10000)) / 1000;
	tab[2] = (a - ((tab[0] * 10000) + (tab[1] * 1000))) / 100;
	tab[3] = (a - ((tab[0] * 10000) + (tab[1] * 1000) + (tab[2] * 100))) / 10;
	tab[4] =  a % 10;
	return (tab);
}
int		*cmp_nb1_nb2(int *tab, int nb2)
{
	int i;
	int j;
	static int tab3[2];
	int tab4[5];

	tab3[0] = 0;
	tab3[1] = 0;
	i = 0;
	j = 0;
	int *tab2 = calcul_number(nb2, tab4);
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (tab[i] == tab2[j] && i == j)
			{
				tab3[0]++;
				i = 5;
			}
			else if (tab[i] == tab2[j] && i != j)
			{
				tab3[1]++;
				i = 5;
			}
			i++;
		}
		j++;
	}
	return (tab3);
}

int		jeu(int a)
{
	int nb_try = 1;
	int nb2;
	int tab3[5];
	
	int *tab = calcul_number(a, tab3);
	printf("joueur 2 Veuillez un nombre à 5 chiffres : ");
	scanf("%d", &nb2);
	while (nb_try < 3)
	{
		int *tab2 = cmp_nb1_nb2(tab, nb2);
		if (tab2[0] == 5)
		{
			printf("vous avez reussi");
			return (0);
		}
		else
			printf("vous avez %d nombre  bien placés et %d nombre mal placés\n", tab2[0], tab2[1]);
		printf("joueur 2 Veuillez un nombre à 5 chiffres : ");
		scanf("%d", &nb2);
		nb_try++;
	}
	printf("Vous avez perdu le code etait %d:\n", a);
	return (0);
}
int		main()
{
	int a;

	printf("Joueur 1 veuillez rentrer votre nombre svp : ");
	scanf("%d", &a);
	jeu(a);
}

