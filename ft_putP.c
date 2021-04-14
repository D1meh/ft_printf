#include "includes/ft_printf.h"

void	ft_putP(long long ptr, t_print *prt)
{
	ft_putstr("0x", prt);
	put_itoh(ptr, 0, prt);
}
