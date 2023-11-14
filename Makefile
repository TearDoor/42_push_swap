# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:45:26 by tkok-kea          #+#    #+#              #
#    Updated: 2023/11/14 14:10:31 by tkok-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

SRCS =  $(wildcard srcs/*.c srcs/utils/*.c)

OBJS = ${SRCS:.c=.o}

LIBFT = ./libft/libft.a

CC =	gcc

CFLAGS =	-Wall -Werror -Wextra

SANITIZE	= -fsanitize=address -g

RM =	rm -rf

all:		${NAME}

${NAME}: 	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

${LIBFT}:
			@echo "Making libft"
			@${MAKE} -C ./libft

clean:
			@${MAKE} -C ./libft fclean
			@echo "Cleaning temporary files"
			@${RM} ${OBJS}


fclean:		clean
			@echo "Removing push_swap"
			${RM} ${NAME}
			@echo "Everthing cleaned"

re:			fclean all

.PHONY:	all clean fclean re
