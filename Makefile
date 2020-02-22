# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omimouni <omimouni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 13:51:45 by omimouni          #+#    #+#              #
#    Updated: 2020/02/22 13:52:16 by omimouni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

RM = rm -rf

NAME = libftprintf.a

SRCS =	*.c \
		utils/*.c
		
OBJS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(OBJS) $(SRCS)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all