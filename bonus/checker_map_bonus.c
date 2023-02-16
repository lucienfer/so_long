/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:39:44 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/23 20:04:48 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_return(void)
{
	write(2, "Invalid map\n", 12);
	return (0);
}

int	check_full_one(char **tab)
{
	int	line_nb;
	int	k;

	line_nb = line_count(tab);
	while (tab[0][0] != '\0')
	{
		k = 0;
		while (tab[0][k] != '\0')
		{
			if (tab[0][k] != '1')
				return (ft_return());
			k++;
		}
		k = 0;
		while (tab[line_nb - 1][k] != '\0')
		{
			if (tab[line_nb - 1][k] != '1')
				return (ft_return());
			k++;
		}
		break ;
	}
	return (1);
}

int	one_p_e(char **tab, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
	{
		write(2, "Invalid map\n", 12);
		return (0);
	}
}

int	one_c(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	if (count >= 1)
		return (1);
	else
	{
		write(2, "Invalid map\n", 12);
		return (0);
	}
}

void	checker_map(char **tab)
{
	if (!check_char(tab))
		exit(ft_freeall(tab));
	if (!check_length(tab))
		exit(ft_freeall(tab));
	if (!check_startend(tab))
		exit(ft_freeall(tab));
	if (!check_full_one(tab))
		exit(ft_freeall(tab));
	if (!one_p_e(tab, 'P'))
		exit(ft_freeall(tab));
	if (!one_p_e(tab, 'E'))
		exit(ft_freeall(tab));
	if (!one_c(tab))
		exit(ft_freeall(tab));
	return ;
}
