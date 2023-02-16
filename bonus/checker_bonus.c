/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:33 by luciefer          #+#    #+#             */
/*   Updated: 2023/02/13 13:55:17 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e' && str[i
				+ 3] == 'r' && str[i + 4] == 0)
			return ;
		i++;
	}
	exit(0);
}

void	check_file(char *map)
{
	char	buff[42];
	int		n;
	int		a;

	a = open(map, O_RDONLY);
	n = read(a, buff, 42);
	if (n < 0)
		return ;
	if (n == 0)
	{
		write(2, "Invalid map\n", 12);
		close (a);
		exit(0);
	}
	n = 0;
	while (buff[n] == '1')
		n++;
	if ((buff[n] != '\n' && buff[n] != '\0') || n == 0)
	{
		write(2, "Invalid map\n", 12);
		close (a);
		exit(0);
	}
	close (a);
	return ;
}

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (0);
		else if (str[i] == '\n' && str[i + 1] == 0)
			return (0);
		i++;
	}
	return (1);
}

char	**checker(char *map, char **tab)
{
	int		a;
	char	*str;

	str = 0;
	check_arg(map);
	check_file(map);
	a = open(map, O_RDONLY);
	str = get_next_line(a);
	if (!check_empty_line(str))
	{
		write(2, "Invalid map\n", 12);
		free(str);
		close(a);
		exit(0);
	}
	tab = ft_split(str, '\n');
	free(str);
	checker_map(tab);
	close(a);
	return (tab);
}
