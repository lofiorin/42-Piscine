/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:22:33 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/12 10:22:39 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_find_special(char c)
{
	int	flag;

	flag = 0;
	if (c < 48 || c > 122)
		flag = 1;
	else if (c > 57 && c < 65)
		flag = 1;
	else if (c > 90 && c < 97)
		flag = 1;
	return (flag);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	while (str[i] != '\0')
	{
		flag = ft_find_special(str[i - 1]);
		if (flag == 1 || i == 0)
		{
			if (str[i] > 96 && 122 > str[i])
				str[i] -= 32; 
		}
		else if (str[i] > 64 && 91 > str[i])
			str[i] += 32;
		i++;
	}
	return (str);
}
