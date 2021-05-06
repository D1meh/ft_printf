NAME = libftprintf.a
SRCS = ft_printf.c \
		find_conv.c \
		ft_putchar.c \
		ft_putnstr.c \
		ft_putP.c \
		ft_putstr.c \
		getFlag.c \
		init_struct.c \
		itoh.c \
		number.c \
		redirect.c \
		redirect_flags.c \
		ft_putS.c \
		ft_putD.c \
		new_itoa.c \
		ft_putX.c \
		flag_zero.c \
		flag_dot.c
		
OBJS = $(SRCS:.c=.o)
INCLUDE = -I./includes

GCC = gcc
FLAGS = -c -Wall -Wextra -Werror
RM = rm -f

$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
