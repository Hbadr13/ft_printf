/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 07:30:04 by hbadr             #+#    #+#             */
/*   Updated: 2021/12/14 07:31:17 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdio.h>
# include<unistd.h>
# include <stdarg.h>

int	ft_printf(const char *src, ...);
int	ft_putchar_fd(int c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_strlen(const char *s);
int	ft_putnbr_fd(long n, int fd);
int	ft_putnbr_fd_uuu(unsigned int n, int fd);
int	ft_putnbr_fd_hexa(unsigned int n, int fd);
int	ft_putnbr_fd_xxxx(unsigned int n, int fd);
int	ft_putnbr_fd_ppp(void *p, int fd);
#endif
