# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cefelix <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 17:19:52 by cefelix           #+#    #+#              #
#    Updated: 2024/06/16 17:19:56 by cefelix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC =  cc
RM = rm -f
AR = ar rcs
FLAGS = -Wall -Wextra -Werror
SRCS = 	./sources/ft_abs.c\
		./sources/ft_printf.c\
		./sources/ft_putstr.c\
		./sources/ft_putnbr.c\
		./sources/ft_strlen.c\
		./sources/ft_putchar.c\
		./sources/ft_print_hex.c\
		./sources/ft_print_ptr.c\
		./sources/ft_putunsigned.c\
		
OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
		
all: ${NAME}
	
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
	
