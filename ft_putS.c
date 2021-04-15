#include "includes/ft_printf.h"

char	*putspaces(char c, va_list args, t_print *prt)
{
	char	*s;
	int		i;
	int		spaces;

	i = 0;
	spaces = 0;
	if (c == 'p')
	{
		s = itoh(va_arg(args, long long), 0);
		spaces = 2;
	}
	if (c == 's')
		s = ft_strdup(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_itoa(va_arg(args, unsigned int));
	else if (c == 'x')
		s = itoh(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		s = itoh(va_arg(args, unsigned int), 1);
	while (i++ < prt->nb1 - (int)ft_strlen(s) - spaces)
		ft_putchar(' ', prt);
	return (s);
}