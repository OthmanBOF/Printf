# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouftou <obouftou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 19:11:30 by obouftou          #+#    #+#              #
#    Updated: 2024/11/26 10:06:57 by obouftou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_puhexa_printf.c ft_putadress_printf.c ft_putchar_printf.c \
			ft_putnbr_printf.c ft_putstr_printf.c \
			ft_unsigned_printf.c ft_printf.c

OBJS = $(SRC:.c=.o)


$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
