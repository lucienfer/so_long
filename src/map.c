/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:59:45 by luciefer          #+#    #+#             */
/*   Updated: 2023/02/02 18:02:45 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <X11/keysym.h>

void	ft_escape(t_data *data)
{
	ft_destroy(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	ft_freeall(data->map);
	free(data->mlx_ptr);
	write(2, "Invalid map\n", 12);
	exit(0);
}

int	handle_input(int keycode, t_data *data)
{
	int		i;
	char	*c;

	i = 0;
	data->anim = 0;
	if (keycode == 65307)
		game_finish(data, 0);
	else if (keycode == 119)
		i = swap_(data, 'w');
	else if (keycode == 97)
		i = swap_(data, 'a');
	else if (keycode == 115)
		i = swap_(data, 's');
	else if (keycode == 100)
		i = swap_(data, 'd');
	c = ft_itoa(i);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 100, 000, c);
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		write(1, c, ft_strlen(c));
		write(1, "\n", 1);
	}
	free(c);
	return (0);
}

void	check_argc(int i)
{
	if (i != 2)
		exit(0);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tab;
	int		i;

	check_argc(argc);
	tab = 0;
	i = 0;
	pathfinding_(argv[1], &data);
	data.map = checker(argv[1], tab);
	recup_pos_p(&data);
	recup_pos_e(&data);
	data.map[data.exit_col][data.exit_line] = '0';
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == 0)
		return (ft_freeall(data.map));
	data.win_ptr = mlx_new_window(data.mlx_ptr, ft_strlen(data.map[0]) * 50,
			len(data.map) * 50, "My first window!");
	mlx_hook(data.win_ptr, 17, (1L << 19), close_window, &data);
	total_coin(&data);
	mlx_hook(data.win_ptr, 02, (1L << 0), &handle_input, &data);
	set_tab(&data, i);
	set_img(&data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
}
