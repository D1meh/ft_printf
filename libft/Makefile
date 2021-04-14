# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 13:33:37 by mtaouil           #+#    #+#              #
#    Updated: 2021/04/14 13:32:04 by mtaouil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_memset.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
		  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		  ft_putchar_fd.c ft_memccpy.c ft_putendl_fd.c ft_memchr.c \
		  ft_putnbr_fd.c ft_memcmp.c ft_putstr_fd.c ft_memcpy.c \
		  ft_split.c ft_strlcat.c ft_strchr.c ft_strlcpy.c ft_strmapi.c \
		  ft_strnstr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_substr.c \
		  ft_strncmp.c ft_memmove.c ft_strrchr.c ft_strtrim.c ft_tolower.c \
		  ft_toupper.c

LISTE	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

LST		= $(OBJS) $(LISTE:.c=.o)

GCC		= gcc
RM		= rm -f
FLAGS	= -Wall -Werror -Wextra

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

bonus:		${LST}
			ar -rcs ${NAME} ${LST}

clean:
			${RM} ${OBJS} ${LST}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
