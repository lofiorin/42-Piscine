#include <unistd.h>

void	print_pav(char **pavimento, int n)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (j < n)
	{
		while (i < n)
		{
			write(1, &pavimento[j][i], 1);
			i++;
		}
		j++;
	}
}

bool	check(int *viste, int i, int j, int valore)
{
	
}

bool	start(int *viste, char **pavimento, int n)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (n == 0)
		return (true);
	while(j < n)
	{
		while(i < n)
		{
			if(pavimento[j][i] != '1' && check(viste, i, j, 1) == true)
				pavimento[j][i] = '1';
			else if(pavimento[j][i] != '2' && check(viste, i, j, 2) == true)
				pavimento[j][i] = '2';
			else if(pavimento[j][i] != '3' && check(viste, i, j, 3) == true)
				pavimento[j][i] = '3';
			else if(pavimento[j][i] != '4' && check(viste, i, j, 4) == true)
				pavimento[j][i] = '4';
		}
	}
	
}

void	init_viste(char **argv, int *viste)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (argv[1][i] != '\0')
	{
		if(argv[1][i] != 32)
		{
			viste[j] = argv[1][i] - 48;
			j++;
		}
		i++;
	}
	
}
//funzione di controllo di input
//controlla se 
bool	controllo_input(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;
	
	i = 0;
	j = 1;
	count = 0;
	if (argc != 2)
		return (false);
	while (j < argc)
	{
		while (argv[j][i] != '\0')
		{
			if ((argv[j][i] < 49 && argv[j][i] > 57) && argv[j][i] != 32)
				return (false);
			if (argv[j][i] > 48 && argv[j][i] < 58)
				count++;
			i++;
		}
		j++;
	}
	if (count != 16)
		return (false);
	return (true);
}

//main
int	main(int argc, char **argv)
{
	int	viste[16];
	int	n;
	char	pavimento[4][4];
	
	n = 4;
	if (controllo_input(argc, argv) == false)
		write(1, "Error\n", 6);
	else
	{
		init_viste(argv, viste);
		if (start(viste, pavimento, n) == false)
			write(1, "Error\n", 6);
		else
		{
			print_pav(pavimento, n);
		}
	}
}
