# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 16:45:26 by tkok-kea          #+#    #+#              #
#    Updated: 2024/03/24 17:17:36 by tkok-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

BONUS	= checker

S_FILES =	push_swap.c \
			pushswap/sort_big.c \
			pushswap/sort_three.c \
			utils/lis.c \

SHR_FILES =	operations/operations_push.c \
			operations/operations_rev_rotate.c \
			operations/operations_rotate.c \
			operations/operations_swap.c \
			utils/init_stack.c \
			utils/stack_check.c \
			utils/stack_utils.c \
			utils/stack_utils2.c \
			utils/utils.c

B_FILES	= checker.c

SRCS	=	$(addprefix srcs/, $(S_FILES)) \
			$(addprefix srcs/, $(SHR_FILES))

B_SRCS	=	$(addprefix srcs/, $(B_FILES)) \
			$(addprefix srcs/, $(SHR_FILES))

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

LIBFT	= ./libft/libft.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -Iinclude -Ilibft

RM		= rm -rf

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Compile Message
CMSG	= @echo "${1}Compiled $@ ${RESET}"

all:		${NAME}

${NAME}: 	${LIBFT} ${OBJS}
			@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
			 ${call CMSG,${GREEN}}

bonus:		${NAME} ${BONUS}

${BONUS}:	${LIBFT} ${B_OBJS}
			@${CC} ${CFLAGS} ${B_OBJS} ${LIBFT} -o ${BONUS}
			${call CMSG,${GREEN}}

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
			 ${call CMSG,${YELLOW}}

${LIBFT}:
			@echo "Making libft"
			@${MAKE} -C ./libft
			@${MAKE} -C ./libft clean

clean:
			@${MAKE} -C ./libft fclean
			@${foreach obj,${OBJS},echo "${RED}Removing ${obj}${RESET}" && ${RM} ${obj};}
			@${foreach obj,${B_OBJS},echo "${RED}Removing ${obj}${RESET}" && ${RM} ${obj};}


fclean:		clean
			@echo "${RED}Removing ${NAME} ${BONUS}${RESET}"
			@${RM} ${NAME} ${BONUS}

re:			fclean all

reb:		re bonus

.PHONY:	all clean fclean re
