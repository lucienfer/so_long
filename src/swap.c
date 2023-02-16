/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:23:46 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/30 17:15:31 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_freeall(char **tab)
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
}

int	movement_two(t_data *data, int u, int i, char mov)
{
	if (data->map[data->player_col + 1][u] != '1' && mov == 's')
	{
		data->map[data->player_col][u] = data->map[data->player_col + 1][u];
		data->map[data->player_col + 1][u] = 'P';
		i++;
	}
	else if (data->map[data->player_col - 1][u] != '1' && mov == 'w')
	{
		data->map[data->player_col][u] = data->map[data->player_col - 1][u];
		data->map[data->player_col - 1][u] = 'P';
		i++;
	}
	return (i);
}

int	movement(t_data *data, int i, int u, char mov)
{
	if (data->map[data->player_col][u + 1] != '1' && mov == 'd')
	{
		data->map[data->player_col][u] = data->map[data->player_col][u + 1];
		data->map[data->player_col][u + 1] = 'P';
		i++;
		data->anim = 1;
	}
	else if (data->map[data->player_col][u - 1] != '1' && mov == 'a')
	{
		data->map[data->player_col][u] = data->map[data->player_col][u - 1];
		data->map[data->player_col][u - 1] = 'P';
		i++;
		data->anim = 0;
	}
	i = movement_two(data, u, i, mov);
	return (i);
}

int	game_finish(t_data *data, int u)
{
	data->map[data->player_col][u] = '0';
	ft_destroy(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_freeall(data->map);
	free(data->mlx_ptr);
	exit(0);
}

int	swap_(t_data *data, char mov)
{
	int			u;
	static int	i;

	recup_pos_p(data);
	u = data->player_line;
	if (!data->img[0])
		set_tab(data, u);
	i = movement(data, i, u, mov);
	if (data->map[data->player_col][u] == 'C')
		data->collect_total--;
	if (data->collect_total == 0 && data->map[data->player_col][u] == 'E')
		game_finish(data, u);
	if (data->map[data->player_col][u] != 'E'
		&& data->map[data->player_col][u] != 'P')
		data->map[data->player_col][u] = '0';
	set_img(data);
	return (i);
}
