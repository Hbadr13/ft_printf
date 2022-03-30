/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 05:21:24 by hbadr             #+#    #+#             */
/*   Updated: 2021/12/14 06:11:47 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char c, va_list stringg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar_fd(va_arg(stringg, int), 1);
	else if (c == 's')
		len = len + ft_putstr_fd(va_arg(stringg, char *), 1);
	else if (c == 'd' || c == 'i')
		len = len + ft_putnbr_fd(va_arg(stringg, int), 1);
	else if (c == 'u')
		len = len + ft_putnbr_fd_uuu(va_arg(stringg, unsigned int), 1);
	else if (c == 'X')
		len = len + ft_putnbr_fd_hexa(va_arg(stringg, unsigned int), 1);
	else if (c == 'x')
		len = len + ft_putnbr_fd_xxxx(va_arg(stringg, unsigned int), 1);
	else if (c == 'p')
		len = len + ft_putnbr_fd_ppp(va_arg(stringg, void *), 1);
	return (len);
}

int	ft_printf(const char *src, ...)
{
	int		i;
	int		len;
	va_list	stringg;

	len = 0;
	va_start(stringg, src);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '%' && src[i + 1] == '%')
		{
			len = len + ft_putchar_fd('%', 1);
			i++;
		}
		else if (src[i] != '%')
			len = len + ft_putchar_fd(src[i], 1);
		else if (src[i] == '%')
		{
			i++;
			len = len + ft_write(src[i], stringg);
		}
		i++;
	}
	va_end(stringg);
	return (len);
}
