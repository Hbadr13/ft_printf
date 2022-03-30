# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 16:31:53 by hbadr             #+#    #+#              #
#    Updated: 2021/12/14 07:38:58 by hbadr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = ft_printf.c ft_putnbr_fd.c ft_putstr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_strlen.c ft_putnbr_fd_uuu.c ft_putnbr_fd_xxxx.c ft_putnbr_fd_hexa.c ft_putnbr_fd_ppp.c

NAME = libftprintf.a
OBJ_FILE = $(SRC_FILE:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = libft.h

all : $(NAME)

$(NAME) : $(OBJ_FILE)
	ar rc $(NAME) $(OBJ_FILE)

%.o:%.c $(HEADER)
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ_FILE)

fclean : clean
	rm -f $(NAME)

re : fclean all
