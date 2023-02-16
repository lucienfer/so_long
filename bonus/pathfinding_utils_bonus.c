/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:53:46 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/26 11:36:13 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_pathfinding(t_data *data)
{
	int	i;
	int	u;

	i = 0;
	while (data->map[i] != 0)
	{
		u = 0;
		while (data->map[i][u])
		{
			if (data->map[i][u] == 'E' || data->map[i][u] == 'C')
			{
				ft_freeall(data->map);
				write(2, "Invalid map\n", 12);
				exit(0);
			}
			u++;
		}
		i++;
	}
}

void	resousse(t_data *data, int i, int j, int u)
{
	i = data->player_line;
	j = data->player_col;
	data->map[j][i] = 'x';
	while (data->map[j] != 0)
	{
		while (data->map[j][i] != 0)
		{
			if (data->map[j][i] == 'x')
			{
				put_x_p(data, i, j);
				put_x_m(data, i, j);
			}
			i++;
		}
		j++;
		if (data->map[j] == 0 && u < len(data->map)
			* ((int)ft_strlen(data->map[0])))
		{
			u++;
			i = 0;
			j = 0;
		}
		i = 0;
	}
}
