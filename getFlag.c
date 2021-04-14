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

static void	change_prt(char f, t_print *prt)
{
	if (f == '.')
		prt->dot = 1;
	if (f == '-')
		prt->minus = 1;
}

static void	change_nb(int *prt_nb, char *flags, int *i, va_list args)
{
	if (flags[*i] == '*')
	{
		*prt_nb = va_arg(args, int);
		*i = *i + 1;
	}
	else
		*prt_nb = new_atoi(flags, i);
	if (*prt_nb < 0)
		*prt_nb = 1;
}

int	getFlag(char *flags, t_print *prt, va_list args)
{
	int	i;

	i = 0;
	if (checkZero(flags[i], prt))
		i++;
	change_nb(&prt->nb1, flags, &i, args);
	if (flags[i] == '.' || flags[i] == '-')
	{
		if (prt->zero || (flags[i] == '-' && prt->nb1))
		{
			free(flags);
			return (-1);
		}
		change_prt(flags[i], prt);
		i++;
	}
	if (!is_conv(flags[i]))
		change_nb(&prt->nb2, flags, &i, args);
	if (!is_conv(flags[i]))
	{
		free(flags);
		return (-1);
	}
	return (1);
}

int	check_error(char *flags, t_print *prt)
{
	char	c;

	c = flags[ft_strlen(flags) - 1];
	if ((c == 'c' || c == 'p') && (prt->zero || prt->dot))
	{
		free(flags);
		return (-1);
	}
	if (c == 's' && prt->zero)
	{
		free(flags);
		return (-1);
	}
	return (1);
}
