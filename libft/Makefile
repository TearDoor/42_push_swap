# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkok-kea <tkok-kea@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 20:26:50 by tkok-kea          #+#    #+#              #
#    Updated: 2023/11/02 18:45:35 by tkok-kea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		  ft_strlen.c  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c\
		  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
		  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
		  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
		  ft_putendl_fd.c ft_putnbr_fd.c \

OBJS	= $(SRC:.c=.o)

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c\
		  ft_lstiter.c ft_lstmap.c\

BOBJS	= $(BONUS:.c=.o)

NAME	= libft.a

AR		= ar rcs

RM 		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
		@$(AR) $(NAME) $(OBJS)

.c.o:
		@$(CC) $(CFLAGS) -c $< -I ./

clean:
		@$(RM) $(OBJS) $(BOBJS)

fclean:	clean
		@$(RM) $(NAME)

bonus:	$(OBJS) $(BOBJS)
		@$(AR) $(NAME) $(OBJS) $(BOBJS)

re:		fclean all

.PHONY:	all clean fclean re bonus
