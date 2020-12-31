#include <stdio.h>
#include <string.h>

int		check_niveau(int niveau)
{
	if (niveau == 1 || niveau == 2)
		return (1);
	else
		return (0);
}
int		check_if_number_have_5_digits(int a)
{
	if (a >= 10000 && a <= 99999)
		return (1);
	return (0);
}
int		check_number(int *tab, int niveau)
{
	int i;
	int j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (tab[i] == tab[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int		*calcul_number(int a, int *tab, int niveau)
{
	tab[0] =  a/10000;
	tab[1] = (a - (tab[0] * 10000)) / 1000;
	tab[2] = (a - ((tab[0] * 10000) + (tab[1] * 1000))) / 100;
	tab[3] = (a - ((tab[0] * 10000) + (tab[1] * 1000) + (tab[2] * 100))) / 10;
	tab[4] =  a % 10;
	if (niveau == 1 && check_number(tab, niveau) == 0)
	{
		printf("le nombre contient des chiffres identiques");
		return (0);
	}
		else
	return (tab);
}
int		*cmp_nb1_nb2_nv2(int *tab, int nb2, int niveau)
{
	int	 tab4[5];
	int *tab2 = calcul_number(nb2, tab4, niveau);
	static int tab3[2];
	int i;
	int j;
	tab3[0] = 0;
	tab3[1] = 0;

	i = 0;
	while (i < 5)
	{
		if (tab[i] == tab2[i])
			tab3[0]++;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		while (tab[i] == tab2[i] && i < 5)
			i++;
		j = i + 1;
		while (j < 5)
		{
			while (tab2[j] == tab[j] && j < 5)
			j++;
			if (tab2[i] == tab[j] && j < 5)
				tab3[1]++;
			j++;
		}
		i++;
	}
	return (tab3);
}

int		*cmp_nb1_nb2_nv1(int *tab, int nb2, int niveau)
{
	int i;
	int j;
	static int tab3[2];
	int tab4[5];

	tab3[0] = 0;
	tab3[1] = 0;
	i = 0;
	j = 0;
	int *tab2 = calcul_number(nb2, tab4, niveau);
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

int		jeu(int a, int niveau)
{
	int nb_try = 0;
	int nb2;
	int tab3[5];
	int *tab2;
	int reponse;
	int indice;
	int d;
	
	int *tab = calcul_number(a, tab3, niveau);
	while (nb_try < 7)
	{
		if (nb_try > 3)
		{
			printf("Voulez vous prendre un joker ? 0 pour oui 1 pour non : ");
			scanf("%d", &reponse);
			if (reponse  == 0)
				{
					printf("Veuillez entrer l'emplacement du  chiffre dont vous voulez connaitre la valeur : ");
					scanf("%d", &indice);
					d++;
					printf("le chiffre à l'emplacement %d a pour valeur %d\n", indice, tab[indice -1]);
					nb_try = nb_try - 3;
				}
		}
		printf("joueur 2 Veuillez un nombre à 5 chiffres : ");
		scanf("%d", &nb2);
		if (niveau == 1)
		tab2 = cmp_nb1_nb2_nv1(tab, nb2, niveau);
		else
		tab2 = cmp_nb1_nb2_nv2(tab, nb2, niveau);
		if (tab2[0] == 5)
		{
			printf("vous avez reussi");
			return (0);
		}
		else
			printf("vous avez %d nombre  bien placés et %d nombre mal placés\n", tab2[0], tab2[1]);
		nb_try++;
	}
	printf("Vous avez perdu le code etait %d:\n", a);
	return (0);
}
int		main()
{
	int niveau;
	int a;
	int tab[5];

	printf("Veuillez choisir un Niveau : 1 pour debutant, 2 pour expert : ");
	scanf("%d", &niveau);
	if (check_niveau(niveau) == 0)
	{
		printf("Vous avez selectionné un mauvais niveau");
		return (0);
	}
	printf("Joueur 1 veuillez rentrer votre nombre svp : ");
	scanf("%d", &a);
	if(calcul_number(a, tab, niveau) == 0)
		return (0);
	if (check_if_number_have_5_digits(a) == 1)
	jeu(a, niveau);
	else
	printf ("le format de votre nombre n'est pas correct");
}

