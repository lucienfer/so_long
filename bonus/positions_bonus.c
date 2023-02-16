/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:01:27 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/26 11:36:17 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	total_coin(t_data *data)
{
	int	i;
	int	u;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i] != 0)
	{
		u = 0;
		while (data->map[i][u])
		{
			if (data->map[i][u] == 'C')
				j++;
			u++;
		}
		i++;
	}
	data->collect_total = j;
}

void	recup_pos_p(t_data *data)
{
	int	i;
	int	u;

	i = 0;
	while (data->map[i] != 0)
	{
		u = 0;
		while (data->map[i][u])
		{
			if (data->map[i][u] == 'P')
			{
				data->player_line = u;
				data->player_col = i;
				return ;
			}
			u++;
		}
		i++;
	}
}

void	recup_pos_e(t_data *data)
{
	int	i;
	int	u;

	i = 0;
	while (data->map[i] != 0)
	{
		u = 0;
		while (data->map[i][u])
		{
			if (data->map[i][u] == 'E')
			{
				data->exit_line = u;
				data->exit_col = i;
				return ;
			}
			u++;
		}
		i++;
	}
}
