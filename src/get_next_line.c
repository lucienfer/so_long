/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <luciefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:42 by luciefer          #+#    #+#             */
/*   Updated: 2023/01/30 14:30:46 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin_gnl(char *buff, char *rest)
{
	char	*str;
	int		i;
	int		u;

	u = 0;
	i = 0;
	if (!buff && !rest)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(rest)) + 1);
	if (!str)
		return (0);
	if (rest)
	{
		while (rest[u])
			str[i++] = rest[u++];
	}
	u = 0;
	while (buff[u])
		str[i++] = buff[u++];
	str[i] = 0;
	if (rest)
		free(rest);
	return (str);
}

char	*get_buff(int fd, char *rest)
{
	static int	i;
	char		*buff;
	int			n;

	n = 1;
	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (n > 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = 0;
		rest = ft_strjoin_gnl(buff, rest);
	}
	free(buff);
	return (rest);
}

char	*get_next_line(int fd)
{
	char	*rest;

	rest = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rest = get_buff(fd, rest);
	if (!rest)
		return (NULL);
	return (rest);
}
