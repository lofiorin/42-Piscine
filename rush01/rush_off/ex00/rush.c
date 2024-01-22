/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:27:08 by anomourn          #+#    #+#             */
/*   Updated: 2023/09/17 23:28:10 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	stampa(int tab[4][4][4], int ord);
void	rimuovi_poss(int *tab, int poss);
void	metti_poss(int *tab, int ord, int poss);
int	unica_poss(int *tab, int ord);
int	v_poss(int *tab, int poss);
void	riempi(int **arr, int ord, int ***tab);
void	crea_tabella(int **arr, int ord);
int	set_ord(char *str);

void	stampa(int tab[4][4][4], int ord)
{
	int	i;
	int	j;
	int	k;
	char	c;

	i = 0;
	while (i < ord)
	{
		j = 0;
		while (j < ord)
		{
			k = 0;
			while (k < ord)
			{
				if (tab[i][j][k] == 1)
				{
					if (k != 0)
						write(1, " ", 1);
					c = k + 1 + '0';
					write(1, &c, 1);
					c = j + '0';
					write(1, " [", 2);
					write(1, &c, 1);
					write(1, "] ", 2);
				}
					
				k++;
			}
			j++;
		}
		if (i != ord - 1)
			write(1, "\n", 1);
		i++;
	}
}

void	rimuovi_poss(int *tab, int poss)
{
	if (poss != 0)
		tab[poss - 1] = 0;
}

void	metti_poss(int *tab, int ord, int poss)
{
	int	i;

	i = 0;
	while (i < ord)
	{
		if (i != poss - 1)
			rimuovi_poss(tab, i);
		i++;
	}
}

int	unica_poss(int *tab, int ord)
{
	int	i;
	int	poss;
	int	cont;

	cont = 0;
	poss = 1;
	while (poss <= ord && cont != 1)
	{
		i = 0;
		cont = 0;
		while (i < ord)
		{
			if(tab[poss - 1] == 1)
				cont++;
			i++;
		}
		poss++;
	}
	if (cont == 1)
		return (poss);
	else
		return (0);
}

int	v_poss(int *tab, int poss)
{
	if (tab[poss - 1] == 1)
		return (1);
	else
		return (0);
}

void	riempi(int **arr, int ord, int ***tab2)
{
	int	i;
	int	j;
	int	i2;
	int	j2;
	int	k;
	int	fine;
	int	tab[4][4][4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				tab[i][j][k] = 1;
				k++;
			}
			j++;
		}
		i++;
	}
	(void) tab2;
	fine = 0;
	i = 0;
	while (!fine)
	{
		fine = 1;
		while (i < ord)
		{
			j = 0;
			while (j < ord)
			{
				if (i % (ord - 1) == 0 && j % (ord - 1) == 0) // se e` un angolo
				{
					if (arr[(ord - j) % ord][j] != 1 || arr[((ord - j) % ord) + 2][i] != 1) // se c'e` un numero diverso da 1 come istruzione accanto
						rimuovi_poss(tab[i][j], ord); // togli la possibilita` del 4 (ord)
					else
						metti_poss(tab[i][j], ord, ord); // lascia solo il 4 (ord)
					if (arr[(ord - j) % ord][j] == ord - 1 || arr[((ord - j) % ord) + 2][i] == ord - 1) // se c'e` un 3 (ord - 1) come istruzione accanto
						rimuovi_poss(tab[i][j], ord - 1); // togli la possibilita` del 3 (ord - 1)
				}
				else if(i == 0 || j == 0) // se e` un lato
				{
					if ((i % (ord - 1) == 0 && arr[(ord - j) % ord][j] != 1) || (j % (ord - 1) == 0 && arr[((ord - j) % ord) + 2][i] != 1)) // se c'e` un numero diverso da 1 come istruzione accanto
						rimuovi_poss(tab[i][j], ord); // togli la possibilita` del 4 (ord)
					else
						metti_poss(tab[i][j], ord, ord); // lascia solo il 4 (ord)
					if ((i % (ord - 1) == 0 && arr[(ord - j) % ord][j] == ord - 1) || (j % (ord - 1) == 0 && arr[((ord - j) % ord) + 2][i] == ord - 1)) // se c'e` un 3 (ord - 1) come istruzione accanto
						rimuovi_poss(tab[i][j], ord - 1); // togli la possibilita` del 3 (ord - 1)
						
				}
				if (arr[0][j] == ord) // se c'e` ord in alto
					metti_poss(tab[i][j], ord, i + 1);
				if (arr[1][j] == ord) // se c'e` ord in basso
					metti_poss(tab[i][j], ord, ord - i);
				if (arr[2][i] == ord) // se c'e` ord a sinistra
					metti_poss(tab[i][j], ord, j + 1);
				if (arr[3][i] == ord) // se c'e` ord a destra
					metti_poss(tab[i][j], ord, ord - j);
				i2 = 0;
				while (i2 < ord)
				{
					if (i2 != j)
						rimuovi_poss(tab[i][j], unica_poss(tab[i][i2], ord)); // tolgo le uniche possibilita` degli altri
					i2++;
				}
				i2 = 0;
				while (i2 < ord)
				{
					if (i2 != j)
						rimuovi_poss(tab[i][j], unica_poss(tab[i2][j], ord));
					i2++;
				}
				i2 = 1;
				while (i2 <= ord) // scorro le possibilita`
				{
					j2 = 0;
					while (j2 < ord) // scorro le colonne
					{
						if (v_poss(tab[i][j2], i2) && j2 != j)
							j2 = ord;
						j2++;
					}
					if (j2 == ord)
					{
						k = 0;
						while (k < ord)
						{
							if(k != i2)
								rimuovi_poss(tab[i][j], k);
							k++;
						}
					}
					i2++;
				}
				i2 = 1;
				while (i2 <= ord) // scorro le possibilita`
				{
					j2 = 0;
					while (j2 < ord) // scorro le righe
					{
						if (v_poss(tab[j2][j], i2) && j2 != i)
							j2 = ord;
						j2++;
					}
					if (j2 == ord)
					{
						k = 0;
						while (k < ord)
						{
							if (k != i2)
								rimuovi_poss(tab[i][j], k);
							k++;
						}
					}
					i2++;
				}
				j++;
				if (!unica_poss(tab[i][j], ord))
					fine = 0;
			}
			i++;
		}
	}
	stampa(tab, ord);
}

void	crea_tabella(int **arr, int ord)
{
	int	i;
	int	j;
	int	k;
	int	***tab;

	tab = (int ***) malloc(ord * 8);
	i = 0;
	while (i < ord)
	{
		tab[i] = (int **) malloc(ord * 8);
		j = 0;
		while (j < ord)
		{
			tab[i][j] = (int *) malloc(ord * 4);
			k = 0;
			while (k < ord)
				tab[i][j][k++] = 1;
			j++;
		}
		i++;
	}
	riempi(arr, ord, tab);
	//stampa(tab, ord);
	i = 0;
	while (i < ord)
	{
		j = 0;
		while(j < ord)
			free(tab[i][j++]);
		free(tab[i]);
		i++;
	}
	free(tab);
	
}

int	set_ord(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (str[i] && num >= 0)
	{
		if ((str[i] == ' ' && !(str[i + 1] >= '1' && str[i + 1] <= '9'))
			|| (str[i] >= '1' && str[i] <= '9' && 
				str[i + 1] != '\0' && str[i + 1] != ' ')
			|| (str[i] != ' ' && !(str[i] >= '1' && str[i] <= '9')))
			num = -1;
		else if (str[i] >= '1' && str[i] <= '9')
			num++;
		i++;
	}
	i = 1;
	while (i * i != num && i <= 9)
		i++;
	if (i == 10)
		return (-1);
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	ord;
	int	cont;
	int	**arr;

	ord = set_ord(argv[1]);
	if (ord <= 0 || argc != 2 || argv[1][0] == ' ')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	arr = (int **) malloc(4 * 8 * 4);
	while (i < ord)
		arr[i++] = (int *) malloc(ord * 4);
	cont = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < ord)
		{
			arr[i][j] = argv[1][cont] - '0';
			cont += 2;
			j++;
		}
		i++;
	}
	crea_tabella(arr, ord);
	i = 0;
	while (i < ord)
		free(arr[i++]);
	free(arr);
	return (0);
}
