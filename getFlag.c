#include "includes/ft_printf.h"

static int	checkZero(char f, t_print *prt)
{
	if (f == '0')
	{
		prt->zero = 1;
		return (1);
	}
	return (0);
}

static void	change_prt(char *flag, t_print *prt, int *i)
{
	if (flag[*i] == '.')
	{
		*i = *i + 1;
		prt->dot = 1;
		prt->dot_pos = 1 + prt->minus;
	}
	if (flag[*i] == '-')
	{
		*i = *i + 1;
		prt->minus++;
		prt->min_pos = 1 + prt->dot;
	}
}

static void	changestar(t_print *prt, int n, va_list args)
{
	if (n % 2 == 1)
	{
		prt->nb1 = absolute(va_arg(args, int), prt, n);
	}
	else
	{
		prt->nb2 = absolute(va_arg(args, int), prt, n);
	}
}

static void	change_nb(t_print *prt, char *flags, int *i, va_list args)
{
	static int	n = 1;

	if (is_conv(flags[*i]))
	{
		n++;
		return ;
	}
	if (flags[*i] == '0')
		*i = *i + 1;
	if (flags[*i] == '*')
	{
		changestar(prt, n, args);
		*i = *i + 1;
	}
	else
	{
		if (n % 2 == 1)
			prt->nb1 = new_atoi(flags, i);
		else
			prt->nb2 = new_atoi(flags, i);
	}
	n++;
}

int	getFlag(char *flags, t_print *prt, va_list args)
{
	int	i;

	i = 0;
	while (flags[i] != '\0' && !is_conv(flags[i]))
	{
		if (checkZero(flags[i], prt))
			i++;
		if (flags[i] == '-')
			change_prt(flags, prt, &i);
		change_nb(prt, flags, &i, args);
		change_prt(flags, prt, &i);
		change_nb(prt, flags, &i, args);
	}
	if (prt->minus && !prt->dot && prt->nb1 && !prt->nb2)
	{
		prt->nb2 = prt->nb1;
		prt->nb1 = 0;
	}
	if (!is_conv(flags[i]))
	{
		free(flags);
		return (-1);
	}
	return (1);
}
