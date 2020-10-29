# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysoroko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 11:34:27 by ysoroko           #+#    #+#              #
#    Updated: 2020/10/29 12:51:34 by ysoroko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	 		= 		gcc -c 
CCO			= 		gcc -o
CFLAGS		=		-Wall -Wextra -Werror
SRCS		=		srcs/doop.c srcs/ft_atoi.c srcs/ft_operations.c srcs/ft_putnbr.c
OBJS		=		${SRCS:.c=.o}
NAME		=		do-op

.c.o:		
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

all:	${OBJS}	
		${CCO} ${NAME} ${OBJS} 

clean:	
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re 
