# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 13:51:45 by omimouni          #+#    #+#              #
#    Updated: 2020/02/27 14:20:49 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_reader.c	\
		ft_show_char.c \
		ft_show_execption.c \
		ft_show_hex.c \
		ft_show_nbr.c \
		utils/ft_intlen.c \
		utils/ft_putchar.c \
		utils/ft_puthex.c \
		utils/ft_putnbr.c \
		utils/ft_putstr.c \
		utils/ft_strlen.c

OBJS = ft_printf.o \
		ft_reader.o	\
		ft_show_char.o \
		ft_show_execption.o \
		ft_show_hex.o \
		ft_show_nbr.o \
		ft_intlen.o \
		ft_putchar.o \
		ft_puthex.o \
		ft_putnbr.o \
		ft_putstr.o \
		ft_strlen.o

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
