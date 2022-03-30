/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_uuu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 06:07:58 by hbadr             #+#    #+#             */
/*   Updated: 2021/12/14 06:17:23 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	len_nmpr(unsigned int n)
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

int	ft_putnbr_fd_uuu(unsigned int n, int fd)
{
	long	var;

	var = n;
	if (var < 0)
	{	
		var = 4294967295 + var + 1;
		n = var;
	}
	if (var < 10)
		ft_putchar_fd(var + '0', fd);
	else
	{
		ft_putnbr_fd_uuu(var / 10, fd);
		ft_putnbr_fd_uuu(var % 10, fd);
	}
	return (len_nmpr(n));
}
