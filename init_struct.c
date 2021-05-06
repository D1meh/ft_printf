#include "includes/ft_printf.h"

void	init_struct(t_print *prt)
{
	prt->dot = 0;
	prt->minus = 0;
	prt->zero = 0;
	prt->nb1 = 0;
	prt->nb2 = 0;
	prt->dot_pos = 0;
	prt->min_pos = 0;
	prt->is_neg1 = 0;
	prt->is_neg2 = 0;
}
