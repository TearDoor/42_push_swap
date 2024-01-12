# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkok-kea <tkok-kea@student.42kl.edu.my     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:45:26 by tkok-kea          #+#    #+#              #
#    Updated: 2024/01/13 01:47:32 by tkok-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

BONUS	= checker

SRCS	= $(wildcard srcs/*.c srcs/pushswap/*.c srcs/utils/*.c)

OBJS	= ${SRCS:.c=.o}

B_SRCS	= $(wildcard srcs/*.c srcs/checker/*.c srcs/utils/*.c)

B_OBJS	= ${B_SRCS:.c=.o}

LIBFT	= ./libft/libft.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -rf

SANITIZE	= -fsanitize=address -g

all:		${NAME}

${NAME}: 	${OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

bonus:		${NAME} ${BONUS}

${BONUS}:	${B_OBJS} ${LIBFT}
			${CC} ${CFLAGS} ${B_OBJS} ./libft/libft.a -o ${BONUS}

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
			${RM} ${NAME} ${BONUS}
			@echo "Everthing cleaned"

re:			fclean all

.PHONY:	all clean fclean re
