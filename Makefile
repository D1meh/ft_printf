NAME = libftprintf.a
SRCS = ft_printf.c \
		find_conv.c \
		ft_putchar.c \
		ft_putnstr.c \
		ft_putP.c \
		ft_putstr.c \
		ft_uplow.c \
		getFlag.c \
		init_struct.c \
		itoh.c \
		number.c \
		redirect.c \
		redirect_flags.c
OBJS = $(SRCS:.c=.o)
INCLUDE = -I./includes

GCC = gcc
FLAGS = -c -Wall -Wextra -Werror
RM = rm -f

$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(GCC) $(FLAGS) $(INCLUDE) $(SRCS)
			ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
