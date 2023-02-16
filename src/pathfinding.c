/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:57:51 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/27 13:16:00 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	len(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}

void	put_x_p(t_data *data, int i, int j)
{
	int	x;
	int	u;

	x = i;
	u = j;
	while (data->map[u][i] != '1')
	{
		data->map[u][i] = 'x';
		u++;
	}
	while (data->map[j][x] != '1')
	{
		data->map[j][x] = 'x';
		x++;
	}
}

void	put_x_m(t_data *data, int i, int j)
{
	int	x;
	int	u;

	x = i;
	u = j;
	while (data->map[u][i] != '1')
	{
		data->map[u][i] = 'x';
		u--;
	}
	while (data->map[j][x] != '1')
	{
		data->map[j][x] = 'x';
		x--;
	}
}

/*int	ft_freeall(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/

void	pathfinding_(char *str, t_data *data)
{
	int		i;
	int		j;
	int		u;
	char	**tab;

	tab = 0;
	u = 0;
	i = 0;
	j = 0;
	data->map = checker(str, tab);
	recup_pos_p(data);
	resousse(data, i, j, u);
	check_pathfinding(data);
	ft_freeall(data->map);
}
