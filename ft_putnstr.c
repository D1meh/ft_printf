#include "includes/ft_printf.h"

void	ft_putnstr(char *s, t_print *prt, int n)
{
	int		i;

	if (!s)
		return (ft_putnstr("(null)", prt, n));
	i = 0;
	while (s[i] && i < n)
	{
		ft_putchar(s[i], prt);
		i++;
	}
}
