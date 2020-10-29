# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 11:34:27 by ysoroko           #+#    #+#              #
#    Updated: 2020/10/26 20:19:06 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	 	= 		gcc
CFLAGS		=		-Wall -Wextra -Werror
SRCS		=		srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS		=		${SRCS:.c=.o}
NAME		=		libft.a
.c.o:		
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:	
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re 
