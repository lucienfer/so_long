/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:13:27 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/30 13:22:50 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_line(char *rest)
{
	char	*str;
	int		i;

	i = 0;
	if (rest[i] == 0)
		return (0);
	str = malloc(sizeof(char) * ft_strlen(rest) + 1);
	if (!str)
		return (0);
	while (rest[i])
	{
		str[i] = rest[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*get_rest(char *rest)
{
	char	*str;
	int		i;
	int		u;

	u = 0;
	i = ft_strlen(rest);
	if (!i)
	{
		free(rest);
		return (NULL);
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	while (rest[i])
		str[u++] = rest[i++];
	str[u] = 0;
	return (str);
}
