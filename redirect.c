#include "includes/ft_printf.h"
#include <stdio.h>

void	redirect(char *flags, va_list args, t_print *prt)
{
	char	c;

	c = flags[ft_strlen(flags) - 1];
	if (c == '%')
		ft_putchar('%', prt);
	else if (c == 'c')
		ft_putchar(va_arg(args, int), prt);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), prt);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), prt);
	else if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int), prt);
	else if (c == 'x')
		put_itoh(va_arg(args, unsigned int), 0, prt);
	else if (c == 'X')
		put_itoh(va_arg(args, unsigned int), 1, prt);
	else if (c == 'p')
		ft_putP(va_arg(args, long long), prt);
}
