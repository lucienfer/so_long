/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadresse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciefer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:28:11 by luciefer          #+#    #+#             */
/*   Updated: 2022/12/01 12:00:47 by luciefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadresse(unsigned long p)
{
	int	u;

	u = 2;
	if (p == 0)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	u += ft_puthexa((int long long unsigned)p);
	return (u);
}
