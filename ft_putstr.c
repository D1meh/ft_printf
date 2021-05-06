#include "includes/ft_printf.h"

void	ft_putstr(char *s, t_print *prt)
{
	int	i;

	if (s == NULL)
		return (ft_putstr("(null)", prt));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], prt);
		i++;
	}
}

void	ft_put_and_free(char *s, t_print *prt, char c)
{
	int	i;

	i = 0;
	if (c == 'p')
		ft_putstr("0x", prt);
	while (s[i])
	{
		ft_putchar(s[i], prt);
		i++;
	}
	free(s);
}
