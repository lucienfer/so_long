/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:46:27 by luciefer          #+#    #+#             */
/*   Updated: 2022/12/01 13:27:16 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_hnb(unsigned long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int	ft_puthexa(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
		ft_puthexa(nb % 16);
	}
	else if (nb < 10)
		ft_putchar (nb + 48);
	else
		ft_putchar(nb + 87);
	return (size_hnb(nb));
}

int	ft_puthexaup(unsigned int nb)
{
	if (nb >= 16)
	{
		ft_puthexaup(nb / 16);
		ft_puthexaup(nb % 16);
	}
	else if (nb < 10)
		ft_putchar (nb + 48);
	else
		ft_putchar(nb + 55);
	return (size_hnb(nb));
}
