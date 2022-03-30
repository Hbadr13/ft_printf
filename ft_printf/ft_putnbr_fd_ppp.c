/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_ppp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:27:02 by hbadr             #+#    #+#             */
/*   Updated: 2021/12/14 05:30:12 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nmpr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_addas(unsigned long var, int fd)
{
	int	len;

	len = 0;
	len = len_nmpr(var);
	if (var >= 10 && var <= 15)
		ft_putchar_fd(var + 'W', fd);
	else if (var < 10)
		ft_putchar_fd(var + '0', fd);
	else
	{
		ft_addas(var / 16, fd);
		ft_addas(var % 16, fd);
	}
	return (len);
}

int	ft_putnbr_fd_ppp(void *p, int fd)
{
	unsigned long	n;
	int				ln;

	n = (unsigned long)p;
	write(1, "0x", 2);
	ln = ft_addas(n, fd);
	return (ln + 2);
}
