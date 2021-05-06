#include "includes/ft_printf.h"

static int	base16(long long int nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb != 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

static char	*alloc_nb(long long int nb, char *hexa)
{
	int		count;
	int		i;
	char	*n;

	count = base16(nb);
	n = malloc(sizeof(char) * count);
	if (!n)
		return (NULL);
	n[count] = 0;
	i = count - 1;
	if (nb < 0)
		nb = -nb;
	while (i >= 0)
	{
		n[i] = hexa[nb % 16];
		i--;
		nb /= 16;
	}
	return (n);
}

static char	*change_a(int maj)
{
	char	*a;

	if (maj)
		a = ft_strdup("0123456789ABCDEF");
	else
		a = ft_strdup("0123456789abcdef");
	return (a);
}

char	*itoh(long long n, int maj)
{
	char			*a;
	long long int	nb;
	char			*hexa;

	nb = n;
	a = change_a(maj);
	hexa = alloc_nb(nb, a);
	if (nb == 0)
	{
		hexa[0] = '0';
		hexa[1] = 0;
	}
	free(a);
	return (hexa);
}

void	put_itoh(long long n, int maj, t_print *prt)
{
	char	*s;

	if (n == LONG_MIN)
		s = ft_strdup("8000000000000000");
	else if ((unsigned long)n == ULONG_MAX)
		s = ft_strdup("ffffffffffffffff");
	else
		s = itoh(n, maj);
	ft_putstr(s, prt);
	free(s);
}
