/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 07:28:58 by hbadr             #+#    #+#             */
/*   Updated: 2021/12/14 07:33:12 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nmpr(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(long n, int fd)
{
	long	var;

	var = n;
	if (var < 0)
	{
		ft_putchar_fd('-', fd);
		var = var * -1;
	}
	if (var < 10)
		ft_putchar_fd(var + '0', fd);
	else
	{
		ft_putnbr_fd(var / 10, fd);
		ft_putnbr_fd(var % 10, fd);
	}
	return (len_nmpr(n));
}
