/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:54:49 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/24 18:14:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct t_dielement
{
	long	key;
	char	*value;
}	t_dielement;

typedef struct t_file_lines
{
	char	**lines;
	int		size;
}	t_file_lines;

void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_swap(char *a, char *b);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
long		ft_atoi(const char *str);
int			ft_errormsg(char *prefix);	
char		*ft_strcpy(char *dest, char *src);
char		**ft_split(char *s, char c);
int			ft_count_char(char *str, char c);
t_dielement	*parse_dict_file(char *filename, int *dict_size);
void		ft_print(long n, t_dielement *dict, int first);
#endif
