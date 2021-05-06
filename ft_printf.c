#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	t_print	prt;

	i = 0;
	prt.len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i], &prt);
		else
		{
			init_struct(&prt);
			find_conv(str, args, &i, &prt);
		}
		i++;
	}
	va_end(args);
	return (prt.len);
}
