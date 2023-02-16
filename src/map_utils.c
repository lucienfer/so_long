/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:10:29 by luciefer          #+#    #+#             */
/*   Updated: 2023/02/02 18:12:53 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (data->img[i] != NULL)
			mlx_destroy_image(data->mlx_ptr, data->img[i]);
		i++;
	}
	return ;
}

int	close_window(t_data *data)
{
	ft_destroy(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_freeall(data->map);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	set_tab(t_data *data, int j)
{
	int	i;

	i = 0;
	data->img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm", &j, &j);
	data->img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "img/space.xpm", &j,
			&j);
	data->img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "img/hel-kame.xpm", &j,
			&j);
	data->img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "img/etienne_pro2.xpm",
			&j, &j);
	data->img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit.xpm", &j, &j);
	data->img[5] = mlx_xpm_file_to_image(data->mlx_ptr, "img/etienne_pro1.xpm",
			&j, &j);
	data->img[6] = mlx_xpm_file_to_image(data->mlx_ptr, "img/cameras.xpm", &j,
			&j);
	while (i < 7)
	{
		if (data->img[i] <= 0)
			ft_escape(data);
		i++;
	}
	data->anim = 0;
}

void	img_setter(t_data *data, int i, int u)
{
	if (data->map[i][u] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[0], 50
			* u, 50 * i);
	else if (data->map[i][u] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[1], 50
			* u, 50 * i);
	else if (data->map[i][u] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[2], 50
			* u, 50 * i);
	else if (data->map[i][u] == 'P' && data->anim == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[3], 50
			* u, 50 * i);
	else if (data->map[i][u] == 'P' && data->anim == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[5], 50
			* u, 50 * i);
	else if (data->map[i][u] == 'E' && data->collect_total == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[4], 50
			* u, 50 * i);
}

void	set_img(t_data *data)
{
	int	i;
	int	u;

	i = 0;
	if (data->collect_total == 0)
		data->map[data->exit_col][data->exit_line] = 'E';
	while (data->map[i] != 0)
	{
		u = 0;
		while (data->map[i][u] != 0)
		{
			img_setter(data, i, u);
			u++;
		}
		i++;
	}
}
