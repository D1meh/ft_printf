#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	t_print	prt;
	int		verif;

	i = 0;
	prt.len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &prt);
		else
		{
			init_struct(&prt);
			verif = find_conv(str, args, &i, &prt);
			if (verif == -1)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (prt.len);
}
