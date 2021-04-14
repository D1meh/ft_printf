#include "includes/ft_printf.h"

void	ft_putstr(char *s, t_print *prt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], prt);
		i++;
	}
}

void	put_doubleD(t_print *prt, char *s)
{
	int	zeros;
	int	spaces;

	zeros = prt->nb2 - ft_strlen(s);
	spaces = prt->nb1 - zeros - ft_strlen(s);
	while (spaces > 0)
	{
		ft_putchar(' ', prt);
		spaces--;
	}
	while (zeros > 0)
	{
		ft_putchar('0', prt);
		zeros--;
	}
	ft_putstr(s, prt);
	free(s);
}
