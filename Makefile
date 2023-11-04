# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:45:26 by tkok-kea          #+#    #+#              #
#    Updated: 2023/11/04 18:18:05 by tkok-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRCS =  $(wildcard srcs/*.c)

OBJS = ${SRCS:.c=.o}

CC =	gcc

CLAGS =	-Wall -Werror -Wextra

RM =	rm -rf

all:	${NAME}

${NAME}: 	${OBJS}
			@echo "Making libft"
			@${MAKE} -C ./libft bonus
			@${MAKE} -C ./libft/ft_printf
			@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a ./libft/ft_printf/libftprintf.a -o ${NAME}

clean:
			@echo "Cleaning libft"
			@${MAKE} -C ./libft fclean
			@${MAKE} -C ./libft/ft_printf fclean
			@echo "Cleaning temporary files"
			@${RM} ${OBJS}


fclean:		clean
			@echo "Removing push_swap"
			${RM} ${NAME}
			@echo "Everthing cleaned"

re:			fclean all

.PHONY:	all clean fclean re
