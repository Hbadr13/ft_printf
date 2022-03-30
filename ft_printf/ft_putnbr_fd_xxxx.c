/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_xxxx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 06:09:17 by hbadr             #+#    #+#             */
/*   Updated: 2021/12/14 07:33:27 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	len_nmpr(unsigned int n)
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

int	ft_putnbr_fd_xxxx(unsigned int n, int fd)
{
	unsigned long	var;

	var = n;
	if (var >= 10 && var <= 15)
	{
		ft_putchar_fd(var + 'W', fd);
	}
	else if (var < 10)
		ft_putchar_fd(var + '0', fd);
	else
	{
		ft_putnbr_fd_xxxx(var / 16, fd);
		ft_putnbr_fd_xxxx(var % 16, fd);
	}
	return (len_nmpr(n));
}
